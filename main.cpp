#include <iostream>
#include "TuplePrinter.h"
#include "CSVParser .h"
#include <string>


int main(int argc, char *argv[]) {
    std::ifstream inputFileStream;
    int skipLinesNumber = 0;
    char delimiter = ';';
    argc = argc;
    if (argc >= 2) {
        skipLinesNumber = std::stoi(argv[1]);
        if (skipLinesNumber < 0) {
            std::cerr << "invalid skip lines number! Set default = 0" << std::endl;
            skipLinesNumber = 0;
        }
    }
    if (argc >= 3) {
        delimiter = argv[2][0];
    }
    inputFileStream.open("input.csv", std::ios::binary);

    CSVParser<int, long, double, std::string, int> parser(inputFileStream, skipLinesNumber, delimiter);
    try {
        auto it1 = parser.begin();
        it1++;
        for (auto it = parser.begin(); it != parser.end(); it++) {
            std::cout << *it << std::endl;

        }
        std::cout << *it1;
    } catch (
            std::exception &e
    ) {
        std::cerr << "Main: program stopped!" << std::endl;
    }
    return 0;
}
