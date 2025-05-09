## Practice Problem 2.34 hardback page 98

### Two's-Complement Multiplication

- [Notes](../misc.md#multiplication)

- Fill in the following table showing the results of multiplying different 3-bit numbers, in the style of Figure 2.27 on page 98.
- Assume only three bits (w=3) are available (two's complement decimal -4 to +3)
- Assume only three bits (w=3) are available (unsigned decimal 7 to 0)

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
- Unsigned `100` = 4
- Unsigned `101` = 5
- unsigned multiplication of 4*5 = 20
- Unsigned `20` in binary is `10100`
- Truncated, ignore higher order bits `10` the unsigned result is `100` or 4
- Same result as 20 % 16 = 4
- Two's complement `100` = -4
- Two's complement `101` = -3
- Two's complement multiplication of `-4 * -3` = 12
- Two's complement `12` in binary is `1100`
- Truncated, ignore higher order bits `1` the unsigned result is `100` or -4.

### b.
<!-- - Unsigned `010` = ?
- Unsigned `111` = ?
- unsigned multiplication of ?*? = ?
- Unsigned `20` in binary is `10100`
- Truncated, ignore higher order bits `10` the unsigned result is `100` or 4
- Same result as 20 % 16 = 4
- Two's complement `100` = -4
- Two's complement `101` = -3
- Two's complement multiplication of `-4 * -3` = 12
- Two's complement `12` in binary is `1100`
- Truncated, ignore higher order bits `1` the unsigned result is `100` or -4. -->

### c.


