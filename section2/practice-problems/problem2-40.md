## Practice Problem 2.40 hardback page 103

- [main.c](../practice-problems/code/problem2dot40/main.c)
- [notes | multiplication using left shift](../misc.md#multiplication-by-power-of-2-using-left-shift)

#### Example

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
- (x<<(n+1)) - (x<<m)
- (4<<(3+1))



### Problem

- For each of the following values of K, find ways to express x * K using only the specified number of operations, where we consider both additions and subtractions to have comparable cost. You may need to use some tricks beyond the simple form A and B rules we have considered so far.


|K  |Shifts |Add/Subs |Expression|
|---|---|---|---|
6 |2 | 1 | ?
31 |1 | 1 | ?
-6 |2 | 1 | ?
55 |2 | 2 | ?

### Solution

WIP

