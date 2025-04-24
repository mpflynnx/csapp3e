## Practice Problem 2.21 hardback page 76

If expression has mixed type then signed (+/-)values implicitly cast to unsigned(+)

Casting to unsigned, flips msb to +2^w-1 w=width-1

5bit width

- signed msb = 2^5-1 = 2^4 = -16
- unsigned msb = 2^5-1 = 2^4 = 16

|msb|||||||
|---|---|---|---|---|---|---|
|4|3|2|1|0
|+/-16|8 |4 |2 |1 | Binary position value |
|1|1 |1 |1 |1 | = -1 | signed
|1|1 |1 |1 |1 | = 31 | unsigned

Bit patterns match therefore `==` will be true

Unsigned if have `U` or `u` as suffix

- Two's complement min, Tmin = 2^(32-1) = 2^31 = -2147483647-1 (-2147483648)
    - Tmin = -2147483647-1 is written this way for the C compiler
- Two's complement max , Tmax = (2^32-1)-1 = (2^31)-1 = (2147483648)-1 or 2147483647

- [See video presentation slide](../slides/signed%20casting%20surprises.jpg)

Assuming the expressions are evaluated when executing a 32-bit program on a machine that uses two’s-complement arithmetic, fill in the following table describing the effect of casting and relational operations, in the style of Figure 2.19:

w = 32

- signed msb = 2^32-1 = 2^31 = -2147483648
- unsigned msb = 2^32-1 = 2^31 = 2147483648

|| Expression| Type | Evaluation |
|---|---|---|---|
|[a.](#a)|-2147483647-1 == 2147483648U|Unsigned|True or 1|
|[b.](#b)|-2147483647-1 < 2147483647|Signed|True or 1|
|[c.](#c)|-2147483647-1U < 2147483647|Unsigned|False or 0|
|[d.](#d)|-2147483647-1 < -2147483647|Signed|True or 1|
|[e.](#e)|-2147483647-1U < -2147483647|Unsigned|True or 1|

### a.
- -2147483647-1 (-2147483648) is signed min
- 2147483648U is unsigned the bit pattern is the same

- signed min bit pattern
    - 1000 0000 0000 0000 0000 0000 0000 0000
- signed max bit pattern
    - 0111 1111 1111 1111 1111 1111 1111 1111

- unsigned int 2147483648U bit pattern
    - 1000 0000 0000 0000 0000 0000 0000 0000

- Type is unsigned because of mixed expression, signed is cast to unsigned.
- Both bit patterns match, so expression is True or 1

### b.

-2147483647-1 < 2147483647

- -2147483647-1 (-2147483648) is signed min
- 2147483647 is signed max
- both are signed (not a mixed expression, no cast needed)

- signed min bit pattern
    - 1000 0000 0000 0000 0000 0000 0000 0000
- signed max bit pattern
    - 0111 1111 1111 1111 1111 1111 1111 1111

- Type is signed (not a mixed expression, no cast needed)
- Expression is True or 1 as signed min is less than signed max

### c. 

-2147483647-1U < 2147483647

- -2147483647-1U is different from `-2147483647-1`
- `-2147483647` - `1U` is an expression
- `1U` makes 1 here a unsigned integer
- Therefore `-2147483647` is cast to unsigned int
- When converting a negative two's complement number to unsigned, you add UMax + 1, in this case  to the two's complement negative value.
- -2147483647 + (4294967295 + 1) = 2147483649
- 2147483649 - 1 = 2147483648

- `< 2147483647` is cast to unsigned int and becomes 2147483647
- 2147483648 < 2147483647 is false.
- Type is unsigned (mixed expression casting)
- Expression is False or 0

### d.

-2147483647-1 < -2147483647

- -2147483647-1 (-2147483648) is signed min
- -2147483647 is signed

- Both are signed no cast needed
- Type is signed
- Expression is True or 1

### e.

-2147483647-1U < -2147483647

- -2147483647-1U is different from `-2147483647-1`
- `-2147483647` - `1U` is an expression
- `1U` makes 1 here a unsigned integer
- Therefore `-2147483647` is cast to unsigned int
- when converting a negative two's complement number to unsigned, you add UMax + 1, in this case (2^32)-1 to the two's complement negative value.
- -2147483647 + (4294967295 + 1) = 2147483649
- 2147483649 - 1 = 2147483648
- `< -2147483647` is cast to unsigned int
- when converting a negative two's complement number to unsigned, you add UMax, in this case (2^32)-1 to the two's complement negative value.
- -2147483647 + (4294967295 + 1) = 2147483649


- Therefore is: 2147483648 < 2147483649

- Type is unsigned
- Expression is True or 1



### aside
|msb||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|
|7|6|5|4|3|2|1|0
|128 |64 |32 | 16|8 |4 |2 |1 | Binary position value |
|0 |1 |1 | 1 | 1|1 |1 |1 |= 127 | TMax (2^7)-1
|1 |0 |0 | 0 | 0|0 |0 |0 |= -128 | TMin (-2^7)
|1 |1 |1 | 1 | 1|1 |1 |1 |= -1 | signed
|1 |1 |1 | 1 | 1|1 |1 |1 |= 255 | UMax
|0 |0 |0 | 0 | 0|0 |0 |0 |= 0 | UMin