#define CATCH_CONFIG_MAIN
#include "external-deps/catch2/catch.hpp"

// The above `CATCH_CONFIG_MAIN` definition triggers Cache2 to auto-generate a
// main function which will run any registered tests. By keeping registered
// tests in separate files that will be linked at compile-time, we separate the
// (heavy) cost of compiling the header-only Catch2 library from the (light)
// cost of compiling each test case.
