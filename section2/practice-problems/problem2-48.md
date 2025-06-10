## Practice Problem 2.48 hardback page 119

- [main.c](../practice-problems/code/problem2dot48/main.c)
- [notes | Floating point numbers](../misc.md#floating-point-numbers)

### Problem

As mentioned in Problem 2.6, the integer 3,510,593 has hexadecimal representation 0x00359141, while the single-precision floating-point number 3,510,593.0 has hexadecimal representation 0x4a564504. Derive this floating-point representation and explain the correlation between the bits of the integer and floating-point representations.

#### Solution

#### main.c
```c
#include <stdio.h>

int main() {

    int i = 3510593;
    float f = i;

    return 0;
}
```
#### gdb usage
```bash
(gdb) x /x &i
0x7fffffffdeec:	0x00359141
(gdb) x /t &i
0x7fffffffdeec:	00000000001101011001000101000001

(gdb) x /x &f
0x7fffffffdee8:	0x4a564504
(gdb) x /t &f
0x7fffffffdee8:	01001010010101100100010100000100
```
**binary bit pattern**

1. int i bit pattern

    00000000001101011001000101000001


- s field: 
    - 3510593 is positive so signed bit is `0`
    - s field is `0`
- exp field:
    - 3510593 in binary is 00000000001101011001000101000001
    - Drop the leading 0's
    - Normalize number, express the binary number in the form of 1.xxxxxx * 2^exponent.
    - shift the binary point until it is immediately after the leading '1'. 
    - The number of positions the binary point is shifted determines the exponent.
    - 21 shifts were needed here
    - 1.101011001000101000001 x 2^21
    - The exponent is 21.

- frac field:
    - The mantissa is the fractional part after the leading 1.
    - 1.101011001000101000001
    - Mantissa M = 101011001000101000001
    - Since the mantissa needs to be 23 bits, we pad it with 2 trailing zeros:
    - frac field = 10101100100010100000100 // 23 bits

- Exponent
    - The exponent 21 needs to be biased by 127 (for single precision).
    - Biased exponent = 21 + 127 = 148
    - Now, convert 148 to an 8-bit binary number:
    - Exp (value of exp field bits) = 10010100 is 148
    - check formula, E = Exp - bias = 148 - 127 = 21


- Result
    - Assemble the s, exp and frac fields

    |s|exp|frac
    |--|--|--|
    |0|10010100|10101100100010100000100|

- Bit correlation
```
   0   0   3   5   9   1   4   1 Hex
   |   |   |   |   |   |   |   |
00000000001101011001000101000001 Binary
           *********************  Correlation
  01001010010101100100010100000100 Binary
     |   |   |   |   |   |   |   |
     4   a   5   6   4   5   0   4 Hex
       
```
We can now see that the region of correlation corresponds to the low-order bits of the integer, stopping just before the most significant bit equal to 1 (this bit forms the implied leading 1), matching the high-order bits in the fraction part of the floating-point representation.