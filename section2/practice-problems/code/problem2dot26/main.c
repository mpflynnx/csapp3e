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
    if (strlonger(s1, t1)){
        printf("s1 is longer");
    }
    else {
        printf("t1 is longer");
    }


	return 0;

}
