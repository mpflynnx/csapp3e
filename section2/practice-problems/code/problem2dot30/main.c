#include <stdio.h>
#include <limits.h>

int uadd_ok(unsigned x, unsigned y){

    // unsigned sum = x + y;
    // return sum >= x;

    // Alternative
    return !((UINT_MAX - x) < y);

}

int main(){

    unsigned x = 4294967289;
    unsigned y = 7;
    
    printf("UINT_MAX = %u\n", UINT_MAX);

    if (uadd_ok(x, y)) {
        printf("No overflow\n");
    } else {
        printf("Overflow\n");
    }

	return 0;

}
