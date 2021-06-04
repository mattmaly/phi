#include <gmp.h>
#include <iostream>

int main(int argc, char** argv) {
    // Create a GMP integer.
    mpz_t value;
    mpz_init(value);
    mpz_set_ui(value, 43);

    // Text-format the GMP integer to a char* buffer and print its contents to
    // stdout.
    char* text_value;
    gmp_asprintf(&text_value, "%Zd", value);
    std::cout << "Test value: " << text_value << std::endl;

    // Free all used memory.
    delete text_value;
    mpz_clear(value);

    return 0;
}
