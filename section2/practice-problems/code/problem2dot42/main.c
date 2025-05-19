#include <stdio.h>

int div16(const int x){
    return (int) x >>4;
}


int main() {

    int x = 80; // 80/16 = 5
    int result = div16(x);

    return 0;
}
