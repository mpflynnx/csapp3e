#include <stdio.h>
#include <limits.h>

int tmult_ok(char x, char y) {
    char p = x*y;
    /* Either x is zero, or dividing p by x gives y */
    return !x || p/x == y;
}

int main(){

    unsigned char x, y, p;
    x = 1;
    y = 0b10001110; // 142

    printf("%d\n", x);
    printf("%d\n", y);

    if (tmult_ok(x,y)){
        p = -(x<<1);
        // p = (x<<8-1) - (x<<1);
        printf("result: %d \n", p);
    } else {
        printf("Overflow!\n");
    }

	return 0;

}
