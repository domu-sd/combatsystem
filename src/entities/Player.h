#pragma once

#include "Entity.h"

class Player : public Entity {
    int healCharges;

public:
    Player(const std::string& name, int maxHP, int attackPower, int healCharges = 3);

    Action* chooseAction() override;
    int getHealCharges() const;
    void useHealCharge();
};
