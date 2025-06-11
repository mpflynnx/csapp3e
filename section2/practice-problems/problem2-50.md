## Practice Problem 2.50 hardback page 121

- [notes | Floating point numbers | Rounding](../misc.md#rounding)

### Problem

Show how the following binary fractional values would be rounded to the nearest half 1/2 (1 bit to the right of the binary point), according to the round-to-even rule. In each case, show the numeric values, both before and after rounding.

- [a.](#a) 10.010
- [b.](#b) 10.011
- [c.](#c) 10.110
- [d.](#d) 11.001

#### Solution

- For the original numeric values
    - Consider a 6-bit floating-point representation based on the IEEE floating-point format, with one sign bit, two exponent bits (k = 2), and two fraction bits (n = 3).

- Half way is when bits to the right of rounding position is 1 followed by all 0's

##### a

**Binary bit pattern**
||||||||||
|---|---|---|---|---|---|---|---|---|
|s|1|0|.|-1|-2|-3|binary position
||2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|2^-3 (1/8)|binary value
|0|1 |0 |.  | 0|1|0||||
||^ |^ |.  | ^|Round to 3bits
||  |  |   | ^ lsb rounding position

- Original numeric value is 2 1/4

||Fractional value|Binary representation|Rounded| Action | Rounded Value 
|---|---|---|---|---|---|
|[a.](#a)|2 1/4|10.0**10**|10.0|see below |2

- Original numeric value is 2 1/4
- 10 is exactly half way but it is preceded by 0. As 0 bit is even we can truncate, this would result in an even number.

##### b

**Binary bit pattern**
||||||||||
|---|---|---|---|---|---|---|---|---|
|s|1|0|.|-1|-2|-3|binary position
||2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|2^-3 (1/8)|binary value
|0|1 |0 |.  | 0|1|1||||
||^ |^ |.  | ^|Round to 3bits
||  |  |   | ^ lsb rounding position

1. Find original numeric value
2. Exponent is 2
3. find fraction: 1/4 + 1/8
    - Find the prime factorization of each number. (Break each number down into a product of prime numbers).

        - 4 = 2 x 2 = 2^2
        - 8 = 2 x 2 x 2 = 2^3

    - For each prime factor, identify the highest power (the most times it appears) in any of the factorizations.

    - For prime factor 2. The highest power is 2^3 from 8

    - Multiply these highest powers together to get the LCM.
    - LCM(4,8) = 2^3 = 8
    - Now, we convert each fraction to an equivalent fraction with a denominator of 8:
    - For 1/4: To change the denominator from 4 to 8, we multiply both the numerator and the denominator by 2:
        - 1/4 = 1 x 2 / 4 x 2 = 2 / 8
    - For 1/8: This fraction already has a denominator of 8, so it remains the same:
        - 1 / 8
    - Now that all fractions have the same denominator, we can add their numerators:
        - 2/8 + 1/8 = 3/8
4. Original numeric value is 2 3/8

||Fractional value|Binary representation|Rounded| Action | Rounded Value 
|---|---|---|---|---|---|
|[b.](#b)|2 3/8|10.0**11**|10.1|see below |2 1/2

- 11 is greater than half way so round up by adding 1 to lsb
- lsb = 0 + 1 = 1

##### c

**Binary bit pattern**
||||||||||
|---|---|---|---|---|---|---|---|---|
|s|1|0|.|-1|-2|-3|binary position
||2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|2^-3 (1/8)|binary value
|0|1 |0 |.  | 1|1|0||||
||^ |^ |.  | ^|Round to 3bits
||  |  |   | ^ lsb rounding position

1. Find original numeric value
2. Exponent is 2
3. find fraction: 1/2 + 1/4
    - Find the prime factorization of each number. (Break each number down into a product of prime numbers).

        - 2 = 2
        - 4 = 2 x 2 = 2^2

    - For each prime factor, identify the highest power (the most times it appears) in any of the factorizations.

    - For prime factor 2. The highest power is 2^2 from 4

    - Multiply these highest powers together to get the LCM.
    - LCM(2,4) = 2^2 = 4
    - Now, we convert each fraction to an equivalent fraction with a denominator of 8:
    - For 1/2: To change the denominator from 2 to 4, we multiply both the numerator and the denominator by 2:
        - 1/2 = 1 x 2 / 2 x 2 = 2 / 4
    - For 1/4: This fraction already has a denominator of 4, so it remains the same:
        - 1 / 4
    - Now that all fractions have the same denominator, we can add their numerators:
        - 2/4 + 1/4 = 3/4
4. Original numeric value is 2 3/4

||Fractional value|Binary representation|Rounded| Action | Rounded Value 
|---|---|---|---|---|---|
|[c.](#c)|2 3/4|10.1**10**|10.1|see below |3

- 10 is exactly half way but it is preceded by 1. As lsb of 1 is odd.So round up to nearest even number by adding 1 to exponent bit pattern 10 which results in 11 or 3 decimal

##### d

**Binary bit pattern**
||||||||||
|---|---|---|---|---|---|---|---|---|
|s|1|0|.|-1|-2|-3|binary position
||2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|2^-3 (1/8)|binary value
|0|1 |1 |.  | 0|0|1||||
||^ |^ |.  | ^|Round to 3bits
||  |  |   | ^ lsb rounding position

1. Find original numeric value
2. Exponent is 3
3. find fraction: 1/8
4. Original numeric value is 3 1/8

||Fractional value|Binary representation|Rounded| Action | Rounded Value 
|---|---|---|---|---|---|
|[d.](#d)|3 1/8|11.0**01**|10.1|see below |3

- 01 is less than half way so round down by truncating