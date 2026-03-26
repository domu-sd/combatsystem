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
    int aliveIndex = 1;
    for (Enemy& enemy : enemies) {
        if (enemy.isAlive()) {
            std::cout << aliveIndex << ". " << enemy.getName()
                      << " (HP: " << enemy.getCurrentHP() << ")\n";
            aliveIndex++;
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
    if (!player.isAlive()) return true;

    for (Enemy& enemy : enemies) {
        if (enemy.isAlive()) return false;
    }

    return true;
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

        // Map choice to nth alive enemy
        int aliveIndex = 0;
        Enemy* target = nullptr;
        for (Enemy& e : enemies) {
            if (e.isAlive()) {
                aliveIndex++;
                if (aliveIndex == targetChoice) {
                    target = &e;
                    break;
                }
            }
        }

        std::cout << "-------------------------\n";

        if (actionNum == 1) {
            BasicAttack attack;
            std::cout << player.getName() << " uses Basic Attack!\n";
            attack.execute(player, *target);
            if (target->getCurrentHP() <= 0) {
                std::cout << target->getName() << " has died!\n";
            } else {
                std::cout << target->getName() << " is now " << target->getCurrentHP() << " HP\n";
            }
        } else {
            HeavyAttack attack;
            std::cout << player.getName() << " uses Heavy Attack!\n";
            bool hit = attack.execute(player, *target);
            if (!hit) {
                std::cout << "Heavy Attack missed!\n";
            } else if (target->getCurrentHP() <= 0) {
                std::cout << target->getName() << " has died!\n";
            } else {
                std::cout << target->getName() << " is now " << target->getCurrentHP() << " HP\n";
            }
        }
    } else if (actionNum == 3) {
        Heal heal;
        std::cout << player.getName() << " uses Heal!\n";
        heal.execute(player, player);
        std::cout << player.getName() << " is now " << player.getCurrentHP() << " HP\n";
    }

    std::cout << "-------------------------\n";

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
            std::cout << player.getName() << " is now " << player.getCurrentHP() << " HP\n";
        } else {
            HeavyAttack attack;
            std::cout << enemy.getName() << " uses Heavy Attack!\n";
            bool hit = attack.execute(enemy, player);
            if (!hit) {
                std::cout << enemy.getName() << "'s Heavy Attack missed!\n";
            } else {
                std::cout << player.getName() << " is now " << player.getCurrentHP() << " HP\n";
            }
        }

        std::cout << "-------------------------\n";
    }
}

void GameEngine::run() {
    std::cout << "=== COMBAT START ===\n";
    renderState();

    while (true) {
        processTurn();
        renderState();
        if (checkGameEnd()) {
            if (!player.isAlive()) {
                std::cout << "=== GAME OVER. YOU LOSE ===\n";
            } else {
                std::cout << "=== VICTORY ===\n";
            }
            break;
        }
    }
}
