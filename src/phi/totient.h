#ifndef PHI_TOTIENT
#define PHI_TOTIENT

#include <vector>

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

#endif  // PHI_TOTIENT
