## Practice Problem 2.44 hardback page 108

- [main.c](../practice-problems/code/problem2dot44/main.c)
- [notes | Power of 2 using left shift operator](../misc.md#power-of-2-using-left-shift-operator)
- [notes | Integer C puzzles](../misc.md#integer-c-puzzles)

### Problem

Assume data type int is 32 bits long and uses a two’s-complement representation for signed values. Right shifts are performed arithmetically for signed values and logically for unsigned values. The variables are declared and initialized as shown in [main.c](../practice-problems/code/problem2dot44/main.c)

```c
int x = foo(); /* Arbitrary value */
int y = bar(); /* Arbitrary value */

unsigned ux = x;
unsigned uy = y;
```

For each of the following C expressions, either (1) argue that it is true (evaluates to 1) for all values of x and y, or (2) give values of x and y for which it is false (evaluates to 0):

- [a.](#a) (x > 0) || (x-1 < 0)
- [b.](#b) (x & 7) != 7 || (x<<29 < 0)
- [c.](#c) (x * x) >= 0
- [d.](#d) x < 0 || -x <= 0
- [e.](#e) x > 0 || -x >= 0
- [f.](#f) x+y == uy+ux
- [g.](#g) x*~y + uy*ux == -x

### Solutions

Good edge cases to test for
- Tmin = -2147483647-1
- TMax = 2147483647

#### a.
- (x > 0) || (x-1 < 0)
-  OR ( || ) operator, if the first operand is true , then the second operator is not evaluated
- x > 0, i.e is x positive
- x-1 < 0, i.e is x-1 negative
- if x = Tmin, neither case is ever true
- (x > 0) is false
- Tmin-1 = 2147483647 
- (x-1 < 0) is false

#### b.
- (x & 7) != 7 || (x<<29 < 0)
- 7 is lower order bits as 111, i.e this bits set 2^2, 2^1, 2^0
- x & 7 masks off 7 from x, so we just look at these 3 lower order bits
- these bits all set to 1 is 7 decimal
- (x & 7) != 7  is false if all these bits are set to 1
-  OR ( || ) operator, if the first operand is true , then the second operator is not evaluated
- (x<<29) shifts the last three bits 2^2, 2^1 and 2^0 to the msb, msb-1, msb-2, means msb is 1 which represents negative in twos-complement
- (x<<29) < 0 is true if x's 2^2 bit is set

#### c.
- (x * x) >= 0
- Does doubling a number always result in 0 or a positive number?
- True, If the number is positive and the result doesn't set the signed bit (msb) to 1.
- if x = 65535, False as x*x will result in a number with the signed bit set as this is a negative number.

#### d.

- x < 0 || -x <= 0
- x < 0, is true if x negative
- -x <= 0, is true is -x negative or 0
- True, tested with x as Tmin and x as TMax

#### e.
- x > 0 || -x >= 0
#### f.
#### g.