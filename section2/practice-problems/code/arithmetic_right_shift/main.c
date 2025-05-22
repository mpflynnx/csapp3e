#include <stdio.h>
#include <math.h> // for pow

int divideByK(const int x, const int k){
    int mask = (1<<k) - 1;
    int bias = (x>>31) & mask;
    int result = (x + bias) >> k;
    return result;
}

int main() {
    // Integer division
    // Arithmetic right shift no bias, rounds away from zero
    int x =  -12340;
    int k;

    k = 1; // x>>k divides x by 2^k, x/1
    int divideBy2 = x >> k; // Real -6170.0, actual -6170
    
    k = 4; // x>>k divides x by 2^k, x/16
    int divideBy16 = x >> k; // Real -771.25, actual -772
    
    k = 8; // x>>k divides x by 2^k, x/256
    int divideBy256 = x >> k; // Real -48.203125, actual -49

    // Arithmetic right shift with bias (2^k - 1), rounds towards zero
    int bias;

    k = 1; // x>>k divides x by 2^k, x/1
    bias = pow(2,k) - 1; // 2 - 1
    divideBy2 = (x + bias) >> k; // Real -6170.0, actual -6170
    
    k = 4; // x>>k divides x by 2^k, x/16
    bias = pow(2,k) - 1; // 16 - 1
    divideBy16 = (x + bias) >> k; // Real -771.25, actual -771
    
    k = 8; // x>>k divides x by 2^k, x/256
    bias = pow(2,k) - 1; // 256 - 1
    // bias = (1<<k)-1 // 1<<k same as using pow(2,k) - 1
    divideBy256 = (x + bias) >> k; // Real -48.203125, actual -48

    int check = (x<0 ? x+(1<<k)-1 : x) >> k; // C expression for negative numbers
   
    x =  -12340;
    k = 4; // x>>k divides x by 2^k, x/16
    check = divideByK(x,k);  // -771  

    return 0;
}
