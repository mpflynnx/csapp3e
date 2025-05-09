## Practice Problem 2.34 hardback page 98

### Multiplication

- [Notes](../misc.md#multiplication)

- Assume only three bits (w=3) are available (two's complement decimal -4 to +3)
- Assume only three bits (w=3) are available (unsigned decimal 7 to 0)
- As multiplication of two numbers can require a width double that of w=3, represent binary result in a w=6 format

**Two complement w=6 table**
|||||||||
|---|---|---|---|---|---|---|---|
|5|4|3|2|1|0
|-32|16|8|4 |2 |1 | Binary position value |
| 1|1|1|1|1|1| = -1 | Two's complement

**Unsigned w=6 table**
|||||||||
|---|---|---|---|---|---|---|---|
|5|4|3|2|1|0
|32|16|8|4 |2 |1 | Binary position value |
| 0|0|0|1|1|1| = 7 | Unsigned

### Problem

- Fill in the following table showing the results of multiplying different 3-bit numbers, in the style of Figure 2.27 on page 98.


||Mode|____x||____y||_____x * y||Truncated x * y||
|---|---|---|---|---|---|---|---|---|---|
|||||
|[a.](#a)|Unsigned|4|100|5|101|4*5=20|010100|4|100|
||U2Tw|-4|100|-3|101|-4*-3=12|001100|-4|100|
|[b.](#b)|Unsigned|2|010|7|111|2*7=14|001110|6|110|
||U2Tw|2|010|-1|111|-2|111110|-2|110|
|[c.](#c)|Unsigned|6|110|6|110|6*6=36|100100|4|100|
||U2Tw|-2|110|-2|110|4|000100|-4|100|

### Solutions

### a.
- Unsigned x `100` = 4
- Unsigned y `101` = 5
- unsigned multiplication of 4*5 = 20
- Unsigned `20` in w=6 binary is `010100`
- Truncate, ignore higher order bits `010` the unsigned result is `100` or 4
- Same result as 20 % 16 = 4
- Two's complement `100` = -4
- Two's complement `101` = -3
- Two's complement multiplication of `-4 * -3` = 12
- Two's complement `12` in w=6 binary is `001100`
- Truncate, ignore higher order bits `001` the two's complement result is `100` or -4.

### b.
- Unsigned x `010` = 2
- Unsigned y `111` = 7
- unsigned multiplication of 2*7 = 14
- Unsigned `14` in w=6 binary is `001110`
- Truncate, ignore higher order bits `01` the unsigned result is `110` or 6
- Two's complement `010` = 2
- Two's complement `111` = -1
- Two's complement multiplication of `2 * -1` = -2
- Two's complement `-2` in w=6 binary is `111110`
- Truncate, ignore higher order bits `111` the two's complement result is `110` or -2.

### c.
- Unsigned x `110` = 6
- Unsigned y `110` = 6
- unsigned multiplication of `6*6 = 36`
- Unsigned `36` in w=6 binary is `100100`
- Truncate, ignore higher order bits `100` the unsigned result is `100` or 4
- Two's complement `110` = -2
- Two's complement `110` = -2
- Two's complement multiplication of `-2 * -2 = 4`
- Two's complement `4` in w=6 binary is `000100`
- Truncate, ignore higher order bits `000` the two's complement result is `100` or -4.

