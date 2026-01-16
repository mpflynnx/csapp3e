## Practice Problem 3.2 hardback page 185

- []()

### Problem

For each of the following lines of assembly, determine the appropriate instruction suffix based on the operands. 

### x86-64 mov AT&T syntax
- `movq Source, Dest`

`mov` instruction will only update the the number of bytes determined by the `Dest` destination operand.

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


||||||
|---|---|---|---|---|
||**AT&T**|**Intel**|**Value**|**Notes**
|a|mov_ %eax, (%rsp)||
|b|mov_ (%rax), %dx|||
|c|mov_ $0xFF, %bl|||
|d|mov_ (%rsp, %rdx,4)|| 
|e|mov_ (%rdx), %rax|||
|f|mov_ %dx, (%rax)|||
