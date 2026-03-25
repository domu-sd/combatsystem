#include <cassert>
#include <iostream>
#include "../src/entities/Player.h"
#include "../src/entities/Enemy.h"
#include "../src/actions/Heal.h"

int main() {
    std::cout << "Test 5.1: Player heals another player...";
    Player healer("Healer", 100, 15);
    Player wounded("Wounded", 100, 15);
    wounded.takeDamage(40);
    Heal heal;
    heal.execute(healer, wounded);
    assert(wounded.getCurrentHP() == 80);
    assert(healer.getHealCharges() == 2);
    std::cout << " PASS\n";

    std::cout << "Test 5.2: Enemy cannot heal a player...";
    Enemy goblin("Goblin", 80, 10, "Goblin");
    Player player("Hero", 100, 15);
    player.takeDamage(40);
    heal.execute(goblin, player);
    assert(player.getCurrentHP() == 60);
    assert(healer.getHealCharges() == 2);
    std::cout << " PASS\n";

    std::cout << "Test 5.3: Player cannot heal an enemy...";
    Player player2("Hero2", 100, 15);
    Enemy goblin2("Goblin2", 80, 10, "Goblin");
    goblin2.takeDamage(40);
    heal.execute(player2, goblin2);
    assert(goblin2.getCurrentHP() == 40);
    assert(player2.getHealCharges() == 3);
    std::cout << " PASS\n";

    std::cout << "Test 5.4: Heal charges run out...";
    Player caster("Caster", 100, 15, 1);
    Player target("Target", 100, 15);
    target.takeDamage(40);
    heal.execute(caster, target);
    assert(caster.getHealCharges() == 0);
    heal.execute(caster, target);
    assert(target.getCurrentHP() == 80);
    std::cout << " PASS\n";

    std::cout << "Test 5.5: Heal does not exceed max HP...";
    Player player3("Hero3", 100, 15);
    Player player4("Hero4", 100, 15);
    player4.takeDamage(10);
    Heal bigHeal(50);
    bigHeal.execute(player3, player4);
    assert(player4.getCurrentHP() == 100);
    std::cout << " PASS\n";

    std::cout << "Test 5.6: Cannot heal a dead player...";
    Player alive("Alive", 100, 15);
    Player dead("Dead", 100, 15);
    dead.takeDamage(200);
    heal.execute(alive, dead);
    assert(dead.getCurrentHP() == 0);
    assert(dead.isAlive() == false);
    std::cout << " PASS\n";

    std::cout << "Test 5.7: Dead cannot heal alive player...";
    alive.takeDamage(30);
    heal.execute(dead, alive);
    assert(alive.getCurrentHP() == 70);
    std::cout << " PASS\n";

    std::cout << "All of Test 5 passed.\n\n";

    return 0;
}
