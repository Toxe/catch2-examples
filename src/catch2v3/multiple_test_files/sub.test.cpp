#include "catch2/catch_test_macros.hpp"

#include "testee.hpp"

TEST_CASE("catch2v3, multiple_test_files: sub")
{
    REQUIRE(sub(0, 0) == 0);
    REQUIRE(sub(1, 0) == 1);
    REQUIRE(sub(0, 1) == -1);
    REQUIRE(sub(1, 1) == 0);
    REQUIRE(sub(2, 3) == -1);
    REQUIRE(sub(3, 2) == 1);
}
