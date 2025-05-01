#include <stdio.h>
#include <limits.h>

/* 
* Returns 1 if arguments x and y can be added without causing overflow.
* Adding two positive numbers should not give a negative number.
* Adding two negative numbers should not give a positive number.
* Adding a positive number and a negative number should not give INT_MAX 
* Adding a negative number and a positive number should not give INT_MIN.

*/
// int tadd_ok(int x, int y){

//     int sum = x + y;
//     return !(sum <= 0);
//     // return sum >= x;

//     // Alternative
//     // return !((UINT_MAX - x) < y);

// }

int main(){

    printf("INT_MAX = %d\n", INT_MAX);
    printf("INT_MIN = %d\n", INT_MIN);

    int x = 2147483640;
    int y = 48;
    
    int sum = x + y;

    if (sum >= INT_MAX || sum <= INT_MIN){
        printf("Overflow\n");
    }

    // if (x < 0 && y < 0 && sum <= 0) {
    //     printf("No negative overflow\n");
    // } else if (x > 0 && y > 0 && sum >= 0){
    //     printf("No positive overflow\n");
    // } else {
    //     printf("Overflow\n");
    // }

	return 0;

}
