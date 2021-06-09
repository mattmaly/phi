#include "phi/util.h"

unsigned long ComputeIntegerPower(unsigned long a, unsigned long k) {
    if (k == 0) {
        return 1;
    }
    unsigned long result = a;
    for (--k; k > 0; --k) {
        result *= a;
    }
    return result;
}
