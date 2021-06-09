#ifndef PHI_TOTIENT_FREE
#define PHI_TOTIENT_FREE

// Returns whether the positive integer `n` is totient-free.
//
// A positive integer n > 1 is defined to be "totient-free" if, for any prime
// divisor p of n, the equation phi(x) = phi(p^{{v_p}(n)) has no nontrivial
// solution x for which gcd(x, n/p^{{v_p}(n)}) = 1.
bool IsTotientFree(unsigned long n);

#endif  // PHI_TOTIENT_FREE
