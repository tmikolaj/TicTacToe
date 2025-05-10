
#include "GameManager.h"

GameManager::GameManager() {

}
GameManager::~GameManager() {

}

void GameManager::playRound(bool isXturn) {
    if (isXturn) {
        std::cout << "X TURN" << std::endl;
    }
    else {
        std::cout << "O TURN" << std::endl;
    }
    insertPos(isXturn);
}

void GameManager::insertPos(bool isXturn) {
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
void posCal(unsigned short position, bool isXturn, std::vector<std::vector<char>> board) {
    switch (position) {
        case 1:
            if (board[0][0] == ' ') {
                board[0][0] = isXturn ? 'X' : 'O';
            }
        case 2:
            if (board[0][1] == ' ') {
                board[0][1] = isXturn ? 'X' : 'O';
            }
        case 3:
            if (board[0][2] == ' ') {
                board[0][2] = isXturn ? 'X' : 'O';
            }
        case 4:
            if (board[1][0] == ' ') {
                board[1][0] = isXturn ? 'X' : 'O';
            }
        case 5:
            if (board[1][1] == ' ') {
                board[1][1] = isXturn ? 'X' : 'O';
            }
        case 6:
            if (board[1][2] == ' ') {
                board[1][2] = isXturn ? 'X' : 'O';
            }
        case 7:
            if (board[2][0] == ' ') {
                board[2][0] = isXturn ? 'X' : 'O';
            }
        case 8:
            if (board[2][1] == ' ') {
                board[2][1] = isXturn ? 'X' : 'O';
            }
        case 9:
            if (board[2][2] == ' ') {
                board[2][2] = isXturn ? 'X' : 'O';
            }
    }
}

bool winCheck(std::vector<std::vector<char>> board) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')  ||  (board[0][i] == 'X' && board[0][i] == 'X' && board[0][i] == 'X')) {
            return true;
        }
        else if ((board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')  ||  (board[0][i] == 'O' && board[0][i] == 'O' && board[0][i] == 'O')) {
            return false;
        }
    }
    if (board[1][1] == 'X') {
        if ((board[0][0] == 'X' && board[2][2] == 'X') || (board[0][2] == 'X' && board[2][0] == 'X')) {
            return true;
        }
    }
    else if (board[1][1] == 'O') {
        if ((board[0][0] == 'O' && board[2][2] == 'O') || (board[0][2] == 'O' && board[2][0] == 'O')) {
            return false;
        }
    }
}
