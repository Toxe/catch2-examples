#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "testee.hpp"

TEST_CASE("single_header, multiple_test_files: add")
{
    REQUIRE(add(0, 0) == 0);
    REQUIRE(add(1, 0) == 1);
    REQUIRE(add(0, 1) == 1);
    REQUIRE(add(1, 1) == 2);
    REQUIRE(add(2, 3) == 5);
}
