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

TEST_CASE("Copy-construct a BigInt from another BigInt") {
    BigInt value(43);
    BigInt copied_value(value);
    REQUIRE(copied_value.ToString() == "43");
}

TEST_CASE("Copy-assign a BigInt from another BigInt") {
    BigInt value(43);
    BigInt other_value(0);

    other_value = value;
    REQUIRE(other_value.ToString() == "43");
}
