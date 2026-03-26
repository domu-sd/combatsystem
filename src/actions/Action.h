#pragma once

#include <string>

class Entity;

class Action {
public:
    virtual bool execute(Entity& actor, Entity& target) = 0;
    virtual std::string getName() const = 0;
    virtual ~Action() = default;
};