#ifndef GAME_V_1_PLAYER_H
#define GAME_V_1_PLAYER_H

#include "Cells.h"
#include "Model.h"
#include <string>

class Player {
public:
    virtual std::pair<int, int> makeTurn(Model &model) = 0;

    virtual CellsStatus getStatus() = 0;

    virtual ~Player() = default;
};


#endif //GAME_V_1_PLAYER_H
