#include <stdio.h>
#include <limits.h>

int tmult_ok(char x, char y) {
    char p = x*y;
    /* Either x is zero, or dividing p by x gives y */
    return !x || p/x == y;
}

int main(){

    unsigned char x, k, p;
    x = 11;
    k = 4;

    printf("%d\n", x);
    printf("%d\n", k);

    if (tmult_ok(x,k)){
        // p = (k<<3)+(k<<1)+(k<<0); // Form A
        p = (k<<(3+1));  // Form B
        printf("result: %d \n", p);
    } else {
        printf("Overflow!\n");
    }

	return 0;

}
