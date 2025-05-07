#include <stdio.h>

/* WARNING: This code is buggy */
/* Shift 1 over by 8*sizeof(long) - 1 */

int main(){

    int long x = 1L;
    x << sizeof(long)<<3 - 1;

    return 0;

}
