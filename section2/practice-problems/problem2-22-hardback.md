## Practice Problem 2.22 hardback page 79

### Sign extension on Two's complement numbers

### Positive signed
||||||||
|---|---|---|---|---|---|---|
|4|3|2|1|0
|16|8 |4 |2 |1 | Binary position value |
||0 |1 |1 |0 | = 6 | To extend 4bit to 5bit, add leading 0
|0|0 |1 |1 |0 | = 6 | Value is the same


### Negative signed
||||||||
|---|---|---|---|---|---|---|
|4|3|2|1|0
||-8 |4 |2 |1 | Binary position value |
||1 |1 |1 |0 | = -2 | To extend 4bit to 5bit, add leading 1, leave other bits as is
|-16| 8 |4 |2 |1 | Binary position value |
|1|1 |1 |1 |0 | = -2 | msb now -16, previous msb -8 is now +8 still same result = -2

### Unsigned numbers
- Just add leading 0's.

### Hexadecimal negative signed number examples

- 0xFFFF0123, many leading 1's indicates negative number that is not to far away from zero.

- [See slide for examples](../slides/sign%20extension%20examples.jpg)


Show that each of the following bit vectors is a two’s-complement representation of −5
||||
|--|--|--|
| a. | [1011]| -2^3(-8) + 2^1(2) + 2^0(1) =  -5
| b. | [11011]| -2^4(-16) + 2^3(8) + 2^1(2) + 2^0(1) =  -5
| c. | [111011]| -2^5(-32) + 2^4(16) + 2^3(8) + 2^1(2) + 2^0(1) =  -5
