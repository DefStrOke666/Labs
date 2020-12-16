#include "Model.h"

bool Model::IsTurnPossible(std::pair<int, int> turn) {
    if (turn.first > 2 || turn.first < 0 || turn.second > 2 || turn.second < 0) return false;
    return board.getCell(turn.first, turn.second).GetCellsStatus() == CellsStatus::EMPTY;
}

void Model::ProcessingTheTurn(std::pair<int, int> turn) {
    board.ChangeBoardValue(CurrentTurn, turn.first, turn.second);
}

void Model::MakeTurn(std::pair<int, int> turn) {
    if (IsTurnPossible(turn)) {
        ProcessingTheTurn(turn);
        showBoard();
        if (CurrentTurn == CellsStatus::CROSS)
            CurrentTurn = CellsStatus::ZERO;
        else
            CurrentTurn = CellsStatus::CROSS;
    }else{
        notifyAboutWrongTurn();
    }
}

bool Model::IsGameOver() {
    int counterEmptyCells = 0;
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            if (board.getCell(i, j).GetCellsStatus() == CellsStatus::EMPTY)
                counterEmptyCells += 1;
    }
    if(counterEmptyCells == 0)
        return true;
    for(int i = 0; i < 3; i++){
        if (getCellStatus(i, 0)==getCellStatus(i, 1)&&
            getCellStatus(i, 1)==getCellStatus(i, 2)&&
            getCellStatus(i,0)!=CellsStatus::EMPTY)
            return true;
        if (getCellStatus(0, i)==getCellStatus(1, i)&&
            getCellStatus(1, i)==getCellStatus(2, i)&&
            getCellStatus(0,i)!=CellsStatus::EMPTY)
            return true;
        if (getCellStatus(0, 0)==getCellStatus(1, 1)&&
            getCellStatus(1, 1)==getCellStatus(2, 2)&&
            getCellStatus(0,i)!=CellsStatus::EMPTY)
            return true;
        if (getCellStatus(2, 0)==getCellStatus(1, 1)&&
            getCellStatus(1, 1)==getCellStatus(0, 2)&&
            getCellStatus(0,2)!=CellsStatus::EMPTY)
            return true;
    }
    return false;
}

void Model::addViewer(View *viewer) {
    viewers.push_back(viewer);
}

void Model::notifyAboutWrongTurn() {
    auto it = viewers.begin();
    while (it != viewers.end()) {
        (*it)->wrongTurnMessage();
        it++;
    }
}

void Model::notifyAboutWin() {
    auto it = viewers.begin();
    while (it != viewers.end()) {
        (*it)->printWinMessage(CurrentTurn);
        it++;
    }
}

CellsStatus Model::getCurrentTurn() {
    return CurrentTurn;
}

CellsStatus Model::getCellStatus(int row, int column) {
    return board.getCell(row, column).GetCellsStatus();
}

void Model::showBoard() {
    auto it = viewers.begin();
    while (it != viewers.end()) {
        (*it)->screenUpdate(board);
        it++;
    }
}
