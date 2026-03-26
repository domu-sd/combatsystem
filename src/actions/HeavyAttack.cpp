#include "HeavyAttack.h"
#include "../entities/Entity.h"
#include <random>
#include <iostream>

HeavyAttack::HeavyAttack(int missPercentage)
    : missPercentage(missPercentage)
{
}

bool HeavyAttack::execute(Entity& actor, Entity& target) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);
    int roll = dist(gen);

    if (actor.isAlive() && roll > missPercentage) {
        int baseDamage = actor.getAttackPower();
        target.takeDamage(baseDamage * 2);
        return true;
    }
    return false;
}

std::string HeavyAttack::getName() const {
    return "Heavy Attack";
}