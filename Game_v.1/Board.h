#ifndef GAME_V_1_BOARD_H
#define GAME_V_1_BOARD_H

#include <vector>
#include "Cells.h"
#include <memory>

class Board {
private:
    std::vector<std::vector<Cells>> board;

public:
    Board();

    Cells getCell(int row, int column);

    void ChangeBoardValue(CellsStatus newStatus, int row, int column);
};


#endif //GAME_V_1_BOARD_H
