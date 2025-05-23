#include <stdio.h>
#include <limits.h>

int tmult_ok(char x, char y) {
    char p = x*y;
    /* Either x is zero, or dividing p by x gives y */

    printf("True result: %d \n", p);
    return !x || p/x == y;
}

int main(){

    signed char x, k, p;
    x = 2;
    k = 6;

    printf("%d\n", x);
    printf("%d\n", k);

    if (tmult_ok(x,k)){
        signed char p1, p2, p;


       // p = (x<<1) + (x<<0); // for k = 3

        //p = (x<<(3+1)) - (x<<1);
        //p = (x<<3) + (x<<2) + (x<<1); // for k = 14
        //p = (x<<4) - (x<<1);
        //p = (x<<2) + (x<<1);  // a. Form A for K =6 
        p = (x<<3) - (x<<1); // a. Form b for K = 6
        //p1 = (x<<5); // b. 64
        //p2 = (x<<0); // b. 2
        //p = p1 - p2; // b. 64 - 2 = 62 
        //p = (k<<1);  // b. 
        //p = (x<<5) - x; // b.
        //p = (x
        //p1 = (x<<3); // c.
        //p2 = (x<<1); // c.
        //p = ~(p1+p2) + 1;
        //p = p2 - p1;
        //
        //p1 = (x<<6);
        //p2 = (x<<3);
        //p = (p1 - p2) - (x<<0); // d. for k = 55
        

        printf("Left shift result: %d \n", p);
    } else {
        printf("Overflow!\n");
    }

	return 0;

}
