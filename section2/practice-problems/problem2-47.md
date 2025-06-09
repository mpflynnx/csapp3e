## Practice Problem 2.47 hardback page 117

- [notes | Floating point numbers](../misc.md#floating-point-numbers)

### Problem

Consider a 5-bit floating-point representation based on the IEEE floating-point format, with one sign bit, two exponent bits (k = 2), and two fraction bits (n = 2).
The exponent bias is 2^(2−1) − 1 = 1.
The table that follows enumerates the entire nonnegative range for this 5-bit floating-point representation. Fill in the blank table entries using the following directions:
- Exponent:
    - e: The value represented by considering the exponent field to be an unsigned integer
    - E: The value of the exponent after biasing (d: 1 - Bias, n: Exp - Bias)
    - 2^E : The numeric weight of the exponent
- Fraction:
    - f: The value of the fraction
    - M: The value of the significand
- Value:
    - 2^E × M: The (unreduced) fractional value of the number
    - V : The reduced fractional value of the number
    - Decimal: The decimal representation of the number

Express the values of 2^E , f , M, 2^E × M, and V either as integers (when
possible) or as fractions of the form x/y , where y is a power of 2. You need not fill in entries #.

### Solution hints

- k = 2
- fraction denominator = 2^k = 2^2 = 4

#### Useful table
||||||||||||
|-|---|---|---|---|---|---|---|---|---|---|
||2|1|0|.|-1|-2|binary position
||Sign Bit|2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|binary value
a.|0 |0 |0 |.  | 0|0|If exponent all zeros. Use denormalized form d: 1 - Bias
b.|0 |0 |0 |.  | 0|1|d: 1 - Bias
[c.](#c)|0 |0 |0 |.  | 1|0|d: 1 - Bias
[d.](#d)|0 |0 |0 |.  | 1|1|d: 1 - Bias
[e.](#e)|0 |0 |1 |.  | 0|0|If exponent not all 0's or all 1's. Use normalized form n: e - Bias
[f.](#f)|0 |0 |1 |.  | 0|1|n: e - Bias
[g.](#g)|0 |0 |1 |.  | 1|0|n: e - Bias

#### Solution

|        |Bits   |e|E    |2^E   |f  |M  |2^E x M  |V  |Decimal
|---     |---    |-|---  |---   |---|---|---      |---|---
|[a.](#a)|0 00 00|0|1-1=0|2^0 =1|0/4|0/4|1x0/4=0/4|0  |0.0
|[b.](#b)|0 00 01|0|1-1=0|2^0 =1|1/4|1/4|1x1/4=1/4|1/4|0.25
|[c.](#c)|0 00 10|0|1-1=0|2^0 =1|2/4|2/4|1x2/4=2/4|1/2|0.5
|[d.](#d)|0 00 11|0|1-1=0|2^0 =1|3/4|3/4|1x3/4=3/4|3/4|0.75
|[e.](#e)|0 01 00|1|0|2^0 =1|0/4|4/4|1x4/4=4/4|1|1.0
|[f.](#f)|0 01 01|-|-|-|-|-|-|-|-
|[g.](#g)|0 01 10|-|-|-|-|-|-|-|-

##### d.

- Find f : The value of the fraction

- Fraction recap

- 1/2 + 1/4 = 3/4

1. Find the prime factorization of each number. (Break each number down into a product of prime numbers).
    - 2 = 2^1
    - 4 = 2 x 2 = 2^2
    - The only prime factor is 2

2. For each prime factor, identify the highest power (the most times it appears) in any of the factorizations.
    - The highest is 2^2 = 4 this is the common denominator
3. For 1/2: To change the denominator from 2 to 4, we multiply both the numerator and the denominator by 2:
    - 1/2 = 1 x 2 / 2 x 2 = 2 / 4
4. Now that all fractions have the same denominator, we can add their numerators:
    - 2/4 + 1/4  = 3/4
    - Therefore: 1/2 + 1/4 = 3/4

##### e.

1. e = 2^0 = 1
2. Calculate E:
    - k = 2
    - Normalized bias = 2^(k-1) - 1 
    - 2^(2-1) = 2^1 = 2
    - 2 - 1 = 1
    - bias is 1.
    - E = e - bias = 1 - 1 = 0
3. Calculate 2^E:
    E = 0
    2^0 = 1
    2^E = 1
4. Calculate f:
    - f = 0/4
5. Calculate M:
    - Whole number e is 1
    - fractional part f is 0/4
    - Convert 1 0/4 to improper fraction
    - Multiple whole number 1 by denominator 4
    - 1 x 4 = 4
    - Add the numerators 4 + 0 = 4
    - Place 4 over original denominator 4
    - M = 4/4
6. Calculate 2^E x M:
    - 2^E x M = 2^0 x 4/4
    - E = 0
    - M = 4/4
    - 2^0 = 1
    - 1 x 4/4 = 4/4
    - 2^E x M = 4/4
7. Calculate V
    - 4/4 is 4 divided by 4 = 1
    - V = 1
8. Calculate Decimal
    - 1 to floating point number is 1.0

##### f.

1. e = 2^0 = 1
2. Calculate E:
    - k = 2
    - Normalized bias = 2^(k-1) - 1 
    - 2^(2-1) = 2^1 = 2
    - 2 - 1 = 1
    - bias is 1.
    - E = e - bias = 1 - 1 = 0
3. Calculate 2^E:
    E = 0
    2^0 = 1
    2^E = 1
4. Calculate f:
    - 1/4 + 0/4
    - common denominator is 4
    - all fractions have the same denominator, we can add their numerators:
    - 1 + 0 = 1
    - Place 1 over denominator 4
    - f = 1/4
5. Calculate M:
    - Whole number e is 1
    - fractional part f is 1/4
    - Convert 1 1/4 to improper fraction
    - Multiple whole number 1 by denominator 4
    - 1 x 4 = 4
    - Add the numerators 4 + 1 = 5
    - Place 5 over original denominator 4
    - M = 5/4
6. Calculate 2^E x M:
    - 2^E x M = 2^0 x 4/4
    - E = 0
    - M = 5/4
    - 2^0 = 1
    - 1 x 5/4 = 5/4
    - 2^E x M = 5/4
7. Calculate V
    - 5/4 is 5 divided by 4 = 1
    - V = 5/4
8. Calculate Decimal
    - 5/4 to floating point number is 1.25

##### g.

1. e = 2^0 = 1
2. Calculate E:
    - k = 2
    - Normalized bias = 2^(k-1) - 1 
    - 2^(2-1) = 2^1 = 2
    - 2 - 1 = 1
    - bias is 1.
    - E = e - bias = 1 - 1 = 0
3. Calculate 2^E:
    E = 0
    2^0 = 1
    2^E = 1
4. Calculate f:
    - 1/2 + 0/4
    - The highest denominator is 2^2 = 4 this is the common denominator
    - For 1/2: To change the denominator from 2 to 4, we multiply both the numerator and the denominator by 2:
    - 1/2 = 1 x 2 / 2 x 2 = 2 / 4
    - all fractions have the same denominator, we can add their numerators:
    - 2 + 0 = 2
    - Place 2 over denominator 4
    - f = 2/4
5. Calculate M:
    - Whole number e is 1
    - fractional part f is 2/4
    - Convert 1 1/2 to improper fraction
    - Multiple whole number 1 by denominator 2
    - 1 x 2 = 2
    - Add the numerators 2 + 1 = 3
    - Place 3 over original denominator 4
    - M = 3/4
6. Calculate 2^E x M:
    - 2^E x M = 2^0 x 4/4
    - E = 0
    - M = 5/4
    - 2^0 = 1
    - 1 x 5/4 = 5/4
    - 2^E x M = 5/4
7. Calculate V
    - 5/4 is 5 divided by 4 = 1
    - V = 5/4
8. Calculate Decimal
    - 5/4 to floating point number is 1.25