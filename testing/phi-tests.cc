#define CATCH_CONFIG_MAIN

#include <string>

#include "external-deps/catch2/catch.hpp"
#include "phi/bigint.h"

TEST_CASE("Construct a BigInt from an unsigned long") {
    BigInt small_value(43);
    REQUIRE(small_value.ToString() == "43");

    BigInt large_value(4294967295);
    REQUIRE(large_value.ToString() == "4294967295");
}
