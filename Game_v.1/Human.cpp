#include "Human.h"
#include <iostream>
Human::Human(const std::string &name, CellsStatus status) {
    this->name = name;
    this->status = status;
}

std::pair<int, int> Human::makeTurn(Model &model) {
    std::cout << "Waiting for player " << name << " turn" << std::endl;
    std::string sTurn;
    std::cin >> sTurn;
    std::pair<int, int> turn;
    turn.second = sTurn[0] - 'a';
    turn.first = sTurn[1] - '1';
    return turn;
}

CellsStatus Human::getStatus() {
    return status;
}

Human::~Human() = default;
