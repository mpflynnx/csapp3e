## Practice Problem 2.12 pdf page 84

- [main.c](./code/problem2dot12/)

- Write C expressions, in terms of variable x, for the following values. Your code should work for any word size w ≥ 8. For reference, we show the result of evaluating the expressions for x = 0x87654321, with w = 32.
- a. The least significant byte of x, with all other bits set to 0. [0x00000021]
- b. All but the least significant byte of x complemented, with the least significant byte left unchanged. [0x789ABC21]
- c. The least significant byte set to all ones, and all other bytes of x left unchanged. [0x876543FF]


### Solution


#### a.

- Masking OxFF will return low order byte of word
- bit level `x & 0xFF` yields a value consisting the least significant byte

#### b.

- Masking lsb from being complemented `x ^ ~ 0xFF`

#### c.
- `x | 0xFF` sets least significant byte to all 1's leaving remaining bits unchanged
