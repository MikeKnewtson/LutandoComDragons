#pragma once

#include <HumanWeapon.hpp>
#include <Named.hpp>

namespace Names {
static constexpr char Excaliber[] = "Excaliber";
}

static constexpr auto HeavySwordDamage = 100;

struct HeavySword : public Weapon<HeavySwordDamage>, public HumanWeapon {};

struct Excaliber : public Named<HeavySword, Names::Excaliber> {};