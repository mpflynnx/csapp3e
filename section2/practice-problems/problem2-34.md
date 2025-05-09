## Practice Problem 2.34 hardback page 98

### Multiplication

- [Notes](../misc.md#multiplication)

- Assume only three bits (w=3) are available (two's complement decimal -4 to +3)
- Assume only three bits (w=3) are available (unsigned decimal 7 to 0)

**Two complement w=3 table**
|||||||||
|---|---|---|---|---|---|---|---|
||4|3|2|1|0
||| |-4 |2 |1 | Binary position value |
| |||1|1|1| = -1 | Two's complement

**Unsigned w=3 table**
|||||||||
|---|---|---|---|---|---|---|---|
||4|3|2|1|0
||| |4 |2 |1 | Binary position value |
| |||1|1|1| = 7 | Unsigned

### Problem

- Fill in the following table showing the results of multiplying different 3-bit numbers, in the style of Figure 2.27 on page 98.


||Mode|____x||____y||_____x * y||Truncated x * y||
|---|---|---|---|---|---|---|---|---|---|
|||||
|[a.](#a)|Unsigned|4|100|5|101|4*5=20|10100|4|100|
||U2Tw|-4|100|-3|101|-4*-3=12|1100|-4|100|
|[b.](#b)|Unsigned|2|010|7|111|2*7=14|?|?|?|
||U2Tw|2|010|-1|111|?|?|?|?|
|[c.](#c)|Unsigned|6|110|6|110|6*6=36|?|?|?|
||U2Tw|-2|110|-2|110|?|?|?|?|

### Solutions

### a.
- Unsigned x `100` = 4
- Unsigned y `101` = 5
- unsigned multiplication of 4*5 = 20
- Unsigned `20` in binary is `10100`
- Truncate, ignore higher order bits `10` the unsigned result is `100` or 4
- Same result as 20 % 16 = 4
- Two's complement `100` = -4
- Two's complement `101` = -3
- Two's complement multiplication of `-4 * -3` = 12
- Two's complement `12` in binary is `1100`
- Truncate, ignore higher order bits `1` the unsigned result is `100` or -4.

### b.
- Unsigned x `010` = 2
- Unsigned y `111` = 7
- unsigned multiplication of 2*7 = 14
- Unsigned `14` in binary is `01110`
- Truncate, ignore higher order bits `01` the unsigned result is `110` or 4
- Two's complement `010` = -4
- Two's complement `111` = -3
- Two's complement multiplication of `-4 * -3` = 12
- Two's complement `12` in binary is `1100`
- Truncated, ignore higher order bits `1` the unsigned result is `100` or -4.

### c.


