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
- [Practice Problem 5](#practice-problem-5)


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



### Practice Problem 4



### Practice Problem 5


