### Practice Problem 2.3

A single byte can be represented by 2 hexadecimal digits. Fill in the missing
entries in the following table, giving the decimal, binary, and hexadecimal values
of different byte patterns:

|| 2^n (decimal) | 2^n (binary) | 2^n (hexadecimal)
|---|---|---|---|
|-|0|0000 0000|0x00
|[a.](#a-convert-decimal-to-binary-and-hexadecimal)|158|?|?|
|[b.](#b-convert-decimal-to-binary-and-hexadecimal)|76|?|?|
|[c.](#c-convert-decimal-to-binary-and-hexadecimal)|145|?|?|
|[d.](#d-convert-decimal-to-binary-and-hexadecimal)|?|1010 1110|?|
|[e.](#e-convert-decimal-to-binary-and-hexadecimal)|?|0011 1100|?|
|[f.](#f-convert-decimal-to-binary-and-hexadecimal)|?|1111 0001|?|
|[g.](#g-convert-decimal-to-binary-and-hexadecimal)|?|?|0x75|
|[h.](#h-convert-decimal-to-binary-and-hexadecimal)|?|?|0xBD|
|[j.](#j-convert-decimal-to-binary-and-hexadecimal)|?|?|0xF5|


### a. Convert decimal to binary and hexadecimal

This table helps with binary maths
||||||||||
|---|---|---|---|---|---|---|---|---|
1   |2  |3  |4  |5 |6 |7 |8 | Binary Position
128 |64 |32 |16 |8 |4 |2 |1 | Binary value
2^7|2^6|2^5|2^4|2^3|2^2|2^1|2^0 |2^n



- Compare the decimal number to binary position value.
- Start at Binary position 1

- Rule1. If decimal smaller write a 0 (zero) then move on to the next table position.
- Rule2. If it is equal or larger - minus the binary position value from the decimal
number, add 1 to the binary value column

- is 158 equal to or greater than 128, yes use Rule2, add 1 to binary value

||||||||||
|---|---|---|---|---|---|---|---|---|
1   |2  |3  |4  |5 |6 |7 |8 | Binary Position
128 |64 |32 |16 |8 |4 |2 |1 | Binary value
1 | ? |?|?|?|?|?|?

- 158 subtract 128 equals 30
- Repeat process
- is 30 less than 64? yes, use Rule1, add 0 to column

||||||||||
|---|---|---|---|---|---|---|---|---|
1   |2  |3  |4  |5 |6 |7 |8 | Binary Position
128 |64 |32 |16 |8 |4 |2 |1 | Binary value
1 | 0 |?|?|?|?|?|?

- is 30 less than 32? yes, use Rule1, add 0 to column


||||||||||
|---|---|---|---|---|---|---|---|---|
1   |2  |3  |4  |5 |6 |7 |8 | Binary Position
128 |64 |32 |16 |8 |4 |2 |1 | Binary value
1 | 0 |0|?|?|?|?|?

- is 30 less than 16? no, use Rule2, add 1 to binary value


||||||||||
|---|---|---|---|---|---|---|---|---|
1   |2  |3  |4  |5 |6 |7 |8 | Binary Position
128 |64 |32 |16 |8 |4 |2 |1 | Binary value
1 | 0 |0|1|?|?|?|?

- 30 subtract 16 equals 14
- is 14 less than 8? no, use Rule2, add 1 to binary value

||||||||||
|---|---|---|---|---|---|---|---|---|
1   |2  |3  |4  |5 |6 |7 |8 | Binary Position
128 |64 |32 |16 |8 |4 |2 |1 | Binary value
1 | 0 |0|1|1|?|?|?

- 14 subtract 8 equals 6
- is 6 less than 4? no, use Rule2, add 1 to column

||||||||||
|---|---|---|---|---|---|---|---|---|
1   |2  |3  |4  |5 |6 |7 |8 | Binary Position
128 |64 |32 |16 |8 |4 |2 |1 | Binary value
1 | 0 |0|1|1|1|?|?

- 6 subtract 4 equals 2
- is 2 less than 2? no, use Rule2, add 1 to column

||||||||||
|---|---|---|---|---|---|---|---|---|
1   |2  |3  |4  |5 |6 |7 |8 | Binary Position
128 |64 |32 |16 |8 |4 |2 |1 | Binary value
1 | 0 |0|1|1|1|1|?

- 2 subtract 2 equals 0
- is 0 equal to or greater than 1? no, add 0 to column

||||||||||
|---|---|---|---|---|---|---|---|---|
1   |2  |3  |4  |5 |6 |7 |8 | Binary Position
128 |64 |32 |16 |8 |4 |2 |1 | Binary value
1 | 0 |0|1|1|1|1|0


- final binary number is
10011110

Concise calculations
- 158 => 128, yes, add 1, 158-128 = 30
- 30 => 64, no add 0
- 30 => 32, no add 0
- 30 => 16, yes, add 1, 30-16 = 14
- 14 => 8, yes, add 1, 14-8 = 6
- 6 => 4, yes, add 1, 6-4 = 2
- 2 => 2, yes, add 1, 2-2 = 0
- 0 => 1, no, add 0
- final binary number is 10011110

Method2. We can use the method of successive integer division by 2

- 158/2 = 79, 158%2 = 0
- 79/2 = 39, 79%2 = 1
- 39/2 = 19, 39%2 = 1
- 19/2 = 9, 19%2 = 1
- 9/2 = 4, 9%2 = 1
- 4/2 = 2, 4%2 = 0
- 2/2 = 1, 2%2 = 0
- 1/2 = 0, 1%2 = 1

Now, we read the remainders from bottom to top: 10011110

a. Convert 158 decimal to hexadecimal

x=q⋅16+r is the  division algorithm, specifically when dividing an integer x by 16. Here's a breakdown:
- x: This is the dividend, the number being divided.
- 16: This is the divisor, the number we are dividing by.
- q: This is the quotient, the whole number of times 16 goes into x.
- r: This is the remainder, the amount left over after dividing x by 16.

#### Calculations

- 158 / 16 = 9, 158 % 16 gives a remainder 14 or e
- 9 / 16 = 0, 9 % 16 give a remainder 9

There the hexadecimal representation is **0x9e**

|| 2^n (decimal) | 2^n (binary) | 2^n (hexadecimal)
|---|---|---|---|
|[a.](#a-convert-158-decimal-to-binary-and-hexadecimal)|158|10011110|0x9e|

### b. Convert decimal to binary and hexadecimal

|| 2^n (decimal) | 2^n (binary) | 2^n (hexadecimal)
|---|---|---|---|
|b.|76|?|?|

We can use the method of successive integer division by 2

- 76/2 = 38, 76%2 = 0
- 38/2 = 19, 38%2 = 0 
- 19/2 = 9, 19%2 = 1
- 9/2 = 4, 9%2 = 1
- 4/2 = 2, 4%2 = 0
- 2/2 = 1, 2%2 = 0
- 1/2 = 0, 1%2 = 1

Now, we read the remainders from bottom to top: 01011000

a. Convert 76 decimal to hexadecimal

x=q⋅16+r is the  division algorithm, specifically when dividing an integer x by 16. Here's a breakdown:
- x: This is the dividend, the number being divided.
- 16: This is the divisor, the number we are dividing by.
- q: This is the quotient, the whole number of times 16 goes into x.
- r: This is the remainder, the amount left over after dividing x by 16.

#### Calculations

- 76 / 16 = 4, 158 % 16 gives a remainder 12 or c
- 4 / 16 = 0, 4 % 16 give a remainder 4

There the hexadecimal representation is **0x4c**

|| 2^n (decimal) | 2^n (binary) | 2^n (hexadecimal)
|---|---|---|---|
|b.|76|01011000|0x4c|

### c. Convert decimal to binary and hexadecimal

|| 2^n (decimal) | 2^n (binary) | 2^n (hexadecimal)
|---|---|---|---|
|c.|145|?|?|

We can use the method of successive integer division by 2 to get binary representation of 145

- 145/2 = 72, 145%2 = 1
- 72/2 = 36, 72%2 = 0
- 36/2 = 18, 36%2 = 0 
- 18/2 = 9, 18%2 = 0
- 9/2 = 4, 9%2 = 1
- 4/2 = 2, 4%2 = 0
- 2/2 = 1, 2%2 = 0
- 1/2 = 0, 1%2 = 1

Now, we read the remainders from bottom to top: 10010001

Convert 145 decimal to hexadecimal

x=q⋅16+r is the  division algorithm, specifically when dividing an integer x by 16. Here's a breakdown:
- x: This is the dividend, the number being divided.
- 16: This is the divisor, the number we are dividing by.
- q: This is the quotient, the whole number of times 16 goes into x.
- r: This is the remainder, the amount left over after dividing x by 16.

#### Calculations

- 145 / 16 = 9, 145 % 16 gives a remainder 1
- 9 / 16 = 0, 9 % 16 gives a remainder 9

There the hexadecimal representation is **0x91**

|| 2^n (decimal) | 2^n (binary) | 2^n (hexadecimal)
|---|---|---|---|
|c.|145|10010001|0x91|

### d. Convert decimal to binary and hexadecimal

|| 2^n (decimal) | 2^n (binary) | 2^n (hexadecimal)
|---|---|---|---|
|d.|?|1010 1110|?|

Binary to decimal
This table helps with binary maths

||||||||||
|---|---|---|---|---|---|---|---|---|
1   |2  |3  |4  |5 |6 |7 |8 | Binary Position
128 |64 |32 |16 |8 |4 |2 |1 | Binary position value
1   |0  |1  |0  |1 |1 |1 |0 | Binary value

- sum = 0
- is position 1 = 1 yes 
- sum = sum + value1 = 0 + 128
- is position 2 = 1 no, skip
- is position 3 = 1 yes
- sum = sum + value3 = 128 + 32 = 160
- is position 4 = 1 no, skip
- is position 5 = 1 yes
- sum = sum + value5 = 160 + 8 = 168 
- is position 6 = 1 yes
- sum = sum + value6 = 168 + 4 = 172
- is position 7 = 1 yes
- sum = sum + value7 = 172 + 2 = 174
- is position 8 = 1 no, skip

Total sum is 174

Binary 1010 1110 to hexadecimal

This table helps with binary maths
|||||||
|---|---|---|---|---|---|
|8 |4 |2 |1 | Binary position value |
|1 |0 |1 |0 | = 10 | 0xA
|1 |1 |1 |0 | = 14| 0xE

|Binary|Decimal|Hexadecimal|
|---|---|---|
|1010|10|A|
|1110|14|E|


hexadecimal representation is **0xAE**

|| 2^n (decimal) | 2^n (binary) | 2^n (hexadecimal)
|---|---|---|---|
|d.|174|1010 1110|0xAE|

### e. Convert decimal to binary and hexadecimal

|| 2^n (decimal) | 2^n (binary) | 2^n (hexadecimal)
|---|---|---|---|
|e.|?|0011 1100|?|

Binary to decimal
This table helps with binary maths

||||||||||
|---|---|---|---|---|---|---|---|---|
1   |2  |3  |4  |5 |6 |7 |8 | Binary Position
128 |64 |32 |16 |8 |4 |2 |1 | Binary position value
0   |0  |1  |1  |1 |1 |0 |0 | Binary value

- sum = 0
- is position 1 = 1 no, skip 
- is position 2 = 1 no, skip
- is position 3 = 1 yes
- sum = sum + value3 = 0 + 32 = 32
- is position 4 = 1 yes
- sum = sum + value2 = 32 + 16 = 48
- is position 5 = 1 yes
- sum = sum + value5 = 48 + 8 = 56 
- is position 6 = 1 yes
- sum = sum + value6 = 56 + 4 = 60
- is position 7 = 1 no, skip
- is position 8 = 1 no, skip

Total sum is 60

Binary 0011 1100 to hexadecimal

This table helps with binary maths
|||||||
|---|---|---|---|---|---|
|8 |4 |2 |1 | Binary position value |
|0 |0 |1 |1 | = 3 | 0x3
|1 |1 |0 |0 | = 12| 0xC


hexadecimal representation is **0x3C**

|| 2^n (decimal) | 2^n (binary) | 2^n (hexadecimal)
|---|---|---|---|
|e.|60|0011 1100|0x3C|

### f. Convert decimal to binary and hexadecimal

|| 2^n (decimal) | 2^n (binary) | 2^n (hexadecimal)
|---|---|---|---|
|f.|?|1111 0001|?|

Binary to decimal
This table helps with binary maths

||||||||||
|---|---|---|---|---|---|---|---|---|
1   |2  |3  |4  |5 |6 |7 |8 | Binary Position
128 |64 |32 |16 |8 |4 |2 |1 | Binary position value
1   |1  |1  |1  |0 |0 |0 |1 | Binary value

- sum = 0
- is position 1 = 1 yes
- sum = sum + value1 = 0 + 128 = 128
- is position 2 = 1 yes
- sum = sum + value2 = 128 + 64 = 192
- is position 3 = 1 yes
- sum = sum + value3 = 192 + 32 = 224
- is position 4 = 1 yes
- sum = sum + value4 = 224 + 16 = 240
- is position 5 = 1 no, skip
- is position 6 = 1 no, skip
- is position 7 = 1 no, skip
- is position 8 = 1 yes
- sum = sum + value6 = 240 + 1 = 241


Total sum is 241

Binary 1111 0001 to hexadecimal

This table helps with binary maths
|||||||
|---|---|---|---|---|---|
|8 |4 |2 |1 | Binary position value |
|1 |1 |1 |1 | = 15 | 0xF
|0 |0 |0 |1 | = 1| 0x1


hexadecimal representation is **0xF1**

|| 2^n (decimal) | 2^n (binary) | 2^n (hexadecimal)
|---|---|---|---|
|f.|241|1111 0001|0xF1|

### g. Convert decimal to binary and hexadecimal

|| 2^n (decimal) | 2^n (binary) | 2^n (hexadecimal)
|---|---|---|---|
|[g.](#g-convert-decimal-to-binary-and-hexadecimal)|?|?|0x75|

Hexidecimal to binary

This table helps with binary maths
|||||||
|---|---|---|---|---|---|
|8 |4 |2 |1 | Binary position value |
|0 |1 |1 |1 | = 7 | 0x7
|0 |1 |0 |1 | = 5| 0x5

Reverse and convert to hex add a 
7 = 0111
5 = 0101

Answer: 01110101

Hexadecimal to decimal

Multiply each hexadecimal digit by the appropriate power of 16.

Understanding Hexadecimal Place Values

Hexadecimal uses powers of 16.
0x75 has:
7 in the 16¹ (16) place.
5 in the 16⁰ (1) place.
Conversion Process

1. Break down the hexadecimal number:

    -0x75 = (7 * 16¹) + (5 * 16⁰)
1. Calculate the values:

    - 7 * 16¹(16) = 112
    - 5 * 16⁰(1) = 5
1. Add the results:

- 112 + 5 = 117

Therefore, the decimal equivalent of 0x75 is 117.

|| 2^n (decimal) | 2^n (binary) | 2^n (hexadecimal)
|---|---|---|---|
|[g.](#g-convert-decimal-to-binary-and-hexadecimal)|117|01110101|0x75|

### h. Convert decimal to binary and hexadecimal

|| 2^n (decimal) | 2^n (binary) | 2^n (hexadecimal)
|---|---|---|---|
|[h.](#h-convert-decimal-to-binary-and-hexadecimal)|?|?|0xBD|

Hexadecimal to binary

This table helps with binary maths
|||||||
|---|---|---|---|---|---|
|8 |4 |2 |1 | Binary position value |
|1 |0 |1 |1 | = 11 | 0xB
|1 |1 |0 |1 | = 13 | 0xD

Reverse and convert to hex add a 
7 = 1011
5 = 1101

Answer: 10111101

Hexadecimal to decimal

Multiply each hexadecimal digit by the appropriate power of 16.

Understanding Hexadecimal Place Values

Hexadecimal uses powers of 16.
0xBD has:
B in the 16¹ (16) place.
D in the 16⁰ (1) place.
Conversion Process

1. Break down the hexadecimal number:

    -0xBD = (11 * 16¹) + (13 * 16⁰)
1. Calculate the values:

    - 11 * 16¹(16) = 176
    - 13 * 16⁰(1) = 13
1. Add the results:

- 176 + 13 = 189

Therefore, the decimal equivalent of 0xBD is 189.

|| 2^n (decimal) | 2^n (binary) | 2^n (hexadecimal)
|---|---|---|---|
|[h.](#h-convert-decimal-to-binary-and-hexadecimal)|189|10111101|0xBD|

### j. Convert decimal to binary and hexadecimal

|| 2^n (decimal) | 2^n (binary) | 2^n (hexadecimal)
|---|---|---|---|
|[j.](#j-convert-decimal-to-binary-and-hexadecimal)|?|?|0xF5|

Hexadecimal to binary

This table helps with binary maths
|||||||
|---|---|---|---|---|---|
|8 |4 |2 |1 | Binary position value |
|1 |1 |1 |1 | = 15 | 0xF
|0 |1 |0 |1 | = 5 | 0x5

Reverse and convert to hex add a 
F(15) = 1111
5 = 0101

Answer: 11110101

Hexadecimal to decimal

Multiply each hexadecimal digit by the appropriate power of 16.

Understanding Hexadecimal Place Values

Hexadecimal uses powers of 16.
0xF5 has:
F in the 16¹ (16) place.
5 in the 16⁰ (1) place.
Conversion Process

1. Break down the hexadecimal number:

    -0xF5 = (15 * 16¹) + (5 * 16⁰)
1. Calculate the values:

    - 15 * 16¹(16) = 240
    - 5 * 16⁰(1) = 5
1. Add the results:

- 240 + 5 = 245

Therefore, the decimal equivalent of 0xF5 is 245.

|| 2^n (decimal) | 2^n (binary) | 2^n (hexadecimal)
|---|---|---|---|
|[j.](#j-convert-decimal-to-binary-and-hexadecimal)|245|11110101|0xF5|