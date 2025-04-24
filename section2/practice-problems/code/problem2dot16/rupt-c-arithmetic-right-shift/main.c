#include <stdio.h>

/* 
 * Portable C signed arithmetic right shift (sar)
 * https://github.com/Rupt/c-arithmetic-right-shift
 * https://godbolt.org/z/GTYT6dfW7
 * $ gcc -O1 -std=c99 -Wall -Wextra -pedantic main.c -o main
*/

/* static inline */ int
sari(int m, char n)
{
    const int logical = (((int) -1) >> 1) > 0;
    unsigned fixu = -(logical & (m < 0));
    int fix = *(int*) &fixu;
    return (m >> n) | (fix ^ (fix >> n));
}

int main()
{
	int mm = -109;
	char mn = 2;
	int result = sari(mm, mn);
    printf("%d\n", result); /*  */
	return 0;
}
