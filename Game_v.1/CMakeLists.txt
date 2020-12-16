cmake_minimum_required(VERSION 3.17)
project(Game_v_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Game_v_1 main.cpp Cells.cpp Cells.h Board.cpp Board.h Model.cpp Model.h View.h Controller.cpp Controller.h Player.h Human.cpp Human.h Bot.cpp Bot.h Game.cpp Game.h ModelException.h ConsoleView.cpp ConsoleView.h Util.h View.cpp Util.cpp Player.cpp ModelException.cpp)