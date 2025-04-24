## Practice Problem 2.16 page 57 or pdf page 87

**Note** the hardback book pdf and global edition pdf are different here. The problem used here is from the hardback version.

- Fill in the table below showing the effects of the different shift operations on single-
byte quantities. 
- The best way to think about shift operations is to work with binary representations. 
- Convert the initial values to binary
- Perform the shifts, and then convert back to hexadecimal. 
- Each of the answers should be 8 binary digits or 2 hexadecimal digits.

|a|||a << 2|Logical |a >> 3 |Arithmetic |a >> 3|
|---|---|---|---|---|---|---|---|
|Hex|Binary|Hex|Binary|Hex|Binary|Hex|Binary|
|0xC3|?|?|?|?|?|?|?|
|0x75|?|?|?|?|?|?|?|
|0x87|?|?|?|?|?|?|?|
|0x66|?|?|?|?|?|?|?|

### Solution

|x|||x << 3|Logical |x >> 2 |Arithmetic |X >> 2|
|---|---|---|---|---|---|---|---|
|Hex|Binary|Hex|Binary|Hex|Binary|Hex|Binary|
|0xC3|11000011|0x18|00011**000**|?|**00**110000|?|**11**110000|
|0x75|01110101|0xA8|10101**000**|?|**00**011101|?|**00**011101|
|0x87|10000111|0x38|00111**000**|?|**00**100001|?|**11**100001|
|0x66|01100110|0x30|00110**000**|?|**00**011011|?|**00**011001|