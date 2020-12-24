#ifndef LAB4_TUPLEPRINTER_H
#define LAB4_TUPLEPRINTER_H

#include <iostream>
#include <tuple>

template<class Ch, class Tr, size_t I, typename... TS>
struct tuple_printer {
    static void print(std::basic_ostream<Ch, Tr> &out, const std::tuple<TS...> &t) {
        tuple_printer<Ch, Tr, I - 1, TS...>::print(out, t);
        out << ",";
        out << std::get<I - 1>(t);
    }
};

template<class Ch, class Tr, typename... TS>
struct tuple_printer<Ch, Tr, 1, TS...> {
    static void print(std::basic_ostream<Ch, Tr> &out, const std::tuple<TS...> &t) {
        out << std::get<0>(t);
    }
};


template<class Ch, class Tr, typename... TS>
std::ostream &operator<<(std::basic_ostream<Ch, Tr> &out, const std::tuple<TS...> &t) {
    out << "(";
    tuple_printer<Ch, Tr, sizeof...(TS), TS...>::print(out, t);
    out << ")";
    return out;
}

#endif //LAB4_TUPLEPRINTER_H
