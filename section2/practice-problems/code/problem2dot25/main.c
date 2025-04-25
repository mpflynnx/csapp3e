#include <stdio.h>

/* WARNING: This code is buggy */
float sum_elements(float a[], unsigned length){

    float result = 0;

    for (int i = 0; i <= length-1; i++){
        result += a[i];
    }

    return result;

}

int main(){

    float a[] = {0,1,2,3};
    sum_elements(a, 0);

	return 0;

}
