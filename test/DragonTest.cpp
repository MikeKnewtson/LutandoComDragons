#include <catch2/catch_test_macros.hpp>

#include <Dragon.hpp>

TEST_CASE("Dragon is alive", "[Dragon-Test]")
{
    Dragon dragon;
    REQUIRE(dragon.is_alive());
}