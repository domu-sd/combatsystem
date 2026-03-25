#include "HeavyAttack.h"
#include "../entities/Entity.h"

void HeavyAttack::execute(Entity& actor, Entity& target) {
    if (actor.isAlive()) {
        target.takeDamage(actor.getAttackPower());
    }
}

std::string HeavyAttack::getName() const {
    return "Heavy Attack";
}