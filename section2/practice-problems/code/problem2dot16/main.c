/*
 * Hardback page 58 practice problem
 */

int main(){

	/* For use with gdb debugger
	*  Display 1 byte binary /1bt
	*  (gdb) x /1bt &a1
	*/

	unsigned int a1, a2, a3, a4;
	a1 = 0xC3; /* 11000011 */
	a2 = 0x75; /* 01110101 */
	a3 = 0x87; /* 10000111 */
	a4 = 0x66; /* 01100110 */

	/* left shifting << 3*/
	/* a << 3 */
	unsigned int ls1, ls2, ls3, ls4;
	ls1 = a1 << 3; /* 00011000 */
	ls2 = a2 << 3; /* 10101000 */
	ls3 = a3 << 3; /* 00111000 */
	ls4 = a4 << 3; /* 00110000 */

	/* Logical right shifting >> 2*/
	unsigned int rs1, rs2, rs3, rs4;	
	rs1 = a1 >> 2; /* 00110000 */
	rs2 = a2 >> 2; /* 00011101 */
	rs3 = a3 >> 2; /* 00100001 */
	rs4 = a4 >> 2; /* 00011001 */

	/* Arithmetic right shifting >> 2 */
	int s1, s2, s3, s4;
	s1 = 0xC3; /* 11000011 -109 negative number begins with 1*/
	s2 = 0x75; /* 01110101 */
	s3 = 0x87; /* 10000111 negative number begins with 1*/
	s4 = 0x66; /* 01100110 */

	/* this does produce the expected results*/
	int ars1, ars2, ars3, ars4;	
	ars1 = s1 >> 2; /* 11110000 */
	ars2 = s2 >> 2; /* 00011101 */
	ars3 = s3 >> 2; /* 11100001 */
	ars4 = s4 >> 2; /* 00011001 */

	return 0;

}
