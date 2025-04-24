#include <stdio.h> // for printf

void inplace_swap(int *x, int *y){
    *y = *x ^ *y; // Step1
    *x = *x ^ *y; // Step2
    *y = *x ^ *y; // Step3
}

void reverse_array(int a[], int cnt){
    int first, last;
    // for (first = 0, last = cnt -1; first <= last; first++, last--){ doesn't work with odd numbers
    for (first = 0, last = cnt -1; first < last; first++, last--){
    	inplace_swap(&a[first], &a[last]);
	}

}

int main(){

    int x = 42424242; // for gdb usage

    //int a[] = {1,2,3,4};
	int a[] = {1,2,3,4,5};

    reverse_array(a, 5);
    
    return 0;

}
