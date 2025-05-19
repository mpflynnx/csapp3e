## Practice Problem 2.42 hardback page 107

- [main.c](../practice-problems/code/problem2dot42/main.c)
- [notes | Unsigned Power-of-2 Divide with shift](../misc.md#unsigned-power-of-2-divide-with-shift)

### Problem

- Write a function `div16` that returns the value x/16 for integer argument x. 
- Your function should not use division, modulus, multiplication, any conditionals (if or ?:), any comparison operators (e.g., <, >, or ==), or any loops. 
- You may assume that data type int is 32 bits long and uses a two’s-complement representation, and that right shifts are performed arithmetically.


### Solution

- Logical shifting
- 16 is 2^4
- x>>4 is x/16 