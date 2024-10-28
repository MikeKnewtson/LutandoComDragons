#include <catch2/catch_test_macros.hpp>

#include <Dragon.hpp>
#include <Excaliber.hpp>
#include <Time.hpp>

TEST_CASE("Dragon test", "[Dragon-Test]") {
  Dragon dragon;
  Excaliber sword;
  Time half_an_hour{.seconds = 1800};

  SECTION("Dragon is alive") { REQUIRE(dragon.is_alive()); }

  SECTION("Dragon takes a hit, but survives") {
    dragon.takes_a_hit(sword);
    REQUIRE(dragon.is_alive());
  }

  auto dragon_takes_n_hits_with_a_weapon = [](auto &dragon, const auto &weapon,
                                              const auto n) {
    for (int i = 0; i < n; ++i) {
      dragon.takes_a_hit(weapon);
    }
  };

  SECTION("Dragon is mortal after all") {
    dragon_takes_n_hits_with_a_weapon(dragon, sword, 20);
    REQUIRE_FALSE(dragon.is_alive());
  }

  SECTION("Dragon can heal") {
    dragon_takes_n_hits_with_a_weapon(dragon, sword, 10);
    dragon.has_time(half_an_hour);
    dragon_takes_n_hits_with_a_weapon(dragon, sword, 10);
    REQUIRE(dragon.is_alive());
  }

  SECTION("Dragon needs time to heal") {
    dragon_takes_n_hits_with_a_weapon(dragon, sword, 10);
    dragon.has_time(half_an_hour);
    dragon_takes_n_hits_with_a_weapon(dragon, sword, 10);
    dragon_takes_n_hits_with_a_weapon(dragon, sword, 10);
    REQUIRE_FALSE(dragon.is_alive());
  }
}