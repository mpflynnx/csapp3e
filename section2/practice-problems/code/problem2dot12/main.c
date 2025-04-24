#include <stdio.h> // for printf


int main(){


	int x = 0x87654321;
	/*A.*/
	/*int y = x & 0xFF; // 0x21*/

	/*b. invert all bits bar least significant byte*/
	/*int y = x ^ 0xFFFFFF00; // ^ flip selected bits*/

	/*b. the above would only work when a int is 32bits*/
	/*to make it work regardless of word size see below*/
	int y = x ^ ~0xFF; //expected result 0x789abc21

	/*c. set lsb to 1's leave other unchanged [0x876543FF]*/
	/*int y = x | 0xFF; // mask 0xFF least significant bit, | turn on bits*/
	/*0x876543ff*/
	
	return 0;

}
