#pragma once

template <auto Damage = 50> struct Weapon {
  static constexpr int damage{Damage};
};