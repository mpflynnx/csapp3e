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

### Unsigned addition

- It is easy to understand what happens using smaller bit sizes than say 32bit or 64bit
- Assume only four bits (w=4) are available (decimal 0 to 15)
- If the unsigned addition results in a 5bit unsigned bit pattern we have overflow
- The msb 5th bit is ignored
- 1101 + 0101 = 10010, ignore msb
- standard binary addition:
```
0 + 0 = 0 (carry 0)
0 + 1 = 1 (carry 0)
1 + 0 = 1 (carry 0)
1 + 1 = 0 (carry 1)
```
- In standard binary addition, when the sum of bits in a column is 2 (from 1+1), a '1' is carried over to the next higher bit position, and the current position's sum is 0. If there's also a carry-in from the previous column, the sum of three bits ($1+1+$carry-in) can be 3 (binary 11), resulting in a sum of 1 and a carry of 1 to the next column.

||||||||
|---|---|---|---|---|---|---|
||3|2|1|0
|16|8 |4 |2 |1 | Binary position value |
|1|1 | |1 | |  | carries
||1 |1 |0 |1 | = 13 | unsigned
|+|0 |1 |0 |1 | = 5 | unsigned
|**1**|0 |0 |1 |0 | = 18 | 
|x|0 |0 |1 |0 | = 2 | unsigned

- Unsigned addition result will be 0010 (modular sum)
- 18 % 16 = 2
- 13 + 5 = 18
    - 18 >= 13 is false 

### Two's complement arithmetic

- Same as usually math additions/subtraction
- Assume only four bits (w=4) are available (decimal -8 to +7)
- The msb 5th bit  (signed bit) is ignored
- 1101 + 0010 = 10010, ignore signed bit (overflow)
- Two's complement addition result will be 0010 (2)

#### Two's complement addition examples
||||||||
|---|---|---|---|---|---|---|
||3|2|1|0
||-8 |4 |2 |1 | Binary position value |
|1|1 ||1 | |  | carries
||1 |1 |0 |1 | = -3 | Two's complement
|+|0 |1 |0 |1 | = +5 | Two's complement
|**1**|0 |0 |1 |0 | = -14 | Ignore 5bit
|x|0 |0 |1 |0 | = 2 | 

- True sum `10010` is -14, but we ignore msb so `0010` is 2.
- Same result as `-14 + 2^4(16) = 2`

- See also  

||||||||
|---|---|---|---|---|---|---|
||3|2|1|0
||-8 |4 |2 |1 | Binary position value |
|| |1|1 | |  | carries
||1 |0 |1 |1 | = -5 | Two's complement
|+|0 |0 |1 |1 | = +3 | Two's complement
||1 |1 |1 |0 | = -2 | 

- True sum `1110` is -2
- -14 + 2^4 = 2

#### Negative overflow examples
- Adding two negative numbers results in a positive number, this is referred to a negative overflow.

||||||||
|---|---|---|---|---|---|---|
||3|2|1|0
||-8 |4 |2 |1 | Binary position value |
|1| || | |  | carries
||1 |1 |0 |1 | = -3 | Two's complement
|+|1 |0 |1 |0 | = -6 | Two's complement
|**1**| 0| 1| 1| 1| = 7 | Ignored msb

- True sum `10111` is -9, but we ignore msb so `0111` is 7.
- **Note:** +7 differs from -9 by 16 (2^w)
- -9 + 2^4(16) = 7


#### Positive overflow examples
- Adding two large positive numbers results in a negative number, this is referred to as positive overflow

||||||||
|---|---|---|---|---|---|---|
||3|2|1|0
||-8 |4 |2 |1 | Binary position value |
|| 1|1| 1| |  | carries
||0 |1 |1 |1 | = 7 | Two's complement
|+|0 |1 |0 |1 | = 5 | Two's complement
|**0**| 1| 1| 0|0 | = -4 | Ignored msb

- True sum `01100` is 12, but we ignore msb signed bit msb so `1100` is -4.
- **Note:** -4 differs from +12 by 16 (2^w)
- 12 - 2^4(16) = -4


### Two's complement negation

- In two's complement, subtraction can be performed using the same addition circuitry. To calculate A−B, a computer simply calculates A+(−B). The two's complement of B effectively represents −B, allowing the standard addition logic to handle both addition and subtraction of signed numbers without needing separate and more complex circuits for each operation.