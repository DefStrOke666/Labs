

#ifndef LAB4_TUPLEWRITER_H
#define LAB4_TUPLEWRITER_H

#include <iostream>
#include <tuple>
#include "CSVParserException.h"
#include <sstream>
#include <list>
#include <list>

template<typename First>
std::tuple<First> readTuple(std::list<std::string> &list, unsigned int &column) {
    if (list.empty()) {
        throw CSVParserException("less data was encountered than expected.", column);
    }
    First inputData;
    std::istringstream stream(list.back());
    stream >> inputData;
    if (stream.fail()) {
        throw CSVParserException("invalid data", column);
    }
    list.pop_back();
    ++column;
    return std::make_tuple(inputData);
}

template<typename First, typename Second, typename ...args>
std::tuple<First, Second, args...> readTuple(std::list<std::string> &list, unsigned int &column) {
    if (list.empty()) {
        throw CSVParserException("less data was encountered than expected.", column);
    }
    First inputData;
    std::istringstream stream(list.front());
    stream >> inputData;
    if (stream.fail()) {
        throw CSVParserException("invalid data", column);
    }
    list.pop_front();
    ++column;
    return std::tuple_cat(std::make_tuple(inputData),
                          readTuple<Second, args...>(list, column));
}

#endif //LAB4_TUPLEWRITER_H
