## Practice Problem 2.52 hardback page 122

- [notes | Floating point numbers](../misc.md#floating-point-numbers)
- [notes | Floating point numbers | Rounding](../misc.md#rounding)

### Problem

Consider the following two 7-bit floating-point representations based on the IEEE floating-point format. Neither has a sign bit—they can only represent nonnegative numbers.
1. Format A
    - There are k = 3 exponent bits. The exponent bias is 3.
    - There are n = 4 fraction bits.
2. Format B
    - There are k = 4 exponent bits. The exponent bias is 7.
    - There are n = 3 fraction bits.

Below, you are given some bit patterns in format A, and your task is to convert them to the closest value in format B. If necessary, you should apply the round-to-even rounding rule. In addition, give the values of numbers given by the format A and format B bit patterns. Give these as whole numbers (e.g., 17) or as fractions (e.g., 17/64).

||Format A||||Format B||
|---|---|---|---|---|---|---|
||Bits|Value|||Bits|Value|
||011 0000|1|||0111 000|1|
|[a.](#a)|101 1110|?|||?|?|
|[b.](#b)|010 1001|?|||?|?|
|[c.](#c)|110 1111|?|||?|?|
|[d.](#d)|000 0001|?|||?|?|

#### Solution

##### a

**Format A binary bit pattern**
||||||||||
|---|---|---|---|---|---|---|---|---|
|2|1|0|.|-1|-2|-3|-4|binary position
|2^2 (4)|2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|2^-3 (1/8)|2^-4 (1/16)|binary value
|1|0 |1 |.  | 1|1|1|0|||

If exponent not all 0's or all 1's. Use normalized form n: e - Bias

Format A Value is:
1. e (exponent field value)= 2^2 + 2^0 = 4 + 1 = 5
2. Calculate E (actual exponent) normalized values:
    - k = 3
    - Bias = 2^(k-1) - 1 
    - 2^(3-1) = 2^2 = 4
    - 4 - 1 = 3
    - bias is 3.
    - E = e - bias = 5 - 3 = 2
3. Calculate 2^E:
    - E = 2
    - 2^2 = 4
    - 2^E = 4
4. Calculate f:
    - 1/2 + 1/4 + 1/8 + 0/16
    - 0/16 simplified to 0
    - 1/2 + 1/4 + 1/8 + 0   
    - Find the prime factorization of each number. (Break each number down into a product of prime numbers).

        - 2 = 2^1
        - 4 = 2 x 2 = 2^2
        - 8 = 2 x 2 x 2 = 2^3
    - The only prime factor is 2

    - For each prime factor, identify the highest power (the most times it appears) in any of the factorizations.
    - The highest is 2^3 = 8 this is the common denominator
    - For 1/2: To change the denominator from 2 to 8, we multiply both the numerator and the denominator by 8:
        - 1/2 = 1 x 4 / 2 x 4 = 4 / 8
    - For 1/4: To change the denominator from 4 to 8, we multiply both by 4:
        - 1/4 = 1 x 2 / 4 x 2 = 2 / 8
    - 1/8 remains as 1/8 
    - Now that all fractions have the same denominator, we can add their numerators:
        - 4/8 + 2/8 + 1/8 = 7/8
        - Therefore: f = 7/8
5. Calculate M for normalized Values:
    - M = 1 + f
    - fractional part f is 7/8
    - Convert 1 7/8 to improper fraction
    - Multiple 1 by denominator 8
    - 1 x 8 = 8
    - Add to the numerator 7 + 8 = 15
    - Place 15 over original denominator 8
    - M = 15/8
6. Calculate 2^E x M:
    - 2^E x M = 2^2 x 15/8
    - E = 2
    - M = 15/8
    - 2^2 = 4
    - 4 x 15/8 = 60/8
    - 2^E x M = 60/8
7. Calculate V
    - Can 60/8 be simplified? Yes
8. Simplify the fraction part, by finding the common divisor of 60
   - Use prime factorization (break each number down into a product of prime numbers).
    - divide 60 by a prime number until a whole number is found
        - 60 divided by prime 2 is 30
        - first product is 2
    - divide 30 by a prime number until a whole number is found
        - 30 divided by prime 2 is 15
        - second product is 2
    - divide 15 by a prime number until a whole number is found
        - 15 divided by prime 3 is 5
        - third product is 3
    - 5 is a prime number, so fourth  product is 5
    - 2 x 2 x 3 x 5 = 60
    - 2^2 x 3 x 5
9. Simplify the fraction part, by finding the common divisor of 8
   - Use prime factorization (break each number down into a product of prime numbers).
    - divide 8 by a prime number until a whole number is found
        - 8 divided by prime 2 is 4
        - first product is 2
    - divide 40 by a prime number until a whole number is found
        - 4 divided by prime 2 is 2
        - second product is 2
    - 2 is a prime number, so third  product is 2
    - 2 x 2 x 2 = 8
    - 2^2 x 2 = 8 
9. The greatest common factor is 2^2 = 4
    - 60 divided by 4 = 15
    - 8 divided by 4 = 2
    - so 60/8 simplified it 15/2 
10. The value is 15/2 or 7 1/2 or 7.5 decimal

Format B binary representation is:

1. Find binary representation of 15/2
    - One simple way to think about fractional binary representations is to represent a number as a fraction of the form x/2^k.
    - For improper fraction 15/2, we have decimal 15 which is in binary 1111
    - 1/2 is at the -1 binary position, so k is 1
    - We then put the binary point 1 positions from the right to get binary representation of 111.1
2. Normalize the binary number to find E (actual exponent)
    - Normalize number, express the binary number in the form of 1.xxxxxx * 2^exponent.
    - shift the binary point until it is immediately after the leading '1'.
    - The number of positions the binary point is shifted determines the exponent.
    - 111.1 = 1.111 x 2^2
    - 2 shifts were needed here
    - E (actual exponent) is 2
3. Calculate e (exponent field value) normalized values:
    - k = 4
    - Bias = 2^(k-1) - 1 
    - 2^(4-1) = 2^3 = 8
    - 8 - 1 = 7
    - bias is 7
    - e = E + bias
    - e = 2 + 7 = 9
    - e into binary k=4 bits
    - 1001

**Format B binary bit pattern**
|||||||||||
|---|---|---|---|---|---|---|---|---|---|
|3|2|1|0|.|-1|-2|-3|binary position
|2^3 (8)|2^2 (4)|2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|2^-3 (1/8)|binary value
|1|0 |0 |1 |. | 1|1|1|

4. Calculate f:
    - The mantissa is the fractional part after the leading 1.111
    - The fraction bits are 111, which fit exactly into the n=3 field, no rounding needed.
    - 1/2 + 1/4 + 1/8
    - Find the prime factorization of each number. (Break each number down into a product of prime numbers).
        - 2 = 2^1
        - 4 = 2 x 2 = 2^2
        - 8 = 2 x 2 x 2 = 2^3
    - The only prime factor is 2

    - For each prime factor, identify the highest power (the most times it appears) in any of the factorizations.
    - The highest is 2^3 = 8 this is the common denominator
    - For 1/2: To change the denominator from 2 to 8, we multiply both the numerator and the denominator by 4:
        - 1/2 = 1 x 4 / 2 x 4 = 4 / 8
    - For 1/4: To change the denominator from 4 to 8, we multiply both by 4:
        - 1/4 = 1 x 2 / 4 x 2 = 2 / 8
        - Now that all fractions have the same denominator, we can add their numerators:
        - 4/8 + 2/8 + 1/8 = 17/8
        - Therefore: f = 7/8
        - This is simplified
5. Calculate M for normalized Values:
    - M = 1 + f
    - fractional part f is 7/8
    - Convert 1 7/8 to improper fraction
    - Multiple 1 by denominator 8
    - 1 x 8 = 8
    - Add to the numerator 7 + 8 = 15
    - Place 15 over original denominator 8
    - M = 15/8
6. Calculate 2^E x M:
    - 2^E x M = 2^2 x 15/8
    - E = 2
    - M = 15/8
    - 2^2 = 4
    - 4 x 15/8 = 60/8
    - 2^E x M = 60/8
7. Calculate V
    - Can 60/8 be simplified? Yes
8. Simplify the fraction part, by finding the common divisor of 60
   - Use prime factorization (break each number down into a product of prime numbers).
    - divide 60 by a prime number until a whole number is found
        - 60 divided by prime 2 is 30
        - first product is 2
    - divide 30 by a prime number until a whole number is found
        - 30 divided by prime 2 is 15
        - second product is 2
    - divide 15 by a prime number until a whole number is found
        - 15 divided by prime 3 is 5
        - third product is 3
    - 5 is a prime number, so fourth  product is 5
    - 2 x 2 x 3 x 5 = 60
    - 2^2 x 3 x 5
9. Simplify the fraction part, by finding the common divisor of 8
   - Use prime factorization (break each number down into a product of prime numbers).
    - divide 8 by a prime number until a whole number is found
        - 8 divided by prime 2 is 4
        - first product is 2
    - divide 40 by a prime number until a whole number is found
        - 4 divided by prime 2 is 2
        - second product is 2
    - 2 is a prime number, so third  product is 2
    - 2 x 2 x 2 = 8
    - 2^2 x 2 = 8 
9. The greatest common factor is 2^2 = 4
    - 60 divided by 4 = 15
    - 8 divided by 4 = 2
    - so 60/8 simplified it 15/2 
10. The value is 15/2 or 7 1/2 or 7.5 decimal


**Format B binary bit pattern**
|||||||||||
|---|---|---|---|---|---|---|---|---|---|
|3|2|1|0|.|-1|-2|-3|binary position
|2^3 (8)|2^2 (4)|2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|2^-3 (1/8)|binary value
|1|0 |0 |1 |. | 1|1|1|15/2

##### b

**Format A binary bit pattern**
||||||||||
|---|---|---|---|---|---|---|---|---|
|2|1|0|.|-1|-2|-3|-4|binary position
|2^2 (4)|2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|2^-3 (1/8)|2^-4 (1/16)|binary value
|0|1 |0 |.  | 1|0|0|1|||

Exponent not all 0's or all 1's. Use normalized form n: e - Bias

- Format A Value is:

1. e (exponent field value)= 2^1 = 2
2. Calculate E (actual exponent) normalized values:
    - k = 3
    - Bias = 2^(k-1) - 1 
    - 2^(3-1) = 2^2 = 4
    - 4 - 1 = 3
    - bias is 3.
    - E = e - bias = 2 - 3 = -1
3. Calculate 2^E:
    - E = -1
    - 2^-1 = 0.5
    - 2^E = 0.5
4. Calculate f:
    - 1/2 + 1/16
    - Find the prime factorization of each number. (Break each number down into a product of prime numbers).
        - 2 = 2^1
        - 16 = 2 x 2 x 2 x 2 = 2^4
    - The only prime factor is 2
    - For each prime factor, identify the highest power (the most times it appears) in any of the factorizations.
    - The highest is 2^4 = 16 this is the common denominator
    - For 1/2: To change the denominator from 2 to 16, we multiply both the numerator and the denominator by 8:
        - 1/2 = 1 x 8 / 2 x 8 = 8 / 16
    - 1/16 remains as 1/16 
    - Now that all fractions have the same denominator, we can add their numerators:
        - 8/16 + 1/16 = 9/16
        - Therefore: f = 9/16
5. Calculate M for normalized Values:
    - M = 1 + f
    - fractional part f is 9/16
    - Convert 1 9/16 to improper fraction
    - Multiple 1 by denominator 16
    - 1 x 16 = 16
    - Add to the numerator 9 + 16 = 25
    - Place 25 over original denominator 16
    - M = 25/16
6. Calculate 2^E x M:
    - E = -1
    - M = 25/16
    - 2^-1 = 0.5
    - 0.5 = 1/2
    - 1/2 x 25/16
    - To multiply fractions, multiply the numerators together and the denominators together:
    - (1×25)/(2×16) = 25/32
    - 2^E x M = 25/32
7. The value is 25/32 or 0.78125

- Format B binary representation is:

1. Find binary representation of 25/32
    - One simple way to think about fractional binary representations is to represent a number as a fraction of the form x/2^k.
    - For improper fraction 25/32, we have decimal 25 which is in binary 11001
    - 1/32 is at the -5 binary position, so k is 5
    - We then put the binary point 5 positions from the right to get binary representation of 0.11001
2. Normalize the binary number to find E (actual exponent)
    - Normalize number, express the binary number in the form of 1.xxxxxx * 2^exponent.
    - shift the binary point until it is immediately after the leading '1'.
    - The number of positions the binary point is shifted determines the exponent.
    - As I need to shift right here
    - 0.11001 = 1.1001 x 2^-1
    - 1 negative shift was needed here
    - E (actual exponent) is -1
3. Calculate e (exponent field value) normalized values:
    - k = 4
    - Bias = 2^(k-1) - 1 
    - 2^(4-1) = 2^3 = 8
    - 8 - 1 = 7
    - bias is 7
    - e = E + bias
    - e = -1 + 7 = 6 
    - e into binary k=4 bits
    - 0110
4. Round to even
    - Lets look at the bit pattern
    - 0110 1001
    - We need to round-to-even as 1001 will not fit into Form B frac 3bits

**Format B binary bit pattern**
|||||||||||
|---|---|---|---|---|---|---|---|---|---|
|3|2|1|0|.|-1|-2|-3|-4|binary position
|2^3 (8)|2^2 (4)|2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|2^-3 (1/8)|2^-4 (1/16)|binary value
|0|1 |1 |0 |. | 1|0|0|**1**
|||||.|^|^|^|Round to 7bits
||||| | | |lsb|

- Half way is when bits to the right of rounding position (lsb) is 1 followed by all 0's 
- 1 at the 2^-4 position is exactly half way but it is preceded by 0. As 0 bit is even we can truncate (round down), this would result in an even number.

**Format B binary bit pattern**
|||||||||||
|---|---|---|---|---|---|---|---|---|---|
|3|2|1|0|.|-1|-2|-3|binary position
|2^3 (8)|2^2 (4)|2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|2^-3 (1/8)|binary value
|0|1 |1 |0|. | 1|0|0|

- Find Format B value
1. e (exponent field value)= 2^2 + 2^1 = 4 + 2 = 6
2. Calculate E (actual exponent) normalized values:
    - k = 4
    - Bias = 2^(k-1) - 1 
    - 2^(4-1) = 2^3 = 8
    - 8 - 1 = 7
    - bias is 7.
    - E = e - bias = 6 - 7 = -1
3. Calculate f:
    - 1/2
4. Calculate M for normalized values:
    - M = 1 + f
    - Fractional part is 1/2
    - Convert 1 1/2 to improper fraction
    - Multiple 1 by denominator 2 = 2
    - Add numerators 1 + 2 = 3
    - Place 3 over original denominator 2
    - M = 3/2
5. Calculate 2^E x M:
    - E = -1
    - M = 3/2
    - 2^-1 = 1/2
    - 1/2 x 3/2 
    - To multiply fractions, you multiply the numerators together and the denominators together.
    - 1/2 x 3/2 = (1 x 3)/(2 x 2)= 3/4
6. Value of format B is 3/4 or 0.75