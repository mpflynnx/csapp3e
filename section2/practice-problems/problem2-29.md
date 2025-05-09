## Practice Problem 2.29 hardback page 93

### Two's-Complement Addition

- [Notes](../misc.md#twos-complement-arithmetic)

- Fill in the following table in the style of Figure 2.25. 
- Give the integer values of the 5-bit arguments, the values of both their integer sum (x + y) and two’s-complement sums (x+t/w*y),
the bit-level representation of the two’s-complement sum, and the case from the derivation of Equation 2.13.

- w = 5
- TMin(w) = -(2^w-1) = -(2^4) = -16
- TMax(w) = (2^w-1)-1 = (2^4)-1 = 16 -1 = 15

- Case 1 is when integer sum is less than TMin(w) i.e Negative Overflow
- Case 2 is when the Two's complement sum is equal to integer sum negative 
- Case 3 is when the Two's complement sum is equal to integer sum positive
- Case 4 is when integer sum exceeds TMax(w) i.e Positive Overflow

- x + y is integer sum
- x+t/5y is Two's complement sum

||||||||
|---|---|---|---|---|---|---|
||x|y|x+y|x+t/5y|Case
|[a.](#a)|10100|10001|_|_|1
|[b.](#b)|11000|11000|_|_|2
|[c.](#c)|10111|01000|_|_|2
|[d.](#d)|00010|00101|_|_|3
|[e.](#e)|01100|00100|_|_|4


### Solution

### a. `10100 + 10001`
|||||||||
|---|---|---|---|---|---|---|---|
||4|3|2|1|0
|-32|-16|8 |4 |2 |1 | Binary position value |
| 1|| | | | |  | carries
| |1|0|1|0|0| = -12 | Two's complement
||1|0|0|0|1| = -15 | Two's complement
|1|0| 0| 1| 0| 1| = -27 | x + y
|**x**|0| 0| 1| 0| 1| = 5 | Ignored msb

**Note:** 
- Adding two negative numbers should not give a positive number.
- -27 is less than TMin of -16, this is Case 1 or Negative overflow

### b. `11000 + 11000`
|||||||||
|---|---|---|---|---|---|---|---|
||4|3|2|1|0
|-32|-16|8 |4 |2 |1 | Binary position value |
| |1| | | | |  | carries
| |1|1|0|0|0| = -8 | Two's complement
||1|1|0|0|0| = -8 | Two's complement
|1|1| 0| 0| 0| 0| = -16 | x + y
|**x**|1| 0| 0| 0| 0| = -16 | Ignored msb

**Note:** Case 2 two's complement sum matches integer sum (x + y)

### c. `10111 + 01000`
|||||||||
|---|---|---|---|---|---|---|---|
||4|3|2|1|0
|-32|-16|8 |4 |2 |1 | Binary position value |
| | | | | | |  | carries
| |1|0|1|1|1| = -9  | Two's complement
||0|1|0|0|0| = 8 | Two's complement
||1| 1| 1| 1| 1| = -1 | x + y
||x| 1| 1| 1| 1| = -1 | Ignored msb

**Note:** Case 2 two's complement sum matches integer sum (x + y)

### d. `00010 + 00101`

|||||||||
|---|---|---|---|---|---|---|---|
||4|3|2|1|0
|-32|-16|8 |4 |2 |1 | Binary position value |
| | | | | | |  | carries
| |0|0|0|1|0| = 2  | Two's complement
||0|0|1|0|1| = 5 | Two's complement
|0|0| 0| 1| 1| 1| = 7 | x + y
|**x**|0| 0| 1| 1| 1| = 7 | Ignored msb

**Note:** Case 3 two's complement sum matches integer sum (x + y)

### e. `01100 + 00100`

|||||||||
|---|---|---|---|---|---|---|---|
||4|3|2|1|0
|-32|-16|8 |4 |2 |1 | Binary position value |
| |1|1 | | | |  | carries
| |0|1|1|0|0| = 12  | Two's complement
| |0|0|1|0|0| = 4 | Two's complement
|0|1|0|0|0|0| = 16 | x + y
|**x**|1|0|0|0|0| = -16 | Ignored msb

**Note:** 
- Adding two positive numbers should not give a negative number.
- 16 exceeds TMax of 15, this is Case 4 or Positive overflow
