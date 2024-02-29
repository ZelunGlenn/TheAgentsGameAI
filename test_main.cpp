#include <vector>

#include "gameEngine.h"
#include "player.h"
int main() {
    std::vector<Player> p;
    Player a;
    Player b;
    p.push_back(a);
    p.push_back(b);
    GameEngine g;
    g.initEngine(p, 2, 0);
    g.run();
    return 0;
}