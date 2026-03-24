#include <iostream>
#include "../src/entities/Entity.h"
#include "../src/entities/Player.h"

int main() {
    Player player("Hero", 100, 15);

    std::cout << "=== Entity/Player Creation Test ===\n";
    player.printStatus();
    std::cout << "Alive: " << player.isAlive() << "\n";
    std::cout << "Heal charges: " << player.getHealCharges() << "\n";

    return 0;
}
