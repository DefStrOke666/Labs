#include "Game.h"
#include "ConsoleView.h"
#include "Human.h"
#include "Bot.h"
#include <conio.h>

void Game::start() {
    Model model;
    ConsoleView view;
    model.addViewer(&view);
    Controller controller(model);
    std::cout << "Hello it`s Cross-Zero game.There are a Board 3x3" << std::endl;
    int numberOfPlayers = 0;
    std::cout << "Print number of players"<< std::endl;
    std::cin >> numberOfPlayers;
    while (numberOfPlayers != 2 && numberOfPlayers != 1) {
        std::cerr << "Wrong number of players" << std::endl;
        std::cout << "Print number of players" << std::endl;
        std::cin >> numberOfPlayers;
    }
    Player *firstPlayer;
    Player *secondPlayer;
    if (numberOfPlayers == 1) {
        std::string name;
        std::cout << "Print first player name" << std::endl;
        std::cin >> name;
        firstPlayer = new Human(name, CellsStatus::CROSS);
        secondPlayer = new Bot(CellsStatus::ZERO);
    }
    if (numberOfPlayers == 2) {
        std::string name;
        std::cout << "Print first player name" << std::endl;
        std::cin >> name;
        firstPlayer = new Human(name, CellsStatus::CROSS);
        std::cout << "Print second player name" << std::endl;
        std::cin >> name;
        secondPlayer = new Human(name, CellsStatus::ZERO);
    }
    controller.addPlayer(firstPlayer);
    controller.addPlayer(secondPlayer);
    while (!model.IsGameOver()) {
        bool turnComplete = false;
        while (!turnComplete) {
            try {
                controller.handleTurn();
            }
            catch (const ModelException &a) {
                continue;
            }
            catch (const std::invalid_argument &a) {
                continue;
            }
            turnComplete = true;
        }
    }
    delete firstPlayer;
    delete secondPlayer;
    model.notifyAboutWin();
    _getch();
}

