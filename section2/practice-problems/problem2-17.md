## Practice Problem 2.17 

- book global edition page 95 (detailed here)
- book hardback page 66 (different)

Assuming length w = 4, we can assign a numeric value to each possible hexadecimal
digit, assuming either an unsigned or a two’s-complement interpretation. Fill in
the following table according to these interpretations by writing out the nonzero
powers of 2 in the summations shown in Equations 2.1 and 2.3:

Binary To(2) Two's complement (B2Tw) w = length

Two's complement To(2) Binary (T2Bw)

Binary To(2) U

|| Hexadecimal | 2^n (binary) |B2Uw(x)|B2Tw(x)|
|---|---|---|---|---|
|-|0xA|1010|2^3 + 2^1 = 10|-2^3+2^1=-6
|[a.](#a)|0x1|?|?|
|[b.](#b)|0xB|?|?|
|[c.](#c)|0x2|?|?|
|[d.](#d)|0x7|?|?|
|[e.](#e)|0xC|?|?|


### Example
0xA to binary 

0xA = 10 Decimal
10 decimal = 1010 binary 
2^3 (8) + 2^1 (2) = 10

Binary To Two's complement
B2Tw

2^3 + 2^2 + 2^1 + 2^0
-8 + 0 + 2 +0 = -6

### a.
0x1 to binary 

0x1 = 1 Decimal
1 decimal = 0001 binary 
2^0 (1) = 1

Binary To Two's complement
B2Tw

-2^3 + 2^2 + 2^1 + 2^0

0+0+0+1 = 1

|| Hexadecimal | 2^n (binary) |B2Uw(x)|B2Tw(x)|
|---|---|---|---|---|
|[a.](#a-convert-decimal-to-binary-and-hexadecimal)|0x1|0001|1|1

### b.
0xB to binary 

0xB = 11 Decimal
11 decimal = 1101 binary 
2^3 (8) + 2^1 (2) + 2^0 (1) = 11
1011

Binary To Two's complement
B2Tw

-2^3 + 2^1 + 2^0 = -5

-8+0+2+1 = -5

|| Hexadecimal | 2^n (binary) |B2Uw(x)|B2Tw(x)|
|---|---|---|---|---|
|[b.](#b.)|0xB|1011|2^3 (8) + 2^1 (2) + 2^0 (1) = 11|-2^3 + 2^1 + 2^0 = -5

### c.
0x2 to binary 

0x2 = 2 Decimal
2 decimal = 0010 binary 
2^1 (2) = 2
0010

Binary To Two's complement
B2Tw

-2^3 + 2^2 + 2^1 + 2^0 = 2

-0+0+2+0 = 2

|| Hexadecimal | 2^n (binary) |B2Uw(x)|B2Tw(x)|
|---|---|---|---|---|
|[c.](#c.)|0x2|0010|2^1=2|2^1 = 2|

### d.

0x7 to binary 

0x7 = 11 Decimal
11 decimal = 1101 binary 
2^3 (0) + 2^2(4) + 2^1 (2) + 2^0 (1) = 7
0111

2^3 (0) + 2^2(4) + 2^1 (2) + 2^0 (1) = 7

Binary To Two's complement
B2Tw
-2^3 (0) + 2^2(4) + 2^1 (2) + 2^0 (1) = 7

-0+4+2+1 = 7

|| Hexadecimal | 2^n (binary) |B2Uw(x)|B2Tw(x)|
|---|---|---|---|---|
|[d.](#d.)|0x7|0111|2^2(4) + 2^1 (2) + 2^0 (1) = 7| 2^2(4) + 2^1 (2) + 2^0 (1) = 7|

### e.

0xC to binary 

0xC = 12 Decimal
12 decimal = 1101 binary 
2^3 (8) + 2^2(4) = 12
1100

2^3 (8) + 2^2 (4) = 12

Binary To Two's complement
B2Tw
-2^3 (8) + 2^2 (4) = -4

-8+4 = -4

|| Hexadecimal | 2^n (binary) |B2Uw(x)|B2Tw(x)|
|---|---|---|---|---|
|[e.](#e.)|0xC|1101|2^3 (8) + 2^2 (4) = 12| -2^3 (8) + 2^2 (4) = -4|




### Answers

|| Hexadecimal | 2^n (binary) |B2Uw(x)|B2Tw(x)|
|---|---|---|---|---|
|-|0xA|1010|2^3 + 2^1 = 10|-2^3+2^1=-6
|[a.](#a)|0x1|0001|2^0=1|2^0=1
|[b.](#b)|0xB|1011|2^3 (8) + 2^1 (2) + 2^0 (1) = 11|-2^3 + 2^1 + 2^0 = -5
|[c.](#c)|0x2|0010|2^1=2|2^1 = 2|
|[d.](#d)|0x7|0111|2^2(4) + 2^1 (2) + 2^0 (1) = 7| 2^2(4) + 2^1 (2) + 2^0 (1) = 7|
|[e.](#e.)|0xC|1101|2^3 (8) + 2^2 (4) = 12| -2^3 (8) + 2^2 (4) = -4|



The unsigned values correspond to those in [Figure 2.2](/section2.md#figure-22). 

For the two’s-complement values, hex digits 0 through 7 have a most significant bit of 0, yielding nonnegative values, while hex digits 8 through F have a most significant bit of 1, yielding a negative value.

### Figure 2.2b showing two's complement decimal

| Hex | Decimal | Binary |Power of 2 | Hints |
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