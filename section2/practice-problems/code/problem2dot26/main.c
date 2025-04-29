#include <stdio.h>
#include <string.h> /* Required for strlen() */
#include <stddef.h> /* Required for size_t */

/* WARNING: This function is buggy 
   Determines whether one string is longer than another
*/
int strlonger(char *s, char *t) {
    return strlen(s) - strlen(t) > 0;
    }

int main(){

    char s1[] = "This is my very long long string.";
    char t1[] = "This is a shorter string.";
    char u1[] = "This is a short string.";

    size_t l1 = strlen(s1); // for testing
    size_t l2 = strlen(t1); // for testing
    size_t l3 = strlen(u1); // for testing

    /* Problem
    l3 - l2 = 4294967294
    */

    if (strlonger(u1, t1)){
        printf("u1 is longer\n");
    }
    else {
        printf("t1 is longer\n");
    }


	return 0;

}
