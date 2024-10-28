#pragma once

#include <HumanWeapon.hpp>
#include <MortalCreature.hpp>
#include <type_traits>

static constexpr auto knight_max_health = 100;
static constexpr auto knight_healing_time = 3600;

template <typename WeaponType = Sword>
requires std::is_base_of_v<HumanWeapon, WeaponType> class Knight
    : public MortalCreature<knight_max_health, knight_healing_time> {
  WeaponType weapon;
};