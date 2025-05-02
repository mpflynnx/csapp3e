#include <stdio.h>
#include <limits.h>

/*
* Generate mask indicating rightmost 1 in x.
* For example 0xFF00 -> 0x0100, and 0x6600 --> 0x0200.
* If x == 0, then return 0.
*/
int rightmost_one(unsigned x){
    return;
}

int main(){

    printf("UINT_MAX = %d\n", UINT_MAX);

    unsigned x = 0xFF00;

    rightmost_one(x);

    return 0;

}
