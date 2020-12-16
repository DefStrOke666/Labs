#ifndef GAME_V_1_CONSOLEVIEW_H
#define GAME_V_1_CONSOLEVIEW_H

#include "View.h"

class ConsoleView : public ::View {
public:

    void screenUpdate(Board& board) override;

    void printWinMessage(CellsStatus status) override;

    void wrongTurnMessage() override;
};



#endif //GAME_V_1_CONSOLEVIEW_H
