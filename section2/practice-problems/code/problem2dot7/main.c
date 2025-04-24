/*
*  This program is a simple example of how to use the show_bytes function to print the bytes of a variable.
* The show_bytes function is a simple function that takes a pointer to a variable and the size of the variable
* and prints the bytes of the variable in hexadecimal format.
* The show_int, show_float, and show_pointer functions are just wrappers for the show_bytes function.
* The test_show_bytes function is a simple test function that demonstrates how to use the show_bytes function.
* The test_show_bytes function takes an integer value as input and prints the bytes of the integer value, the float value
* of the integer value, and the pointer value of the integer value.
* The main function is just a simple main function that calls the test_show_bytes function with an integer value.
* The output of the program is the bytes of the integer value, the float value of the integer value, and the pointer value of the integer value.
* The output of the program is in hexadecimal format.

* https://github.com/quchunguang/test/blob/dd1dde14a69d9e8b2c9ed3efbf536df7840f0487/bookcsapp/code/data/show-bytes.c
*
*/

#include <stdio.h> // for printf
#include <string.h> // for strlen()

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len){
    size_t i;
    for(i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x){
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x){
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x){
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val){
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}


int main(){

    // const char s[] = "abcdef";
    const char *s = "abcdef";
    show_bytes((byte_pointer) s, strlen(s));

    return 0;

}
