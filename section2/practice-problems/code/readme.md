### Section 2 code

- A simple `main.c` which only initializes a integer variable named x
- Use it with gdb to view decimal,binary and hexadecimal equivalents of a given integer.

- Compiled using:
```bash
$ gcc -std=c99 -g main.c -o main
```
- Debug using
```bash
$ gdb ./main
```

- Using gdb to find binary and hexadecimal equivalents.
- Firstly run gdb and set a break point, then run the program. Program will halt at breakpoint.

```bash
gdb ./main

Reading symbols from ./main...
(gdb) b main // set breakpoint at main function start
Breakpoint 1 at 0x4010fa: file main.c, line 5.
(gdb) r // run the program upto breakpoint
Starting program: /run/media/live/ntfs/youtube-learning/CarnegieMellonUniversity_CMU/15-213/Introduction to Computer Systems (ICS)/book-csapp3e/section2/code/main 

Breakpoint 1, main () at main.c:5
5	    int x = 42424242; // (gdb) x/tb &x = 10100001110101011110110010
```

- Now you can update the value of the integer variable `x' using set command.

```bash
(gdb) set x = 8388608 // change x to the decimal value
```
- View the hexadecimal and binary equivalent
```
(gdb) p /x x // print hexadecimal of x
$1 = 0x800000
(gdb) p /t x // print binary of x
$2 = 100000000000000000000000
```

- Using gdb to find decimal from a hexadecimal
- Update the value of the integer variable `x` using set command. Use prefix `0x` for hexadecimal number.
```bash
(gdb) set x = 0x7af
(gdb) p x // prints decimal of x
$10 = 1967
````

### Compilation
Most 64-bit machines can also run programs compiled for use on 32-bit machines, a form of backward compatibility. So, for example, when a program prog.c
is compiled with the directive

-m32

then this program will run correctly on either a 32-bit or a 64-bit machine. On the other hand, a program compiled with the directive
-m64 
will only run on a 64-bit machine. 

- [C and C++ Integer Limits](https://learn.microsoft.com/en-us/cpp/c-language/cpp-integer-limits?view=msvc-170)
