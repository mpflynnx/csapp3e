## Practice Problem 2.35 hardback page 99

- [main.c](../practice-problems/code/problem2dot35/main.c)
- [≠ Not Equal Symbol used in the book](https://wumbo.net/symbols/not-equal/)

### Multiplication

- You are given the assignment to develop code for a function `tmult_ok` that will
determine whether two arguments can be multiplied without causing overflow.
Here is your solution:
```c
/* Determine whether arguments can be multiplied without overflow */
int tmult_ok(int x, int y) {
    int p = x*y;
    /* Either x is zero, or dividing p by x gives y */
    return !x || p/x == y;
}
```
- You test this code for a number of values of x and y, and it seems to work properly. 
- Your coworker challenges you, saying, "If I can’t use subtraction to test whether addition has overflowed (see Problem 2.31), then how can you use division to test whether multiplication has overflowed?"
- Devise a mathematical justification of your approach, along the following lines. First, argue that the case x = 0 is handled correctly. 
- Otherwise, consider w-bit numbers x (x not equal to 0), y, p, and q, where p is the result of performing two's complement multiplication on x and y, and q is the result of dividing p by x.
1. Show that x . y, the integer product of x and y, can be written in the form x . y = p + t2w , where t not equal to 0 if and only if the computation of p overflows.
2. Show that p can be written in the form p = x . q + r, where |r| < |x|.
3. Show that q = y if and only if r = t = 0.