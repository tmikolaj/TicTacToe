#include "easyBot.h"

easyBot::easyBot(std::shared_ptr<std::vector<std::vector<char>>> tictactoeBoard) : board(std::move(tictactoeBoard)) {

}
// Check for free places
std::vector<std::pair<int, int> > easyBot::analyzeBoard() {
    std::vector<std::pair<int, int> > res;

    for (int i = 0; i < board->size(); i++) {
        for (int j = 0; j < board->size(); j++) {
            if (board->at(i).at(j) == ' ') {
                res.emplace_back(i, j);
            }
        }
    }
    return res;
}
// Update board (make a move)
void easyBot::makeMove() {
    std::vector<std::pair<int, int>> positions = checkForWinningMove();
    int chance = positions.empty() ? -1 : rand() % positions.size();
    if (chance == 0) {
        board->at(positions[chance].first).at(positions[chance].second) = 'O';
    } else {
        positions = analyzeBoard();
        if (positions.empty()) {
            return;
        }
        int pos = rand() % positions.size();
        board->at(positions[pos].first).at(positions[pos].second) = 'O';
    }
}
// Function does not check diagonally. Intended.
std::vector<std::pair<int, int>> easyBot::checkForWinningMove() {
    std::vector<std::pair<int, int> > res;

    for (int i = 0; i < board->size(); i++) {
        // Vertical check
        if ((board->at(i).at(0) == board->at(i).at(1) && board->at(i).at(0)) != ' ' && board->at(i).at(2) == ' ') {
            res.emplace_back(i, 2);
        }
        if ((board->at(i).at(0) == board->at(i).at(2) && board->at(i).at(0)) != ' ' && board->at(i).at(1) == ' ') {
            res.emplace_back(i, 1);
        }
        if ((board->at(i).at(1) == board->at(i).at(2) && board->at(i).at(0)) != ' ' && board->at(i).at(0) == ' ') {
            res.emplace_back(i, 0);
        }
        // Horizontal check
        if ((board->at(0).at(i) == board->at(1).at(i) && board->at(0).at(i)) != ' ' && board->at(0).at(2) == ' ') {
            res.emplace_back(i, 2);
        }
        if ((board->at(0).at(i) == board->at(2).at(i) && board->at(0).at(i)) != ' ' && board->at(1).at(i) == ' ') {
            res.emplace_back(i, 1);
        }
        if ((board->at(1).at(i) == board->at(2).at(i) && board->at(0).at(i)) != ' ' && board->at(0).at(i) == ' ') {
            res.emplace_back(i, 0);
        }
    }
    return res;
}