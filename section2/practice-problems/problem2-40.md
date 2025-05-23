## Practice Problem 2.40 hardback page 103

- [main.c](../practice-problems/code/problem2dot40/main.c)
- [notes | multiplication of power of 2 using left shift](../misc.md#multiplication-by-power-of-2-using-left-shift)

### Binary to Decimal Table 

||||||||||
|---|---|---|---|---|---|---|---|---|
8   |7  |6  |5  |4 |3 |2 |1 | Width
128 |64 |32 |16 |8 |4 |2 |1 | Binary value
2^7|2^6|2^5|2^4|2^3|2^2|2^1|2^0 |2^n

### Example

- if `x` is `3`
- if `k` is `14`
- x * k = 42
- w=8
- `k` 14 in binary is 00001110

```
76543210  Bit position
00001110  11 Decimal
    ^ ^
    n m  n=3, m=1
```

- 14 also is 2^3(8) + 2^2(4) + 2^1(2)
- `x * y` result is equivalent in C to (x<<3) + (x<<2) + (x<<1)

- Form A:
- (x<<3) + (x<<2) + (x<<1)

- Form B:
- (x<<4) - (x<<1)



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

- x * 6 use 2 shifts and 1 additions/subtractions

- K = 6 or 00000110

```
76543210  Bit position
00000110  6 Decimal
     ^^
     nm  n=2, m=1
```
- Shifts = 2
- Form A:
- (x<<2^n) + (x<<2^m)
- (x<<2^2) + (x<<2^1)
- (x<<2) + (x<<1)
- Form B:
- (x<<2^(n+1)) - (x<<2^m)
- (x<<3) - (x<<1)

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
- Form B: Minimum shifts with subtraction is 1
- because no shift is needed when m=0
- 2^0 which is 1*x = x.

|7|6|5|4|3|2|1|0|Position|
|---|---|---|---|---|---|---|---|---|
|128 |64 |32 |16 |8 |4 |2 |1 | Binary value
|2^7|2^6|2^5|2^4|2^3|2^2|2^1|2^0 |2^n
|0|0|0|1|1|1|1|1|
|-|-|1|-|-|-|-|1| Form B
|||^|||||^|
|||n|||||m|n=5, m=0

- To achieve one shift
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
    ^n ^m n=3, m=1 (ignore higher order bits)
```

- Lets say x is 3
- for 3 * -6 = -18

```
76543210  Bit position
11101110  -18 in Decimal
```

- x << n or 3<<3 = 3 * 2^3 = 3 * 8 = 24.
- x << m or 3<<1 = 3 * 2^1 = 3 * 2 = 6.
- if we subtract `m` result from `n` result we get a negative number.
- 6 - 24 = -18  

- Therefore, the solution is: (x<<1) - (x<<3)
-  It's a valid alternative to calculating the positive product and then negating it.

#### d.

- x * 55 use 2 shifts and 2 additions/subtractions


|7|6|5|4|3|2|1|0|Position|
|---|---|---|---|---|---|---|---|---|
|128 |64 |32 |16 |8 |4 |2 |1 | Binary value
|2^7|2^6|2^5|2^4|2^3|2^2|2^1|2^0 |2^n
|0|0|1|1|0|1|1|1| 55
|-|-|1|-|-|-|-|1| Form A
|||^n+|^n+||^n+|^n+|^m|


- This could be done with `Form A` in 5 shifts and 4 additions but that's too many.
- `Form B` may be a better option, but there is a 0 at the 2^3 position? We need to think differently.

- Look at the higher order bit at 2^5
- Form B trick to move up to the next 2^n can be used

|7|6|5|4|3|2|1|0|Position|
|---|---|---|---|---|---|---|---|---|
|128 |64 |32 |16 |8 |4 |2 |1 | Binary value
|2^7|2^6|2^5|2^4|2^3|2^2|2^1|2^0 |2^n
|0|0|1|1|0|1|1|1| 55
|-|1|-|-|-|-|-|-| Form B
||^n|||||||n=6, 2^6 = 64


- Making n now 2^6 = 64
- Look at the last three bits after the 0 at 2^3
- Form B trick to move up to the next 2^n can be used

|7|6|5|4|3|2|1|0|Position|
|---|---|---|---|---|---|---|---|---|
|128 |64 |32 |16 |8 |4 |2 |1 | Binary value
|2^7|2^6|2^5|2^4|2^3|2^2|2^1|2^0 |2^n
|0|0|1|1|0|1|1|1
|-|-|-|-|1|0|0|0| Form B
|||||^n|||^m|n=3, m=0


- making n for the low order bit now 2^3 = 8
- As seen with the high order bit 2^6 = 64
- 64 - 8 = 56
- Form B requires a 2^m which is still 2^0 = 1
- (x<<6 - x<<3) - x<<0
- But no shift is needed when m=0
- 2^0 which is 1*x = x.
- This equates to.
- ((x * 64) - (x * 8)) - (x * 1)
- 2^0 which is 1*x = x.
- As (x * 1) is always x, we can use the code
- (x<<6 - x<<3) - x
