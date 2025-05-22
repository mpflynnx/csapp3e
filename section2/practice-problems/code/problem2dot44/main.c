#include <stdio.h>

int foo(){
    return 0;
}

int bar(){
    return 0;
}

int main() {

    int x = foo(); /* Arbitrary value */
    int y = bar(); /* Arbitrary value */

    unsigned ux = x;
    unsigned uy = y;

    (x > 0) || (x-1 < 0);
    (x & 7) != 7 || (x<<29 < 0);
    (x * x) >= 0;
    x < 0 || -x <= 0;
    x > 0 || -x >= 0;
    x+y == uy+ux;
    x*~y + uy*ux == -x;

    return 0;
}
