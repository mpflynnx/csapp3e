## Miscellaneous notes

lecture 2 video time 1:05:26

- [gemini](https://gemini.google.com/app/9832d3245255217c)

Book page 65

### Figure 2.2

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
| 8 | 8 | 1000 |2^3|
| 9 | 9 | 1001 ||
| A | 10 | 1010 ||*Easy to remember as A
| B | 11 | 1011 |
| C | 12 | 1100 ||*Easy to remember as C
| D | 13 | 1101 ||
| E | 14 | 1110 ||
| F | 15 | 1111 ||*Easy to remember as F

One simple trick for doing the conversion in your head is to memorize the decimal equivalents of hex digits A, C, and F.

1 byte (2^8 or 256 Dec) table helps with binary maths
||||||||||
|---|---|---|---|---|---|---|---|---|
1   |2  |3  |4  |5 |6 |7 |8 | Binary Position
128 |64 |32 |16 |8 |4 |2 |1 | Binary value
2^7|2^6|2^5|2^4|2^3|2^2|2^1|2^0 |2^n

2 byte (2^16) table (Short, float)

|byte|||||||byte|||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
1   |2   |3   |4   |5   |6   |7  |8  | 1 |2  |3  |4  |5  |6  |7  |8   |
2^15|2^14|2^13|2^12|2^11|2^10|2^9|2^8|2^7|2^6|2^5|2^4|2^3|2^2|2^1|2^0 |

32bit 4byte 2^n (Int, double)
- 2^31 to 2^24
- 2^23 to 2^16
- 2^15 to 2^8
- 2^7 to 2^0

64bit 4byte 2^n (long long)
- 2^63 to 2^56
- 2^55 to 2^48
- 2^47 to 2^40
- 2^39 to 2^32


Maximum values
|||||||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
0|1|1|1|1|1|1|1| 1|1|1|1|1|1|1|1

equivalent to 2^15 -1 


### Floating point numbers

A sign bit is the most significant bit i.e 2^7, 2^15 or 2^31 it represents positive or negative 
the remaining bits represent magnitude

### Two's complement (Section 2.2.3)

Take the +15 number bit pattern 

0xF = 15 Decimal
15 decimal = 1111 binary 
2^3 (8) + 2^2(4) + 2^1 (2) + 2^0 (1) = 15
1111

Binary To Two's complement
B2Tw
-2^3 (8) + 2^2(4) + 2^1 (2) + 2^0 (1) = -1

1111 in two's complement is -1 [see table](problem2-17.md#figure-22b-showing-twos-complement-decimal)

### negative numbers to binary

convert -5 to binary

1. add 1 = -4

1. represent as 4 in binary

1. 2^2 = 4

1. 0100

1. complement all bits

1. 1011 equivalent to -5

1. Binary To Two's complement
B2Tw
1. -2^3 (8) + 2^1 (2) + 2^0 (1) = 
1. -8+2+1 = -5

<!-- invert all numbers become -15
add 1 (overflow condition, 1 goes to 2^0 position) 
then you get -1


|||||||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
0|0|0|0|0|0|0|0|0|0|0|0|1|1|1|1
1|1|1|1|1|1|1|1|1|1|1|1|0|0|0|0
0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0
1|1|1|1|1|1|1|1|1|1|1|1|0|0|0|1


-1 equivalent to

1111111

Add 1 to the value -->