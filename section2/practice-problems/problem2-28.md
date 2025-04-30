## Practice Problem 2.28 hardback page 89

### Unsigned additive inverse

- The unsigned additive inverse is not a negative number in the traditional sense but rather a number that, when added using modular arithmetic, results in zero.

- [Notes](../misc.md#twos-complement-addition)

- We can represent a bit pattern of length w = 4 with a single hex digit. 
- For an unsigned interpretation of these digits, fill in the following table giving the values and the bit representations (in hex) of the **unsigned additive inverses** of the digits shown.


|||x|______-(u/4)*x||||
|---|---|---|---|---|---|---|
||Hex|Decimal|Decimal|Hex
|[a.](#a)|0x0|0|0|0x0|
|[b.](#b)|0x5|5|11|0xB|
|[c.](#c)|0x8|8|8|0x8|
|[d.](#d)|0xd|13|3|0x3|
|[e.](#e)|0xF|15|1|0x1|


### solution
- modulo 16 arithmetic
- length w = 4, 2^4 = 16
### a.
### b.
- 0x5 = 5
- 2^w - 5 = 16 - 4 = 11 = 0xB
### c.
- 0x8 = 8
- 2^w - 8 = 16 - 8 = 8 = 0x8
### d.
- 0xD = 13
- 2^w - 13 = 16 - 13 = 3 = 0x3
### e.
- 0xF = 15
- 2^w - 15 = 16 - 15 = 1 = 0x1

<!-- (-u/4*x)+x = 16

u = 8
(-8/4*8)+8 = 16

-16 + 8 = -8

(-u/4*x)+x = 16

(-u/4*13)+13 = 16 -->

