#pragma once
#include "utils.h"

namespace Utils {
    sf::Vector2f normalize(sf::Vector2f v) {
        float mag = sqrt(v.x * v.x + v.y * v.y);
        return mag > 0 ? v/mag : v;
    }
}