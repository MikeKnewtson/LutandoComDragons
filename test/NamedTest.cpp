#include <catch2/catch_test_macros.hpp>

#include <Named.hpp>

#include <cstring>
#include <type_traits>

struct Foo {};
static constexpr char FooName[] = "Foo";

struct NamedFoo : public Named<Foo, FooName> {};

TEST_CASE("Named test", "[Named-Test]") {

  SECTION("Can get name") {
    REQUIRE(0 == std::strcmp("Foo", NamedFoo::get_name()));
    REQUIRE(FooName == NamedFoo::get_name());
  }

  SECTION("Can get name at compile time") {
    static_assert(FooName == NamedFoo::get_name(), "Name is not Foo");
  }

  SECTION("Named Foo is a Foo") {
    static_assert(std::is_base_of_v<Foo, NamedFoo>, "NamedFoo is not a Foo");
  }
}