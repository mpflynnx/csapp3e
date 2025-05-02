## CS:APP Web Aside DATA:TNEG

- [Bit-level representation of two's complement negation](http://csapp.cs.cmu.edu/3e/waside/waside-tneg.pdf)

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

### Two's complement negation (alternative method)

- An alternative technique for performing two's complement negation exists that offers a different perspective on the bitwise manipulation involved.
- Based on bit-level representation.
- We complement each bit to the left of rightmost **1** bit, a.k.a position _k_ (in bold)
- All bits to the right of position _k_ remain the same.
- Invert all the bits to the left of position _k_.

### Practice Problem 2

- Show how the bit-level negation procedure applies to the examples of Practice Problem 1. 
1) determine the bit position **k** of the rightmost 1,
2) apply the rule of complementing the bits to the left of position **k**.

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

### Practice Problem 3

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