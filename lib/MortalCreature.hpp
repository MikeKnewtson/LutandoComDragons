#pragma once

#include <Time.hpp>
#include <Weapon.hpp>
#include <algorithm>

template <auto max_health, auto healing_time> class MortalCreature {
private:
  int health{max_health};

  void heals(const Time &time) {
    health += (time.seconds * max_health) / healing_time;
    health = std::min(health, max_health);
  }

public:
  void takes_a_hit(const Weapon &weapon) { health -= weapon.damage; }

  void has_time(const Time &time) { heals(time); }

  [[nodiscard]] constexpr bool is_alive() const { return health > 0; }
};