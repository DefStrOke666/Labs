#ifndef GAME_V_1_CONTROLLER_H
#define GAME_V_1_CONTROLLER_H

#include "Model.h"
#include "View.h"
#include "Util.h"
#include <string>
#include "Player.h"
#include <map>

class Controller {
public:
    explicit Controller(Model &model);

    void handleTurn();

    void addPlayer(Player *player);

private:
    Model &model;

    std::map<CellsStatus, Player *> players{};

    Player *currentPlayer();
};

#endif
