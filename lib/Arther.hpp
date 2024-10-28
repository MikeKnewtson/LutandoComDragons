#pragma once

#include <Excaliber.hpp>
#include <Knight.hpp>

namespace Names {
static constexpr char Arther[] = "Arther";
}

struct Arther : public Named<Knight<Excaliber>, Names::Arther> {};