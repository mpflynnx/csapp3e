#include <stdio.h> // for printf

int main(){

	/* problem 2.14*/
	// char a = 0x55; /*1010101*/
	// char b = 0x46; /*1000110*/

	// char a1 = a & b;
	// char a2 = a | b;
	// char a3 = ~a | ~b;
	// char a4 = a & !b;
	// char a5 = a && b;
    // char a6 = a || b;
	// char a7 = !a || !b;
	// char a8 = a && ~b;

	/*problem 2.15*/
	char x = 0x56; /*1010101*/
	char y = 0x55; /*1010101*/

	// char a10 = !(x & ~y);
	char a10 = !(x ^ y);

	return 0;

}
