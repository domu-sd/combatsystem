#include "GameEngine.h"
#include <iostream>
#include "../actions/BasicAttack.h"
#include "../actions/HeavyAttack.h"
#include "../actions/Heal.h"
#include <random>

GameEngine::GameEngine(Player player, std::vector<Enemy> enemies)
    : player(player), enemies(enemies)
{
}

void GameEngine::printEnemyList() {
    for (int i = 0; i < (int)enemies.size(); i++) {
        if (enemies[i].isAlive()) {
            std::cout << i + 1 << ". " << enemies[i].getName()
                      << " (HP: " << enemies[i].getCurrentHP() << ")\n";
        }
    }
}

void GameEngine::renderState() {
    std::cout << "=== Player ===\n";
    std::cout << player.getName() << " (HP: " << player.getCurrentHP() << ")\n";
    std::cout << "=== Enemies ===\n";
    for (Enemy& enemy : enemies) {
        if (enemy.isAlive()) {
            std::cout << enemy.getName() << " (HP: " << enemy.getCurrentHP() << ")\n";
        }
    }
    std::cout << "-------------------------\n";
}

bool GameEngine::checkGameEnd() {
    if (!player.isAlive()) {
        std::cout << "=== GAME OVER — YOU LOST ===\n";
        return true;
    }

    bool allDead = true;
    for (Enemy& enemy : enemies) {
        if (enemy.isAlive()) {
            allDead = false;
            break;
        }
    }

    if (allDead) {
        std::cout << "=== VICTORY ===\n";
        return true;
    }

    return false;
}

void GameEngine::processTurn() {
    std::cout << "\n[Your Turn]\n";
    std::cout << "Choose action:\n";
    std::cout << "1. Basic Attack\n";
    std::cout << "2. Heavy Attack\n";
    std::cout << "3. Heal\n";
    std::cout << "> ";

    int actionNum = 0;
    while (actionNum < 1 || actionNum > 3) {
        std::cin >> actionNum;
        if (actionNum < 1 || actionNum > 3) {
            std::cout << "Invalid choice, try again.\n> ";
        }
    }

    if (actionNum == 1 || actionNum == 2) {
        std::cout << "Choose a target:\n";
        printEnemyList();
        std::cout << "> ";

        int aliveCount = 0;
        for (Enemy& e : enemies) {
            if (e.isAlive()) {
                aliveCount++;
            }
        }

        int targetChoice = 0;
        while (targetChoice < 1 || targetChoice > aliveCount) {
            std::cin >> targetChoice;
            if (targetChoice < 1 || targetChoice > aliveCount) {
                std::cout << "Invalid target, try again.\n> ";
            }
        }

        if (actionNum == 1) {
            BasicAttack attack;
            std::cout << player.getName() << " uses Basic Attack!\n";
            attack.execute(player, enemies[targetChoice - 1]);
        } else {
            HeavyAttack attack;
            std::cout << player.getName() << " uses Heavy Attack!\n";
            attack.execute(player, enemies[targetChoice - 1]);
        }
    } else if (actionNum == 3) {
        Heal heal;
        std::cout << player.getName() << " uses Heal!\n";
        heal.execute(player, player);
    }

    // Enemy turn
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dist(0, 1);

    for (Enemy& enemy : enemies) {
        if (!enemy.isAlive()) continue;

        std::cout << "\n[Enemy Turn] " << enemy.getName() << "\n";

        if (dist(gen) == 0) {
            BasicAttack attack;
            std::cout << enemy.getName() << " uses Basic Attack!\n";
            attack.execute(enemy, player);
        } else {
            HeavyAttack attack;
            std::cout << enemy.getName() << " uses Heavy Attack!\n";
            attack.execute(enemy, player);
        }
    }
}

void GameEngine::run() {
    std::cout << "=== COMBAT START ===\n";
    renderState();

    while (true) {
        processTurn();
        renderState();
        if (checkGameEnd()) {
            break;
        };
    }
}
