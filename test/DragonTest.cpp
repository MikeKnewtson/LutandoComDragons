#include <catch2/catch_test_macros.hpp>

#include <Dragon.hpp>
#include <Time.hpp>
#include <Weapon.hpp>


TEST_CASE("Dragon test", "[Dragon-Test]") {
  Dragon dragon;
  Weapon sword;
  Time half_an_hour{.seconds = 1800};

  SECTION("Dragon is alive") { REQUIRE(dragon.is_alive()); }

  SECTION("Dragon takes a hit, but survives") {
    dragon.takes_a_hit(sword);
    REQUIRE(dragon.is_alive());
  }

  SECTION("Dragon is mortal after all") {
    dragon.takes_a_hit(sword);
    dragon.takes_a_hit(sword);
    REQUIRE_FALSE(dragon.is_alive());
  }

  SECTION("Dragon can heal") {
    dragon.takes_a_hit(sword);
    dragon.has_time(half_an_hour);
    dragon.takes_a_hit(sword);
    REQUIRE(dragon.is_alive());
  }

  SECTION("Dragon needs time to heal") {
    dragon.takes_a_hit(sword);
    dragon.has_time(half_an_hour);
    dragon.takes_a_hit(sword);
    dragon.takes_a_hit(sword);
    REQUIRE_FALSE(dragon.is_alive());
  }
}