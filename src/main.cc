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

    std::cout << "=== Totient-free numbers ===" << std::endl;
    TotientCache totient_cache;
    totient_cache.Precompute(1000);
    std::vector<unsigned long> totient_free_numbers;
    for (unsigned long i = 1; i <= totient_cache.MaxCachedInput(); ++i) {
        std::cout << "phi(" << i << ") = " << totient_cache.Phi(i) << std::endl;
        if (IsTotientFree(i)) {
            totient_free_numbers.push_back(i);
            std::cout << i << " is totient-free." << std::endl;
        }
    }

    std::cout << "=== Totient-free (degree-2) numbers ===" << std::endl;
    for (unsigned long i : totient_free_numbers) {
        std::cout << "Checking " << i << "..." << std::endl;
        if (IsTotientFreeWithDegree(i, 2)) {
            std::cout << i << " is totient-free with degree 2." << std::endl;
        }
    }

    return 0;
}
