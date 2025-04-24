#include <stdio.h>

/* 
* (gdb) x /4bt &word
* 0x7fffffffdecc:	01110110	00000000	00000000	00000000
*/
int fun1(unsigned word) {
	return (int) ((word << 24) >> 24);
}

/*
* (gdb) x /4bt &word
* 0x7fffffffdecc:	01110110	00000000	00000000	00000000
*/
int fun2(unsigned word) {
	return ((int) word << 24) >> 24;
}

int main(){

	// unsigned word = 0x00000076;
/* fun1
* (gdb) x /4bt &word
* 0x7fffffffdecc:	01110110	00000000	00000000	00000000
*/
/* fun2
* (gdb) x /4bt &word
* 0x7fffffffdecc:	01110110	00000000	00000000	00000000
*/


	// unsigned word = 0x87654321; // negative number
// fun1
// 	(gdb) x /4bt &word
// 0x7fffffffdecc:	00100001	01000011	01100101	10000111
// fun2
// (gdb) x /4bt &word
// 0x7fffffffdecc:	00100001	01000011	01100101	10000111


	unsigned word = 0xEDCBA987; // negative number

// 	fun1
// 	(gdb) x /4bt &word
// 0x7fffffffdecc:	10000111	10101001	11001011	11101101
// fun2
// (gdb) x /4bt &word
// 0x7fffffffdecc:	10000111	10101001	11001011	11101101

	fun1(word);
	fun2(word);

	return 0;

}
