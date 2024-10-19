#pragma once

#include <Weapon.hpp>
#include <Time.hpp>

class Dragon {
private:
    static constexpr int max_health = 100;
    static constexpr int healing_time = 3600;
    int health{max_health};

public:
    void takes_a_hit(const Weapon& weapon) {
        health -= weapon.damage;
    }

    void has_time(const Time& time) {
        health += (time.seconds * max_health) / healing_time;
        if (health > max_health) {
            health = max_health;
        }
    }

    [[nodiscard]] constexpr bool is_alive() const { return health > 0; }
};