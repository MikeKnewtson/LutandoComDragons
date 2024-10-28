#pragma once

#include <Time.hpp>
#include <algorithm>

template <auto max_health, auto healing_time> class MortalCreature {
private:
  int health{max_health};

  void heals(const Time &time) {
    health += (time.seconds * max_health) / healing_time;
    health = std::min(health, max_health);
  }

public:
  template <typename WeaponT> void takes_a_hit(const WeaponT &weapon) {
    health -= WeaponT::damage;
  }

  void has_time(const Time &time) { heals(time); }

  [[nodiscard]] constexpr bool is_alive() const { return health > 0; }
};