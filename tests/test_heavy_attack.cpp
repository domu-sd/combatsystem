#include <cassert>
#include <iostream>
#include "../src/entities/Enemy.h"
#include "../src/entities/Player.h"
#include "../src/actions/HeavyAttack.h"

int main() {
    Player player("Hero", 100, 15);
    Enemy enemy("Goblin King", 40, 15, "Goblin");
    HeavyAttack heavyHit(0);
    HeavyAttack heavyMiss(100);

    std::cout << "Test 4.1: Player does heavy attack on Goblin";
    assert(player.getName() == "Hero");
    assert(player.getCurrentHP() == 100);
    assert(player.getAttackPower() == 15);
    assert(player.isAlive() == true);

    assert(enemy.getName() == "Goblin King");
    assert(enemy.getCurrentHP() == 40);
    assert(enemy.getAttackPower() == 15);
    assert(enemy.isAlive() == true);

    // deals damage to enemy
    heavyHit.execute(player, enemy);
    assert(enemy.getCurrentHP() == 10);
    std::cout << " PASS\n";

    std::cout << "Test 4.2: Goblin does heavy attack on Player";
    heavyHit.execute(enemy, player);
    assert(player.getCurrentHP() == 70);
    assert(enemy.getCurrentHP() == 10);
    assert(player.isAlive() == true);
    std::cout << " PASS\n";

    std::cout << "Test 4.3: Player misses heavy attack on Goblin";
    heavyMiss.execute(player, enemy);
    assert(enemy.getCurrentHP() == 10);
    assert(enemy.isAlive() == true);

    std::cout << "Test 4.3: Dead Entity cannot attack";
    heavyHit.execute(player, enemy);
    assert(enemy.getCurrentHP() == 0);
    assert(enemy.isAlive() == false);
    heavyHit.execute(enemy, player);
    assert(player.getCurrentHP() == 70);
    assert(player.isAlive() == true);
    std::cout << " PASS\n";

    std::cout << "Test 4.4: Attacking dead entity does nothing";
    heavyHit.execute(player, enemy);
    assert(enemy.getCurrentHP() == 0);
    assert(enemy.isAlive() == false);
    std::cout << " PASS\n";

    std::cout << "All of Test 4 passed.\n\n";

    return 0;
}
