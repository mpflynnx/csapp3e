#include <stdio.h>
#include <limits.h>

int tmult_ok(char x, char y) {
    char p = x*y;
    /* Either x is zero, or dividing p by x gives y */
    return !x || p/x == y;
}

int main(){

    signed char x, k, p;
    x = 2;
    k = -6;

    printf("%d\n", x);
    printf("%d\n", k);

    if (tmult_ok(x,k)){
        signed char p1, p2, p;
        //p = (x<<2) + (x<<1);  // a. 
        //p1 = (x<<5); // b. 64
        //p2 = (x<<0); // b. 2
        //p = p1 - p2; // b. 64 - 2 = 62 
        //p = (k<<1);  // b. 
        //p = (x<<5) - x; // b.
        //p = (x
        p1 = (x<<3); // c.
        p2 = (x<<1); // c.
        p = ~(p1+p2) + 1;
        //p = p2 - p1;
        printf("result: %d \n", p);
    } else {
        printf("Overflow!\n");
    }

	return 0;

}
