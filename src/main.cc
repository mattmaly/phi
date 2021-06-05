#include <iostream>

#include "phi/bigint.h"

int main(int argc, char** argv) {
    // Create a BigInt.
    BigInt value(43);

    // Print its value to stdout.
    std::cout << "Test value: " << value.ToString() << std::endl;

    return 0;
}
