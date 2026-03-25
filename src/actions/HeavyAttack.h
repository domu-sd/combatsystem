#pragma once

#include "Action.h"

class HeavyAttack : public Action {
private:
    int missPercentage; // chance of missing (100 = always misses)

public:
    HeavyAttack(int missPercentage = 20);
    void execute(Entity& actor, Entity& target) override;
    std::string getName() const override;
};