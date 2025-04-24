## Practice Problem 2.19 hardback page 100

Using the table you filled in when solving Problem 2.17, fill in the following table describing the function T2Uw, w= wordsize of 4:

|| Hexadecimal x| 2^n (binary) |B2Uw(x)|B2Tw(x)|T2Uw(x)
|---|---|---|---|---|---|
|-|0xE|1110|2^3 + 2^2 + 2^1 = 14|-2^3 + 2^2 + 2^1=-2|2^3 + 2^2 + 2^1 = 14|
|[a.](#a)|0x0|0000|0|0|0|
|[b.](#b.)|0x5|0101|2^2 (4) + 2^0 (1) = 5|2^2 (4) + 2^0 (1) = 5|2^2 (4) + 2^0 (1) = 5|
|[c.](#c.)|0x8|1000|2^3 (8) = 8|-2^3 (8) = -8|2^3 (8) = 8|
|[d.](#d.)|0xD|1101|2^3 (8) + 2^2(4) + 2^0 (1) = 13|2^3 (-8) + 2^2(4) + 2^0 (1) = -3 |2^3 (8) + 2^2(4) + 2^0 (1) = 13|
|[e.](#e.)|0xF|1111|2^3(8) + 2^2(4) + 2^1(2)+ 2^0(1) = 15|-2^3(-8) + 2^2(4) + 2^1(2)+ 2^0(1) = -1|2^3(8) + 2^2(4) + 2^1(2)+ 2^0(1) = 15|

### Two's complement 2 Unsigned w, w = wordsize
- For negative x, T2Uw(x) = x + 2^w
- For non negative x, T2Uw(x) = x