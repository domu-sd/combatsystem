#include "BasicAttack.h"
#include "../entities/Entity.h"

void BasicAttack::execute(Entity& actor, Entity& target) {
    if (actor.isAlive()) {
        target.takeDamage(actor.getAttackPower());
    }
}

std::string BasicAttack::getName() const {
    return "Basic Attack";
}