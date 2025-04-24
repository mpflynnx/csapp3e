#include <stdio.h> // for printf

/*
0	0	0	0	0	1	1	0	
2^7 2^6 2^5 2^4 2^3 2^2 2^1 2^0 = 6
*/

#define MASK 0x6 /* 0000 0110 */

/* Declarations of functions implementing operations bis and bic */

/* set z to 1 at each position where m is 1*/
int bis(int x, int m){
	int z = x | m;
	return z;
}

/* set z to 0 at each position where m is 1*/
int bic(int x, int m){
	int z = x & ~m;
	return z;
}

/* Compute x|y using only calls to functions bis and bic */
int bool_or(int x, int y) {
	int result = bis(x,y);
	return result;
}

/* Compute x^y using only calls to functions bis and bic */
int bool_xor(int x, int y) {
	/*struggled with this*/
	
	/* solution copied from book*/
	/*x ^ y = (x & ~y) | (~x & y)*/
	
	int result = bis(bic(x,y), bic(y,x));
	
	return result;
}


int main(){


	int x = 0xC; /* 0000 1100 */

	/*int result1 = bis(MASK, x);*/
	/*int result2 = bic(MASK, x);*/

	/*int result1 = bool_or(MASK, x);*/
	int result2 = bool_xor(MASK, x);
	/**/
	/*int result3 = x | MASK;*/
	int result4 = x ^ MASK;
	
	return 0;

}
