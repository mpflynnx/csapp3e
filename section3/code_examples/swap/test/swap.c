#include <stdint.h>

void swap (uint64_t *xp, uint64_t *yp) { // %rdi first argument xp register, &rsi second argument yp register
    uint64_t t0 = *xp;  // rax
    uint64_t t1 = *yp; // rdx
    *xp = t1;
    *yp = t0;
}

int main() {
    uint64_t xp = 0x749B2F1A;
    uint64_t yp = 0x52D109E4;
    swap(&xp, &yp); // Pass addresses, not values
    return 0;
}

// https://godbolt.org/z/P5aK73q47