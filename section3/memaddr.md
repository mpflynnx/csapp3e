## Memory addressing

Memory addressing example `movb 9(%rax, %rdx)`

AT&T Addressing Mode for x86-64 memory operands. Represents a specific way to calculate a memory address using a base, an index, and an offset.

The general formula for this notation is:

$$
\text{Address} = \text{Displacement} + \text{Base} + (\text{Index} \times \text{Scale})
$$

**Breaking Down `9(%rax, %rdx)`**

Here is how the example maps to the formula:

- `9` **(Displacement)**: A constant offset added to the total.

- `%rax` **(Base)**: The starting memory address (often the start of an array or a struct). If there is nothing before the first comma. This means the Base is treated as 0.

- `%rdx` **(Index)**: A value that "offsets" from the base (often an loop counter or index variable).

- `1` **(Scale)**: Since there is no third register or number inside the parentheses, the scale defaults to 1.

2. The Resulting Calculation when the CPU executes an instruction with this operand, it calculates the target address as:

$$
\text{Target Address} = \text{Value in } \%rax + \text{Value in } \%rdx + 9
$$


||||
|---|---|---|
**Component**|	**Example**|	**Allowed Values**|
|Displacement|	9|	Any 32-bit integer|
|Base|	%rax|	Any general-purpose register|
|Index|	%rdx|	Any general-purpose register (except %rsp)|
|Scale|	Implicit 1|	1, 2, 4, 8|

**Intel syntax**

Looks much like a maths equation `[rax + rdx + 9]`

