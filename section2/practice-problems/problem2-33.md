## Practice Problem 2.33 hardback page 95

### Two's-Complement Negation

- [Notes](../misc.md#twos-complement-negation)
- [Bit-level representation of two's complement negation | CS:APP3e Web Asides](http://csapp.cs.cmu.edu/3e/waside/waside-tneg.pdf)

- We can represent a bit pattern of length w = 4 with a single hex digit.
- For a two’s complement interpretation of these digits, fill in the following table to determine
the additive inverses of the digits shown:
- What can be observed about the bit patterns generated when compared with unsigned negation?

|||x|______-(t/4)*x||||
|---|---|---|---|---|---|---|
||Hex|Decimal|Decimal|Hex
|[a.](#a)|0x0|0|_|_|
|[b.](#b)|0x5|5|_|_|
|[c.](#c)|0x8|8|_|_|
|[d.](#d)|0xd|13|_|_|
|[e.](#e)|0xF|15|_|_|


### Solution
- One technique for performing two’s-complement negation at the bit level is to complement the bits and then increment the result.

- [Completed table](#completed-table)

### a.
- 0x0 = 0b0000 = 0 in Decimal
- Complement bits returns 0b1111 = -1
- Increment = -1 + 1 = 0 in Decimal
- Converting 0b0000 = 0 to Hex
- 0b0000 = 0 or 0x0

### b.
- 0x5 = 0b0101 = 5 in Decimal
- Complement bits returns 0b1010 = -6
- Increment = -6 + 1 = -5 in Decimal
- Converting 0b1011 = -5 to Hex
- 0b1011 = 11 or 0xB

### c.
- 0x8 = 0b1000 = -8 in Decimal
- Complement bits returns 0b0111 = 7
- Increment = 7 + 1 = 8 in Decimal
- Convert 0b1000 = -8 to Hex
- 0b1000 = 8 or 0x8

### d.
- 0xd = 0b1101 = -3 in Decimal
- Complement bits returns 0b0010 = 2
- Increment = 2 + 1 = 3 in Decimal
- Convert 0b0011 = 3 to Hex
- 0b0011 = 3 or 0x3
### e.
- 0xF = 0b1111 = -1 in Decimal
- Complement bits returns 0b0000 = 0
- Increment = 0 + 1 = 1 in Decimal
- Convert 0b0001 = 1 to Hex
- 0b0001 = 1 or 0x1


### Completed table
|||x|______-(t/4)*x||||
|---|---|---|---|---|---|---|
||Hex|Decimal|Decimal|Hex
|[a.](#a)|0x0|0|0|0x0|
|[b.](#b)|0x5|5|-5|0xB|
|[c.](#c)|0x8|8|-8|0x8|
|[d.](#d)|0xd|-3|3|0x3|
|[e.](#e)|0xF|-1|1|0x1|

### Unsigned negation Comparison

- The same bit pattern are returned for Unsigned negation.

|||x|______-(u/4)*x||||
|---|---|---|---|---|---|---|
||Hex|Decimal|Decimal|Hex
|[a.](#a)|0x0|0|0|0x0|
|[b.](#b)|0x5|5|11|0xB|
|[c.](#c)|0x8|8|8|0x8|
|[d.](#d)|0xd|13|3|0x3|
|[e.](#e)|0xF|15|1|0x1|