#include <catch2/catch_test_macros.hpp>

#include <Knight.hpp>
#include <Time.hpp>
#include <Weapon.hpp>

TEST_CASE("Knight test", "[Knight-Test]") {
  Knight knight;
  Weapon dragon_claw;
  Time half_an_hour{.seconds = 1800};

  SECTION("knight is alive") { REQUIRE(knight.is_alive()); }

  SECTION("knight takes a hit, but survives") {
    knight.takes_a_hit(dragon_claw);
    REQUIRE(knight.is_alive());
  }

  SECTION("knight is mortal after all") {
    knight.takes_a_hit(dragon_claw);
    knight.takes_a_hit(dragon_claw);
    REQUIRE_FALSE(knight.is_alive());
  }

  SECTION("knight can heal") {
    knight.takes_a_hit(dragon_claw);
    knight.has_time(half_an_hour);
    knight.takes_a_hit(dragon_claw);
    REQUIRE(knight.is_alive());
  }

  SECTION("knight needs time to heal") {
    knight.takes_a_hit(dragon_claw);
    knight.has_time(half_an_hour);
    knight.takes_a_hit(dragon_claw);
    knight.takes_a_hit(dragon_claw);
    REQUIRE_FALSE(knight.is_alive());
  }
}