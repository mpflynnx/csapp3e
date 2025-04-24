## Practice Problem 2.6

- [main.c](./code/problem2dot6/main.c)
- A simple `main.c` which only initializes a integer variable named x
- Use it with gdb to view decimal,binary and hexadecimal equivalents of a given integer.

- Compiled using:
```bash
$ gcc -std=c99 -g main.c -o main
```
- Debug using gdb in this case gdb was configured to use gdb-dashboard via /home/live/.gdbinit
```bash
$ gdb -q ./main
>>> b main
>>> r
>>> s
```

- Using gdb to find binary and hexadecimal equivalents.
- Firstly run gdb and set a break point, then run the program. Program will halt at breakpoint.


- Hexadecimal representations
```bash
>>> x /x &ival
0x7fffffffdf3c:	0x0027c8f8
>>> x /x &fval
0x7fffffffdf38:	0x4a1f23e0
```

A. Write the binary representations
```bash
>>> x /t &ival
0x7fffffffdf3c:	00000000001001111100100011111000
>>> x /t &fval
0x7fffffffdf38:	01001010000111110010001111100000
```

B.
- With the second word shifted two positions to the right relative to the first, we find a sequence with 21 matching bits.

00000000001001111100100011111000
>>01001010000111110010001111100000
             ^--------------^
111110010001111100000

00000000001001111100100011111000
>>01001010000111110010001111100000

C.

We find all bits of the integer embedded in the floating-point number, except for the most significant bit having value 0. In addition, the floating-point number has some nonzero high-order bits that do not match those of the integer.

page76

ival = 12345;

0x7fffffffdf38:	0x4640e400
>>> x /x &ival2
0x7fffffffdf3c:	0x00003039
>>> x /t &ival2
0x7fffffffdf3c:	00000000000000000011000000111001
>>> x /t &fval2
0x7fffffffdf38:	01000110010000001110010000000000

- With the second word shifted 10 positions to the right relative to the first, we find a sequence with 21 matching bits.

1000000111001
                  
00000000000000000011000000111001
>>>>>>>>>>01000110010000001110010000000000
                  ^^-----------^
                  |
                  msb
