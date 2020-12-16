#ifndef GAME_V_1_VIEW_H
#define GAME_V_1_VIEW_H
#include "Util.h"
#include "Board.h"
#include <iostream>
class View{
public:
    virtual void screenUpdate(Board &board) = 0;

    virtual void printWinMessage(CellsStatus status) = 0;

    virtual void wrongTurnMessage() = 0;
};


#endif //GAME_V_1_VIEW_H
