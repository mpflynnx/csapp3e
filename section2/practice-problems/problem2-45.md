## Practice Problem 2.45 hardback page 111

- [notes | Floating point numbers](../misc.md#floating-point-numbers)
- [errata page 111]()
### Problem

Fill in the missing information in the following table:

||Fractional value|Binary representation|Decimal representation
|---|---|---|---|
|[a.](#a)|1/8|0.001|0.125
|[b.](#a)|3/4|?|?
|[c.](#a)|25/16|?|?
|[d.](#a)|?|10.1011|?
|[e.](#a)|?|1.001|?
|[f.](#a)|?|?|5.875
|[g.](#a)|?|?|3.1875

Errata page. 111, Practice Problem 2.45. The entry in the third row should be 25/16.

#### Hint
- One simple way to think about fractional binary representations is to represent a number as a fraction of the form x/2^k.
- We can write this in binary using the binary representation of x, with the binary point inserted k positions in from the right.
- As an example, for 25/16, we have decimal 25 = binary 11001
- 1/16 is at the -4 binary position, so k is 4
- We then put the binary point 4 positions from the right to get binary representation of 1.1001

### Solutions

#### a.
- Given fractional value of 1/8
- As 1/8 is a x/2^k we can represent is exactly

|||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|
|4|3|2|1|0|.|-1|-2|-3|-4| binary position
|16|8 |4 |2 |1 |.|1/2|1/4|1/8|1/16|binary value
|| | | |0 |.  | 0|0|1||binary representation|

Decimal 1 divided by 8 = 0.125 

#### b.
- Given fractional value of 3/4
- Decimal representation 3/4 is  3 divided by 4 = 0.75
- 0.75 can be made up of 0.5 + 0.25
- Decimal 0.5 is 1/2
- Decimal 0.25 is 1/4

|||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|
|4|3|2|1|0|.|-1|-2|-3|-4| binary position
|16|8 |4 |2 |1 |.|1/2|1/4|1/8|1/16|binary value
|| | | |0 |.  | 1|1|||binary representation|

- binary representation is 0.11

#### c.
- Given fractional value of 25/16
- Decimal representation 25/16 is 25 divided by 16 = 1.5625
-  0.5625 as a fraction in simplest form is 9/16
- 9/16 can be presented as
- 8/16 + 1/16 = 9/16
- in decimal that's, 0.5 + 0.0625
- in fractions that's, 1/2 + 1/16
- binary representation is 1.1001

|||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|
|4|3|2|1|0|.|-1|-2|-3|-4| binary position
|16|8 |4 |2 |1 |.|1/2|1/4|1/8|1/16|binary value
|| | | |1 |.  | 1|0|0|1|binary representation|

##### c. Alternatively
- One simple way to think about fractional binary representations is to represent a number as a fraction of the form x/2^k.
- For 25/16, we have decimal 25 which is in binary 11001
- 1/16 is at the -4 binary position, so k is 4
- We then put the binary point 4 positions from the right to get binary representation of 1.1001
