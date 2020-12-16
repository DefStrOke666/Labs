#include "Bot.h"

CellsStatus Bot::getStatus() {
    return status;
}

Bot::Bot(CellsStatus status) {
 this->status = status;
}

std::pair<int, int> Bot::makeTurn(Model &model) {
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            std::pair<int,int> turn;
            turn.first = a;
            turn.second = b;
            if (model.IsTurnPossible(turn)) {
                return turn;
            }
        }
    }
    return {5,5};
}

Bot::~Bot() = default;
