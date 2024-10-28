#pragma once

#include <Weapon.hpp>

struct HumanWeapon {};

static constexpr auto SwordDamage = 50;

struct Sword : public Weapon<SwordDamage>, public HumanWeapon {};
