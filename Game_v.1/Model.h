#ifndef GAME_V_1_MODEL_H
#define GAME_V_1_MODEL_H
#include "Board.h"
#include "View.h"
#include "ModelException.h"

class Model {

private:
    Board board;
    CellsStatus CurrentTurn = CellsStatus::CROSS;
    std::vector<View *> viewers;

public:
    CellsStatus getCurrentTurn();

    CellsStatus getCellStatus(int row, int column);

    bool IsTurnPossible(std::pair<int,int> turn);

    void ProcessingTheTurn(std::pair<int,int> turn);

    void MakeTurn(std::pair<int,int> turn);

    bool IsGameOver();

    void addViewer(View *viewer);

    void showBoard();

    void notifyAboutWrongTurn();

    void notifyAboutWin();
};


#endif
