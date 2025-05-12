#ifndef IMPOSSIBLEBOT_H
#define IMPOSSIBLEBOT_H

#include "bot.h"

class impossibleBot : public bot {
private:
    std::shared_ptr<std::vector<std::vector<char>>> board;
    bool isXturn;
    int minimax(int index, bool Xturn);
    bool winCheck();
protected:
    std::vector<std::pair<int, int>> analyzeBoard() override;
    std::vector<std::pair<int, int>> checkForWinningMove() override;
public:
    impossibleBot(std::shared_ptr<std::vector<std::vector<char>>> tictactoeBoard, bool turn);
    ~impossibleBot() override = default;

    void makeMove() override;
};

#endif //IMPOSSIBLEBOT_H
