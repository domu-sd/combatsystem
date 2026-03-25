#pragma once

#include "Action.h"

class Heal : public Action {
private:
    int healPower; // amount of health being healed

public:
    Heal(int healPower = 20);
    void execute(Entity& actor, Entity& target) override;
    std::string getName() const override;
};