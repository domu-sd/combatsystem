#include "Player.h"

Player::Player(const std::string& name, int maxHP, int attackPower, int healCharges)
    : Entity(name, maxHP, attackPower), healCharges(healCharges)
{
}

Action* Player::chooseAction() {
    return nullptr;
}

int Player::getHealCharges() const {
    return healCharges;
}

void Player::useHealCharge() {
    healCharges -= 1;
    if (healCharges < 0) {
        healCharges = 0;
    }
}