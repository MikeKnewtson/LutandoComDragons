#pragma once

#include <HumanWeapon.hpp>
#include <Named.hpp>

namespace Names {
static constexpr char Excaliber[] = "Excaliber";
}

struct Excaliber : public Named<Sword, Names::Excaliber> {};