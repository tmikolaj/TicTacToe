#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <vector>

class GameManager {
private:
    void posCal(unsigned short position, bool& isXturn, std::vector<std::vector<char>> board);
    void insertPos(bool& isXturn);
public:
    GameManager() = default;
    ~GameManager() = default;
    void playRound(bool& isXturn);
    bool winCheck(std::vector<std::vector<char>> board, bool isXturn);
};




#endif //GAMEMANAGER_H
