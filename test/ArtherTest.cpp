#include <catch2/catch_test_macros.hpp>

#include <Arther.hpp>
#include <Excaliber.hpp>
#include <format>

TEST_CASE("Arther test", "[Arther-Test]") {
  Arther arther;

  SECTION("Arther is a knight who caries Excaliber") {
    static_assert(Arther::get_name() == Names::Arther,
                  "Knight is not named Arther");
    REQUIRE(arther.get_name() == Names::Arther);

    static_assert(Arther::WeaponType::get_name() == Names::Excaliber,
                  "Arther does not have Excaliber");
    REQUIRE(arther.weapon.get_name() == Names::Excaliber);

    const auto message = std::format("{} carries {}", arther.get_name(),
                                     arther.weapon.get_name());
    REQUIRE(message == "Arther carries Excaliber");
  }
}