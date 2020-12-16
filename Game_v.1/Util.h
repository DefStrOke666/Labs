
#ifndef GAME_V_1_UTIL_H
#define GAME_V_1_UTIL_H

#include <stdexcept>
#include <vector>
#include <sstream>
#include "Cells.h"

namespace Util {
    static char getCharByStatus(CellsStatus status) {
        if (status == CellsStatus::EMPTY) {
            return ' ';
        }
        if (status == CellsStatus::ZERO) {
            return 'O';
        }
        if (status == CellsStatus::CROSS) {
            return 'X';
        }
        throw std::invalid_argument("haha");
    }
};


#endif //GAME_V_1_UTIL_H
