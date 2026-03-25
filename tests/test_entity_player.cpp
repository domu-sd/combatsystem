#include <cassert>
#include <iostream>
#include "../src/entities/Entity.h"
#include "../src/entities/Player.h"

int main() {
    Player player("Hero", 100, 15);

    std::cout << "Test 1.1: Player creation...";
    assert(player.getName() == "Hero");
    assert(player.getCurrentHP() == 100);
    assert(player.getAttackPower() == 15);
    assert(player.isAlive() == true);
    assert(player.getHealCharges() == 3);
    std::cout << " PASS\n";

    std::cout << "Test 1.2: Player takes damage, stays alive...";
    player.takeDamage(30);
    assert(player.getCurrentHP() == 70);
    assert(player.isAlive() == true);
    std::cout << " PASS\n";

    std::cout << "Test 1.3: Player takes lethal damage, dies...";
    player.takeDamage(200);
    assert(player.getCurrentHP() == 0);
    assert(player.isAlive() == false);
    std::cout << " PASS\n";

    std::cout << "Test 1.4: Healing a dead player does nothing...";
    player.heal(50);
    assert(player.getCurrentHP() == 0);
    assert(player.isAlive() == false);
    std::cout << " PASS\n";

    std::cout << "Test 1.5: Healing a live player restores HP...";
    Player player2("Hero2", 100, 15);
    player2.takeDamage(30);
    player2.heal(20);
    assert(player2.getCurrentHP() == 90);
    assert(player2.isAlive() == true);
    std::cout << " PASS\n";

    std::cout << "All of Test 1 passed.\n\n";

    return 0;
}
