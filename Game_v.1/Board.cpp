#include "Board.h"

Board::Board() {
    for (int i = 0; i < 3; i++){
        std::vector<Cells> vector;
        board.push_back(vector);
        for (int j = 0; j < 3; j++){
            Cells cell;
            board[i].push_back(cell);
        }
    }
}

void Board::ChangeBoardValue(CellsStatus newStatus, int row, int column) {
    board[row][column].ChangeCellsStatus(newStatus);
}

Cells Board::getCell(int row, int column) {
    return board[row][column];
}
