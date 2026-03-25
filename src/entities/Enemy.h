#pragma once

#include "Entity.h"

class Enemy : public Entity {
    const std::string enemyType;

public:
    Enemy(const std::string& name, int maxHP, int attackPower, std::string enemyType);

    Action* chooseAction() override;
    std::string getEnemyType() const;
};