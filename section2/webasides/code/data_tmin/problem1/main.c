#include <stdio.h>

/*
 All of these variations can be summarized by the table shown
 in Figure 2. For the cases where the result has type long 
 or long long, the constant is negative, but it is 64 bits long. 
 For the cases where the result has type unsigned, the constant 
 is positive and 32 bits long. These outcomes can be demonstrated 
 by the following code:
*/


int main(){

    int dpos32 = (-2147483648 > 0);
    int hpos32 = (0x80000000 > 0);

    return 0;

}

/*

These lines of code attempt to express TMin 32 as a decimal
or hexadecimal constant and test whether the value is greater
than zero. Depending on the compiler version and word size, 
we find that the value of dpos32 can be either 1 or 0, 
indicating that the decimal constant can be either positive 
or nonnegative, while the value of hpos32 is consistently 1, 
indicating that the hexadecimal constant is consistently positive. 
Our seemingly simple task of writing TMin 32 as a constant 
is more difficult than might be expected!

*/
