#include "ConsoleView.h"
void ConsoleView::screenUpdate(Board &board) {
    for (int i = 0; i < 3; i++) {
        char a = Util::getCharByStatus(board.getCell(i,0).GetCellsStatus());
        char b = Util::getCharByStatus(board.getCell(i,1).GetCellsStatus());
        char c = Util::getCharByStatus(board.getCell(i,2).GetCellsStatus());
        std::cout << a << '|' << b <<'|' << c << std::endl;
    }
}

void ConsoleView::printWinMessage(CellsStatus status) {
    if (status == CellsStatus::CROSS) {
        std::cout << "ZERO win";
    } else {
        std::cout << "CROSS win";
    }
}

void ConsoleView::wrongTurnMessage() {
    std::cout << "Wrong turn.Try again" << std::endl;
}