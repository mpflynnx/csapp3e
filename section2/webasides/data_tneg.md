## CS:APP Web Aside DATA:TNEG

- [Bit-level representation of two's complement negation](http://csapp.cs.cmu.edu/3e/waside/waside-tneg.pdf)
- [Writing TMin in C](http://csapp.cs.cmu.edu/3e/waside/waside-tmin.pdf)
- [Bitwise Operators in C](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)

### Software used for code:
- OS
    - Slackware Live Xfce (15+) 23/04/25 - 32bit version
- Compiler/debugger
    - gcc (GCC) 14.2.0
    - GNU gdb (GDB) 16.3
    - GNU Make 4.4.1

### Practice problems TOC

- [Practice problem 1 | Complementing and incrementing](#practice-problem-1)
- [Practice Problem 2](#practice-problem-2)
- [Practice Problem 3 | Two's complement negation (alternative method)](#practice-problem-3)
- [Practice Problem 4](#practice-problem-4)
- [Practice Problem 5](#practice-problem-5)


### Practice Problem 1

- Fill in the following table showing the effects of complementing and incrementing several five-bit vectors
- Show both the bit vectors and the numeric values.
- Complement the bits `~x` and then increment the result `incr(~x)`


|||x||~x||incr(~x)|||
|---|---|---|---|---|---|---|---|---|
||Binary|Decimal|Binary|Decimal|Binary|Decimal|
|[a.](#a)|01101|13|10010|-14|10011|-13|
|[b.](#b)|01110|14|10001|-15|10010|-14|
|[c.](#c)|11000|-8|00111|7|01000|8|
|[d.](#d)|11111|-1|00000|0|00001|1|
|[e.](#e)|10000|-16|01111|15|10000|-16|

### Practice Problem 2

- Show that first decrementing and then complementing is equivalent to complementing and then incrementing.

|||x||dec(-x)||~x|||
|---|---|---|---|---|---|---|---|---|
||Binary|Decimal|Binary|Decimal|Binary|Decimal|
|[a.](#a)|01101|13|01100|12|10011|-13|
|[b.](#b)|01110|14|01101|13|10010|-14|
|[c.](#c)|11000|-8|10111|-7|01000|8|
|[d.](#d)|11111|-1|11110|-15|00001|1|
|[e.](#e)|10000|-16|01111|15|10000|-16|


- That is, for any signed value x, the C expressions -x,  ̃x+1, and  ̃(x-1) yield identical results. 
- What mathematical properties of two’s-complement addition does your derivation rely on?

### Two's complement negation (alternative method)

- An alternative technique for performing two's complement negation exists that offers a different perspective on the bitwise manipulation involved.
- Based on bit-level representation.
- We complement each bit to the left of rightmost _1_ bit, a.k.a position _k_ (in bold italics)
- All bits to the right of position _k_ remain the same.
- Invert all the bits to the left of position _k_.

### Practice Problem 3

- Show how the bit-level negation procedure applies to the examples of Practice Problem 1. 
1) Determine the bit position **_k_** of the rightmost 1,
2) Apply the rule of complementing the bits to the left of position **_k_**.

|||x||~x|||
|---|---|---|---|---|---|---|
||Binary|Decimal|Binary|Decimal|
|[a.](#a)|0110**1**|13|**1001**1|-13|
|[b.](#b)|011**1**0|14|**100**10|-14|
|[c.](#c)|1**1**000|-8|**0**1000|8|
|[d.](#d)|1111**1**|-1|**0000**1|1|
|[e.](#e)|**1**0000|-16|10000|-16|

### a.
- Right most bit **k** is 0110**1**
- Leave **k** as `1`
- Then complement only bits to the left of **k** i.e **1001**1

### b.
- Right most bit **k** is 011**1**0
- Leave **k** as `1`
- Then complement only bits to the left of **k** i.e **1001**1

### c.
- Right most bit **k** is 1**1**000
- Leave **k** as `1`
- Then complement only bits to the left of **k** i.e **0**1000

### d.
- Right most bit **k** is 1111**1**
- Leave **k** as `1`
- Then complement only bits to the left of **k** i.e **0000**1

### e.
- Right most bit **k** is **1**0000
- Leave **k** as `1`
- Then complement only bits to the left of **k**
- There are no bits to the left so the bits are unchanged 10000

### Practice Problem 4

- [main.c]()
- You are given the task of writing a function with the following prototype:

```c
/*
* Generate mask indicating rightmost 1 in x.
* For example 0xFF00 -> 0x0100, and 0x6600 --> 0x0200.
* If x == 0, then return 0.
*/
int rightmost_one(unsigned x);
```

- If argument x equals 0, this function returns 0. Otherwise, it returns a mask consisting of a single one in
the same position as the least significant bit with value 1 in x.
- Having just learned how to negate a number based on its bit-level representation, you realize this function can be written as a very simple expression having just two operations. 
- Show the code.



### Bit pattern representation analysis

**Two's complement numbers**
|Decimal|Hex|
|---|---|
|65280|0xff00 |
|-65280|0xffff0100|

**Bit pattern representation**
```bash      
00000000 00000000 11111111 00000000 - 0xff00
11111111 11111111 00000001 00000000 - 0xffff0100
                         ^--------^ Matching pattern from lsb to right most 1
```

|Decimal|Hex|
|---|---|
|26112|0x6600 |
|-26112|0xffff9a00|

**Bit pattern representation**
```bash      
00000000 00000000 01100110 00000000 - 0x6600
11111111 11111111 10011010 00000000 - 0xffff9a00
                        ^---------^ Matching pattern from lsb to right most 1
```

- The & (bitwise AND) in C takes two numbers as operands and does AND on every bit of two numbers. The result of AND is 1 only if both bits are 1.
- We can see the only place where both bits are 1 is also the right most 1 
- Therefore to find the right most 1 we perform AND with the positive and negative bit patterns of the same number.

```bash      
00000000 00000000 01100110 00000000 - 0x6600
11111111 11111111 10011010 00000000 - 0xffff9a00
                        ^ Right most 1 value 0x0200
```

```c
int x = 0x6600;
int y = -x; /* 0xffff9a00 */
result = x & y; /* 0x0200 or 10 Decimal*/
```

### Solution 

```c
/*
* Generate mask indicating rightmost 1 in x.
* For example 0xFF00 -> 0x0100, and 0x6600 --> 0x0200.
* If x == 0, then return 0.
*/
int rightmost_one(unsigned x);
    return (x & -x);
```
**gdb testing 0x6600**
```bash
Breakpoint 1, main () at main.c:15
15	    int x = 0x6600;
(gdb) n
17	    int result = rightmost_one(x);
(gdb) n
19	    return 0;
(gdb) x /t &result
0xbffff400:	00000000000000000000001000000000
(gdb) x /x &result
0xbffff400:	0x00000200
```
**gdb testing 0xFF00**
```bash
Breakpoint 1, main () at main.c:15
15	    int x = 0xFF00;
(gdb) n
17	    int result = rightmost_one(x);
(gdb) n
19	    return 0;
(gdb) p /x result
$28 = 0x100
(gdb) x /t &result
0xbffff400:	00000000000000000000000100000000
```

### Practice Problem 5

- [Writing TMin in C](http://csapp.cs.cmu.edu/3e/waside/waside-tmin.pdf)

- [main.c](../webasides/code/problem5/main.c)
- Suppose that we compile the code on a machine that uses a 32-bit, two’s complement representation of data type int, and that the compiler implements ISO-C99. For each of these, determine:

|||
|---|---|
|[A.](#5a)|2147483647 + 1
|[B.](#5b)|0x7FFFFFFF + 1
|[C.](#5c)|2147483649 - 1
|[D.](#5d)|0x80000001 - 1
|[E.](#5e)|-(2147483649 - 1)
|[F.](#5f)|-(0x80000001 - 1)


- What would be the resulting data type of the expression?
- What would be the resulting numeric value?
- Would we get TMin 32 if we cast the value to type int?

#### 5.A

- Try to compile a main.c with this line of code.

```c
    int x = 2147483647 + 1; /* A */
```
- Results in a compiler warning
```bash
$ make
gcc -std=c99 -g main.c -o main
main.c: In function ‘main’:
main.c:10:24: warning: integer overflow in expression of type ‘int’ results in ‘-2147483648’ [-Woverflow]
   10 |     int x = 2147483647 + 1; /* A */
      |                        ^

```

-  When the compiler encounters a number of the form X, it first determines the data type and value for X and then increments it. 

- The value 2,147,483,648 is too large to represent as an int, since this value is one larger than TMax 32. 

- The value overflows to become INT_MIN i.e -2147483648.

- Casting to an int would have no effect

#### 5.B

- Try to compile a main.c with this line of code.

```c
    int x = 0x7FFFFFFF + 1; /* A */
```
- Results in a compiler warning
```bash
$ make
gcc -std=c99 -g main.c -o main
main.c: In function ‘main’:
main.c:11:24: warning: integer overflow in expression of type ‘int’ results in ‘-2147483648’ [-Woverflow]
   11 |     int x = 0x7FFFFFFF + 1; /* B */
      |                        ^
```

-  When the compiler encounters a number of the form X, it first determines the data type and value for X and then increments it. 

- The value 0x7FFFFFFF is hexadecimal for 2,147,483,647. Adding 1, it would then be too large to represent as an int, since this value is one larger than TMax 32. 

- The value overflows to become INT_MIN i.e -2147483648.

- Casting to an int would have no effect

#### 5.C

- Try to compile a main.c with this line of code.

```c
    int x = 2147483649 - 1; /* C */
```

No compile warnings are given.

- For the case of ISO C99, for decimal value of x, the compiler proceeds from int to long to long long, finally finding a data type that can represent the number 2,147,483,649.
- Then the expression -1 is preformed.
- For example, to represent what is happening, force the value to fit using `long long` type.
- Regardless of whether you are on a 32-bit or 64-bit system, the size of `long long` is typically 64 bits (8 bytes).

```
long long x = 2,147,483,649L;
0x00 00 00 00 80 00 00 01 // 8 bytes wide

long long y = x - 1;
0x00 00 00 00 80 00 00 00 // 8 bytes wide
```
- Casting `long long` to an `int` strips the leading 0's to leave what is a representation of a negative signed integer of value -2147483648 aka TMIN 32.

```
int z = y;

0x80 00 00 00 // 4 bytes wide 
```

#### 5.D

- Try to compile a main.c with this line of code.

```c
    int x = 0x80000001 - 1; /* D */
```

No compile warnings are given.

This is the hexadecimal equivalent of problem 5.C 

```c
int x = 2147483649 - 1; /* C */
```

- For the case of ISO C99, for hexadecimal value of x, the compiler proceeds from int to unsigned, finally finding a data type that can represent the number 2,147,483,649.
- Then the expression -1 is preformed.
- For example, to represent what is happening, force the value to fit using `unsigned` type.

```
unsigned x = 0x80000001;
0x80 00 00 01 // 4 bytes wide

unsigned y = x - 1;
0x80 00 00 00 // 4 bytes wide
```
- Casting `unsigned` to an `int` leaves what is a representation of a negative signed integer of value -2147483648 aka TMIN 32.

```
int z = y;

0x80 00 00 00 // 4 bytes wide 
```

#### 5.E

- Try to compile a main.c with this line of code.

```c
    int x = -(2147483649 - 1); /* E */
```

No compile warnings are given.

<!-- -  When the compiler encounters a number of the form -X, it first determines the data type and value for X and then negates it. 

TMin 32 as -2147483648
The value 2,147,483,648 is too large to represent as an int, since this value is one larger than TMax 32 


- values 2,147,483,648 and −2,147,483,648 have the same bit representations
as 32-bit numbers

- For the case of ISO C99, the compiler proceeds from int to long to long long, finally finding a data type
that can represent the number 2,147,483,648.

- TMin 32 as -2147483647-1
- Since 2147483647 is the value
of TMax 32, it can be represented as an int, and hence there is no need to invoke the conversion rules -->


