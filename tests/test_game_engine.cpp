#include <cassert>
#include <iostream>
#include "../src/engine/GameEngine.h"
#include "../src/levels/LevelLoader.h"

int main() {
    std::cout << "Test 6.1: Game is not over at start...";
    Level level = LevelLoader::level1();
    GameEngine engine(level.player, level.enemies);
    assert(engine.checkGameEnd() == false);
    std::cout << " PASS\n";

    std::cout << "Test 6.2: Game ends when all enemies die...";
    Level level2 = LevelLoader::level1();
    GameEngine engine2(level2.player, level2.enemies);
    for (Enemy& enemy : engine2.getEnemies()) {
        enemy.takeDamage(9999);
    }
    assert(engine2.checkGameEnd() == true);
    std::cout << " PASS\n";

    std::cout << "Test 6.3: Game ends when player dies...";
    Level level3 = LevelLoader::level1();
    GameEngine engine3(level3.player, level3.enemies);
    engine3.getPlayer().takeDamage(9999);
    assert(engine3.checkGameEnd() == true);
    std::cout << " PASS\n";

    std::cout << "All of Test 6 passed.\n\n";

    return 0;
}
