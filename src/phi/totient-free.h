#ifndef PHI_TOTIENT_FREE
#define PHI_TOTIENT_FREE

// Returns whether the positive integer `n` is totient-free.
//
// A positive integer n > 1 is defined to be "totient-free" if, for any prime
// divisor p of n, the equation phi(x) = phi(p^{{v_p}(n)) has no nontrivial
// solution x for which gcd(x, n/p^{{v_p}(n)}) = 1.
bool IsTotientFree(unsigned long n);

// Returns whether the positive integer `n` is totient-free with degree `k`.
//
// A positive integer n > 1 is defined to be "totient-free with degree k" if,
// for any size-k subset S = {p_1^a_1, ..., p_k^a_k} of the set of prime power
// divisors of p, the equation phi(x) = phi(product over S) has no nontrivial
// solution x for which gcd(x, n/(product over S)) = 1.
bool IsTotientFreeWithDegree(unsigned long n, unsigned long k);

#endif  // PHI_TOTIENT_FREE
