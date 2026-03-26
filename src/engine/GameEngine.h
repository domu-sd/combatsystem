#pragma once

#include "../entities/Player.h"
#include "../entities/Enemy.h"
#include <vector>

class GameEngine {
private:
    Player player;
    std::vector<Enemy> enemies;

public:
    GameEngine(Player player, std::vector<Enemy> enemies);
    void renderState();
    bool checkGameEnd();
    void processTurn();
    void run();

    void printEnemyList();
};