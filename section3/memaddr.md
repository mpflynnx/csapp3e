## Memory addressing

Memory addressing example `movb 9(%rax, %rdx)`

AT&T Addressing Mode for x86-64 memory operands. Represents a specific way to calculate a memory address using a base, an index, and an offset.

Parentheses is used to indicate "the value at the address held in this register."

The general formula for this notation is:
```
Address = Displacement + Base + (Index * Scale)
```

**Breaking Down `9(%rax, %rdx)`**

Here is how the example maps to the formula:

- `9` **(Displacement)**: A constant offset added to the total.

- `%rax` **(Base)**: The starting memory address (often the start of an array or a struct). If there is nothing before the first comma. This means the Base is treated as 0.

- `%rdx` **(Index)**: A value that "offsets" from the base (often an loop counter or index variable).

- `1` **(Scale)**: Since there is no third register or number inside the parentheses, the scale defaults to 1. Scale values can be 1,2,4,8 depending on the datatype, int scale 4, long scale 8.

2. The Resulting Calculation when the CPU executes an instruction with this operand, it calculates the target address as:

Target Address = Value in %rax + Value in %rdx + 9



||||
|---|---|---|
**Component**|	**Example**|	**Allowed Values**|
|Displacement|	9|	Any 32-bit integer|
|Base|	%rax|	Any general-purpose register|
|Index|	%rdx|	Any general-purpose register (except %rsp)|
|Scale|	Implicit 1|	1, 2, 4, 8|

**Intel syntax**

Looks much like a maths equation `[rax + rdx + 9]`

### Address computation examples

- [Video Lecture 05: Machine-Level Programming I: Basics](https://scs.hosted.panopto.com/Panopto/Pages/Viewer.aspx?id=6e410255-3858-4e85-89c7-812c5845d197)
- Taken from Video Lecture 05 at time 1:04:41

|||||
---|---|---|---|
|**Register**|**Value**|
|%rdx|0xf000|
|%rcx|0x0100|


||||||
|---|---|---|---|---|
||**Expression**|**Address Computation**|**Address**|**Notes**
|a|0x8(%rdx)|0xf000 + 0x8|0xf008| 8 + Value in %rdx
|b|(%rdx, %rcx)|0 + 0xf000 + 0x0100|0xf100| Value in %rdx + Value in %rcx
|c|(%rdx, %rxc,4)|0xf000 + (0x0100 * 4)|0xf400|Value in %rdx + (Value in %rcx * 4)
|d|0x80(,%rdx,2)|0x80 + 0 + (0xf000 * 2)|0x1e080|0x80 + 0 + (Value in %rdx * 2)
