#include "Controller.h"

Controller::Controller(Model &model) : model(model) {}

void Controller::handleTurn() {
    std::pair<int,int> turn = currentPlayer()->makeTurn(model);
    if (model.IsTurnPossible(turn)) {
        model.MakeTurn(turn);
    } else {
        model.notifyAboutWrongTurn();
        throw std::invalid_argument("Wrong turn format");
    }
}

void Controller::addPlayer(Player *player) {
    players[player->getStatus()] = player;
}

Player *Controller::currentPlayer() {
    if (model.getCurrentTurn() == CellsStatus::ZERO) {
        if (players.find(CellsStatus::ZERO) != players.end()) {
            return players[CellsStatus::ZERO];
        }
    }
    if (model.getCurrentTurn() == CellsStatus::CROSS) {
        if (players.find(CellsStatus::CROSS) != players.end()) {
            return players[CellsStatus::CROSS];
        }
    }
    throw std::invalid_argument("don`t initialize player for this turn");
}

