#include "phi/totient-free.h"

#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

#include "phi/totient.h"
#include "phi/util.h"

// TODO(issue #1): Move the below helper functions from the unnamed namespace
// into util.{h, cc}.
namespace {

// Returns the smallest prime divisor of the given positive integer `n`.
unsigned long GetSmallestPrimeDivisor(unsigned long n) {
    // TODO: Replace sqrt(n) with a faster integer-based square-root function.
    for (unsigned long i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return i;
        }
    }
    return n;
}

// `PrimePower` represents a prime power as a pair (`prime`, `power`) of
// positive integers where `prime` is prime.
struct PrimePower {
    unsigned long prime;
    unsigned long power;

    unsigned long ComputeValue() const {
        return ComputeIntegerPower(prime, power);
    }
};

// Returns {(p_1, a_1), ..., (p_k, a_k)}, representing the unique factorization
// of the given positive integer `n`, such that p_1 < ... < p_k.
std::vector<PrimePower> GetPrimePowerFactors(unsigned long n) {
    // TODO: Consider pre-reserving space for `factors`, following the Erdős-Kac
    // theorem [1] which states that the number of prime factors of a positive
    // integer N is approximately ln(ln(N)).
    //
    // [1] - https://en.wikipedia.org/wiki/Erdős–Kac_theorem
    std::vector<PrimePower> factors;
    while (n != 1) {
        PrimePower pp;
        pp.prime = GetSmallestPrimeDivisor(n);
        pp.power = 1;
        n /= pp.prime;
        while (n % pp.prime == 0) {
            n /= pp.prime;
            ++pp.power;
        }
        factors.push_back(pp);
    }
    return factors;
}

}  // namespace

bool IsTotientFree(unsigned long n) {
    if (n % 12 != 0) {
        return false;
    }
    const std::vector<PrimePower> factors = GetPrimePowerFactors(n);
    for (const PrimePower& pp : factors) {
        const unsigned long pp_totient =
                ComputeTotientOfPrimePower(pp.prime, pp.power);
        const unsigned long pp_value = pp.ComputeValue();
        const unsigned long n_without_pp = n / pp_value;
        for (unsigned long x : ComputePreImageOfTotient(pp_totient)) {
            if (x != pp_value && std::gcd(x, n_without_pp) == 1) {
                return false;
            }
        }
    }
    return true;
}
