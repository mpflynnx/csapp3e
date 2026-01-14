## Practice Problem 3.1 hardback page 182

- [Required reading: Calculate a memory address using a base, an index, and an offset.](../memaddr.md)

### Problem

Assume the following values are stored at the indicated memory address and registers.

|||||||
|---|---|---|---|---|---|
|**Address**|**Value**|**Register**|**Value**|
|0x100|0xFF|%rax|0x100|
|0x104|0xAB|%rcx|0x1|
|0x108|0x13|%rdx|0x3|
|0x10C|0x11|

||||||
|---|---|---|---|---|
||**AT&T**|**Intel**|**Value**|**Notes**
|a|%rax|rax|0x100|Register
|b|0x104|0x104|0xAB|Absolute address
|c|$0x108|0x108|0x108| Immediate, $ prefix is for constants
|d|(%rax)|[rax]|0xFF| Parentheses or square brackets is used to indicate "the value at the address held in this register."
|e|4(%rax)|[rax + 4]|0xAB|Displacement 4 + Parentheses is used to indicate "the value at the address held in this register." Address: 4 + 0x100 = 0x104 Value at 0x104 is 0xAB.
|f|9(%rax, %rdx)|[rax + rdx + 9]|0x11|[See below for explanation](#f-9rax-rdx)
|g|260(%rcx, %rdx)|[rcx + rdx + 260]|0x13|[See below for explanation](#g-operand-260rcx-rdx)
|h|0xFC(,%rcx,4)|[rcx*4 + 0xFC]|0xFF|[See below for explanation](#h-operand-0xfc-rcx-4)
|k|(%rax,%rdx,4)|[rax + rdx*4]|0x11|[See below for explanation](#k-operand-raxrdx4)


### f. Operand 9(%rax, %rdx)

|||||||
|---|---|---|---|---|---|
|**Address**|**Value**|**Register**|**Value**|
|0x100|0xFF|%rax|0x100|
|0x108|0x13|%rdx|0x3|


Equates to:

$\text{Value in } \%rax + \text{Value in } \%rdx + 9 = \text{Target Address} $

9 Decimal to Hexadecimal = 0x9

Hex addition: 
0x100 + 0x3 + 0x9 = Target Address = `0x10C`

Value at $\text{Target Address}$ `0x10C` is `0x11`.

### g. Operand: 260(%rcx, %rdx)

|||||||
|---|---|---|---|---|---|
|**Address**|**Value**|**Register**|**Value**|
|0x104|0xAB|%rcx|0x1|
|0x108|0x13|%rdx|0x3|

Equates to:

$\text{Value in } \%rcx + \text{Value in } \%rdx + 260 = \text{Target Address} $

Converting 260 Decimal to Hexadecimal = `0x104`

Hex addition: 
0x1 + 0x3 + 104 = Target Address = `0x108`

Value at $\text{Target Address}$ `0x108` is `0x13`.

### h. Operand: 0xFC(, %rcx, 4)

In this problem. The first register or number inside parentheses is omitted. Therefore defaults to 0. 
The third number `4` inside the parentheses is the scale.

|||||||
|---|---|---|---|---|---|
|**Address**|**Value**|**Register**|**Value**|
|0x100|0xFF|%rax|0x100|
|0x104|0xAB|%rcx|0x1|

Converting displacement 0xFC from Hexadecimal to Decimal = `252`

`252(, %rcx, 4)` Equates to:

$\text{(0} + \text{Value in } \%rcx * 4) + 252 = \text{Target Address}$

(0x1 * 4) = 0x4 or 4 decimal

Decimal addition:
- (4) + 252 = 256

Target address (hexadecimal): 
- Decimal 256 to hexadecimal = 0x100

Value at $\text{Target Address}$ `0x100` is `0xFF`.

#### Intel syntax

[base + index*scale + disp]

[rcx*4 + 0xFC]

- Base: Omitted
- Index: rcx
- Scale: *4
- Displacement: + 0xFC (252 decimal)

The calculation:
$$(0x1 \times 4) + 0xFC = 0x4 + 0xFC = \mathbf{0x100}$$

Value at $\text{Target Address}$ `0x100` is `0xFF`.

### k. Operand: (%rax,%rdx,4)

In this problem. The deplacement before the parentheses is omitted. Therefore defaults to 0. 
The third number `4` inside the parentheses is the scale multiplier for the value inside `%rdx`.

|||||||
|---|---|---|---|---|---|
|**Address**|**Value**|**Register**|**Value**|
|0x100|0xFF|%rax|0x100|
|0x108|0x13|%rdx|0x3
|0x10C|0x11|

`(%rax, %rdx, 4)` Equates to:

$\text{Value in } \%rax + \text{(Value in } \%rdx * 4) = \text{Target Address}$

0x3 = 3 decimal

0x100 + (3 * 4) = 0x100 + 12 (0xC) = 0x10C

Target address (hexadecimal): 0x10C

Value at $\text{Target Address}$ `0x10C` is `0x11`.

#### Intel syntax

[base + index*scale + disp]

[rax + rdx*4]

- Base: rax
- Index: rdx
- Scale: *4
- Displacement: Omitted

The calculation:
$$0x100 + (3 (0x3) \times 4) = 0x100 + 12 (0xC) = \mathbf{0x10C}$$

Value at $\text{Target Address}$ `0x10C` is `0x11`.