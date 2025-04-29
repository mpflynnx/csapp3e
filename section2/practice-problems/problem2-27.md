## Practice Problem 2.27 hardback page 89

- [main.c](./code/problem2dot27/main.c)

### Unsigned addition

- Write a function with the following prototype:
```c
/* Determine whether arguments can be added without overflow */
int uadd_ok(unsigned x, unsigned y);
```

- This function should return 1 if arguments x and y can be added without causing overflow.

### solution

- UINT_MAX = 4294967295
- Programmatically get the max of type x
- When x < y < 16

```c
int uadd_ok(unsigned x, unsigned y){
    unsigned sum = x + y;
    return sum >= x;
}
```

- With no overflow, `sum` will always be greater or equal to `x` as `y` cannot be negative with `unsigned` types.

```
unsigned x = 4294967290;
unsigned y = 5;
mathematical sum = 4294967295

4294967295 >= 4294967291 is true
```
- If `sum` does overflow, the result will be wrapped around and will be less the `x`
```
unsigned x = 4294967291;
unsigned y = 5;
mathematical sum = 4294967296
wrapped around sum = 32767

32767 >= 4294967291 is false
```
### Alternative

- This version directly checks if adding `y` to `x` would exceed `UINT_MAX`
- As this would return false for no overflow we need to invert it to fit the `uadd_ok` spec
```c
int uadd_ok(unsigned x, unsigned y){
    return !((UINT_MAX - x) < y);
}
```

- With no overflow.
```
unsigned x = 4294967289;
unsigned y = 5;
mathematical sum = 4294967294

4294967295 - 4294967289 = 6
6 < 5 = false
```
- For overflow
```
unsigned x = 4294967289;
unsigned y = 7;

4294967295 - 4294967289 = 6

6 < y = true