#include "phi/totient.h"

#include <numeric>

#include "phi/util.h"

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

void TotientCache::Precompute(unsigned long n) {
    const unsigned long previous_max = MaxCachedInput();
    if (n <= previous_max) {
        return;
    }
    totient_values_.resize(n + 1);
    // Initialize totient_values_[k] to k, for each new k.
    std::iota(totient_values_.begin() + previous_max + 1, totient_values_.end(),
            previous_max + 1);

    std::vector<bool> initialized(n, false);
    for (unsigned long i = 2; i <= n; ++i) {
        if (!initialized[i]) {
            for (unsigned long j = i; j <= n; j += i) {
                if (j > previous_max) {
                    totient_values_[j] -= (totient_values_[j] / i);
                }
                initialized[j] = true;
            }
        }
    }

    for (unsigned long preimage = previous_max + 1; preimage <= n; ++preimage) {
        totient_value_to_preimage_[totient_values_[preimage]].push_back(
                preimage);
    }
}

unsigned long TotientCache::MaxCachedInput() const {
    if (totient_values_.empty()) {
        return 0;
    }
    return totient_values_.size() - 1;
}

unsigned long TotientCache::Phi(unsigned long n) {
    Precompute(n);
    return totient_values_[n];
}

const std::vector<unsigned long>&
TotientCache::InversePhi(unsigned long totient) {
    // Because phi(N) >= sqrt(N/2) [1], every pre-image x of totient is
    // guaranteed to be at most 2*totient^2. Specifically, if x > 2*totient^2,
    // then rearrangement yields sqrt(x/2) > totient, and thus phi(x) > totient.
    //
    // Thus, if we precompute this cache for input values up to and including
    // 2*totient^2, then we can guarantee that totient_value_to_preimage_
    // contains all preimages of totient.
    //
    // [1] - https://en.wikipedia.org/wiki/Euler%27s_totient_function
    Precompute(2 * totient * totient);
    const auto iter = totient_value_to_preimage_.find(totient);
    if (iter == totient_value_to_preimage_.end()) {
        static const auto* const kEmptyPreimage =
                new std::vector<unsigned long>();
        return *kEmptyPreimage;
    }
    return iter->second;
}
