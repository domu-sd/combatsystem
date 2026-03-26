#include <iostream>
#include "engine/GameEngine.h"

int main() {
    Player player("Hero", 150, 25);
    Enemy goblin_enemy("Goblin", 40, 15, "Goblin");
    Enemy goblin_king_enemy("Goblin King", 50, 20, "Goblin");
    std::vector<Enemy> enemies;

    enemies.push_back(goblin_enemy);
    enemies.push_back(goblin_king_enemy);

    GameEngine gameEngine(player, enemies);
    gameEngine.run();
    return 0;
}