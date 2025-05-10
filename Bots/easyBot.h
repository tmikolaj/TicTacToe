#ifndef EASYBOT_H
#define EASYBOT_H

#include "bot.h"

class easyBot : public bot {
private:
    std::shared_ptr<std::vector<std::vector<char>>> board;
protected:
    std::vector<std::pair<int, int>> analyzeBoard() override;
    std::vector<std::pair<int, int>> checkForWinningMove() override;
public:
    easyBot(std::shared_ptr<std::vector<std::vector<char>>> tictactoeBoard);
    ~easyBot() override;

    void makeMove() override;
};

#endif //EASYBOT_H
