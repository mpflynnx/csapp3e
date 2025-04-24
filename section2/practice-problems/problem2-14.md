## Practice Problem 2.14 pdf page 86


Fill in the byte values for the different C expressions

int a = 0x55;
int b = 0x46;


q1. 

a & b = ?

||||
|--|--|--|
|  |0x55 | 01010101|
|& |0x46 | 01000110|
|  |     | 01000100|

01000100 to decimal (not needed but)

2^6 + 2^2 = 64 + 4 = 68 decimal

01000100 to hexadecimal

This table helps with binary maths
|||||||
|---|---|---|---|---|---|
|8 |4 |2 |1 | Binary position value |
|0 |1 |0 |0 | = 4 | 0x4
|0 |1 |0 |0 | = 4| 0x4

a1. a & b = 0x44


q2. 

a | b = ?

||||
|--|--|--|
|  |0x55 | 01010101|
|\||0x46 | 01000110|
|  |     | 01010111|

01010111 to decimal (not needed but)

2^6 + 2^4 + 2^2 + 2^1 + 2^0 = 2^12 decimal
64 + 16 + 4 + 2 + 1 = 87

01010111 to hexadecimal

This table helps with binary maths
|||||||
|---|---|---|---|---|---|
|8 |4 |2 |1 | Binary position value |
|0 |1 |0 |1 | = 5 | 0x5
|0 |1 |1 |1 | = 7| 0x7

a2. a | b = 0x57


q3. 

~a | ~b = ?

~ 0x55 | ~ 0x46 = ?

~0x55 
|||
|--|--|
|~|01010101
| |10101010

~0x46 
|||
|--|--|
|~|01000110
| |10111001

Calculate 
`~0x55 | ~0x46`
||||
|--|--|--|
|  |~0x55 | 10101010
|\||~0x46 | 10111001
|  |      | 10111011



10111011 to hexadecimal

This table helps with binary maths
|||||||
|---|---|---|---|---|---|
|8 |4 |2 |1 | Binary position value |
|1 |0 |1 |1 | = 11 | 0xB
|1 |0 |1 |1 | = 11 | 0xB

a3. a | b = 0xBB


q4.

a & !b = 0x55 & !0x46

a = 0x55
!b = 0x00

0x55 & 0x00

||||
|--|--|--|
|  |0x55 | 01010101|
|& |0x00 | 00000000|
|  |     | 00000000|

a & !b = 0x00

q5.
a && b = 0x01, true as both are not 0x00

q6.
a || b = 0x01, true as both are not 0x00

q7.
!a || !b = !a = 0x00, !b = 0x00  0x00 || 0x00 = 0x00

q8.
a && ~b = 0x55 && ~0x46 = 0x01
