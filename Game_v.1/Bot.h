#ifndef GAME_V_1_BOT_H
#define GAME_V_1_BOT_H

#include "Player.h"

class Bot : public :: Player{
public:
    CellsStatus status;

    CellsStatus getStatus() override;

    Bot(CellsStatus status);

    std::pair<int, int> makeTurn(Model &model) override;

    ~Bot() override;
};

#endif //GAME_V_1_BOT_H
