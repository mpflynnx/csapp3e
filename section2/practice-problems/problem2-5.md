## Practice Problem 2.5 Hardback page 48


- [main.c](./code/problem2dot5/main.c)

- Consider the following three calls to show_bytes:

```c
int val = 0x87654321;
byte_pointer valp = (byte_pointer) &val;
show_bytes(valp, 1); /* A. */
show_bytes(valp, 2); /* B. */
show_bytes(valp, 3); /* C. */
```

- Indicate the values that will be printed by each call on a little-endian machine and on a big-endian machine:

||Little endian|Big endian|
|--|--|--|
A.|21| 87|
B.|21 43| 87 65|
c.|21 43 65| 87 65 43|

- Run the program on little-endian machine to check
- gdb result viewing val using `x /4bx &val'
- shows 4bytes in hexadecimal little-endian
```bash
(gdb) x /4bx &val
0x7fffffffdec4:	0x21	0x43	0x65	0x87
```