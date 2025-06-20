## CS:APP Web Aside DATA:TMIN

- [Writing TMin in C](http://csapp.cs.cmu.edu/3e/waside/waside-tmin.pdf)
- [Bitwise Operators in C](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)

### Software used for code:
- OS
    - Slackware Live Xfce (15+) Build Date 23/04/25 - 32bit version
    - Compiler/debugger
    - gcc (GCC) 14.2.0
    - GNU gdb (GDB) 16.3
    - GNU Make 4.4.1
- OS
    - Slackware 15 - 64bit version
    - Compiler/debugger
    - gcc (GCC) 11.2.0
    - GNU gdb (GDB) 11.2
    - GNU Make 4.3

### Understanding Tmin
In two's complement representation, which is almost universally used for integers in computers:

- Tmax (maximum integer value) is represented by 0 followed by all 1s. For a 32-bit integer, this is 0111...111 (31 ones).
- Tmin (minimum integer value) is represented by 1 followed by all 0s. For a 32-bit integer, this is 1000...000 (31 zeros).

This means that the most significant bit (MSB) of Tmin is 1, and all other bits are 0.

#### How to achieve Tmin from 1 using bitwise operators
You can achieve Tmin by left-shifting the most significant bit (which is initially 1 in Tmin) into its correct position.

1. Start with 1: The number 1 in binary is 00...001.
2. Left Shift: To get Tmin, you need to move this 1 to the most significant bit position. For a 32-bit integer, this means shifting it left by (sizeof(int) * 8 - 1) positions.

Let's illustrate with an example assuming a 32-bit integer:

- sizeof(int) is typically 4 bytes.
- sizeof(int) * 8 is 32 bits.
- sizeof(int) * 8 - 1 is 31.

So, 1 << 31 would result in Tmin.

#### C function to return Tmin
- Using only one left shift operator.
```c
int tmin(void) {
    int x = 1;
    return x << 31;
}
```

### Page 3 example code
- [main.c](./code/data_tmin/example/C90/main.c)

- 32bit C90 compile warning

```bash
$ make
gcc -std=c90 -g main.c -o main
main.c: In function ‘main’:
main.c:15:5: warning: this decimal constant is unsigned only in ISO C90
   15 |     int dpos32 = (-2147483648 > 0);
      |     ^~~

```
- 32bit C90 result

```bash
(gdb) p dpos32
$1 = 1
(gdb) p hpos32
$2 = 1
```
- 64bit C90 no compile warning
- 64bit C90 result
```
(gdb) p dpos32
$1 = 0
(gdb) p hpos32
$2 = 1
```


- 32bit C99 no compile warning

```bash
$ make
gcc -std=c99 -g main.c -o main
```

- 32bit C99 result

```bash
(gdb) p dpos32
$1 = 0
(gdb) p hpos32
$2 = 1
```
- 64bit C99 no compile warning
- 64bit C99 result
```bash
(gdb) p dpos32
$1 = 0
(gdb) p hpos32
$2 = 1
```

### Practice problems TOC

- [Practice problem 1](#practice-problem-1)
- [Practice Problem 2](#practice-problem-2)
- [Practice Problem 3](#practice-problem-3)
- [Practice Problem 4](#practice-problem-4)


### Practice Problem 1

- [main.c](../webasides/code/data_tmin/problem1/C90/main.c)

```c
    int dtmin32 = -2147483648;
    int dpos32a = (dtmin32 > 0);
    int htmin32 = 0x80000000;
    int hpos32a = (htmin32 > 0);
```

- -2147483648 is the decimal value for TMIN and fits into signed integer 4bytes
- 0x80000000 is the hexadecimal TMIN fits into signed integer 4bytes
- The machine architecture or C version is not relevant here.

### Practice Problem 2

- [main.c](./code/data_tmin/problem2/main.c)

- Suppose we try to write TMin 32 as -0x7FFFFFFF-1. 
- Would the C compiler generate a constant of type int for both 32- and 64-bit programs and for both versions of the C language standard? Explain.

- The int data type that can represent the number 0x7FFFFFFF.

- The value -0x7FFFFFFF is hexadecimal for -2,147,483,647. 
- Subtracting 1, it would then be still be an int of TMIN -2,147,483,648 

### Practice Problem 3

- [main.c](./code/data_tmin/problem3/main.c)

WIP

### Practice Problem 4

- Suppose we try to write the value of TMin 64 as decimal and hexadecimal constants. 
- Fill in the following table using the rules shown in Figure 1 from [Web Aside Writing TMin in C](http://csapp.cs.cmu.edu/3e/waside/waside-tmin.pdf) to determine what type the resulting value should be. 
- You may find some cases where the rules do not define a valid representation for the constant. Indicate such cases
with the entry “undefined.”

||Word Size|C Version|-9223372036854775808|0x8000000000000000||
|---|---|---|---|---|---|
|A|32|C90|||
|B|32|C99|||
|C|64|C90|||
|D|64|C99|||

#### a 32bit C90
WIP

#### b 32bit C99
WIP

#### c 64bit C90

- [main.c](../webasides/code/data_tmin/problem4/64bit/C90/main.c)
```c
    long x = -9223372036854775808; /* 64bit C90 */
    long y = 0x8000000000000000; /* 64bit C90 */
```

- When the above code is compiled the following warning occurs.

```bash
make
gcc -std=c90 -g main.c -o main
main.c: In function ‘main’:
main.c:5:15: warning: integer constant is so large that it is unsigned
    5 |     long x = -9223372036854775808; /* 64bit C90 */
      |               ^~~~~~~~~~~~~~~~~~~
main.c:5:5: warning: this decimal constant is unsigned only in ISO C90
    5 |     long x = -9223372036854775808; /* 64bit C90 */
      |     ^~~~

```

- This is a case for `x` where the unsigned long data type exists for this value with 64bit C90.

#### D 64bit C99

- [main.c](../webasides/code/data_tmin/problem4/64bit/C99/main.c)
```c
    long x = -9223372036854775808; /* 64bit C99 */
    long y = 0x8000000000000000; /* 64bit C99 */
```
- When the above code is compiled the following warning occurs.

```bash
$ make
gcc -std=c99 -g main.c -o main
main.c: In function ‘main’:
main.c:5:23: warning: integer constant is so large that it is unsigned
    5 |     long x = 9223372036854775808; /* 64bit C99 */
```
- This is a case for `x` where no valid data type exists for this value with 64bit C99 so it is undefined.
- This is a case for `y` where a unsigned long data type can represent the hexadecimal value.

- TMin64 should be represented as `-9223372036854775807 - 1` to fit in a `long`
```c
    long x = -9223372036854775807 - 1; /* 64bit C99 */
    long y = 0x8000000000000000; /* 64bit C99 */
```
- No compile errors with above code for `x`.