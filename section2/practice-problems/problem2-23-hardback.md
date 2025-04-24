## Practice Problem 2.23 hardback page 80

- [main.c](./code/problem2dot23/main.c)

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


- Assume program executed on 32bit machine that use's two's-complement

### Sign extension on Two's complement numbers



