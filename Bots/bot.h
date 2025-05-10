#ifndef BOT_H
#define BOT_H

#include <vector>
#include <utility>
#include <cstdlib>
#include <memory>

class bot {
protected:
    virtual std::vector<std::pair<int, int>> analyzeBoard() = 0;
    virtual std::vector<std::pair<int, int>> checkForWinningMove() = 0;
public:
    bot() = default;
    virtual ~bot() = default;

    virtual void makeMove() = 0;
};

#endif //BOT_H
