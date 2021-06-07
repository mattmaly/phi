#include "phi/totient.h"

#include <numeric>

std::vector<unsigned long> ComputeTotientRange(unsigned long n) {
    std::vector<unsigned long> totient_values;
    totient_values.resize(n + 1);

    // Initiliaze totient_values[k] to k, for each k.
    std::iota(totient_values.begin(), totient_values.end(), 0);

    for (unsigned long i = 2; i <= n; ++i) {
        if (totient_values[i] == i) {
            for (unsigned long j = i; j <= n; j += i) {
                totient_values[j] -= (totient_values[j] / i);
            }
        }
    }

    return totient_values;
}
