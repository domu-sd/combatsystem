#include <cassert>
#include <iostream>
#include "../src/entities/Entity.h"
#include "../src/entities/Enemy.h"

int main() {

    Enemy enemy("Goblin King", 100, 15, "Goblin");

    std::cout << "Test 2.1: Enemy creation...";
    assert(enemy.getName() == "Goblin King");
    assert(enemy.getCurrentHP() == 100);
    assert(enemy.getAttackPower() == 15);
    assert(enemy.isAlive() == true);
    assert(enemy.getEnemyType() == "Goblin");
    std::cout << " PASS\n";

    std::cout << "Test 2.2: Enemy takes damage, stays alive...";
    enemy.takeDamage(30);
    assert(enemy.getCurrentHP() == 70);
    assert(enemy.isAlive() == true);
    std::cout << " PASS\n";

    std::cout << "Test 2.3: Enemy takes lethal damage, dies...";
    enemy.takeDamage(200);
    assert(enemy.getCurrentHP() == 0);
    assert(enemy.isAlive() == false);
    std::cout << " PASS\n";

    std::cout << "All of Test 2 passed.\n";
    return 0;
}
