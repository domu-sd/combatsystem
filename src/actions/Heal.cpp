#include "Heal.h"
#include "../entities/Entity.h"
#include "../entities/Player.h"

Heal::Heal(int healPower)
    : healPower(healPower)
{
}

bool Heal::execute(Entity& actor, Entity& target) {
    Player* actorPlayer = dynamic_cast<Player*>(&actor);
    Player* targetPlayer = dynamic_cast<Player*>(&target);

    if (actorPlayer && targetPlayer &&
        actorPlayer->isAlive() && targetPlayer->isAlive() &&
        actorPlayer->getHealCharges() > 0)
    {
        actorPlayer->useHealCharge();
        targetPlayer->heal(healPower);
        return true;
    }
    return false;
}

std::string Heal::getName() const {
    return "Heal";
}