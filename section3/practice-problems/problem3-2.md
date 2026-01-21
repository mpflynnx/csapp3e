## Practice Problem 3.2 hardback page 185

- []()

### Problem

For each of the following lines of assembly, determine the appropriate instruction suffix based on the operands. 

### x86-64 mov AT&T syntax
- `movq Source, Dest`

`mov` instruction will only update the the number of bytes determined by the `Dest` destination operand if smaller than the `Source`

The suffix of the `mov` instruction is determined solely by the amount of data you are moving to the destination.

Exceptions occur when `movl` has a register as a destination. The high-order 4 bytes are set to 0. This is due to the convention adopted for x86-64, that any instruction that generate a 32-bit value for a register also sets the high-order portion of the register to 0. 

In AT&T syntax
mov, can be rewritten as

|||
|---|---|
|**Instuction**|**Description**|
|movb| Move byte (8bit)
|movw| Move word (16bit)
|movl| Move double word (32bit)
|movq| Move quad word (64bit)

In x86-64 memory references, those in parentheses () are always given in quad word registers, even if the operand is a byte, single word, or double word.

### Table
||||||
|---|---|---|---|---|
||**AT&T**|**Instruction**|**Notes**
|a|mov_ %eax, (%rsp)|movl|[See below for explanation](#a)
|b|mov_ (%rax), %dx|movw|[See below for explanation](#b)
|c|mov_ $0xFF, %bl|movb|[See below for explanation](#c)
|d|mov_ (%rsp, %rdx,4), %dl|movb|[See below for explanation](#d)
|e|mov_ (%rdx), %rax|movq|[See below for explanation](#e)
|f|mov_ %dx, (%rax)|movw|[See below for explanation](#f)

### a.

**Step1. Identify the Register Size**
```Assembly
    %eax, (%rsp)
```
The source register is `%eax`. In the x86-64 architecture, register names indicate their bit-width:

    - rax: 64 bits (Quadword)
    - eax: 32 bits (Longword/Doubleword)
    - ax: 16 bits (Word)
    - al: 8 bits (Byte)

**2. Match the Suffix to the Size**

AT&T syntax uses suffixes to match these bit-widths:

- q (quad): 64 bits
- **l (long): 32 bits**
- w (word): 16 bits
- b (byte): 8 bits

Since `%eax` is a 32-bit register, the instruction must use the `l` suffix.

**3. The Memory Operand**

The destination is `(%rsp)`. While the stack pointer register `%rsp` is a 64-bit register (holding a 64-bit memory address), the data being moved into that address is only 32 bits wide because it is coming from `%eax`. The CPU will write exactly 4 bytes (32 bits) of data to the memory location pointed to by the stack pointer.

[back](#table)

### b.

**Step1. Identify the Register Size**
```Assembly
    (%rax), %dx
```

The destination register is `%dx`. In x86-64, the "x" family of registers follows this size hierarchy:

- rdx: 64 bits (Quadword)
- edx: 32 bits (Longword)
- **dx: 16 bits (Word)**
- dl / dh: 8 bits (Byte)

**Step 2. Match the Suffix to the Size**

AT&T syntax uses suffixes to match these bit-widths:

- q (quad): 64 bits
- l (long): 32 bits
- **w (word): 16 bits**
- b (byte): 8 bits

Since `%dx` is a 16-bit register, the instruction must use the `w` suffix.

**Step 3. The Memory Operand**

The source is `(%rax)`. Even though `%rax` is a 64-bit register holding a full memory address, the instruction only "grabs" 16 bits (2 bytes) from that location to fill the `%dx` register. The remaining bits in the memory location at `%rax` are left untouched.

[back](#table)
### c.

**Step 1. Identify the Register Size**
```Assembly
$0xFF, %bl
```

The destination register is `%bl`. In the x86-64 register hierarchy, the "b" registers (like `%al`, `%bl`, `%cl`, `%dl`) represent the low-order 8 bits of the original 16-bit registers.

- rbx: 64 bits (Quadword)
- ebx: 32 bits (Longword)
- bx: 16 bits (Word)
- bl: 8 bits (Byte)

**Step 2. Match the Suffix to the Size**

AT&T syntax uses suffixes to match these bit-widths:

- q (quad): 64 bits
- l (long): 32 bits
- w (word): 16 bits
- **b (byte): 8 bits**

As we are moving data into a 8-bit register, instruction must use the `b` suffix.

**Step 3. The Immediate Value**

The source is `$0xFF`. The `$` indicates this is a literal constant (immediate value). While `0xFF` (255 in decimal) could fit into a larger register, the move is restricted by the size of the destination. Because the destination `%bl` can only hold 8 bits, the `movb` instruction ensures only 1 byte of data is processed.

**Warning** If you tried to write `movb $0x1FF, %bl`, the compiler would throw an error. `0x1FF` is `511`, which requires 9 bits, making it too large to fit into the 8-bit `%bl` register.

[back](#table)
### d.

**Step 1. Identify the Register Size**
```Assembly
(%rsp,%rdx), %dl
```
The destination register is `%dl`. This is the low-order byte of the `%rdx` register.

- rdx: 64 bits
- edx: 32 bits
- dx: 16 bits
- **dl: 8 bits (Byte)**

**Step 2. Match the Suffix to the Size**

AT&T syntax uses suffixes to match these bit-widths:

- q (quad): 64 bits
- l (long): 32 bits
- w (word): 16 bits
- **b (byte): 8 bits**

As we are moving data into a 8-bit register, instruction must use the `b` suffix.

**Step 3. The Memory Operand**

The source is `(%rsp, %rdx, 4)`. This is a complex address calculation (Scaled Indexed Addressing).

- Base: `%rsp` (The current stack pointer)
- Index: `%rdx`
- Scale: `4`
- Calculation: `Address = rsp + (rdx * 4)`

Even though the address calculation uses 64-bit registers `(%rsp and %rdx)`, the instruction only fetches one single byte from the resulting memory address because the destination `%dl` is only one byte wide.

[back](#table)

### e.

**Step 1. Identify the Register Size**
```Assembly
    (%rdx), %rax
```

The destination register is `%rax`. In the x86-64 architecture, the `r` prefix indicates the full **64-bit** width of the register.

- **rax: 64 bits (Quadword)**
- eax: 32 bits (Longword/Doubleword)
- ax: 16 bits (Word)
- al: 8 bits (Byte)

**Step 2. Match the Suffix to the Size**

AT&T syntax uses suffixes to match these bit-widths:

- **q (quad): 64 bits**
- l (long): 32 bits
- w (word): 16 bits
- b (byte): 8 bits

As we are moving data into a 64-bit register, instruction must use the `q` suffix.

**Step 3. The Memory Operand**

The source is `(%rdx)`. The CPU treats the value inside the 64-bit register `%rdx` as a memory address. Because of the `q` suffix, the CPU will go to that address and fetch 8 contiguous bytes (64 bits) of data to place into `%rax`.


### f.

**Step 1. Identify the Register Size**
```Assembly
    %dx, (%rax)
```