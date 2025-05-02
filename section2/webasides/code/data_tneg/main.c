#include <stdio.h>

/*
* Generate mask indicating rightmost 1 in x.
* For example 0xFF00 -> 0x0100, and 0x6600 --> 0x0200.
* If x == 0, then return 0.
*/
int rightmost_one(unsigned x){
    return (x & -x);
}

int main(){

    int x = 0x6600;

    int result = rightmost_one(x);

    return 0;

}
