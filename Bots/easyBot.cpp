#include "easyBot.h"

easyBot::easyBot(std::shared_ptr<std::vector<std::vector<char>>> tictactoeBoard) : board(std::move(tictactoeBoard)) {

}
easyBot::~easyBot() {

}
// Check for free places
std::vector<std::pair<int, int> > easyBot::analyzeBoard() {
    
}
// Update board (make a move)
void easyBot::makeMove() {

}
std::vector<std::pair<int, int>> easyBot::checkForWinningMove() {

}