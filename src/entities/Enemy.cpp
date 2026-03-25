#include "Enemy.h"

Enemy::Enemy(const std::string& name, int maxHP, int attackPower, std::string enemyType)
    : Entity(name, maxHP, attackPower), enemyType(enemyType)
{
}

Action* Enemy::chooseAction() {
    return nullptr;
}

std::string Enemy::getEnemyType() const {
    return enemyType;
}