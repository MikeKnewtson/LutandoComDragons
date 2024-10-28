#pragma once

#include <Weapon.hpp>

struct HumanWeapon {};

struct Sword : public Weapon<50>, public HumanWeapon {};
