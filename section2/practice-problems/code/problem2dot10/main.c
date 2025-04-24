#include <stdio.h> // for printf

void inplace_swap(int *x, int *y){
    *y = *x ^ *y; // Step1
    *x = *x ^ *y; // Step2
    *y = *x ^ *y; // Step3
}

int main(){

    int a = 78; // 01001110, 4e
    int b = 225; // 11100001, e1

    int* ptr_a = &a;
    int* ptr_b = &b;

    inplace_swap(ptr_a, ptr_b);
    
    return 0;

}