#include <iostream>
#include <vector>
#include <ctime>
#include "Game/GameManager.h"
#include "Bots/easyBot.h"

void clear();

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));

    unsigned short turnCount = 0, option = 0;
    bool isXturn = true;
    bot* aiBot = nullptr;
}

void clear() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}