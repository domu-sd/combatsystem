#pragma once

#include "Action.h"

class BasicAttack : public Action {
    public:
    void execute(Entity& actor, Entity& target) override;
    std::string getName() const override;
};