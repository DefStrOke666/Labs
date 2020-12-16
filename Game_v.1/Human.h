#ifndef GAME_V_1_HUMAN_H
#define GAME_V_1_HUMAN_H

#include "Player.h"
#include "Controller.h"

class Human : public ::Player{
    std::string name;
    CellsStatus status;

public:
    virtual ~Human();

public:
    CellsStatus getStatus();

    Human(const std::string &name, CellsStatus status);

    std::pair<int, int> makeTurn(Model &model) override;
};


#endif //GAME_V_1_HUMAN_H
