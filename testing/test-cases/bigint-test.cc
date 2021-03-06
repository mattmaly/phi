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

TEST_CASE("Re-assign a BigInt a new integer value") {
    BigInt value(43);
    value.Assign(123);
    REQUIRE(value.ToString() == "123");
}

TEST_CASE("Add BigInts") {
    BigInt value(43);
    BigInt other_value(41);

    value.Add(other_value);
    REQUIRE(value.ToString() == "84");
}

TEST_CASE("Multiply BigInts") {
    BigInt value(43);
    BigInt other_value(7);

    value.MultiplyBy(other_value);
    REQUIRE(value.ToString() == "301");
}

TEST_CASE("Divide BigInts") {
    BigInt value(43);
    BigInt other_value(7);

    value.DivideBy(other_value);
    REQUIRE(value.ToString() == "6");
}
