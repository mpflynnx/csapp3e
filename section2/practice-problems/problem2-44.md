## Practice Problem 2.44 hardback page 108

- [main.c](../practice-problems/code/problem2dot44/main.c)
- [notes | Power of 2 using left shift operator](../misc.md#power-of-2-using-left-shift-operator)
- [notes | Unsigned Power-of-2 Divide with shift](../misc.md#signed-twos-complement-power-of-2-divide-with-shift-alternative)

### Problem

Assume data type int is 32 bits long and uses a two’s-complement representation for signed values. Right shifts are performed arithmetically for signed values and logically for unsigned values. The variables are declared and initialized as shown in [main.c](../practice-problems/code/problem2dot44/main.c)

For each of the following C expressions, either (1) argue that it is true (evaluates to 1) for all values of x and y, or (2) give values of x and y for which it is false (evaluates to 0):

- A. (x > 0) || (x-1 < 0)
- B. (x & 7) != 7 || (x<<29 < 0)
- C. (x * x) >= 0
- D. x < 0 || -x <= 0
- E. x > 0 || -x >= 0
- F. x+y == uy+ux
- G. x*~y + uy*ux == -x

### Solution

WIP