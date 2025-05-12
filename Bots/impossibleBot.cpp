#include <limits.h>
#include "impossibleBot.h"

impossibleBot::impossibleBot(std::shared_ptr<std::vector<std::vector<char>>> tictactoeBoard, bool turn) : board(std::move(tictactoeBoard)), isXturn(turn) {

}
int impossibleBot::minimax(int index, bool Xturn) {
    if (winCheck() && Xturn) {
        return 1; // AI wins
    } else if (winCheck() && !Xturn) {
        return -1; // Player wins
    } else {
        bool isDraw = true;
        for (int i = 0; i < board->size(); i++) {
            for (int j = 0; j < board->size(); j++) {
                if (board->at(i).at(j) == ' ') {
                    isDraw = false;
                }
            }
            if (!isDraw) {
                break;
            }
        }
        if (isDraw) {
            return 0; // No one wins
        }
    }
    int bestScore = Xturn ? INT_MAX : INT_MIN;

    for (int i = 0; i < board->size(); i++) {
        for (int j = 0; j < board->size(); j++) {
            if (board->at(i).at(j) == ' ') {
                board->at(i).at(j) = Xturn ? 'X' : 'O';

                int score = minimax(index + 1, !Xturn);

                board->at(i).at(j) = ' ';

                if (Xturn) {
                    bestScore = std::min(bestScore, score); // minimize for the player
                } else {
                    bestScore = std::max(bestScore, score); // maximize for the AI
                }
            }
        }
    }
    return bestScore;
}
bool impossibleBot::winCheck() {
    for (int i = 0; i < 3; i++)
    {
        if (board->at(i).at(0) != ' ' && board->at(i).at(0)== board->at(i).at(1) && board->at(i).at(1) == board->at(i).at(2)) {
            return true;
        }
        if (board->at(0).at(i) != ' ' && board->at(0).at(i) == board->at(1).at(i) && board->at(1).at(i) == board->at(2).at(i)) {
            return true;
        }
    }
    if (board->at(0).at(0) != ' ' && board->at(0).at(0) == board->at(1).at(1) && board->at(1).at(1) == board->at(2).at(2)) {
        return true;
    }
    else if (board->at(0).at(2) != ' ' && board->at(0).at(2) == board->at(1).at(1) && board->at(1).at(1) == board->at(2).at(0)) {
        return true;
    }
    return false;
}
std::vector<std::pair<int, int>> impossibleBot::analyzeBoard() {
    int bestScore = INT_MIN;
    std::pair<int, int> bestMove;

    // Finding the best score and move
    for (int i = 0; i < board->size(); i++) {
        for (int j = 0; j < board->size(); j++) {
            if (board->at(i).at(j) == ' ') {
                board->at(i).at(j) = 'O';
                int score = minimax(0, isXturn);
                board->at(i).at(j) = ' ';

                if (score > bestScore) {
                    bestScore = score;
                    bestMove = std::make_pair(i, j);
                }
            }
        }
    }
    return { bestMove };
}
void impossibleBot::makeMove() {
    std::vector<std::pair<int, int>> pos = analyzeBoard();
    if (pos.empty()) {
        return;
    }
    board->at(pos[0].first).at(pos[0].second) = 'O';
}
// No need for this check
std::vector<std::pair<int, int>> impossibleBot::checkForWinningMove() {
    return {};
}

