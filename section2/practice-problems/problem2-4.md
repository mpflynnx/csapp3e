## Practice Problem 2.4 (International edition of book)

Without converting the numbers to decimal or binary, try to solve the following
arithmetic problems, giving the answers in hexadecimal. Hint: Just modify the
methods you use for performing decimal addition and subtraction to use base 16.

||||||
|---|---|---|---|---|
|[a.](#a-hexadecimal-arithmetic)|0x605C|+|0x5 =|?|
|[b.](#b-hexadecimal-arithmetic)|0x605C|-|0x20 =|?|
|[c.](#c-hexadecimal-arithmetic)|0c605C|+|32 =|?|
|[d.](#d-hexadecimal-arithmetic)|0x60FA|-|0x605C =|?|

## a. hexadecimal arithmetic
|||
|-|-|
| |0x605C
|+|0x0005
||||
||||

1. C + 5 = 12(decimal) + 5(decimal) = 17(decimal)

1.  - 17 / 16 = 1, 17 % 16 gives a remainder 1
    - 1 / 16 = 1, 1 % 16 gives a remainder 1

    - There the hexadecimal representation is **0x11**
1. Write down "1" and carry-over "1".

```bash
  0x605C
+ 0x0005
--------
       1
```

4. Add the next column (16s column), including the carry-over:

    - 5 + 0 + 1 (carry-over) = 6 (decimal) = 6 (hexadecimal).
    - Write down "6".

```bash
  0x605C
+ 0x0005
--------
      61
```

5. Add the next column (256s column):
    - 0 + 0 + 0
    - Write down "0".

```bash
  0x605C
+ 0x0005
--------
     061
```

6. Add the leftmost column (4096s column):

    - 6 + 0 = 6.
    - Write down "6".

```bash
  0x605C
+ 0x0005
--------
    6061
```

The answer is 0x6061

## b. hexadecimal arithmetic

|||
|-|-|
| |0x605C
|-|0x0020
||||
||||

1. C - 0 = C

1. Write down "C".

```bash
  0x605C
- 0x0020
--------
       C
```

4. Subtract the next column (16s column)

    - 5 - 2 = 3 (hexadecimal).
    - Write down "3".

```bash
  0x605C
- 0x0020
--------
      3C
```

5. Add the next column (256s column):
    - 0 + 0 + 0
    - Write down "0".

```bash
  0x605C
+ 0x0020
--------
     03C
```

6. Add the leftmost column (4096s column):

    - 6 + 0 = 6.
    - Write down "6".

```bash
  0x605C
+ 0x0020
--------
    603C
```

The answer is 0x603C

## c. hexadecimal arithmetic

Decimal 32 is 0x20

|||
|-|-|
| |0x605C
|+|0x0020
||||
||||

1. Add the right most C + 0 = C gives a remainder 14
1. Write down "C".

```bash
  0x605C
+ 0x0020
--------
       C
```

4. Add the next column (16s column), including the carry-over:

    - 5 + 2  = 7 (decimal) = 7 (hexadecimal).
    - Write down "7".

```bash
  0x605C
+ 0x0020
--------
      7C
```

5. Add the next column (256s column):
    - 0 + 0 + 0
    - Write down "0".

```bash
  0x605C
+ 0x0020
--------
     07C
```

6. Add the leftmost column (4096s column):

    - 6 + 0 = 6.
    - Write down "6".

```bash
  0x605C
+ 0x0020
--------
    607C
```

The answer is 0x607C

## d. hexadecimal arithmetic

|||
|-|-|
| |0x60FA
|-|0x605C
||||
||||

1. A - C = = 10(decimal) - 12(decimal)
    - Since 10 - 12 would give us a negative number, we need to borrow from the next column.
    - Borrow 1 from the 16s column, which is equivalent to borrowing 16 in the units column.
    - Now we have 10 + 16 = 26 (decimal).
26 - 12 = 14 (decimal), which is E in hexadecimal.
Write down "E".

```bash
  0x60FA
- 0x605C
--------
       E       
```

4. Subtract the next column (16s column)

    - E (14) - 5 = 9 (hexadecimal).
    - Write down "9".

```bash
  0x60FA
- 0x605C
--------
      9E
```

5. Add the next column (256s column):
    - 0 - 0 = 0
    - Write down "0".

```bash
  0x60FA
- 0x605C
--------
     09E
```

6. Add the leftmost column (4096s column):

    - 6 - 6 = 0.
    - Write down "0".

```bash
  0x60FC
- 0x605C
--------
    009E
```

The answer is 0x9E

### External references
- [Hex Calculator](https://www.calculator.net/hex-calculator.html)