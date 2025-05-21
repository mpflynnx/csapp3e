## Practice Problem 2.42 hardback page 107

- [main.c](../practice-problems/code/problem2dot42/main.c)
- [notes | Power of 2 using left shift operator](../misc.md#power-of-2-using-left-shift-operator)
- [notes | Unsigned Power-of-2 Divide with shift](../misc.md#signed-twos-complement-power-of-2-divide-with-shift-alternative)

### Problem

- Write a function `div16` that returns the value x/16 for integer argument x. 
- Your function should not use division, modulus, multiplication, any conditionals (if or ?:), any comparison operators (e.g., <, >, or ==), or any loops. 
- You may assume that data type int is 32 bits long and uses a two’s-complement representation, and that right shifts are performed arithmetically.


### Solution

- Integer types have width w=32 by default
- Using right shift on x >> w-1, x>>32-1, x>>31. Will result in all 1's if x is negative, all 0's if positive
- Logarithm base 2 of 16 is 4
- We then create mask using k=4, mask = 2^k - 1 or mask = (1<<k) - 1
- Produce bias using, bias = (x>>31) & mask
- bias will be 0 if x is positive
- The result of the division is obtained using, (x + bias) >> k

```c
/* Divides x by 2^k*/
int divideByK(const int x, const int k){
    int mask = (1<<k) - 1;
    int bias = (x>>31) & mask;
    int result = (x + bias) >> k;
    return result;
}
```