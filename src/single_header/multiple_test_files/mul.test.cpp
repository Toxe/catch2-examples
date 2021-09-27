#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "testee.hpp"

TEST_CASE("mul")
{
    REQUIRE(mul(0, 0) == 0);
    REQUIRE(mul(1, 0) == 0);
    REQUIRE(mul(0, 1) == 0);
    REQUIRE(mul(1, 1) == 1);
    REQUIRE(mul(2, 3) == 6);
}
