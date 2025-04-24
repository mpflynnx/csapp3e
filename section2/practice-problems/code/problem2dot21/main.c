#include <stdio.h>
#include <limits.h>

/* comparing bit patterns*/
void expression(int u, int tu){
	if (u < tu) {
		printf("True: u = %u < tu= %d\n", u, tu);
	} else {
		printf("False: u = %u, tu= %d\n", u, tu);
	}	
}

int cornercase(int x){
	if (x < 0){
		return -x;
	} else {
		return x;
	}
}

int main(){

	unsigned int u;
	signed int tu;

	u = -2147483647-1U;
    tu = 2147483647;

	// if (2147483648U == -2147483647-1) {
	// 	printf("True: u = %u == tu = %d\n", u, tu);
	// }

	// expression(u = -2147483647-1, tu = 2147483647);

	/* c. */
	/* -2147483647-1U < 2147483647 */
	/* (tuc - 1U) < tuc2 */

	__uint32_t umax = UINT_MAX;
	signed tuc = -2147483647;
	unsigned int uc = (unsigned int)tuc; /* 2147483649*/
	// unsigned int uc = tuc; /* 2147483649*/
	/* u2 - 1U */
	unsigned resultc = uc - 1; /* 2147483648 */
	unsigned tuc2 = 2147483647;

	if (resultc < tuc2) {
		printf("c. True: u = %u < tu = %u\n", resultc, tuc2);
	} else {
		printf("c. False: u = %u > tu = %u\n", resultc, tuc2);
	}



	/* e. */
	/* -2147483647-1U < -2147483647 */
	/* (tu2 - 1U) < tu2 */
	signed tue = -2147483647;
	unsigned int ue = tue; /* 2147483649*/
	/* u2 - 1U */
	unsigned resulte = ue - 1; /* 2147483648 */

	if (resulte < ue) {
		printf("e. True: u = %u < tu = %u\n", resulte, ue);
	}

	/* tmin will be returned*/
	// int cc = cornercase(-2147483647-1);


	return 0;

}
