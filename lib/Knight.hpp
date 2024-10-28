#pragma once

#include <HumanWeapon.hpp>
#include <MortalCreature.hpp>
#include <type_traits>

static constexpr auto knight_max_health = 100;
static constexpr auto knight_healing_time = 3600;

template <typename WeaponT = Sword>
requires std::is_base_of_v<HumanWeapon, WeaponT> struct Knight
    : public MortalCreature<knight_max_health, knight_healing_time> {
  typedef WeaponT WeaponType;
  static const WeaponT weapon;
};

template <typename WeaponT>
requires std::is_base_of_v<HumanWeapon, WeaponT> inline const WeaponT
    Knight<WeaponT>::weapon;