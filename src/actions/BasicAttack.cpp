#include "BasicAttack.h"
#include "../entities/Entity.h"
#include <iostream>

bool BasicAttack::execute(Entity& actor, Entity& target) {
    if (actor.isAlive()) {
        target.takeDamage(actor.getAttackPower());
        return true;
    }
    return false;
}

std::string BasicAttack::getName() const {
    return "Basic Attack";
}