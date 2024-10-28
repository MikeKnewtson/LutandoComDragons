#pragma once

#include <MortalCreature.hpp>

static constexpr auto DragonMaxHealth = 1000;
static constexpr auto DragonHealingTime = 3600;

class Dragon : public MortalCreature<DragonMaxHealth, DragonHealingTime> {};