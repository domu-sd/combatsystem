#include <cassert>
#include <iostream>
#include "../src/entities/Enemy.h"
#include "../src/entities/Player.h"
#include "../src/actions/BasicAttack.h"

int main() {
    Player player("Hero", 100, 15);
    Enemy enemy("Goblin King", 40, 15, "Goblin");
    BasicAttack basicAttack;

    std::cout << "Test 3.1: Player does basic attack on Goblin";
    assert(player.getName() == "Hero");
    assert(player.getCurrentHP() == 100);
    assert(player.getAttackPower() == 15);
    assert(player.isAlive() == true);

    assert(enemy.getName() == "Goblin King");
    assert(enemy.getCurrentHP() == 40);
    assert(enemy.getAttackPower() == 15);
    assert(enemy.isAlive() == true);

    // deals damage to enemy
    basicAttack.execute(player, enemy);
    assert(enemy.getCurrentHP() == 25);
    std::cout << " PASS\n";

    std::cout << "Test 3.2: Goblin does basic attack on Player";
    basicAttack.execute(enemy, player);
    assert(player.getCurrentHP() == 85);
    assert(enemy.getCurrentHP() == 25);
    assert(player.isAlive() == true);
    std::cout << " PASS\n";

    std::cout << "Test 3.3: Enemy takes lethal damage, dies...";
    basicAttack.execute(player, enemy);
    assert(enemy.getCurrentHP() == 10);
    assert(enemy.isAlive() == true);
    basicAttack.execute(player, enemy);
    assert(enemy.getCurrentHP() == 0);
    assert(enemy.isAlive() == false);
    std::cout << " PASS\n";

    std::cout << "Test 3.4: Dead Enemy cannot attack player";
    basicAttack.execute(enemy, player);
    assert(player.getCurrentHP() == 85);
    assert(player.isAlive() == true);
    std::cout << " PASS\n";

    std::cout << "Test 3.5: Attacking dead entity does nothing";
    basicAttack.execute(player, enemy);
    assert(enemy.getCurrentHP() == 0);
    assert(enemy.isAlive() == false);
    std::cout << " PASS\n";

    std::cout << "All of Test 3 passed.\n\n";

    return 0;
}
