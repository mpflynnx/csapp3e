## Practice Problem 2.45 hardback page 111

- [notes | Floating point numbers](../misc.md#floating-point-numbers)
- [errata page 111]()
### Problem

Fill in the missing information in the following table:

||Fractional value|Binary representation|Decimal representation
|---|---|---|---|
|[a.](#a)|1/8|0.001|0.125
|[b.](#b)|3/4|?|?
|[c.](#c)|25/16|?|?
|[d.](#d)|?|10.1011|?
|[e.](#e)|?|1.001|?
|[f.](#f)|?|?|5.875
|[g.](#g)|?|?|3.1875

Errata page. 111, Practice Problem 2.45. The entry in the third row should be 25/16.

#### Hint
- One simple way to think about fractional binary representations is to represent a number as a fraction of the form x/2^k.
- We can write this in binary using the binary representation of x, with the binary point inserted k positions in from the right.
- As an example, for 25/16, we have decimal 25 = binary 11001
- 1/16 is at the -4 binary position, so k is 4
- We then put the binary point 4 positions from the right to get binary representation of 1.1001

### Solutions

#### a.
- Given fractional value of 1/8
- As 1/8 is a x/2^k we can represent is exactly

|||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|
|4|3|2|1|0|.|-1|-2|-3|-4| binary position
|16|8 |4 |2 |1 |.|1/2|1/4|1/8|1/16|binary value
|| | | |0 |.  | 0|0|1||binary representation|

Decimal 1 divided by 8 = 0.125 

#### b.
- Given fractional value of 3/4
- Decimal representation 3/4 is  3 divided by 4 = 0.75
- 0.75 can be made up of 0.5 + 0.25
- Decimal 0.5 is 1/2
- Decimal 0.25 is 1/4

|||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|
|4|3|2|1|0|.|-1|-2|-3|-4| binary position
|16|8 |4 |2 |1 |.|1/2|1/4|1/8|1/16|binary value
|| | | |0 |.  | 1|1|||binary representation|

- binary representation is 0.11

#### c.
- Given fractional value of 25/16
- Decimal representation 25/16 is 25 divided by 16 = 1.5625
-  0.5625 as a fraction in simplest form is 9/16
- 9/16 can be presented as
- 8/16 + 1/16 = 9/16
- in decimal that's, 0.5 + 0.0625
- in fractions that's, 1/2 + 1/16
- binary representation is 1.1001

|||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|
|4|3|2|1|0|.|-1|-2|-3|-4| binary position
|16|8 |4 |2 |1 |.|1/2|1/4|1/8|1/16|binary value
|| | | |1 |.  | 1|0|0|1|binary representation|

##### c. Alternatively
- One simple way to think about fractional binary representations is to represent a number as a fraction of the form x/2^k.
- For improper fraction 25/16, we have decimal 25 which is in binary 11001
- 1/16 is at the -4 binary position, so k is 4
- We then put the binary point 4 positions from the right to get binary representation of 1.1001

#### d.
- Given the binary representation 10.1011
- Find the fractional representation

|||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|
|4|3|2|1|0|.|-1|-2|-3|-4| binary position
|16|8 |4 |2 |1 |.|1/2|1/4|1/8|1/16|binary value
|| | |1 |0 |. | 1|0|1|1|binary representation|

- 2 is the whole number
- 1/2 + 1/8 + 1/16 is the fractional part
1. For the fractional part, find the common denominator.

2. Find the prime factorization of each denominator. (Break each number down into a product of prime numbers).
    - 2 = 2^1
    - 8 = 2 x 2 x 2 = 2^3
    - 16 = 2 x 2 x 2 x 2 = 2^4
    - The only prime factor is 2
    - The highest is 2^4 = 16 this is the common denominator

3. For 1/2: To change the denominator from 2 to 16, we multiply both the numerator and the denominator by 8:
- 1/2 = 1 x 8 / 2 x 8 = 8 / 16
4. For 1/8: To change the denominator from 8 to 16, we multiply both the numerator and the denominator by 2:
- 1/8 = 1 x 2 / 8 x 2 = 2 / 16
5. For 1/16: This fraction already has a denominator of 16, so it remains the same:
- 1 / 16
6. Add the fractions
- 8/16 + 2/16 + 1/16 = (8+2+1)/16 = 11/16
7. Can 11/16 be simplified further?
    - prime factor of 11 is 11 (prime number)
    - prime factor of 16 is 2^4, 2
    - there are no common factors so 11/16 is the simplest form
8. The mixed number consists a whole number and a fractional part: 2 11/16
9. Convert mixed number to a improper fraction
10. Multiply the whole number by the denominator
- 2 x 16 = 32
11. Add the numerator of the fraction 11 to 32.
- 11 + 32 = 43
12. Place 43 over the original denominator 16
- 43/16
13. The fractional representation as a improper number is 43/16
14. As a decimal 43/16 is 2.6875
15. Check the binary representation using the improper fraction.
    - One simple way to think about fractional binary representations is to represent a number as a fraction of the form x/2^k.
    - For improper fraction 43/16, we have decimal 43 which is in binary 101011
    - 1/16 is at the -4 binary position, so k is 4
    - We then put the binary point 4 positions from the right to get binary representation of 10.1011

#### e.
- Given the binary representation 1.001
- Find the fractional representation

|||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|
|4|3|2|1|0|.|-1|-2|-3|-4| binary position
|16|8 |4 |2 |1 |.|1/2|1/4|1/8|1/16|binary value
|| | | |1 |. | 0|0|1||binary representation|

- 1 is the whole number
- 1/8 is the fractional part

1. The mixed number consists a whole number and a fractional part: 1 1/8
2. Convert mixed number to a improper fraction
3. Multiply the whole number by the denominator
    - 1 x 8 = 8
4. Add the numerator of the fraction 1 to 8.
    - 1 + 8 = 9
5. Place 9 over the original denominator 8
    - 9/8
6. The fractional representation as a improper number is 9/8
7. As a decimal number 9/8 is 1.125

#### f.
- Given the decimal representation 5.875
- Find the improper fraction
1. Write the decimal as a fraction
    - whole number is 5 
    - 0.875 has three digits after the decimal point so the fractional part is 875/1000
2. Simplify the fraction part
3. Find common divisor (GCD) of 875
    - Use prime factorization (break each number down into a product of prime numbers).
    - divide 875 by a prime number until a whole number is found
    - first prime 2: no, move to next prime number 3 
    - second prime 3: no, move to next prime number 5
    - third prime 5: yes, 875 / 5 = 175
    - 5 x 175 = 875, first product 5
    - divide 175 by a prime number until a whole number is found
    - first prime 2: no, move to next prime number 3 
    - second prime 3: no, move to next prime number 5
    - third prime 5: yes, 175 / 5 = 35
    - 5 x 35 = 175, second product 5
    - divide 35 by a prime number until a whole number is found
    - first prime 2: no, move to next prime number 3 
    - second prime 3: no, move to next prime number 5
    - third prime 5: yes, 35 / 5 = 7
    - 5 x 7 = 35, third product 5
    - 7 is a prime number, so fourth product is 7
    - 5 x 5 x 5 x 7 = 875
    - 5^3 x 7 = 875
4. Find common divisor (GCD) of 1000
    - Use prime factorization (break each number down into a product of prime numbers).
    - divide 1000 by a prime number until a whole number is found
    - first prime 2: yes, 1000 / 2 = 500
    - 2 x 500 = 1000, first product 2 
    - divide 500 by a prime number until a whole number is found
    - first prime 2: yes, 500 / 2 = 250
    - 2 x 250 = 500, second product 2  
    - divide 250 by a prime number until a whole number is found
    - first prime 2: yes, 250 / 2 = 125
    - 2 x 125 = 250, third product 2
    - divide 125 by a prime number until a whole number is found
    - first prime 2: no, move to next prime number 3 
    - second prime 3: no, move to next prime number 3
    - third prime 3: yes, 125 / 5 = 25
    - 5 x 25 = 125, fourth product 5
    - divide 25 by a prime number until a whole number is found
    - first prime 2: no, move to next prime number 3 
    - second prime 3:no, move to next prime number 3
    - third prime 5: yes, 25 / 5 = 5
    - 5 x 5 = 25, fifth product 5
    - 5 is a prime number, so sixth product is 5
    - 2 x 2 x 2 x 5 x 5 x 5 = 1000
    - or 2^3 x 5^3
5. The common factor is 5^3 = 125
    - 875 divided by 125 = 7
    - 1000 divided by 125 = 8
    - so 875/1000 simplified it 7/8
6. mixed fraction is whole and fractional part
    - which is 5 7/8
7. Convert mixed number to a improper fraction
    - Multiply the whole number by the denominator
    - 5 x 8 = 40
    - Add the numerator of the fraction 7 to 40.
    - 40 + 7 = 47
    - Place 47 over the original denominator 8
    - 47/8
    - The fractional representation as a improper number is 47/8
14. As a decimal 47/8 is 5.875
15. Find binary representation of 47/8
    - One simple way to think about fractional binary representations is to represent a number as a fraction of the form x/2^k.
    - For improper fraction 47/8, we have decimal 47 which is in binary 101111
    - 1/8 is at the -3 binary position, so k is 3
    - We then put the binary point 3 positions from the right to get binary representation of 101.111

#### g.
- Given the decimal representation 3.1875
1. Find the improper fraction
    - Write the decimal as a fraction
    - whole number is 3 
    - 0.1875 has four digits after the decimal point so the fractional part is 1875/10000
2. Simplify the fraction part, by finding the common divisor of 1875
    - Use prime factorization (break each number down into a product of prime numbers).
    - divide 1875 by a prime number until a whole number is found
    - 1875 divided by prime 3 is 625
    - 3 x 625 = 1875, first product is 3.
    - divide 625 by a prime number until a whole number is found
    - 625 divided by prime 5 is 125
    - 5 x 125 = 625, second product is 5.
    - divide 125 by a prime number until a whole number is found
    - 125 divided by prime 5 is 25
    - 5 x 25 = 125, third product is 5.
    - divide 25 by a prime number until a whole number is found
    - 25 divided by prime 5 is 5
    - 5 x 5 = 25, fourth product us 5.
    - divide 5 by a prime number not needed as 5 is a prime.
    - fifth product is 5.
    - 3 x 5 x 5 x 5 x 5 = 1875
    - 3 x 5^4 
    - or 3 x 625 = 1875
3. Find common divisor (GCD) of 10000
    - Use prime factorization (break each number down into a product of prime numbers).
    - divide 10000 by a prime number until a whole number is found
    - 10000 divided by 2 is 5000
    - 2 x 5000 = 10000, first product is 2
    - 5000 divided by 2 is 2500
    - 2 x 2500 = 5000, second product is 2
    - 2500 divided by 2 is 1250
    - 2 x 1250 = 2500, third product is 2
    - 1250 divided by 2 is 625
    - 2 x 625 = 1250, fourth product is 2
    - 625 divided by 5 is 125
    - 5 x 125 = 625, fifth product is 5
    - 125 divided by 5 is 25
    - 5 x 25 = 125, sixth product is 5
    - 25 divided by 5 is 5
    - 5 x 5 = 25, seventh product is 5
    - 5 divided by a prime number is not needed as 5 is a prime.
    - eighth product is 5.
    - 2^4(16) x 5^4(625) = 10000
4. The common factor is 5^4 = 625
    - 1875 divided by 625 = 3
    - 10000 divided by 625 = 16
    - so 1875/10000 simplified is 3/16
5. Mixed fraction number is 3 3/16
6. Convert mixed fraction to improper fraction
    - Multiple the whole number 3 by denominator 16
    - 3 x 16 = 48
    - Add numerator 3 to 48
    - 48 + 3 = 51
    - Place 51 over denominator 16
    - 51/16 is the improper fraction
7. Confirm decimal representation of 51/16 is 3.1875
8. Find binary representation of 51/16.
    - One simple way to think about fractional binary representations is to represent a number as a fraction of the form x/2^k.
    - For improper fraction 51/16, we have decimal 51 which is in binary 110011
    - 1/16 is at the -4 binary position, so k is 4
    - We then put the binary point 4 positions from the right to get binary representation of 11.0011