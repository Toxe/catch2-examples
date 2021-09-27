#include "catch2/catch.hpp"

#include "testee.hpp"

TEST_CASE("single_header, single_test_file_multiple_sources: sub")
{
    REQUIRE(sub(0, 0) == 0);
    REQUIRE(sub(1, 0) == 1);
    REQUIRE(sub(0, 1) == -1);
    REQUIRE(sub(1, 1) == 0);
    REQUIRE(sub(2, 3) == -1);
    REQUIRE(sub(3, 2) == 1);
}
