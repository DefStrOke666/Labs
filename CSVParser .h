#ifndef LAB4_CSVPARSER_H
#define LAB4_CSVPARSER_H

#include <stdio.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include "CSVParserException.h"
#include <locale>
#include <algorithm>
#include <regex>
#include "TupleWriter.h"
#include <list>

template<typename ...Args>
class CSVParser {
    class ParserCtype : public std::ctype<char> {
    private:
        mask performedTable[table_size]{};

    public:
        explicit ParserCtype(char delimiter, size_t refs = 0)
                : std::ctype<char>(&performedTable[0], false, refs) {
            std::copy_n(classic_table(), table_size, performedTable);
            performedTable[' '] = lower;
            performedTable[delimiter] = space;
        }
    };

private:
    std::ifstream &input;
    int linesSkip;
    char delimiter;
    std::streampos startPos;

    void skipLines(int skipLinesNumber) {
        std::string temp;
        for (int i = 0; i < skipLinesNumber; i++) {
            if (std::getline(input, temp)) {
                skipLinesNumber--;
            } else {
                throw std::invalid_argument("aga");
            }
        }
        startPos = input.tellg();
    }

public:
    CSVParser(std::ifstream &inputStream, const int skipLinesNumber, char csvDelimiter) : input(inputStream) {
        linesSkip = skipLinesNumber;
        delimiter = csvDelimiter;
        skipLines(skipLinesNumber);
    }

    class iterator {
        friend class CSVParser;

        typedef std::tuple<Args...> iterator_type;
        typedef std::input_iterator_tag iterator_category;
        typedef iterator_type value_type;
        typedef ptrdiff_t difference_type;
        typedef iterator_type &reference;
        typedef iterator_type *pointer;
    private:
        iterator();

        std::ifstream &itInputStream;
        bool itEndOfFile = false;
        iterator_type value;
        unsigned int itCurrentRow;
        std::string itCurrentLine;
        char itDelimiter;
        std::streampos itPos;


        explicit iterator(std::ifstream &inputStream, bool endOfFile, const unsigned int row, const char delimiter,
                          std::streampos itPos)
                : itInputStream(inputStream) {
            itEndOfFile = endOfFile;
            itCurrentRow = row;
            itDelimiter = delimiter;
            this->itPos = itPos;
            if (itEndOfFile || itPos == EOF) {
                itEndOfFile = true;
                return;
            }

            readNextTuple();

        }

    public:

        std::list<std::string> csv_read_row(std::istream &in, char delimiter) {
            std::stringstream ss;
            bool inquotes = false;
            std::list<std::string> row;
            char c;
            while ((c = in.get()) != EOF) {
                {
                    if (!inquotes && c == '"') //beginquotechar
                    {
                        inquotes = true;
                    } else if (inquotes && c == '"') //quotechar
                    {
                        if (in.peek() == '"')//2 consecutive quotes resolve to 1
                        {
                            ss << (char) in.get();
                        } else //endquotechar
                        {
                            inquotes = false;
                        }
                    } else if (!inquotes && c == delimiter) //end of field
                    {
                        row.push_back(ss.str());
                        ss.str("");
                    } else if (!inquotes && (c == '\r' || c == '\n')) {
                        if (in.peek() == '\n') { in.get(); }
                        row.push_back(ss.str());
                        return row;
                    } else {
                        ss << c;
                    }
                }
            }
            row.push_back(ss.str());
            return row;
        }

        void readNextTuple() {
            try {
                itInputStream.clear();
                itInputStream.seekg(itPos);
                itInputStream >> itCurrentLine;
                itPos = itInputStream.tellg();
                std::istringstream stringStream(itCurrentLine);
                std::list<std::string> v = csv_read_row(stringStream, itDelimiter);
                unsigned int currentColumn = 1;
                value = readTuple<Args...>(v, currentColumn);
                ++itCurrentRow;
            } catch (CSVParserException &exception) {
                std::cerr << "CSVParser Iterator: in row " << itCurrentRow << ", in column "
                          << exception.getErrorColumn()
                          << " " << exception.what();
                throw std::runtime_error("");
            }
        }

    public:
        iterator(const iterator &it) : itInputStream(it.itInputStream) {
            itEndOfFile = it.itEndOfFile;
            itCurrentRow = it.itCurrentRow;
            itDelimiter = it.itDelimiter;
            value = it.value;
            itPos = it.itPos;
        }

        bool operator==(const iterator &other) const {
            if (other.itEndOfFile && this->itEndOfFile) {
                return true;
            }
            return (value == other.value);
        }

        bool operator!=(const iterator &other) const {
            return !(*this == other);
        }

        typename iterator::reference operator*() {
            return value;
        }

        typename iterator::reference operator->() {
            return &(value);
        }

        iterator &operator++() {
            if (itEndOfFile || itPos == EOF) {
                itEndOfFile = true;
                return *this;
            }

            readNextTuple();
            return *this;
        }

        iterator operator++(int) {
            iterator result(*this);
            ++(*this);
            return result;
        }

    };

    iterator begin() {
        input.clear();
        return iterator(input, false, linesSkip, delimiter, startPos);
    }

    iterator end() {
        return iterator(input, true, UINT_MAX, delimiter, EOF);
    }


};

#endif //LAB4_CSVPARSER_H
