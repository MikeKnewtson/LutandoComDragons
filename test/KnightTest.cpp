#include <catch2/catch_test_macros.hpp>

#include <Arther.hpp>
#include <Excaliber.hpp>
#include <Time.hpp>
#include <format>

TEST_CASE("Knight test", "[Knight-Test]") {
  Arther knight;
  Weapon dragon_claw;
  Time half_an_hour{.seconds = 1800};

  SECTION("Arther is a knight who caries Excaliber") {
    static_assert(Arther::get_name() == Names::Arther,
                  "Knight is not named Arther");
    REQUIRE(knight.get_name() == Names::Arther);

    static_assert(Arther::WeaponType::get_name() == Names::Excaliber,
                  "Arther does not have Excaliber");
    REQUIRE(knight.weapon.get_name() == Names::Excaliber);

    const auto message = std::format("{} carries {}", knight.get_name(),
                                     knight.weapon.get_name());
    REQUIRE(message == "Arther carries Excaliber");
  }

  SECTION("Knight is alive") { REQUIRE(knight.is_alive()); }

  SECTION("Knight takes a hit, but survives") {
    knight.takes_a_hit(dragon_claw);
    REQUIRE(knight.is_alive());
  }

  SECTION("Knight is mortal after all") {
    knight.takes_a_hit(dragon_claw);
    knight.takes_a_hit(dragon_claw);
    REQUIRE_FALSE(knight.is_alive());
  }

  SECTION("Knight can heal") {
    knight.takes_a_hit(dragon_claw);
    knight.has_time(half_an_hour);
    knight.takes_a_hit(dragon_claw);
    REQUIRE(knight.is_alive());
  }

  SECTION("Knight needs time to heal") {
    knight.takes_a_hit(dragon_claw);
    knight.has_time(half_an_hour);
    knight.takes_a_hit(dragon_claw);
    knight.takes_a_hit(dragon_claw);
    REQUIRE_FALSE(knight.is_alive());
  }
}