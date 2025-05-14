## Practice Problem 2.40 hardback page 103

- [main.c](../practice-problems/code/problem2dot40/main.c)
- [notes | multiplication using left shift](../misc.md#multiplication-by-power-of-2-using-left-shift)

### Binary to Decimal Table 

||||||||||
|---|---|---|---|---|---|---|---|---|
8   |7  |6  |5  |4 |3 |2 |1 | Width
128 |64 |32 |16 |8 |4 |2 |1 | Binary value
2^7|2^6|2^5|2^4|2^3|2^2|2^1|2^0 |2^n

### Example

- if `x` is `11`
- if `k` is `4`
- x * k = 44
- W=8
- 11 in binary is 00001011 

```
76543210  Bit position
00001011  11 Decimal
    ^  ^
    n  m  n=3, m=0
```

- Form A:
- (k<<n) + (k<<(n-1)) + (k<<m)
- (4<<3) + (4<<(3-2)) + (4<<3-3)

- Form B:
- Not possible with these numbers



### Problem

- For each of the following values of K, find ways to express x * K using only the specified number of operations, where we consider both additions and subtractions to have comparable cost. You may need to use some tricks beyond the simple form A and B rules we have considered so far.


||K  |Shifts |Add/Subs |Expression|
|---|---|---|---|---|
|[a.](#a)|6 |2 | 1 | ?
|[b.](#b)|31 |1 | 1 | ?
|[c.](#c)|-6 |2 | 1 | ?
|[d.](#d)|55 |2 | 2 | ?

### Solution

#### a.

- x * 6
- K = 6 or 00000110

```
76543210  Bit position
00000110  6 Decimal
     ^^
     nm  n=2, m=1
```
- Shifts = 2
- Form A:
- (x<<n) + (x<<m)
- (x<<2^2) + (x<<2^1)
- (x<<2) + (x<<1)

#### b.

- x * 31 in 1 shift
- K = 31 or 00011111

```
76543210  Bit position
00011111  31 in Decimal
   ^   ^
   n   m  n=4, m=0
```
- Form A: Maximum shifts with addition is 5.
- Form B: Minimum shifts with subtraction is 2.
- 31 is close to 2^5 of 32
- 31 can be achieved by 2^5(32) - 2^0(1) or 32 subtract 1 equals 31

- Lets say x is 2
- for 2 * 31 = 62
- 00111110 is 62
- (2<<5) = 64
- (2<<0) = 2
- expression = (2<<5) - (2<<0)
- Why do the second shift when (2<<0) is 2 and x is 2?
- When 64 - x = 62
- expression = (x<<5) - x = 62

- But we can do it in only one operand
- place 31 and 62 in binary together
```
00011111 - 31
00111110 - 62
```
- They are off by 1 to the left
- lets switch the x and k values
- k * x = 31 * 2
- (31<<?) = 62
- 31 * 2 is equivalent to (31<<1) = 62
- Because one of the numbers in the multiplication (x = 2) is a power of two (2^1), the entire multiplication can be replaced by a single left shift of the other number (31) by the exponent (1).

#### c.

- x * -6 in 2 shifts

- One approach is to think in positive numbers, then negate the answer then add 1 to obtain the negative result.
- This is preferred for predictable results

- x * 6 in 2 shifts
- K = 6 or 00000110
```
76543210  Bit position
00000110  6 in Decimal
     ^^
     nm   n=2, m=1
```

- Lets say x is 3
- for 3 * 6 = 18

- x << n or 3<<2 = 3 * 2^2 = 3 * 4 = 12.
- x << m or 3<<1 = 3 * 2^1 = 3 * 2 = 6.
- 12 + 6 = 18  
- We could use the bitwise NOT then add 1 to get -18
- ~((x<<2) + (x<<1)) + 1
- ~(12 + 6) + 1
- Therefore, the solution is: ~((x<<2) + (x<<1)) + 1

- Thinking negative numbers
- x * -6 in 2 shifts

```
76543210  Bit position
11111010  -6 in Decimal (two's complement)
    ^ ^
    n m  n=3, m=1 (ignore higher order bits)
```

- Lets say x is 3
- for 3 * -6 = -18

```
76543210  Bit position
11101110  -18 in Decimal
```

- x << n or 3<<3 = 3 * 2^3 = 3 * 8 = 24.
- x << m or 3<<1 = 3 * 2^1 = 3 * 2 = 6.
- if we subtract `n` result from `m` result we get a negative number.
- 6 - 24 = -18  

- Therefore, the solution is: (x<<1) - (x<<3)
-  It's a valid alternative to calculating the positive product and then negating it.

#### d.

- x * 55 use 2 shifts and 2 additions/subtractions

```
76543210  Bit position
00110111  55 Decimal
  ^    ^
  n    m  n=5, m=1
```
2^5 = 32
2^6 = 64

- Lets say x is 3
- for 3 * 55 = -18

```
10100101
```