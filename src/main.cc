#include <gmp.h>
#include <iostream>
#include <memory>

int main(int argc, char** argv) {
    // Create a GMP integer.
    mpz_t value;
    mpz_init_set_ui(value, 43);

    // Text-format the GMP integer to a char* buffer and print its contents to
    // stdout.
    std::unique_ptr<char[]> text_value(mpz_get_str(/*str=*/nullptr, /*base=*/10, value));
    std::cout << "Test value: " << text_value.get() << std::endl;

    // Free all used memory.
    mpz_clear(value);

    return 0;
}
