## Practice Problem 2.39 hardback page 103

- [main.c](../practice-problems/code/problem2dot39/main.c)
- [notes | multiplication using left shift](../misc.md#multiplication-by-power-of-2-using-left-shift)

#### Example 1b

- if `x` is `2`
- if `y` is `14`
- 142 in binary is 10001110 

```
Unsigned char
87654321 Bit count
76543210 Bit position
10001110 142 Decimal
^     ^
n     m  n=8-1, m=1
```
- Form A:
- (x<<n) + (x<<(n-1)) + (x<<m)
- (2<<3) + (2<<(3-1)) + (2<<1)

- Form B:
- (x<<(n+1)) - (x<<m)
- (2<<(7+1)) - (2<<1)

### Problem

How could we modify the expression for `Form B` for the case where bit position n is the most significant bit?

- Form B:
- (x<<(n+1)) - (x<<m)

```
76543210 Bit position
10001110 
^     ^
n     m n=7, m=1
```

### Solution

WIP

