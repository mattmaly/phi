#include "phi/bigint.h"

#include <memory>

BigInt::BigInt(unsigned long initial_value) {
    mpz_init_set_ui(value_, initial_value);
}

BigInt::BigInt(const BigInt& other) {
    mpz_init_set(value_, other.value_);
}

BigInt::~BigInt() {
    mpz_clear(value_);
}

BigInt& BigInt::operator=(const BigInt& other) {
    mpz_set(value_, other.value_);
    return *this;
}

std::string BigInt::ToString() const {
    // When passed a nullptr first argument, `mpz_get_str()` dynamically
    // allocates a char[] containing the text-formatted representation of
    // value_.
    //
    // We immediately wrap the char[] in a std::unique_ptr to prevent leaks,
    // and then we copy its contents into a std::string.
    std::unique_ptr<char[]> text_value(
        mpz_get_str(/*str=*/nullptr, /*base=*/10, value_));
    return std::string(text_value.get());
}
