#ifndef PHI_TOTIENT
#define PHI_TOTIENT

#include <vector>
#include <unordered_map>

#include "phi/bigint.h"

// In all below functions, "phi()" refers to Euler's totient function [1].
//
// [1] - https://en.wikipedia.org/wiki/Euler%27s_totient_function

// Returns {0, phi(1), phi(2), ..., phi(n)}.
std::vector<unsigned long> ComputeTotientRange(unsigned long n);

// Returns phi(p^k), assuming that p is prime (otherwise, this function's
// behavior is undefined).
unsigned long ComputeTotientOfPrimePower(unsigned long p, unsigned long k);

// Returns, in ascending order, all positive integers x for which
// phi(x) == totient.
std::vector<unsigned long> ComputePreImageOfTotient(unsigned long totient);

// An object for computing and caching values of the phi function. Unless
// otherwise specified, a TotientCache will maintain values of phi(x) in memory
// for all values of x ranging from 1 to the highest value that has been
// requested by the caller so far in this TotientCache's lifetime.
class TotientCache {
public:
    // Updates this cache to store all precomputed values {phi(1), ..., phi(n)}.
    // If MaxCachedInput() >= n, then this function has no effect.
    void Precompute(unsigned long n);

    // Returns the highest value n for which this TotientCache has already
    // computed and cached phi(n).
    unsigned long MaxCachedInput() const;

    // Returns Phi(n), preceded by Precompute(n).
    unsigned long Phi(unsigned long n);

    // Returns the pre-image of totient, which is the set of distinct positive
    // integers {x : phi(x) = totient}, in ascending order.
    const std::vector<unsigned long>& InversePhi(unsigned long totient);
private:
    // totient_values_[i] contains phi(i) (so, position 0 is ignored).
    std::vector<unsigned long> totient_values_;
    // totient_value_to_preimage_[M] contains the set of all distinct positive
    // integers x for which phi(x) = M, in ascending order.
    std::unordered_map<unsigned long, std::vector<unsigned long>>
            totient_value_to_preimage_;
};

#endif  // PHI_TOTIENT
