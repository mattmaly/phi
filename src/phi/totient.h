#ifndef PHI_TOTIENT
#define PHI_TOTIENT

#include <vector>

#include "phi/bigint.h"

// Returns {0, phi(1), phi(2), ..., phi(n)}, where phi() is Euler's totient
// function.
std::vector<unsigned long> ComputeTotientRange(unsigned long n);

#endif  // PHI_TOTIENT
