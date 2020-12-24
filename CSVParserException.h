#ifndef LAB4_CSVPARSEREXCEPTION_H
#define LAB4_CSVPARSEREXCEPTION_H

#pragma once

#include <exception>
#include <string>


class CSVParserException : public std::exception {

private:
    std::string errorMessage;
    unsigned int currentErrorColumn = 0;
public:

    explicit CSVParserException(const std::string &errorMessage, const unsigned int column) {
        this->errorMessage = errorMessage;
        currentErrorColumn= column;
    }

    int getErrorColumn() {
        return currentErrorColumn;
    }

    [[nodiscard]] const char *what() const noexcept override {
        return errorMessage.c_str();
    }

};

#endif //LAB4_CSVPARSEREXCEPTION_H
