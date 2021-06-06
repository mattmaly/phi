#define CATCH_CONFIG_MAIN
#include "external-deps/catch2/catch.hpp"

#include <string>

TEST_CASE("Empty test") {
    REQUIRE(1 + 2 == 3);
}
