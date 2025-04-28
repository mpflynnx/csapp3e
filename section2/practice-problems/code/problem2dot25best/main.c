#include <stddef.h> // Required for size_t
#include <stdio.h>

/* This code is best practice */
float sum_elements(float a[], size_t length){

    float result = 0;

    for (size_t i = 0; i < length; ++i){
        result += a[i];
    }

    return result;

}

int main(){

    float a[] = {0.0,1.0,2.0,3.0,4.0};
    sum_elements(a, (sizeof(a) / sizeof(a[0])));

	return 0;

}
