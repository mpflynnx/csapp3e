#include <stdio.h>

int tmult_ok(int x, int y) {
    int p = x*y;
    /* Either x is zero, or dividing p by x gives y */
    return !x || p/x == y;
}

int main(){

    int x = 0b010;
    int y = 0b111;
    int p;
    
    if (tmult_ok(x,y)){
        p = x * y;
    }

	return 0;

}
