#include "phi/bigint.h"

#include <memory>

BigInt::BigInt(unsigned long initial_value) {
    mpz_init_set_ui(value_, initial_value);
}

BigInt::~BigInt() {
    mpz_clear(value_);
}

std::string BigInt::ToString() const {
    std::unique_ptr<char[]> text_value(
        mpz_get_str(/*str=*/nullptr, /*base=*/10, value_));
    return std::string(text_value.get());
}
