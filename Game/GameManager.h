#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <vector>


class GameManager {
private:
    void posCal(unsigned short position, bool isXturn, std::vector<std::vector<char>> board);
    void insertPos(bool isXturn);
public:
    GameManager();
    ~GameManager();
    void playRound(bool isXturn);
    bool winCheck();
};




#endif //GAMEMANAGER_H
