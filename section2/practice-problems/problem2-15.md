## Practice Problem 2.15

Using only bit-level and logical operations, write a C expression that is equivalent to x == y. In other words, it will return 1 when x and y are equal and 0 otherwise.

my chunking

int x = 0x55;
int y = 0x55;

flip all bits of y using bit level operator ~
~y
~0x55 
|||
|--|--|
|~|01010101
| |10101010 = 

then bit level AND & with y

(x & ~y)

x 01010101
y 10101010

||||
|--|--|--|
|  |0x55 | 01010101|
|& |0xAA | 10101010|
|  |     | 00000000|

result = 00000000

need to flip this so result is true
use logical not ! operator


My answer:
!(x & ~y)

so (x & ~y) is the same as (x ^ y)

correct answer is !(x ^ y)

(x ^ y) get 0 if both 1

||||
|--|--|--|
|  |0x55 | 01010101|
|^ |0x55 | 01010101|
|  |     | 00000000|

