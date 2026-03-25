#pragma once

#include "Action.h"

class HeavyAttack : public Action {
    protected:
    int missPercentage;

    public:
    void execute(Entity& actor, Entity& target) override;
    std::string getName() const override;
};