#pragma once

#include "../entities/Player.h"
#include "../entities/Enemy.h"
#include <string>
#include <vector>

struct Level {
    std::string name;
    Player player;
    std::vector<Enemy> enemies;
};
