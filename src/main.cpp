#include <iostream>
#include "engine/GameEngine.h"
#include "levels/LevelLoader.h"

int main() {
    std::cout << "=== COMBAT SIMULATOR ===\n";
    std::cout << "Select a level:\n";
    std::cout << "1. " << LevelLoader::level1().name << "\n";
    std::cout << "2. " << LevelLoader::level2().name << "\n";
    std::cout << "> ";

    int choice = 0;
    while (choice < 1 || choice > 2) {
        std::cin >> choice;
        if (choice < 1 || choice > 2) {
            std::cout << "Invalid choice, try again.\n> ";
        }
    }

    Level level = (choice == 1) ? LevelLoader::level1() : LevelLoader::level2();

    GameEngine gameEngine(level.player, level.enemies);
    gameEngine.run();

    return 0;
}
