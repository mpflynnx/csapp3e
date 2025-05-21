#include <stdio.h>

/* Divides x by 2^k*/
int divideByK(const int x, const int k){
    int mask = (1<<k) - 1;
    int bias = (x>>31) & mask;
    int result = (x + bias) >> k;
    return result;
}


int main() {

    int x = -12340;
    int result = divideByK(x, 4);

    return 0;
}
