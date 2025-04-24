## Practice Problem 2.23 hardback page 80

- [main.c](./code/problem2dot23/main.c)

- Here are two functions that are used for extracting values from a `word` in which multiple but fields have been packed.
- Note carefully the ordering of the cast and shift operations.
```c
int fun1(unsigned word) {
	return (int) ((word << 24) >> 24);
}
```
- Right shift is performed on unsigned variable `word`
- Right shifts of unsigned values are performed logically
- `fun1` extracts a value from low-order 8 bits giving an integer in range 0 to 255.

```c
int fun2(unsigned word) {
	return ((int) word << 24) >> 24;
}
```
- Right shift is performed on signed variable `word`
- Right shifts of signed values are performed arithmetically
- `fun2` extracts a value from low-order 8 bits but performs sign extension giving an integer in range -128 to 127.


- Assume program executed on 32bit machine that use's two's-complement i.e 1 word = 32bits (4 bytes)

A. Fill in the following table showing the effect of these functions for several example arguments. You will find it more convenient to work with a hexadecimal representation. Remember that hex digits 8 through F have, their
most significant bits equal to 1.

||w|fun1(w)|fun2(w)|
|--|--|--|--|
|[a.](#a-fun2w-explanation)|0x00000076|0x00000076|0x00000076
|[b.](#b-fun2w-explanation)|0x87654321|0x00000021|0x00000021
|[c.](#c-fun2w-explanation)|0x000000C9|0x000000C9|0xFFFFFFC9
|[d.](#d-fun2w-explanation)|0xEDCBA987|0X00000087|0xFFFFFF87

### a. `fun2(w)` Explanation
1. `(int) word << 24` would result in 0x**76**000000.
1. `>> 24` (arithmetic right shift because of the (int) cast):
1. Converting `0x76` to binary, reverse and convert hex to binary 
	- 0x6 = 0110
	- 0x7 = 0111

1. `0x76` in binary is 01110110 
1. Note that the msb is `0` the sign bit is positive.
1. The right shift will propagate this 0 to the left, resulting in 0x000000**76**, which represents 118 in two's complement.

### b. `fun2(w)` Explanation
1. `(int) word << 24` would result in 0x**21**000000.
1. `>> 24` (arithmetic right shift because of the (int) cast):
1. Converting `0x21` to binary, reverse and convert hex to binary 
	- 0x1 = 0001
	- 0x2 = 0010

1. `0x21` in binary is 00100001 
1. Note that the msb is `0` the sign bit is positive.
1. The right shift will propagate this 0 to the left, resulting in 0x000000**21**, which represents 33 in two's complement.

### c. `fun2(w)` Explanation
1. `(int) word << 24` would result in 0x**C9**000000.
1. `>> 24` (arithmetic right shift because of the (int) cast):
1. Converting `0xC9` to binary, reverse and convert hex to binary 
	- 0x9 = 1001
	- 0xC = 1100

1. `0xC9` in binary is 11001001 
1. Note that the msb is `1` the sign bit is negative.
1. The right shift will propagate this 1 to the left, resulting in 0xFFFFFF**C9**, which represents -55 in two's complement.

### d. `fun2(w)` Explanation
1. `(int) word << 24` would result in 0x**87**000000.
1. `>> 24` (arithmetic right shift because of the (int) cast):
1. Converting `0x87` to binary, reverse and convert hex to binary 
	- 0x7 = 0111
	- 0x8 = 1000

1. `0x87` in binary is 10000111 
1. Note that the msb is `1` the sign bit is negative.
1. The right shift will propagate this 1 to the left, resulting in 0xFFFFFF**87**, which represents -121 in two's complement.


B. Describe in words the useful computation each of these functions provide.

- `fun1()` retrieves the low order byte of the unsigned integer in range 0 to 255.
- `fun2()` retrieves the low order byte of the signed integer and performs sign conversion. Range -128 to 127. It's particularly useful when dealing with data where individual bytes have a signed interpretation within a larger unsigned container.