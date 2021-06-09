#include <iostream>
#include <vector>

#include "phi/bigint.h"
#include "phi/totient.h"
#include "phi/totient-free.h"

int main(int argc, char** argv) {
    // Create a BigInt.
    BigInt value(43);

    // Print its value to stdout.
    std::cout << "Test BigInt value: " << value.ToString() << std::endl;

    const std::vector<unsigned long> totient_values = ComputeTotientRange(100);
    for (unsigned long i = 1; i < totient_values.size(); ++i) {
        std::cout << "phi(" << i << ") = " << totient_values[i] << std::endl;
        if (IsTotientFree(i)) {
            std::cout << i << " is totient-free." << std::endl;
        }
    }

    return 0;
}
