#include "LevelLoader.h"

Level LevelLoader::level1() {
    Player player("Hero", 150, 25);

    std::vector<Enemy> enemies;
    enemies.push_back(Enemy("Goblin", 40, 10, "Goblin"));
    enemies.push_back(Enemy("Goblin King", 60, 15, "Goblin"));

    return Level{"Level 1: The Goblin Cave", player, enemies};
}

Level LevelLoader::level2() {
    Player player("Hero", 150, 25);

    std::vector<Enemy> enemies;
    enemies.push_back(Enemy("Orc", 80, 20, "Orc"));
    enemies.push_back(Enemy("Orc Warchief", 120, 30, "Orc"));

    return Level{"Level 2: The Orc Stronghold", player, enemies};
}
