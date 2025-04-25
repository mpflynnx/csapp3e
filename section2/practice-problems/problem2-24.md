## Practice Problem 2.24 hardback page 82

### Truncation of a unsigned number example

||||||||
|---|---|---|---|---|---|---|
|4|3|2|1|0| Binary position
|16|8 |4 |2 |1 | Binary position value |
|1|1 |0 |1 |1 | = 27 | 
|-|1 |0 |1 |1 | = 11 | 
|^|Removed msb

- In this case there is a difference of 16, like modulo 16 arithmetic.
- 27 % 16 = 11

### Truncation of a Two's complement number

||||||||
|---|---|---|---|---|---|---|
|4|3|2|1|0
|-16|8 |4 |2 |1 | Binary position value |
|1|1 |0 |1 |1 | = -5 | msb -16
||-8 |4 |2 |1 | Binary position value |
|-|1 |0 |1 |1 | = -5 | msb becomes -8
|^|Removed msb


- A negative number can become a positive number

||||||||
|---|---|---|---|---|---|---|
|4|3|2|1|0
|-16|8 |4 |2 |1 | Binary position value |
|1|0 |0 |1 |1 | = -13 | msb 1 which is -16
||8 |4 |2 |1 | Binary position value |
|-|0 |0 |1 |1 | = +3 | msb 0 which is +16
|^|Removed msb

- Think of it like a unsigned number and still 16 difference

||||||||
|---|---|---|---|---|---|---|
|4|3|2|1|0
|16|8 |4 |2 |1 | Binary position value |
|1|0 |0 |1 |1 | = 19 | msb 1 which is 16
||8 |4 |2 |1 | Binary position value |
|-|0 |0 |1 |1 | = +3 | 
|^|Removed msb

- 19 % 16 = 3

### Practice Problem

- Suppose we truncate a 4-bit value (represented by hex digits 0 through F) to a 3-
bit value (represented as hex digits 0 through 7.)

- Fill in the table below showing the effect of this truncation for some cases, in terms of the unsigned and two’s-complement interpretations of those bit patterns.

||_______Hex||_____Unsigned||_____Two's complement||||
|---|---|---|---|---|---|---|---|---|
||Original|Truncated|Original|Truncated|Original|Truncated
|-[a.](#a-unsigned)|0|0|0|?|0|?
|-[b.](#b-unsigned)|2|2|2|?|2|?
|-[c.](#c-unsigned)|9|1|9|?|-7|?
|-[d.](#d-unsigned)|b|3|11|?|-5|?
|-[e.](#e-unsigned)|F|7|15|?|-1|?

### a. Unsigned

|||||||
|---|---|---|---|---|---|
|3|2|1|0| Binary position
|8 |4 |2 |1 | Binary position value |
|0 |0 |0 |0 | = 0 | Original
|- |0 |0 |0 | = 0 | **Truncated**
|^|Removed msb


### a. Two's complement

|||||||
|---|---|---|---|---|---|
|3|2|1|0| Binary position
|8 |4 |2 |1 | Binary position value |
|0 |0 |0 |0 | = 0 | Original
|- |0 |0 |0 | = 0 | **Truncated**
|^|Removed msb

### b. Unsigned

|||||||
|---|---|---|---|---|---|
|3|2|1|0| Binary position
|8 |4 |2 |1 | Binary position value |
|0 |0 |1 |0 | = 2 | Original
|- |0 |1 |0 | = 2 | **Truncated**
|^|Removed msb

### b. Two's complement

|||||||
|---|---|---|---|---|---|
|3|2|1|0| Binary position
|8 |4 |2 |1 | Binary position value |
|0 |0 |1 |0 | = 2 | Original
|- |0 |1 |0 | = 2 | **Truncated**
|^|Removed msb

### c. Unsigned

|||||||
|---|---|---|---|---|---|
|3|2|1|0| Binary position
|8 |4 |2 |1 | Binary position value |
|1 |0 |0 |1 | = 9 | Original
|- |0 |0 |1 | = 1 | **Truncated**
|^|Removed msb

### c. Two's complement

|||||||
|---|---|---|---|---|---|
|3|2|1|0| Binary position
|-8 |4 |2 |1 | Binary position value |
|1 |0 |0 |1 | = -7 | Original
|- |0 |0 |1 | = 1 | **Truncated**
|^|Removed msb

### d. Unsigned

|||||||
|---|---|---|---|---|---|
|3|2|1|0| Binary position
|8 |4 |2 |1 | Binary position value |
|1 |0 |1 |1 | = 11 | Original
|- |0 |1 |1 | = 3 | **Truncated**
|^|Removed msb

### d. Two's complement

|||||||
|---|---|---|---|---|---|
|3|2|1|0| Binary position
|-8 |4 |2 |1 | Binary position value |
|1 |0 |1 |1 | = -5 | Original
|- |0 |1 |1 | = 3 | **Truncated**
|^|Removed msb

### e. Unsigned

|||||||
|---|---|---|---|---|---|
|3|2|1|0| Binary position
|8 |4 |2 |1 | Binary position value |
|1 |1 |1 |1 | = 15 | Original
|- |1 |1 |1 | = 7 | **Truncated**
|^|Removed msb

### e. Two's complement

|||||||
|---|---|---|---|---|---|
|3|2|1|0| Binary position
|-8 |4 |2 |1 | Binary position value |
|1 |1 |1 |1 | = -1 | Original
| |-4 |2 |1 | Binary position value |
|- |1 |1 |1 | = -1 | **Truncated**
|^|Removed msb