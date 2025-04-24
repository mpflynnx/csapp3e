### Practice Problem 2.2

When a value 'x' is a power of 2

2^0 = 1
2^1 = 2
2^2 = 4
2^3 = 8,

#### example:

| n | 2^n (decimal) | 2^n (hexadecimal | 2^n (binary)
|---|---|---|---|
5| 32 | 0x20 | 00100000

2^5 = 2 * 2 * 2 * 2 * 2 = 32

To convert the decimal number 32 to binary, we can use the method of successive division by 2:

- 32 / 2 = 16, remainder 0
- 16 / 2 = 8, remainder 0
- 8 / 2 = 4, remainder 0
- 4 / 2 = 2, remainder 0
- 2 / 2 = 1, remainder 0
- 1 / 2 = 0, remainder 1

Now, we read the remainders from bottom to top: 100000.

Therefore, 32 in binary is 100000.

To convert the hexadecimal number 0x20 to binary, we can convert each hexadecimal digit to its 4-bit binary equivalent.

2 = 0010
0 = 0000
Putting these together, we get:

0010 0000

Therefore, 0x20 in binary is 00100000.

Fill in the ? entries in the following table, giving the decimal and hexadecimal
representations of different powers of 2:

|| n | 2^n (decimal) | 2^n (hexadecimal)
|---|---|---|---|
a.|23|?|?|
b.|? |32,768|? 
c.|? | ? | 0x2000
d.|12 | ? | ?
e.|? | 64 | ?
f.|? | ? | 0x100

a. 2^23 (decimal) is 8388608.
- I opened a Python REPL in a terminal and type
```bash
$ python3
Python 3.9.21 (main, Dec  4 2024, 14:08:38) 
[GCC 11.2.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> import math
>>> pow(2,23)
8388608
```
a. Calculate **8388608** into hexadecimal.

x=q⋅16+r is the  division algorithm, specifically when dividing an integer x by 16. Here's a breakdown:
- x: This is the dividend, the number being divided.
- 16: This is the divisor, the number we are dividing by.
- q: This is the quotient, the whole number of times 16 goes into x.
- r: This is the remainder, the amount left over after dividing x by 16.

#### Calculations

- 8388608 / 16 = 524288, 8388608 % 16 gives a remainder 0
- 524288 / 16 = 32768, 524288 % 16 give a remainder 0
- 32768 / 16 = 2048, remainder 0
- 2048 / 16 = 128, remainder 0
- 128 / 16 = 8, remainder 0
- 8 / 16 = 0, remainder 8

There the hexadecimal representation is **0x800000**
| n | 2^n (decimal) | 2^n (hexadecimal)
|---|---|---|
23 | 8388608 | 0x800000

b. I am given a decimal of 32,768. I need to calculate the hexadecimal and the `n` value.

- To find 'n' when 2^n = 32,768, we need to determine what power of 2 equals 32,768

- Method1: Repeated division by 2: Keep dividing 32,768 by 2 until you reach 1, counting how many times you divide. `n` is 15.
- Method2: Calculate the base-2 logarithm of 32,768, `n` is 15.
```python
>>> import math
>>> math.log2(32768)
15.0
```
b. Calculate **32768** into hexadecimal.
#### Calculations

- 32768 / 16 = 2048, 32768 % 16 gives a remainder 0
- 2048 / 16 = 128, 2048 % 16 give a remainder 0
- 128 / 16 = 8, remainder 0
- 8 / 16 = 0, remainder 8

There the hexadecimal representation is **0x8000**
| n | 2^n (decimal) | 2^n (hexadecimal)
|---|---|---|
15 | 32768 | 0x8000

c. I am given only a hexadecimal value of 0x2000, I need to find n and 2^n.

- Firstly find the decimal. Multiply each hexadecimal digit by the appropriate power of 16.

Understanding Hexadecimal Place Values

Hexadecimal uses powers of 16.
0x2000 has:
2 in the 16³ (4096) place.
0 in the 16² (256) place.
0 in the 16¹ (16) place.
0 in the 16⁰ (1) place.
Conversion Process

1. Break down the hexadecimal number:

    -0x2000 = (2 * 16³) + (0 * 16²) + (0 * 16¹) + (0 * 16⁰)
1. Calculate the values:

    - 2 * 16³ = 2 * 4096 = 8192
    - 0 * 16² = 0
    - 0 * 16¹ = 0
    - 0 * 16⁰ = 0
1. Add the results:

- 8192 + 0 + 0 + 0 = 8192

Therefore, the decimal equivalent of 0x2000 is 8192.

I am given a decimal of 8192. I need to calculate the hexadecimal and the `n` value.

- To find 'n' when 2^n = 8192, we need to determine what power of 2 equals 8192

- Method1: Repeated division by 2: Keep dividing 8192 by 2 until you reach 1, counting how many times you divide. `n` is 13.
- Method2: Calculate the base-2 logarithm of 8192, `n` is 13.
```python
>>> import math
>>> math.log2(8192)
13.0
```

| n | 2^n (decimal) | 2^n (hexadecimal)
|---|---|---|
|13 | 8192 | 0x2000

d. Fill in the blank entries in the table.

| n | 2^n (decimal) | 2^n (hexadecimal)
|---|---|---|
|12 | ? | ?

2^n (decimal) = 2^12 = 4096 

```python
import math
pow(2,5)
4096
```

| n | 2^n (decimal) | 2^n (hexadecimal)
|---|---|---|
|12 | 4096 | ?

2^n (hexadecimal) calculations
- 4096 / 16 = 256, 4096 % 16 gives a remainder 0
- 256 / 16 = 16, 256 % 16 give a remainder 0
- 16 / 16 = 1, remainder 0

There the hexadecimal representation is **0x1000**

| n | 2^n (decimal) | 2^n (hexadecimal)
|---|---|---|
|12 | 4096 | 0x1000

e. Fill in the ? entries in the following table, giving the decimal and hexadecimal
representations of different powers of 2:

| n | 2^n (decimal) | 2^n (hexadecimal)
|---|---|---|
|? | 64 | ?

I am given a decimal of 64. I need to calculate the hexadecimal and the `n` value.

- To find 'n' when 2^n = 64, we need to determine what power of 2 equals 64

- Method1: Repeated division by 2: Keep dividing 64 by 2 until you reach 1, counting how many times you divide. `n` is 6.
- Method2: Calculate the base-2 logarithm of 32,768, `n` is 15.
```python
>>> import math
>>> math.log2(32768)
6.0
```
| n | 2^n (decimal) | 2^n (hexadecimal)
|---|---|---|
|6 | 64 | ?

Calculate **64** into hexadecimal.
#### Calculations

- 64 / 16 = 4, 64 % 16 gives a remainder 0
- 4 / 16 = 0, 16 % 16 give a remainder 4

There the hexadecimal representation is **0x40**

| n | 2^n (decimal) | 2^n (hexadecimal)
|---|---|---|
|6 | 64 | 0x40

f. Fill in the ? entries in the following table, giving the decimal and hexadecimal
representations of different powers of 2:

| n | 2^n (decimal) | 2^n (hexadecimal)
|---|---|---|
|? | ? | 0x100

I am given only a hexadecimal value of 0x100, I need to find n and 2^n.

- Firstly find the decimal. Multiply each hexadecimal digit by the appropriate power of 16.

Understanding Hexadecimal Place Values

Hexadecimal uses powers of 16.
0x100 has:
1 in the 16² (256) place.
0 in the 16¹ (16) place.
0 in the 16⁰ (1) place.
Conversion Process

1. Break down the hexadecimal number:

    -0x100 = (1 * 16²) + (0 * 16¹) + (0 * 16⁰)
1. Calculate the values:

    - 1 * 16² = 1 * 256 = 256
    - 0 * 16¹ = 0
    - 0 * 16⁰ = 0
1. Add the results:

- 256 + 0 + 0 = 256

Therefore, the decimal equivalent of 0x100 is 256.

| n | 2^n (decimal) | 2^n (hexadecimal)
|---|---|---|
|? | 256 | 0x100

- To find 'n' when 2^n = 256, we need to determine what power of 2 equals 256

- Method1: Repeated division by 2: Keep dividing 256 by 2 until you reach 1, counting how many times you divide. `n` is 8.
- Method2: Calculate the base-2 logarithm of 256, `n` is 8.
```python
>>> import math
>>> math.log2(32768)
8.0
```
| n | 2^n (decimal) | 2^n (hexadecimal)
|---|---|---|
|8 | 256 | 0x100

Completed table

|| n | 2^n (decimal) | 2^n (hexadecimal)
|---|---|---|---|
a.|23 | 8,388,608 | 0x800000
b.|15 | 32,768 | 0x8000 
c.|13 | 8,192 | 0x2000
d.|12 | 4,096 | 0x1000
e.|6 | 64 | 0x40
f.|8 | 256 | 0x100