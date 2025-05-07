#include <stdio.h>
#include <limits.h>

int main(){

    printf("INT_MAX = %d\n", INT_MAX);
    printf("INT_MIN = %d\n", INT_MIN);
    printf("UINT_MAX = %u\n", UINT_MAX);

    // int x = 2147483647 + 1; /* A */
    
    // int x = 0x7FFFFFFF + 1; /* B */
    
    // int x = 2147483649 - 1; /* C */
    
    // long long x = 2147483649L; /* C understanding*/
    // long long y = x - 1; /* C understanding */
    // int z = y; /* C understanding */

    // unsigned x = 0x80000001; /* D Understanding*/
    // unsigned y = x - 1; /* D Understanding*/
    // int z = y; /* D Understanding*/

    int x = -(2147483649 - 1); /* E */

    return 0;

}

