## Practice Problem 2.33 hardback page 95

### Two's-Complement Negation

- [Notes](../misc.md#twos-complement-negation)

- We can represent a bit pattern of length w = 4 with a single hex digit.
- For a two’s complement interpretation of these digits, fill in the following table to determine
the additive inverses of the digits shown:

|||x|______-(t/4)*x||||
|---|---|---|---|---|---|---|
||Hex|Decimal|Decimal|Hex
|[a.](#a)|0x0|_|_|_|
|[b.](#b)|0x5|5|_|_|
|[c.](#c)|0x8|8|_|_|
|[d.](#d)|0xd|13|_|_|
|[e.](#e)|0xF|15|_|_|


### Solution
- One technique for performing two’s-complement negation at the bit level is to complement the bits and
then increment the result.

### b.
- 0x5 = 0b0101
- Complement bits returns 0b1010 = -6
- Increment = -6 + 1 = -5
- Converting -5 or 0b1011 to Hex
- 0b1011 = 11 or 0xB

### c.
- 0x8 = 0b1000 = -8
- Complement bits returns 0b0111 = 7
- Increment = 7 + 1 = 8
- Converting 8 or 0b1000 to Hex
- 0b1000 = 8 or 0x8

### d.
- 0xD = 13
- 2^w - 13 = 16 - 13 = 3 = 0x3
### e.
- 0xF = 15
- 2^w - 15 = 16 - 15 = 1 = 0x1