#include <stdio.h>
#include <limits.h>

int main(){

    printf("INT_MAX = %d\n", INT_MAX);
    printf("INT_MIN = %d\n", INT_MIN);
    printf("UINT_MAX = %u\n", UINT_MAX);

    int x = 2147483647 + 1; /* A */

    return 0;

}
