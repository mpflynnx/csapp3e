## Practice Problem 2.30 hardback page 94

### Two's-Complement Addition

- [main.c](./code/problem2dot30/)

- [Notes](../misc.md#twos-complement-arithmetic)

- Write a function with the following prototype:

```c
/* Determine whether arguments can be added without overflow */
int tadd_ok(int x, int y);
```

- This function should return 1 if arguments x and y can be added without causing overflow.


### Solution

- See main.c for solution
- Function takes in integer by default this is two's complement.
- Adding two positive numbers should not give a negative number.
- Adding two negative numbers should not give a positive number.
- Adding a positive number and a negative number should not give INT_MAX 
- Adding a negative number and a positive number should not give INT_MIN.
