
#include <iostream>
#include "Entity.h"

Entity::Entity(const std::string& name, int maxHP, int attackPower)
    : name(name), currentHP(maxHP), maxHP(maxHP), attackPower(attackPower), alive(true)
{
}

void Entity::takeDamage(int amount) {
    currentHP -= amount;
    if (currentHP <= 0) {
        currentHP = 0;
        alive = false;
    }
}

void Entity::heal(int amount) {
    currentHP += amount;
    if (currentHP > maxHP) {
        currentHP = maxHP;
    }
}

void Entity::printStatus() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "HP: " << currentHP << std::endl;
}

bool Entity::isAlive() const {
    return alive;
}

std::string Entity::getName() const {
    return name;
}

int Entity::getCurrentHP() const {
    return currentHP;
}

int Entity::getAttackPower() const {
    return attackPower;
}
