#pragma once

#include <string>

class Action;

class Entity {
protected:
    std::string name;
    int currentHP;
    int maxHP;
    int attackPower;
    bool alive;

public:
    Entity(const std::string& name, int maxHP, int attackPower);
    virtual ~Entity() = default;

    virtual void takeDamage(int amount);
    virtual void heal(int amount);
    virtual Action* chooseAction() = 0;
    virtual void printStatus() const;

    bool isAlive() const;
    std::string getName() const;
    int getCurrentHP() const;
    int getAttackPower() const;
};
