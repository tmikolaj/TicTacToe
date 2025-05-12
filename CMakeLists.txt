cmake_minimum_required(VERSION 3.30)
project(Tic_Tac_Toe)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tic_Tac_Toe main.cpp
        Bots/bot.h
        Bots/easyBot.cpp
        Bots/easyBot.h
        Game/GameManager.cpp
        Game/GameManager.h
        Bots/impossibleBot.cpp
        Bots/impossibleBot.h)
