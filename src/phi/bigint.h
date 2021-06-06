#ifndef PHI_BIGINT
#define PHI_BIGINT

#include <gmp.h>
#include <string>

class BigInt {
public:
    // Initializes a BigInt with the given `initial_value`.
    explicit BigInt(unsigned long initial_value);

    // Copy constructor.
    BigInt(const BigInt& other);

    // Frees all memory associated with this BigInt.
    ~BigInt();

    // Copy-assignment operator.
    BigInt& operator=(const BigInt& other);

    // Returns a std::string containing the base-10 representation of this
    // BigInt.
    std::string ToString() const;
private:
    mpz_t value_;
};

#endif  // PHI_BIGINT
