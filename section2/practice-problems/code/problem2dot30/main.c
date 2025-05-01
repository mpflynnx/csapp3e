#include <stdio.h>
#include <limits.h>

/* 
* Returns 1 if arguments x and y can be added without causing overflow.
*/
int tadd_ok(int x, int y){

    // unsigned sum = x + y;
    // return sum >= x;

    // Alternative
    return !((UINT_MAX - x) < y);

}

int main(){

    int x = 4294967289;
    int y = 4294967289;
    
    printf("INT_MAX = %u\n", INT_MAX);
    printf("INT_MIN = %u\n", INT_MIN);

    // if (uadd_ok(x, y)) {
    //     printf("No overflow\n");
    // } else {
    //     printf("Overflow\n");
    // }

	return 0;

}
