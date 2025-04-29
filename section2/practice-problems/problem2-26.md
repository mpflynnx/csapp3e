## Practice Problem 2.26 hardback page 83

- [main.c](./code/problem2dot26/main.c)

### Advice on Signed versus Unsigned

- You are given the assignment of writing a function that determines whether one string is longer than another. You decide to make use of the string library function
strlen having the following declaration:
```c
/* Prototype for library function strlen */
size_t strlen(const char *s);
```
- Here is your first attempt at the function:
```c
/* Determine whether string s is longer than string t */
/* WARNING: This function is buggy */
int strlonger(char *s, char *t) {
return strlen(s) - strlen(t) > 0;
}
```
- When you test this on some sample data, things do not seem to work quite right. 
- You investigate further and determine that, when compiled as a 32-bit program, data type size_t is defined (via typedef) in header file stdio.h to be unsigned.

1. For what cases will this function produce an incorrect result?
1. Explain how this incorrect result comes about.
1. Show how to fix the code so that it will work reliably.


### Solutions
1. When `char *s` is smaller than `char *t` the result of `strlen(s) - strlen(t) > 0` will still be `true`

2. Given a `char *s` of length 23 and a `char *t` of length 25.

    - `strlen()` returns size_t (unsigned integer)
    - Subtraction on unsigned integers can cause wrap around.
    - size_t s = 23 - size_t t = 25 = 4294967294
    - Therefore 4294967294 > 0 == true

3. A fix could be to cast the the result of `strlen()` to an `int` then perform the subtraction.
    - (int)strlen(s) - (int)strlen(t) > 0;
    - int s = 23 - int t = 25 = -2
    - Therefore -2 > 0 == false

Also: Why is function returning a int? It is returning a bool?    

### Alternatively:
The function could be


```c
#include <stdbool.h> // For bool, true, false
#include <string.h>  // For strlen

bool strlonger(char *s, char *t) {
    return strlen(s) > strlen(t);
}
```

Better still

```c
bool strlonger(const char *s, const char *t) {
    // Handle NULL pointers
    if (s == NULL) {
        return false; // A NULL string cannot be longer than any string (including another NULL)
    }
    if (t == NULL) {
        return true; // A non-NULL string is considered longer than a NULL string
    }

    // Compare lengths of non-NULL strings
    return strlen(s) > strlen(t);
```