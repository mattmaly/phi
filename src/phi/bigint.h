#ifndef PHI_BIGINT
#define PHI_BIGINT

#include <gmp.h>
#include <string>

class BigInt {
public:
    explicit BigInt(unsigned long initial_value);
    ~BigInt();

    std::string ToString() const;
private:
    mpz_t value_;
};

#endif  // PHI_BIGINT
