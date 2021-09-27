#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "testee.hpp"

TEST_CASE("single_header, single_test_file_one_source: libtestee")
{
    SECTION("add")
    {
        REQUIRE(add(0, 0) == 0);
        REQUIRE(add(1, 0) == 1);
        REQUIRE(add(0, 1) == 1);
        REQUIRE(add(1, 1) == 2);
        REQUIRE(add(2, 3) == 5);
    }

    SECTION("mul")
    {
        REQUIRE(mul(0, 0) == 0);
        REQUIRE(mul(1, 0) == 0);
        REQUIRE(mul(0, 1) == 0);
        REQUIRE(mul(1, 1) == 1);
        REQUIRE(mul(2, 3) == 6);
    }

    SECTION("sub")
    {
        REQUIRE(sub(0, 0) == 0);
        REQUIRE(sub(1, 0) == 1);
        REQUIRE(sub(0, 1) == -1);
        REQUIRE(sub(1, 1) == 0);
        REQUIRE(sub(2, 3) == -1);
        REQUIRE(sub(3, 2) == 1);
    }
}
