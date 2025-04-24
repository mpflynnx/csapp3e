#include <stdio.h>

int main (){

	/* signed verse unsigned arithmetic gotchas*/

	unsigned int i; /* unsigned watch out i will alway be equal to or greater than 0*/

	for (i = n-1; i >= 0; i--){

		// use i to loop over array

		/* i could go to UMax as i unsigned
		* out of array bound
		
		*/
	}

	int j; // this is signed int

	// watch out sizeof returns an unsigned value 
	for (j = n-1; j - sizeof(char) >= 0; j--){

		// would do a unsigned comparison (not what was wanted here)
		// use i to loop over array

		/* i could go to UMax as i unsigned
		* out of array bound
		
		*/
	}

	return 0;
}