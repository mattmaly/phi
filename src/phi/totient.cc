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

namespace {
// Returns a^k.
unsigned long ComputeIntegerPower(unsigned long a, unsigned long k) {
    if (k == 0) {
        return 1;
    }
    unsigned long result = a;
    for (--k; k > 0; --k) {
        result *= a;
    }
    return result;
}
}  // namespace

unsigned long ComputeTotientOfPrimePower(unsigned long p, unsigned long k) {
    if (k == 0) {
        return 1;
    }
    return ComputeIntegerPower(p, k - 1) * (p - 1);
}

std::vector<unsigned long> ComputePreImageOfTotient(unsigned long totient) {
    // Because phi(N) >= sqrt(N/2) [1], every pre-image x of totient is
    // guaranteed to be at most 2*totient^2. Specifically, if x > 2*totient^2,
    // then rearrangement yields sqrt(x/2) > totient, and thus phi(x) > totient.
    //
    // [1] - https://en.wikipedia.org/wiki/Euler%27s_totient_function
    const unsigned long preimage_upper_bound = 2 * totient * totient;

    // Compute phi(x) for every x in {1, ..., preimage_upper_bound}, and return
    // the subset of values in that range for which phi(x) == totient.
    const std::vector<unsigned long> totient_values =
            ComputeTotientRange(preimage_upper_bound);
    std::vector<unsigned long> preimage;
    for (unsigned long x = 1; x < totient_values.size(); ++x) {
        if (totient_values[x] == totient) {
            preimage.push_back(x);
        }
    }
    return preimage;
}
