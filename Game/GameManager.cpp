#include <iostream>
#include "GameManager.h"

void GameManager::playRound(bool& isXturn) {
    if (isXturn) {
        std::cout << "X TURN" << std::endl;
    }
    else {
        std::cout << "O TURN" << std::endl;
    }
    insertPos(isXturn);
}
void GameManager::insertPos(bool& isXturn) {
    unsigned short position;
    if (isXturn) {
        std::cout << "choose position(1 - 9)" << std::endl;
        std::cin >> position;
        isXturn = false;
    }
    else {
        isXturn = true;
    }
}
//Converting Position to Matrix indices
void GameManager::posCal(unsigned short position, bool& isXturn, std::vector<std::vector<char>> board) {
    switch (position) {
        case 1:
            if (board[0][0] == ' ') {
                board[0][0] = isXturn ? 'X' : 'O';
            }
            break;
        case 2:
            if (board[0][1] == ' ') {
                board[0][1] = isXturn ? 'X' : 'O';
            }
            break;
        case 3:
            if (board[0][2] == ' ') {
                board[0][2] = isXturn ? 'X' : 'O';
            }
            break;
        case 4:
            if (board[1][0] == ' ') {
                board[1][0] = isXturn ? 'X' : 'O';
            }
            break;
        case 5:
            if (board[1][1] == ' ') {
                board[1][1] = isXturn ? 'X' : 'O';
            }
            break;
        case 6:
            if (board[1][2] == ' ') {
                board[1][2] = isXturn ? 'X' : 'O';
            }
            break;
        case 7:
            if (board[2][0] == ' ') {
                board[2][0] = isXturn ? 'X' : 'O';
            }
            break;
        case 8:
            if (board[2][1] == ' ') {
                board[2][1] = isXturn ? 'X' : 'O';
            }
            break;
        case 9:
            if (board[2][2] == ' ') {
                board[2][2] = isXturn ? 'X' : 'O';
            }
            break;
        default:
            isXturn = !isXturn;
            insertPos(isXturn);
    }
}
bool GameManager::winCheck(std::vector<std::vector<char>> board, bool isXturn) {
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            std::cout << isXturn ? "O wins!\n" : "X wins!\n";
            return true;
        }
        if (board[0][i] != 0 && board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            std::cout << isXturn ? "O wins!\n" : "X wins!\n";
            return true;
        }
    }
    if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        std::cout << isXturn ? "O wins!\n" : "X wins!\n";
        return true;
    }
    else if (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        std::cout << isXturn ? "O wins!\n" : "X wins!\n";
        return true;
    }
    return false;
}
