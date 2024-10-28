#pragma once

#include <Named.hpp>
#include <Weapon.hpp>

struct HumanWeapon {};

struct Sword : public Weapon<50>, public HumanWeapon {};

namespace Names {
static constexpr char Excaliber[] = "Excaliber";
}

struct Excaliber : public Named<Sword, Names::Excaliber> {};
