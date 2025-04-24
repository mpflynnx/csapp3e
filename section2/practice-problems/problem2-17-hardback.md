## Practice Problem 2.17 

- book hardback page 66 different to global edition

Assuming length w = 4 (w for word size), we can assign a numeric value to each possible hexadecimal
digit, assuming either an unsigned or a two’s-complement interpretation. Fill in
the following table according to these interpretations by writing out the nonzero
powers of 2 in the summations shown in Equations 2.1 and 2.3:

Binary To(2) Two's complement (B2Tw) w = length

Two's complement To(2) Binary (T2Bw)

Binary To(2) U

|| Hexadecimal | 2^n (binary) |B2Uw(x)|B2Tw(x)|T2Uw(x)
|---|---|---|---|---|---|
|-|0xE|1110|2^3 + 2^2 + 2^1 = 14|-2^3 + 2^2 + 2^1=-2||
|[a.](#a)|0x0|0000|0|0||
|[b.](#b.)|0x5|0101|2^2 (4) + 2^0 (1) = 5|2^2 (4) + 2^0 (1) = 5||
|[c.](#c.)|0x8|1000|2^3 (8) = 8|-2^3 (8) = -8||
|[d.](#d.)|0xD|1101|2^3 (8) + 2^2(4) + 2^0 (1) = 13|2^3 (-8) + 2^2(4) + 2^0 (1) = -3 ||
|[e.](#e.)|0xF|1111|2^3(8) + 2^2(4) + 2^1(2)+ 2^0(1) = 15|-2^3(-8) + 2^2(4) + 2^1(2)+ 2^0(1) = -1||



### a.
0x0 to binary 

0x0 = 0 Decimal
0 decimal = 0000 binary 

Binary To Two's complement
B2Tw

-2^3 + 2^2 + 2^1 + 2^0

0+0+0+1 = 1

|| Hexadecimal | 2^n (binary) |B2Uw(x)|B2Tw(x)|
|---|---|---|---|---|
|[a.](#a-convert-decimal-to-binary-and-hexadecimal)|0x0|0000|0|0

### b.
0x5 to binary 

0x5 = 5 Decimal
5 decimal = 0101 binary 
2^2 (4) + 2^0 (1) = 5
0101

Binary To Two's complement
B2Tw

2^2 (4) + 2^0 (1) = 5

|| Hexadecimal | 2^n (binary) |B2Uw(x)|B2Tw(x)|
|---|---|---|---|---|
|[b.](#b.)|0x5|0101|2^2 (4) + 2^0 (1) = 5|2^2 (4) + 2^0 (1) = 5

### c.
0x8 to binary 

0x8 = 8 Decimal
8 decimal = 1000 binary 
2^3 (8) = 8
1000

Binary To Two's complement
B2Tw

-2^3 = -8

-8+0+0+0 = -8

|| Hexadecimal | 2^n (binary) |B2Uw(x)|B2Tw(x)|
|---|---|---|---|---|
|[c.](#c.)|0x8|1000|2^3 (8) = 8|-2^3 (8) = -8|

### d.

0xD to binary 

0xD = 13 Decimal
13 decimal = 1101 binary 
2^3 (8) + 2^2(4) + 2^0 (1) = 13
1101


Binary To Two's complement
B2Tw
-2^3 (-8) + 2^2(4) + 2^0 (1) = -3

-8+4+1 = -3

|| Hexadecimal | 2^n (binary) |B2Uw(x)|B2Tw(x)|
|---|---|---|---|---|
|[d.](#d.)|0xD|1101|2^3 (8) + 2^2(4) + 2^0 (1) = 13|2^3 (-8) + 2^2(4) + 2^0 (1) = -3 |

### e.

0xF to binary 

0xF = 15 Decimal
15 decimal = 1111 binary 
2^3 (8) + 2^2(4) + 2^1(2)+ 2^0(1) = 15
1111


Binary To Two's complement
B2Tw
-2^3 (-8) + 2^2(4) + 2^1(2)+ 2^0(1) = -1



|| Hexadecimal | 2^n (binary) |B2Uw(x)|B2Tw(x)|
|---|---|---|---|---|
|[e.](#e.)|0xF|1111|2^3(8) + 2^2(4) + 2^1(2)+ 2^0(1) = 15|-2^3(-8) + 2^2(4) + 2^1(2)+ 2^0(1) = -1|


The unsigned values correspond to those in [Figure 2.2](/section2.md#figure-22). 

For the two’s-complement values, hex digits 0 through 7 have a most significant bit of 0, yielding non negative values, while hex digits 8 through F have a most significant bit of 1, yielding a negative value.

### Figure 2.2b showing two's complement decimal

| Hex | B2T(X) | X |Power of 2 | Hints |
|---|---|---|---|---|
| 0 | 0 | 0000 |2^0|
| 1 | 1 | 0001 ||
| 2 | 2 | 0010 |2^1|
| 3 | 3 | 0011 ||
| 4 | 4 | 0100 |2^2|
| 5 | 5 | 0101 ||
| 6 | 6 | 0110 ||
| 7 | 7 | 0111 ||
| 8 | -8 | 1000 |2^3|
| 9 | -7 | 1001 ||
| A | -6 | 1010 ||*Easy to remember as A
| B | -5| 1011 |
| C | -4 | 1100 ||*Easy to remember as C
| D |  -3| 1101 ||
| E |  -2| 1110 ||
| F |  -1| 1111 ||*Easy to remember as F

### External references
- [Hex Calculator](https://www.calculator.net/hex-calculator.html)