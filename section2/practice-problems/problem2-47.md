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
possible) or as fractions of the form x/y , where y is a power of 2.

### Solution hints

- k = 2
- fraction denominator = 2^k = 2^2 = 4


#### Solution

**Binary bit pattern**
||||||||||||
|-|---|---|---|---|---|---|---|---|---|---|
||2|1|0|.|-1|-2|binary position
||Sign Bit|2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|binary value
a.|0 |0 |0 |.  | 0|0|If exponent all zeros. Use denormalized form d: 1 - Bias
b.|0 |0 |0 |.  | 0|1|d: 1 - Bias
[c.](#c)|0 |0 |0 |.  | 1|0|d: 1 - Bias


|        |Bits   |e|E    |2^E   |f  |M  |2^E x M  |V  |Decimal
|---     |---    |-|---  |---   |---|---|---      |---|---
|[a.](#a)|0 00 00|0|1-1=0|2^0 =1|0/4|0/4|1x0/4=0/4|0  |0.0
|[b.](#b)|0 00 01|0|1-1=0|2^0 =1|1/4|1/4|1x1/4=1/4|1/4|0.25
|[c.](#c)|0 00 10|0|1-1=0|2^0 =1|2/4|2/4|1x2/4=2/4|1/2|0.5


##### d.

|        |Bits   |e|E    |2^E   |f  |M  |2^E x M  |V  |Decimal
|---     |---    |-|---  |---   |---|---|---      |---|---
|[d.](#d)|0 00 11|-|-|-|-|-|-|-|-

**Binary bit pattern**
||||||||||||
|-|---|---|---|---|---|---|---|---|---|---|
||2|1|0|.|-1|-2|binary position
||Sign Bit|2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|binary value
[d.](#d)|0 |0 |0 |.  | 1|1|d: 1 - Bias

If exponent all zeros. Use denormalized form d: 1 - Bias

1. e = 2^0 = 1
2. Calculate E for denormalized values:
    - k = 2
    - Bias = 2^(k-1) - 1 
    - 2^(2-1) = 2^1 = 2
    - 2 - 1 = 1
    - bias is 1.
    - E = 1 - bias = 1 - 1 = 0
3. Calculate 2^E:
    - E = 0
    - 2^0 = 1
    - 2^E = 1
4. Calculate f:
    - Find the prime factorization of each number. (Break each number down into a product of prime numbers).
    - 2 = 2^1
    - 4 = 2 x 2 = 2^2
    - The only prime factor is 2
    - For each prime factor, identify the highest power (the most times it appears) in any of the factorizations.
    - The highest is 2^2 = 4 this is the common denominator
    - For 1/2: To change the denominator from 2 to 4, we multiply both the numerator and the denominator by 2:
    - 1/2 = 1 x 2 / 2 x 2 = 2 / 4
    - Now that all fractions have the same denominator, we can add their numerators:
    - 2/4 + 1/4  = 3/4
    - Therefore: 1/2 + 1/4 = 3/4
5. Calculate M for denormalized Values:
    - M = f
    - fractional part f is 3/4
    - M = 3/4
6. Calculate 2^E x M:
    - 2^E x M = 2^0 x 3/4
    - E = 0
    - M = 3/4
    - 2^0 = 1
    - 1 x 3/4 = 3/4
    - 2^E x M = 3/4
7. Calculate V
    - V = 3/4
8. Calculate Decimal
    - 3/4 to floating point number is 0.75

##### e.

|        |Bits   |e|E    |2^E   |f  |M  |2^E x M  |V  |Decimal
|---     |---    |-|---  |---   |---|---|---      |---|---
|[e.](#e)|0 01 00|-|-|-|-|-|-|-|-

**Binary bit pattern**
||||||||||||
|-|---|---|---|---|---|---|---|---|---|---|
||2|1|0|.|-1|-2|binary position
||Sign Bit|2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|binary value
[e.](#d)|0 |0 |1 |.  | 0|0|n: e - Bias

If exponent not all 0's or all 1's. Use normalized form n: e - Bias

1. e = 2^0 = 1
2. Calculate E normalized values:
    - k = 2
    - Bias = 2^(k-1) - 1 
    - 2^(2-1) = 2^1 = 2
    - 2 - 1 = 1
    - bias is 1.
    - E = e - bias = 1 - 1 = 0
3. Calculate 2^E:
    - E = 0
    - 2^0 = 1
    - 2^E = 1
4. Calculate f:
    - f = 0/4
5. Calculate M for normalized Values:
    - M = 1 + f
    - fractional part f is 0/4
    - Convert 1 0/4 to improper fraction
    - Multiple 1 by denominator 4
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

|        |Bits   |e|E    |2^E   |f  |M  |2^E x M  |V  |Decimal
|---     |---    |-|---  |---   |---|---|---      |---|---
|[f.](#f)|0 01 01|-|-|-|-|-|-|-|-

**Binary bit pattern**
||||||||||||
|-|---|---|---|---|---|---|---|---|---|---|
||2|1|0|.|-1|-2|binary position
||Sign Bit|2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|binary value
[f.](#f)|0 |0 |1 |.  | 0|1|n: e - Bias

If exponent not all 0's or all 1's. Use normalized form n: e - Bias
1. e = 2^0 = 1
2. Calculate E:
    - k = 2
    - Bias = 2^(k-1) - 1 
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
5. Calculate M for normalized Values:
    - M = 1 + f
    - fractional part f is 1/4
    - Convert 1 1/4 to improper fraction
    - Multiple 1 by denominator 4
    - 1 x 4 = 4
    - Add the numerators 4 + 1 = 5
    - Place 5 over original denominator 4
    - M = 5/4
6. Calculate 2^E x M:
    - 2^E x M = 2^0 x 5/4
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

|        |Bits   |e|E    |2^E   |f  |M  |2^E x M  |V  |Decimal
|---     |---    |-|---  |---   |---|---|---      |---|---
|[g.](#g)|0 01 10|-|-|-|-|-|-|-|-

**Binary bit pattern**
||||||||||||
|-|---|---|---|---|---|---|---|---|---|---|
||2|1|0|.|-1|-2|binary position
||Sign Bit|2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|binary value
[g.](#g)|0 |0 |1 |.  | 1|0|n: e - Bias

If exponent not all 0's or all 1's. Use normalized form n: e - Bias

1. Calculate e:
    - e = 2^0 = 1
2. Calculate E:
    - k = 2
    - Bias = 2^(k-1) - 1 
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
5. Calculate M for normalized Values:
    - M = 1 + f
    - fractional part f is 2/4
    - Convert 1 2/4 to improper fraction
    - Multiple 1 by denominator 4
    - 1 x 4 = 4
    - Add the numerators 2 + 4 = 6
    - Place 6 over original denominator 4
    - M = 6/4
6. Calculate 2^E x M:
    - 2^E x M = 2^0 x 6/4
    - E = 0
    - M = 6/4
    - 2^0 = 1
    - 1 x 6/4 = 6/4
    - 2^E x M = 6/4
7. Calculate V
    - Can 6/4 be simplified?
    - Use prime factorization (break each number down into a product of prime numbers).
    - divide 6 by a prime number until a whole number is found
    - 6 divided by prime 3 is 3.
    - Prime factor of 6 is 3
    - divide 4 by a prime number until a whole number is found
    - 4 divided by 2 is 2
    - Prime factor of 4 is 2     - V = 3/2
8. Calculate Decimal
    - 3/2 to floating point number is 1.5

##### h.

|        |Bits   |e|E    |2^E   |f  |M  |2^E x M  |V  |Decimal
|---     |---    |-|---  |---   |---|---|---      |---|---
|[h.](#h)|0 01 11|-|-|-|-|-|-|-|-

**binary pattern**
||2|1|0|.|-1|-2|binary position||||
|-|---|---|---|---|---|---|---|---|---|---|
||Sign Bit|2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|binary value
[h.](#h)|0 |0 |1 |.  | 1|1|n: e - Bias

If exponent not all 0's or all 1's. Use normalized form n: e - Bias
1. Calculate e:
    - e = 2^0 = 1
2. Calculate E:
    - k = 2
    - Bias = 2^(k-1) - 1 
    - 2^(2-1) = 2^1 = 2
    - 2 - 1 = 1
    - bias is 1.
    - E = e - bias = 1 - 1 = 0
3. Calculate 2^E:
    E = 0
    2^0 = 1
    2^E = 1
4. Calculate f:
    - 1/2 + 1/4
    - Find the prime factorization of each number. (Break each number down into a product of prime numbers).
        - 2 = 2^1
        - 4 = 2 x 2 = 2^2
    - The only prime factor is 2

    - For each prime factor, identify the highest power (the most times it appears) in any of the factorizations.
        - The highest is 2^2 = 4 this is the common denominator
    - For 1/2: To change the denominator from 2 to 4, we multiply both the numerator and the denominator by 2:
        - 1/2 = 1 x 2 / 2 x 2 = 2 / 4
    - Now that all fractions have the same denominator, we can add their numerators:
        - 2/4 + 1/4  = 3/4
        - Therefore: 1/2 + 1/4 = 3/4
5. Calculate M for normalized Values:
    - M = 1 + f
    - fractional part f is 3/4
    - Convert 1 3/4 to improper fraction
    - Multiple 1 by denominator 4
    - 1 x 4 = 4
    - Add the numerators 3 + 4 = 7
    - Place 7 over original denominator 4
    - M = 7/4
6. Calculate 2^E x M:
    - 2^E x M = 2^0 x 7/4
    - E = 0
    - M = 7/4
    - 2^0 = 1
    - 1 x 7/4 = 7/4
    - 2^E x M = 7/4
7. Calculate V
    - Can 7/4 be simplified?
    - No, 7 is a prime number
    - V = 7/4
8. Calculate Decimal
    - 7/4 to floating point number is 1.75

##### j.

|        |Bits   |e|E    |2^E   |f  |M  |2^E x M  |V  |Decimal
|---     |---    |-|---  |---   |---|---|---      |---|---
|[j.](#j)|0 10 00|-|-|-|-|-|-|-|-

**binary pattern**
||2|1|0|.|-1|-2|binary position||||
|-|---|---|---|---|---|---|---|---|---|---|
||Sign Bit|2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|binary value
[j.](#j)|0 |1 |0 |.  | 0|0|n: e - Bias

If exponent not all 0's or all 1's. Use normalized form n: e - Bias
1. Calculate e:
    - e = 2^1 = 2
2. Calculate E:
    - k = 2
    - Bias = 2^(k-1) - 1 
    - 2^(2-1) = 2^1 = 2
    - 2 - 1 = 1
    - bias is 1.
    - E = e - bias = 2 - 1 = 1
3. Calculate 2^E:
    E = 1
    2^1 = 2
    2^E = 2
4. Calculate f:
    - 0/4    
5. Calculate M for normalized Values:
    - M = 1 + f
    - fractional part f is 2 0/4
    - Convert 1 0/4 to improper fraction
    - Multiple 1 by denominator 4
    - 1 x 4 = 4
    - Add the numerators 4 + 0 = 4
    - Place 4 over original denominator 4
    - M = 4/4 
6. Calculate 2^E x M:
    - 2^E x M = 2^1 x 4/4
    - E = 1
    - M = 4/4
    - 2^1 = 2
    - 2 x 4/4 = 8/4
    - 2^E x M = 8/4
7. Calculate V
    - Can 8/4 be simplified?
    - Yes, 8/4 is 2
    - V = 2
8. Calculate Decimal
    - 2 to floating point number is 2.0

##### k.

|        |Bits   |e|E    |2^E   |f  |M  |2^E x M  |V  |Decimal
|---     |---    |-|---  |---   |---|---|---      |---|---
|[k.](#k)|0 10 01|-|-|-|-|-|-|-|-

**binary pattern**
||2|1|0|.|-1|-2|binary position||||
|-|---|---|---|---|---|---|---|---|---|---|
||Sign Bit|2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|binary value
[k.](#k)|0 |1 |0 |.  | 0|1|n: e - Bias

If exponent not all 0's or all 1's. Use normalized form n: e - Bias

1. Calculate e:
    - e = 2^1 = 2
2. Calculate E:
    - k = 2
    - Bias = 2^(k-1) - 1 
    - 2^(2-1) = 2^1 = 2
    - 2 - 1 = 1
    - bias is 1.
    - E = e - bias = 2 - 1 = 1
3. Calculate 2^E:
    E = 1
    2^1 = 2
    2^E = 2
4. Calculate f:
    - 1/4 + 0/4
    - common denominator is 4
    - all fractions have the same denominator, we can add their numerators:
    - 1 + 0 = 1
    - Place 1 over denominator 4
    - f = 1/4  
5. Calculate M for normalized Values:
    - M = 1 + f
    - fractional part f is 1/4
    - Convert 1 1/4 to improper fraction
    - Multiple 1 by denominator 4
    - 1 x 4 = 4
    - Add the numerators 4 + 1 = 5
    - Place 5 over original denominator 4
    - M = 5/4
6. Calculate 2^E x M:
    - 2^E x M = 2^1 x 5/4
    - E = 1
    - M = 5/4
    - 2^1 = 2
    - 2 x 5/4 = 10/4
    - 2^E x M = 10/4
7. Calculate V
    - Can 10/4 be simplified?
    - Yes, 10 divided by prime 2 is 5
    - 4 divided by prime 2 is 2
    - V = 5/2
8. Calculate Decimal
    - 5/2 to floating point number is 2.5

##### l.

|        |Bits   |e|E    |2^E   |f  |M  |2^E x M  |V  |Decimal
|---     |---    |-|---  |---   |---|---|---      |---|---
|[l.](#l)|0 10 10|-|-|-|-|-|-|-|-

**binary pattern**
||2|1|0|.|-1|-2|binary position||||
|-|---|---|---|---|---|---|---|---|---|---|
||Sign Bit|2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|binary value
[l.](#l)|0 |1 |0 |.  | 1|0|n: e - Bias

If exponent not all 0's or all 1's. Use normalized form n: e - Bias

1. Calculate e:
    - e = 2^1 = 2
2. Calculate E:
    - k = 2
    - Bias = 2^(k-1) - 1 
    - 2^(2-1) = 2^1 = 2
    - 2 - 1 = 1
    - bias is 1.
    - E = e - bias = 2 - 1 = 1
3. Calculate 2^E:
    E = 1
    2^1 = 2
    2^E = 2
4. Calculate f:
    - 1/2 + 0/4
    - The highest denominator is 2^2 = 4 this is the common denominator
    - For 1/2: To change the denominator from 2 to 4, we multiply both the numerator and the denominator by 2:
    - 1/2 = 1 x 2 / 2 x 2 = 2 / 4
    - all fractions have the same denominator, we can add their numerators:
    - 2 + 0 = 2
    - Place 2 over denominator 4
    - f = 2/4
5. Calculate M for normalized Values:
    - M = 1 + f
    - fractional part f is 2/4
    - Convert 1 2/4 to improper fraction
    - Multiple 1 by denominator 4
    - 1 x 4 = 4
    - Add the numerators 4 + 2 = 6
    - Place 5 over original denominator 4
    - M = 6/4
6. Calculate 2^E x M:
    - 2^E x M = 2^1 x 5/4
    - E = 1
    - M = 6/4
    - 2^1 = 2
    - 2 x 6/4 = 12/4
    - 2^E x M = 12/4
7. Calculate V
    - Can 12/4 be simplified?
    - Yes, 12 divided by prime 2 is 6
    - 4 divided by prime 2 is 2
    - V = 6/2 = 3
8. Calculate Decimal
    - 3 to floating point number is 3.0

##### m.

|        |Bits   |e|E    |2^E   |f  |M  |2^E x M  |V  |Decimal
|---     |---    |-|---  |---   |---|---|---      |---|---
|[m.](#m)|0 10 11|-|-|-|-|-|-|-|-

**binary pattern**
||2|1|0|.|-1|-2|binary position||||
|-|---|---|---|---|---|---|---|---|---|---|
||Sign Bit|2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|binary value
[m.](#m)|0 |1 |0 |.  | 1|1|n: e - Bias

If exponent not all 0's or all 1's. Use normalized form n: e - Bias

1. Calculate e:
    - e = 2^1 = 2
2. Calculate E:
    - k = 2
    - Bias = 2^(k-1) - 1 
    - 2^(2-1) = 2^1 = 2
    - 2 - 1 = 1
    - bias is 1.
    - E = e - bias = 2 - 1 = 1
3. Calculate 2^E:
    E = 1
    2^1 = 2
    2^E = 2
4. Calculate f:
    - 1/2 + 1/4
    - Find the prime factorization of each number. (Break each number down into a product of prime numbers).
        - 2 = 2^1
        - 4 = 2 x 2 = 2^2
    - The only prime factor is 2

    - For each prime factor, identify the highest power (the most times it appears) in any of the factorizations.
    - The highest is 2^2 = 4 this is the common denominator
    - For 1/2: To change the denominator from 2 to 4, we multiply both the numerator and the denominator by 2:
        - 1/2 = 1 x 2 / 2 x 2 = 2 / 4
    - Now that all fractions have the same denominator, we can add their numerators:
        - 2/4 + 1/4  = 3/4
        - Therefore: 1/2 + 1/4 = 3/4
5. Calculate M for normalized Values:
    - M = 1 + f
    - fractional part f is 3/4
    - Convert 1 3/4 to improper fraction
    - Multiple 1 by denominator 4
    - 1 x 4 = 4
    - Add the numerators 3 + 4 = 7
    - Place 7 over original denominator 4
    - M = 7/4
6. Calculate 2^E x M:
    - 2^E x M = 2^E x 7/4
    - E = 1
    - M = 7/4
    - 2^1 = 2
    - 2 x 7/4 = 14/4
    - 2^E x M = 14/4
7. Calculate V
    - Can 14/4 be simplified?
    - Yes, 14 divided by prime 2 is 7
    - 4 divided by prime 2 is 2
    - V = 7/2
8. Calculate Decimal
    - 7/2 to floating point number is 3.5

##### n.

|        |Bits   |e|E    |2^E   |f  |M  |2^E x M  |V  |Decimal
|---     |---    |-|---  |---   |---|---|---      |---|---
|[n.](#n)|0 11 00|-|-|-|-|-|-|-|-

**binary pattern**
||2|1|0|.|-1|-2|binary position||||
|-|---|---|---|---|---|---|---|---|---|---|
||Sign Bit|2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|binary value
[n.](#n)|0 |1 |1 |.  | 0|0| +Infinity

- The sign bit is 0, exponent field all 1's and fraction field is all 0's this results in positive infinity. Infinity represents overflow.
- If sign bit is 1, exponent field all 1's and fraction field is all 0's this results in negative infinity. Infinity represents overflow.

##### p.

|        |Bits   |e|E    |2^E   |f  |M  |2^E x M  |V  |Decimal
|---     |---    |-|---  |---   |---|---|---      |---|---
|[p.](#p)|0 11 01|-|-|-|-|-|-|-|-
||0 11 10|-|-|-|-|-|-|-|-
||0 11 11|-|-|-|-|-|-|-|-

**binary pattern**
||2|1|0|.|-1|-2|binary position||||
|-|---|---|---|---|---|---|---|---|---|---|
||Sign Bit|2^1 (2) |2^0 (1) |.|2^-1 (1/2)|2^-2 (1/4)|binary value
[p.](#p)|0 |1 |1 |.  | 0|1| NaN
||0 |1 |1 |.  | 1|0| NaN
||0 |1 |1 |.  | 1|1| NaN

- When exponent field all 1's and fraction field is non zero, this results in NaN or Not a Number.