## Miscellaneous notes

## Table of Contents
- [Number representation](#number-representation)
- [Floating point numbers](#floating-point-numbers)
- [Floating Point Rounding](#rounding)
- [Floating Point Multiplication Example](#floating-point-multiplication-example)
- [Floating Point in C](#floating-point-in-c)
- [Floating Point Puzzles](#floating-point-puzzles)
- [Two's complement](#twos-complement)
- [Negative numbers to binary](#negative-numbers-to-binary)
- [Unsigned addition](#unsigned-addition)
- [Two's complement arithmetic](#twos-complement-arithmetic)
- [Two's complement addition examples](#twos-complement-addition-examples)
- [Negative overflow examples](#negative-overflow-examples)
- [Positive overflow examples](#positive-overflow-examples)
- [Two's complement negation](#twos-complement-negation)
- [Multiplication](#multiplication)
- [Division](#unsigned-power-of-2-divide-with-shift)
- [Power of 2 using left shift operator](#power-of-2-using-left-shift-operator)
- [Integer C Puzzles](#integer-c-puzzles)

### Number representation

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

Resources
- [float.exposed](https://float.exposed/0x44bf9400)

#### Prime numbers 0 to 255

2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251

#### Fraction recap

In fractions 1/4 + 1/8 + 1/16 = 7/16

To solve this we first need to find a common denominator for all the fractions.

The denominators are 4,8 and 16. 

1. Find the prime factorization of each number. (Break each number down into a product of prime numbers).

    - 4 = 2 x 2 = 2^2
    - 8 = 2 x 2 x 2 = 2^3
    - 16 = 2 x 2 x 2 x 2 = 2^4

2. For each prime factor, identify the highest power (the most times it appears) in any of the factorizations.

    - For prime factor 2. The highest power is 2^4 from 16

3. Multiply these highest powers together to get the LCM.
    - LCM(4,8,16) = 2^4 = 16
4. Now, we convert each fraction to an equivalent fraction with a denominator of 16:
5. For 1/4: To change the denominator from 4 to 16, we multiply both the numerator and the denominator by 4:
    - 1/4 = 1 x 4 / 4 x 4 = 4 / 16
6. For 1/8: To change the denominator from 8 to 16, we multiply both the numerator and the denominator by 2:
    - 1/8 = 1 x 2 / 8 x 2 = 2 / 16
7. For 1/16: This fraction already has a denominator of 16, so it remains the same:
    - 1 / 16
8. Now that all fractions have the same denominator, we can add their numerators:
    - 4/16 + 2/16 + 1/16 = 7/16 
#### Fractional Binary Numbers examples


|||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|
|4|3|2|1|0|.|-1|-2|-3|-4| binary position
|2^4 (16)|2^3 (8) |2^2 (4) |2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|2^-3 (1/8)|2^-4 (1/16)|binary value
|| |1 |0 |1 |.  | 1|1|||5 3/4|
|| | >>|1 |0 |.  | 1|1|1||2 7/8| >> right shift divides by 2
|| | |>>|1 |.  | 0|1|1|1|1 7/16| >> right shift divides by 2
||||||^|
|<|-|-|-|^2|binary point|-^2|-|-|>

- shifting right (unsigned) divides by 2 - hence how 101.11 shifted right by 1 is 10.111
- `5 3/4` divided by 2 is `2 7/8` 
- Shifting left multiplies by 2
- hence how 10.111 shift left by 1 is 101.11
- `2 7/8` multiplied by 2 is `5 3/4`
- Notation of numbers to the right of binary point is: 1.0-epsilon

#### Limitations
- Can only exactly represent numbers of the form x/2^k
- Other values are only approximated with increasing accuracy by lengthening the binary representation
- Can have very large number with less accuracy or very small number with more accuracy, by moving the binary point as required

#### Floating point representation
- Numerical Form: (-1)^s * M * 2^E
    - Sign bit `s` determines positive or negative
    - Significand `M` (mantissa) normally fractional value in range [1.0 - 2.0]
    - Exponent `E` weights value by power of 2
- Encoding 32bit or 64bit
    - MSB S is sign bit `s`
    - exp field encodes E (but is not equal to E)
    - frac field encodes `M` (but is not equal to M)

    |s|exp|frac
    |--|--|--|
    |-|-------|----------------|

#### IEEE Floating Point
- Single precision: 32 bits

    |s|exp|frac
    |--|--|--|
    |1-bit|--8-bits|------23-bits----------|

- Double precision: 64 bits

    |s|exp|frac
    |--|--|--|
    |1-bit|--11-bits|------52-bits----------|

- Non standard Extended precision: 80 bits (Intel only)

    |s|exp|frac
    |--|--|--|
    |1-bit|--15-bits|------63 or 64-bits----------|


#### Normalized Values (most common)
- Occurs when: exp field not equal to all `0's` and not equal to all `1's` (these are special)
- Exponent value coded as a biased value: Exp = e - Bias
    - e: unsigned value of exp field ek-1 to e0 or 7 to 0
    - Bias: 2^(k-1) - 1, where k is number of exponent bits
    - Single precision k=8 bias: 127 (Exp: 1..254, e: -126..127)
    - Double precision k=11 bias: 1023 (Exp: 1..2046, e: -1022..1023)

- Significand always Normalize M with leading 1: M = 1.xxx binary representation (not encoded)
    - xxx...x: bits of frac field
    - Minimum when frac all `0's` = 000...0 (M = 1.0)
    - Maximum when frac all `1's` = 111...1 (M = 2.0 - epsilon)
    - Leading M not encoded and we get an extra leading bit for "free"

- Limitations: When the number is closer to 0 the implied leading 1 used, limits us. Then we use `Denormalized Values`

#### Normalized Values Encoding example
```c
1	#include <stdio.h>
2	
3	int main() {
4	
        int i = 15213;
5	    float f = 15213.0;

6	    return 0;
7	}

```
- Value: float f = 15213.0; // Single precision
- s field: 
    - 15213.0 is positive so signed bit is `0`
    - s field is `0`
- exp field:
    - 15213 in binary is 11101101101101
    - Normalize number, express the binary number in the form of 1.xxxxxx * 2^exponent.
    - shift the binary point until it is immediately after the leading '1'. 
    - The number of positions the binary point is shifted determines the exponent.
    - 13 shifts were needed here
    - 1.1101101101101 x 2^13
    - The exponent is 13.

- frac field:
    - The mantissa is the fractional part after the leading 1.
    - 1.1101101101101
    - Mantissa M = 1101101101101
    - Since the mantissa needs to be 23 bits, we pad it with trailing zeros:
    - frac field = 11011011011010000000000 // 23 bits

- Exponent
    - The exponent 13 needs to be biased by 127 (for single precision).
    - Biased exponent = 13 + 127 = 140
    - Now, convert 140 to an 8-bit binary number:
    - Exp (value of exp field bits) = 10001100 is 140
    - check formula, E = Exp - bias = 140 - 127 = 13


- Result
    - Assemble the s, exp and frac fields

    |s|exp|frac
    |--|--|--|
    |0|10001100|11011011011010000000000|

```bash
(gdb) x /t &f
0x7fffffffdebc:	01000110011011011011010000000000
```

##### Recap

Exponent can be confusing.
- Exp ranges, Exp is encoding not a interpreted value
- Exp is e - bias
- 0 is the smallest Exp 00000000
- 2^8-1 is the largest Exp 255 or 01111111

e is the value to encode
- Range of value for e is
    - e min = Exp min - e = 0 - 127 = -127 or 2^e-127
    - e max Exp max - e = 255 - 127 = 128 or 2^128
    - E middle is 0

#### Denormalized Values (when number 0 or closer to 0)
- Condition: exp = 000...0
- No implied 1, but implied 0

- Exponent value coded as a biased value: Exp = 1 - Bias
 
- Significand M with implied leading 0: M = 0.xxx binary representation (not encoded)
    - xxx...x: bits of frac field
    - Minimum when frac all `0's` = 000...0

- As signed bit may be 1 or 0 then values could be +0 and -0

- Condition: exp = 111...1
    - Case: exp = 111...1, frac = 000...0
        - Represents value infinity
        - Operation that overflows
        - Both positive and negative
        - E.g. 1.0/0.0 = -1.0/-0.0 = +infinity, 1.0/-0.0 = -infinity

    - Case: exp = 111...1, frac not equal to 000...0
        - Not-a-NUmber (NaN)
        - Represents case when noo numeric value can be determined
        - E.g. sqrt(-1), infinity - infinity, infinity x 0

#### 8-bit Floating Point Representation example
- As with Two's complement use small bit pattern widths to see what happens at extremes.

    |s|exp|frac
    |--|--|--|
    |0|4bits|3bits|

- 8-bit Floating Point Representation
    - sign bit is in most significant bit
    - the next 4 bits are the exponent, - bias is 2^(4-1) - 1 = 7
    - the last 3 bits are the frac
    - Same general form as IEEE Format
    - normalized, denormalized
    - representation of 0, NaN, infinity


### Rounding

- With floating point arithmetic we can only approximate the real arithmetic
- We need to have a method of finding the closest matching value to the real result
- IEEE defines four rounding modes
- Round-to-even (a.k.a round to nearest) is the default mode
- Other modes available by using assembly language instructions only.
- Round-to-even avoids statistical bias in most real-life situations
- It will round upward 50% of the time and round downward about 50% of the time
- The least significant bit (lsb) is considered to be even or odd.


#### Round-to-even decimal examples
-  Rounding to the nearest hundredth
- 1.2349999 to 1.23: Same for all modes
- 1.2350001 to 1.24: Same for all modes
- 1.2350000 to 1.24: Round odd 5 lsb down to a even lsb of 4
- 1.2450000 to 1.24: Round odd 5 lsb down to even lsb of 4
- 7.8950000 to 7.90 (lsb is 0 even)
- 7.8850000 to 7.88 (lsb is 8 even)

#### Round-to-even binary numbers example
- Even when when lsb is 0
- Half way is when bits to the right of rounding position is 1 followed by all 0's
- Assume we can only use 4-bits to represent a 7-bit real number
- Round to nearest 1/4 (2bit right of binary point)

##### a.

**Binary bit pattern**
||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|
|s|1|0|.|-1|-2|-3|-4|-5|binary position
||2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|2^-3 (1/8)|2^-4 (1/16)|2^-5 (1/32)|binary value
|0|1 |0 |.  | 0|0|0|1|1||
||^ |^ |.  | ^|^|Round to 4bits
||  |  |   | |^ lsb rounding position

||Fractional value|Binary representation|Rounded| Action | Rounded Value 
|---|---|---|---|---|---|
|[a.](#a)|2 3/32|10.00**011**|10.00|see below |2


- 011 is less than half way so round down by truncating

##### b.

**Binary bit pattern**
||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|
|s|1|0|.|-1|-2|-3|-4|-5|binary position
||2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|2^-3 (1/8)|2^-4 (1/16)|2^-5 (1/32)|binary value
|0|1 |0 |.  | 0|0|1|1|0||
||^ |^ |.  | ^|^|Round to 4bits
||  |  |   | |^ lsb rounding position


||Fractional value|Binary representation|Rounded| Action | Rounded Value 
|---|---|---|---|---|---|
|[b.](#b)|2 3/16|10.00**110**|10.01| see below| 2 1/4

- 110 is greater than half way so round up

##### c.

**Binary bit pattern**
||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|
|s|1|0|.|-1|-2|-3|-4|-5|binary position
||2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|2^-3 (1/8)|2^-4 (1/16)|2^-5 (1/32)|binary value
|0|1 |0 |.  | 1|1|1|0|0||
||^ |^ |.  | ^|^|Round to 4bits
||  |  |   | |^ lsb rounding position

||Fractional value|Binary representation|Rounded| Action | Rounded Value 
|---|---|---|---|---|---|
|[c.](#c)|2 7/8|10.11**100**|11.00| see below| 3

- 100 is exactly half way but it is preceded by a 1 which is odd. So round up to nearest even number by adding 1 to exponent bit pattern 10 which results in bit pattern 11 or 3 decimal.

##### d.

**Binary bit pattern**
||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|
|s|1|0|.|-1|-2|-3|-4|-5|binary position
||2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|2^-3 (1/8)|2^-4 (1/16)|2^-5 (1/32)|binary value
|0|1 |0 |.  | 1|0|1|0|0||
||^ |^ |.  | ^|^|Round to 4bits
||  |  |   | |^ lsb rounding position

||Fractional value|Binary representation|Rounded| Action | Rounded Value 
|---|---|---|---|---|---|
|[d.](#d)|2 5/8|10.10**100**|10.10| see below| 2 1/2

- 100 is exactly half way but it is preceded by 0. As 0 bit is even we can truncate, this would result in an even number.

**Binary bit pattern**
||||||||||||
|-|---|---|---|---|---|---|---|---|---|---|
||2|1|0|.|-1|-2|binary position
||Sign Bit|2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|binary value
a.|0 |1 |0 |.  | 0|0|
b.|0 |1 |0 |.  | 0|1|
c.|0 |1 |0 |.  | 1|1|
d.|0|1|0|.|1|0

- It is important to recognise the half way marker, and then determine whether there is a need to round up or round down.
- Round down by truncating
- Round up by adding a 1 and propagate it 

### Floating Point Multiplication Example

- Given two floating point normalized numbers in form below:
    - 1.010 x 2^2
    - 1.110 x 2^3

- Multiple, then round to 4bits.

- Neither number has a sign bit, they can only represent nonnegative numbers.
    - If the numbers have a sign bit then XOR the sign bits together to get the sign bit for the multiplication result.

1. Calculate M (mantissas) by Multiply the significands (biggest chore):
```
    1.010
x   1.110
    -----
    0000 (1.010 x 0)
    1010 (1.010 x 1, shifted by 1 to the left)
    1010 (1.010 x 1, shifted by 2 to the left)
+   1010 (1.010 x 1, shifted by 3 to the left)
    ------
    10.001100
```
2. Add Exponents: 
    - 2 + 3 = 5
3. Exact result:
    - Drop trailing 0's
    - 10.0011 x 2^5
4. Normalize to 1.xxxxxx * 2^exponent 
    - If M greater than or equal to 2, shift M right, increment E
    - 1.00011 x 2^6
    - If E out of range then this will overflow to infinity
5. Find the value
    - 1.00011 x 2^6
    - shift binary point to the right 6 times
    - 1.00011 = 1000110.0 (omit .0)
    - 1000110 to decimal
    - 2^6 + 2^2 + 2^1 = 64 + 4 + 2  = 70
6. Round M to fit frac precision 3bits

|||||||||
|---|---|---|---|---|---|---|---|
|s|0|.|-1|-2|-3|-4|-5
|-|2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|2^-3 (1/8)|2^-4 (1/16)|2^-5 (1/32)
| 0|1 |.  | 0|0|0|1|1||
||||||^ lsb rounding position |^|^

- The bits to the right of rounding position -3 are 11.
- 11 is greater than half way so round up by adding 1 to lsb
- lsb = 0 + 1 = 1
- 1.001 x 2^6
7. Find the value
    - 1.001 x 2^6
    - shift binary point to the right 6 times
    - 1.001 = 1001000.0 (omit .0)
    - 1001000 to decimal
    - 2^6 + 2^3 = 64 + 8 = 72

### Floating Point Addition Example

- Steps:
    - Line up binary points
    - Do the addition
    - Normalize the number
    - Round if needed

- Given two floating point normalized numbers in form below:
    - 1.010 x 2^2
    - 1.110 x 2^3

- Add the numbers, then round to 4bits.

- Neither number has a sign bit, they can only represent nonnegative numbers.


1. Calculate M (mantissas) by adding the significands:
    - Align the binary points, by matching the highest exponent 2^3 of the two numbers.
    - 1.010 x 2^2 becomes 0.1010 x 2^3
    - 1.110 x 2^3 becomes 1.1100 x 2^3 (add trailing 0)

|||||||||
|---|---|---|---|---|---|---|---|
|| 1|| | |  | | carries
||0|. |1 |0 |1 | 0
|+|1|. |1 |1 |0 | 0
|1|0| .|0 |1 |1|0




2. Exponent: 
    - 2^3
3. Exact result:
    - 10.0110 x 2^3
4. Normalize to 1.xxxxxx * 2^exponent 
    - If M greater than or equal to 2, shift M right, increment E
    - 1.00110 x 2^4
    - If M less than 1, shift left k positions, decrement E by k
    - If E out of range then this will overflow to infinity
5. Find the value:
    - 1.00110 x 2^4
    - shift binary point to the right 4 times
    - 1.00110 = 10011.0 (Omit .0)
    - 10011 to decimal
    - 2^4 + 2^1 + 2^0 = 16 + 2 + 1  = 19. 
6. Round M to fit frac precision 3bits

|||||||||
|---|---|---|---|---|---|---|---|
|s|0|.|-1|-2|-3|-4|
|-|2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|2^-3 (1/8)|2^-4 (1/16)|
| 0|1 |.  | 0|0|1|1|||
||||||^ lsb rounding position |^|

- The bit to the right of rounding position -3 is 1.
- 1 is exactly half way but it is preceded by 1. As lsb of 1 is odd. Round up to nearest even number by adding 1 to the lsb. 1 + 1 is 10
- lsb = 1 + 1 = 10
- 1.010 x 2^4
7. Find the value
    - 1.010 x 2^4
    - shift binary point to the right 6 times
    - 1.010 = 10100.0 (omit .0)
    - 10100 to decimal
    - 2^4 + 2^2 = 16 + 4 = 20.

### Floating Point in C

#### C types
- type float - single precision
- type double - double precision

#### Conversions/Casting
- Casting between int, float and double changes the bit representation

- double/float to int
    - Truncates fractional part
    - Like rounding toward zero
    - Not defined when out of range or NaN, generally sets to TMin in most cases
- int to double
    - number of int bits will fit in the frac field
    - exact conversion, as long as int has less than or equal 53 bit word size
- int to float
    - more bits in a int than in the frac field of a float
    - Will round according to rounding mode

#### Floating Point Puzzles

- For each of the following C expressions, either:
    - Argue that it is true for all argument values
    - Explain why not true
    - Assume neither d nor f is NaN

```c
int x = ...;
float f = ...;
double d = ...;
```

##### a.
- x == (int)(float) x
- Cast a x `int` to a `float` then cast back to a `int`
- is x == x ?
- False, casting from `int` to `float` changes the bit representation by truncating
- Casting from `float` to `int` keeps the truncated bit representation of the `float`

##### b.
- x == (int)(double) x
- Cast a x `int` to a `double` then cast back to `int`
- is x == x ?
- True, as long as the int is less than 53 bits, the number of `int` bits will fit in the frac field of a `double`

##### c.

- f == (float)(double) f
- Cast f `float` to a `double` then cast double back to a `float`
- True, `float` frac bits fit into `double` frac bits

##### d.

- d == (float)(double) d
- Cast d `double` to a `float` then cast back to `double`
- False, double frac bits truncated to fit into float

##### e.

- f == -(-f);
- Negate f, then negate again, will it equal f?
- True, as only one bit is toggled

##### f.
- 2/3 == 2/3.0
- False, 2/3 is integer division and gives 0, 2/3.0 is floating point division and returns a `float` not a `int`

##### g.

- d < 0.0 same as ((d*2) < 0.0)
- is d double negative
- is d*2 still negative
- True, even if d*2 overflows negative infinity is is still less than 0, as sign bit not changed

##### h.

- d > f same as -f > -d
- Is a negative float greater than an negative double?
- True

##### j.

- d * d >= 0.0
- If d is squared is it greater than or equal to 0.0 (i.e not negative)?
- True squared numbers are always non negative

##### k.

- (d + f) -d == f
- Add a float to a double, then subtract the double does it equal f
- False, lack of associativity

### Two's complement

A sign bit is the most significant bit i.e 2^7, 2^15 or 2^31 it represents positive or negative 
the remaining bits represent magnitude

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
- In standard binary addition, when the sum of bits in a column is 2 (from 1+1), a '1' is carried over to the next higher bit position, and the current position's sum is 0. If there's also a carry-in from the previous column, the sum of three bits (1+1+carry-in) can be 3 (binary 11), resulting in a sum of 1 and a carry of 1 to the next column.

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
- Adding two Wbit numbers may equal a result that requires as much as Wbit + 1 to represent it.
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

### Multiplication

- We saw that, adding two Wbit numbers may equal a result that requires as much as Wbit + 1 to represent it.
- For  multiplication, Wbit number x Wbit number may equal a result that requires as much as 2xWbit to represent it.
- We are potentially squaring the largest number.
- If you cannot represent the true sum in the bits available the low order bits are used as the result i.e ignore msb (signed bit).

#### Unsigned multiplication
- Modulo arithmetic
- Multiplying in binary like multiplying in decimal

#### Unsigned multiplication example 1

- Assume only four bits (w=4) are available (decimal 0 to 15)
- In decimal 3 * 5 = 15
- True sum in binary `1111` is 15 (no overflow)

#### Unsigned multiplication example 2
- In decimal 5 * 5 = 25
- True sum in binary `00011001` is 25, but we ignore high order bits so `1001` is 9.
- Same result as 25 % 16 = 9

#### Two's complement multiplication
- We ignore high order bits but now must also use the remaining msb (signed bit) to determine the polarity of the result.
- This can lead to a result that completely disregards the polarity of the the two operands.

#### Two's complement multiplication example 1

- In decimal 5 * 4 = 20
- True sum in binary `00010100` is 20, but we ignore high order bits so `0100` is +4.
- msb (signed bit) is `0` so positive
- Same result as 20 % 16 = +4

#### Two's complement multiplication example 2
- Multiply two positive numbers and get a negative result
- True sum in decimal 5 * 5 = 25
- True sum in binary `00011001` is 25.
- Ignore high order bits so `1001`
- msb (signed bit) is `1` so result is negative `-7`.

#### Two's complement multiplication example 3
- Multiply two negative numbers and get a positive result
- Two's complement binary `1101` is -3 or unsigned 13.
- Two's complement binary `1110` is -2 or unsigned 14.
- True sum unsigned is 13 * 14 = 182 = `0xB6`
- Ignore higher or `0xB` to leave `0x6` or `0110`
- `-3 * -2` is 6.
- 99% of the time the same algorithm and hardware can be used for unsigned and two's complement.



<!-- - Multiple a number by power of 2
- Shift left by 2

||||||||||
|---|---|---|---|---|---|---|---|---|
|6|5|4|3|2|1|0
|64|32|16|8 |4 |2 |1 | Binary position value |
||||0 |1 |0 |1 | = 5 | 
|**1**|0|1|0 |1 |0 |0 | = 25 |  -->


### Multiplication by power of 2 using left shift

- Book Section 2.3.6
- Unsigned, two's complement multiplication
- Most machines shift and add faster than multiply
- compilers generate shift code automatically based on a series of conditions
- x << n gives the same result as x * 2^n
- n must be a 2^n number i.e 0,1,2,4,8,16,32 etc
- overflow follows the same as described early


#### Example 1a
- Use left shift to get equivalent to `2 * 14 = 28`
- if `x` is `2`
- if `k` is `14`
- 14 in binary is 00001110 
- 14 also is 2^3(8) + 2^2(4) + 2^1(2)
- `x * k` result is equivalent in C to (x<<3) + (x<<2) + (x<<1)
- After 1st shift (x<<3) result is `x * 8 = 16`
- After 2nd shift (x<<2) result is `x * 4 = 8`
- After 3rd shift (x<<1) result is `x * 2 = 4`
- Total is 16 + 8 + 4 = 28
- A better solution requiring fewer shifts
- `x * k` result is equivalent in C to (x<<4) - (x << 1)
- After 1st shift (x<<4) result is `x * 16 = 32`
- After 2nd shift (x<<1) result is `x * 2 = 4`
- Total is 32 - 4 = 28


#### Example 1b

- if `x` is `2`
- if `k` is `14`
- 14 in binary is 00001110 

```
76543210 Bit position
00001110 14 Decimal
    ^ ^
    n m  n=3, m=1
```
- Form A:
- (x<<n) + (x<<(n-1)) + (x<<m)
- (2<<3) + (2<<(3-1)) + (2<<1)

- Form B:
- (x<<(n+1)) - (x<<m)
- (2<<(3+1)) - (2<<1)


#### Example 2
- u << 3 == u * 8 because 2^3 is 8
- (u << 5) - (u << 3) == u * 24
- 2^5 = 32 - (2^3 = 8) = 24



3 * 3 ??


00000011

2^1 + 2^0

3<<2 + 3<<1

### Unsigned Power of 2 Divide with shift
- Unsigned division is a logical shift
- Division is slow even on modern computers (30+ clock cycles)
```
x 0110 is 6
k = 1
>>k equivalent to divide by 2^k = 2^1 = 2, 6/2 = 3
0011 is 3
>>k equivalent to divide by 2^k = 2^1 = 2, 3/2 = 1.5
0001 is 1 here 1.5 is rounded down towards zero to 1 
```
### Signed (Two's complement) Power of 2 Divide with shift

- Positive numbers are treated the same as unsigned i.e logical shift
- Negative numbers need the use of arithmetic shifting
- The msb (signed bit) of 1 needs to be maintained and duplicated during division

```
x 1010 is -6
k = 1

>>k equivalent to divide by 2^k = 2^1 = 2, -6/2 is -3
1101 is -3

1   1       01            1
^   ^       ^             ^
new copied  shifted       lost
msb msb     bit pattern   bit
```

```
x 1101 is -3
k = 1

>>k equivalent to divide by 2^k = 2^1 = 2, but -3/2 is -1.5 we get
1110 is -2 which is rounded away from zero and -1.5

1   1       10            1
^   ^       ^             ^
new copied  shifted       lost
msb msb     bit pattern   bit
```
- We require -1
- There is a trick the compiler uses to fix this
- We must first add a `bias` to the bit pattern to be divided
```
x 1101 is -3
k = 1
bias = (2^k) - 1 or (1<<k) -1, (2) - 1 = 1 or 0001
0001 is the bias to add
1110 is new number to divide

>>k equivalent to divide by 2, we get 1111 is -1 which is rounded towards zero from -1.5

1   1       11            0
^   ^       ^             ^
new copied  shifted       lost
msb msb     bit pattern   bit
```
- C expression for negative integers
```c
    int x = -12340;
    int k = 8; // 2^8 = 256
    divideBy256 = (x<0 ? x+(1<<k)-1 : x) >> k;

```

### Signed (Two's complement) Power of 2 Divide with shift (alternative)

- We saw previously this expression, to divide signed integer x by k
```c
(x<0 ? x+(1<<k)-1 : x) >> k;
```
- We check if x is less than 0 i.e a negative number
- If x is negative, calculate a bias then add it to x
- else do not add a bias to x
- then right shift x by k

**Alternative**
- There is another way to do this without using the <, ? or : operators
- Integer types have width w=32 by default
- Using right shift on x >> w-1, x>>32-1, x>>31. Will result in all 1's if x is negative, all 0's if positive
- We then create mask using k, mask = 2^k - 1 or mask = (1<<k) - 1
- Produce bias using, bias = (x>>31) & mask
- bias will be 0 if x is positive
- The result of the division is obtained using, (x + bias) >> k

### Tips for negating a binary representation of a integer
- Complement and increment trick
- Works with a negative to positive or positive to negative negations
- How to get x to -x
```
1010 is -6
~ complement(flip) the bits gives 0101, then +1

0101
0001
0110 = 6
```

```
0110 = 6
~ complement(flip) the bits gives 1010, then +1

1010
0001
1010 = -6
```

### Power of 2 using left shift operator
- 2 to the Power 8 or 2^8 is 256.

- In C you can use a library math.h with pow() function

```c
#include<math.h> // use -lm in compilation to link math.h
x = pow(2,8) // 256
```

- Alternatively you can use the left shift operator <<

```c
x = 1<<8; // 256
```

### Integer C Puzzles
- Puzzles taken from [Video Lecture 03: Bits, Bytes, and Integers (cont.)](https://scs.hosted.panopto.com/Panopto/Pages/Viewer.aspx?id=526e6341-aa53-4107-8fa1-d13c0e92342e) section named `Integer C Puzzles`

```c
    int x = foo(); /* Arbitrary value */
    int y = bar(); /* Arbitrary value */

    unsigned ux = x;
    unsigned uy = y;
```

#### a.
- is x < 0 equivalent to ((x*2) < 0)
- x < 0, checking for a negative
- If x was negative then x*2 will always be negative? true or false?
- false, try x as Tmin
- Tmin = -2147483647-1
- if x = Tmin then x is negative
- 2*Tmin is -4294967296
- This number to too big to fit in a 32bit signed integer
- 2*Tmin is 0xFFFFFFFF00000000
- x it will become zero as only the lower level bytes will fit.



#### b.
- ux >=0, true or false
- true, ux is x casted to unsigned, will be 0 or greater

#### c.
- x & 7 == 7 equivalent to (x<<30) < 0
- 7 is lower order bits as 111, i.e this bits set 2^2, 2^1, 2^0
- x & 7 masks off 7 from x, so we just look at these 3 lower order bits
- these bits all set to 1 is 7 decimal
- x & 7 == 7 is true if these bits are all set to 1
- (x<<30) shifts the last bits 2^1 and 2^0 to the msb and msb-1, means msb is 1 which represents negative in twos-complement, the 2^2 bit falls off the front.
- (x<<30) < 0 is true if x's 2^1 bit set


#### d.
- ux > -1
- Never true always false usigned int never negative
#### e.
- is x > y equivalent to -x < -y
- false
- what is the negative of Tmin?
- Use complement and increment trick
- You still get Tmin

#### f.
- x * x >= 0
- false

#### g.
- x > 0 && y > 0 equivalent to x + y > 0
- false

#### h.
- x >= 0 equivalent to -x <= 0
- true

#### h.
- x <= 0 equivalent to -x >= 0
- Asymmetry with signed numbers edge case
- The answer is false, Tmin
- The one negative number that cannot be represented as positive is Tmin

#### j.
- (x|-x)>>31 == -1
- ORing two zero numbers is 0
- Any nonzero number is true
- subtract -1 from all 0's = -1
- then OR them together

#### k.
- ux >> 3 == ux/8
- unsigned division example
- 2^3 = 8
- true ux >> 3 == ux/8

#### m.
- x >> 3 == x/8
- Two's-complement division
- 2^3 = 8
- True if x positive
- False if x negative, need bias for negative, see below
- logarithm base 2 of 8 is 3, k=3
 We then create mask using k, mask = 2^k - 1 or mask = (1<<3) - 1
- mask is 7 decimal
- produce bias using, (x>>31) & mask
- The result of the division is obtained using, (x + bias) >> k


#### n.
- x & (x-1) != 0
- Tmin = -2147483647-1
- TMax = 2147483647
- if x = Tmin, msb will be 1 
- x-1 will be TMax due to overflow
- x & (x-1) masks off the value of x-1 from x
- false if x = Tmin, as the result will be 0
- true if x = Tmax


