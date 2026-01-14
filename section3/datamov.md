## Data Movement Instructions (hardback 3.4.2 page 182)

- [C code example showing mov operand combinations](./code_examples/movq/main.c)
- [AT&T syntax assembly](./code_examples/movq/main-att.s)
- [Intel syntax assembly](./code_examples/movq/main-intel.s)

- [C function copies a 64-bit value from one pointer's address to another](./code_examples/copy_val.c)
- [ARMv8 assembly](https://godbolt.org/#g:!((g:!((g:!((h:codeEditor,i:(filename:'1',fontScale:14,fontUsePx:'0',j:1,lang:___c,selection:(endColumn:2,endLineNumber:3,positionColumn:2,positionLineNumber:3,selectionStartColumn:2,selectionStartLineNumber:3,startColumn:2,startLineNumber:3),source:'void+copy_val(long+*dest,+long+*src)+%7B%0A++++*dest+%3D+*src%3B%0A%7D'),l:'5',n:'0',o:'C+source+%231',t:'0')),k:45.246753246753244,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((h:compiler,i:(compiler:armv8-cclang2110,filters:(b:'1',binary:'1',binaryObject:'1',commentOnly:'1',debugCalls:'1',demangle:'1',directives:'1',execute:'1',intel:'0',libraryCode:'1',trim:'1',verboseDemangling:'0'),flagsViewOpen:'1',fontScale:14,fontUsePx:'0',j:1,lang:___c,libs:!(),options:'-Og+-S',overrides:!(),selection:(endColumn:1,endLineNumber:1,positionColumn:1,positionLineNumber:1,selectionStartColumn:1,selectionStartLineNumber:1,startColumn:1,startLineNumber:1),source:1),l:'5',n:'0',o:'+armv8-a+clang+21.1.0+(Editor+%231)',t:'0')),k:54.753246753246756,l:'4',n:'0',o:'',s:0,t:'0')),l:'2',n:'0',o:'',t:'0')),version:4)

### x86-64 AT&T syntax
- `movq` (move quadword, 64-bit)
- `movq Source, Dest`

The instruction is explicitly `movq`. The q stands for Quadword (64-bit). If you were moving a 32-bit int, it would be `movl` (Longword).

The order of operands is (Source, Destination), and it uses specific prefixes `%` for registers and `$` for constants.

Parentheses `(%rsi)` is used to indicate "the value at the address held in this register."

The table below summarizes all the standard `movq` combinations in the AT&T style

|Combination|AT&T Syntax Example |	C Equivalent|
|---|---|---|
|Imm → Reg|	movq $0xABC, %rax|	temp = 2748;
|Reg → Reg|	movq %rdi, %rax|	dest = src;
|Imm → Mem|	movq $10, global_val(%rip)|	global = 10;|
|Reg → Mem|	movq %rax, (%rsi)|	*ptr = val;|
|Mem → Reg|	movq (%rsi), %rax|	val = *ptr;|

- Imm = Immediate: Constant integer data
- Reg = Register: One of the 16 integer registers (%rsp is reserved)
- mem = Memory: 8 consecutive bytes of memory at address given by register

The x86-64 architecture physically does not have an instruction that moves data from one memory address to another in a single step.

### x86-64 Intel syntax
- Intel Syntax: `mov Dest, Source`

`movq` (move quadword) is simply displayed as `mov`, and the size of the operation is specified by the `QWORD PTR` (Quad-Word Pointer) directive, indicating a 64-bit operation.

`[rsi]` square brackets for dereferencing "the value at the address held in this register."

|Combination|Intel Syntax Example |	C Equivalent|
|---|---|---|
|Imm → Reg|	mov rax, 0xABC|	temp = 2748;|
|Reg → Reg|	mov rax, rdi	|dest = src;|
|Imm → Mem|	mov QWORD PTR [rip+offset], 10	|global = 10;|
|Reg → Mem|	mov QWORD PTR [rsi], rax	|*ptr = val;|
|Mem → Reg|	mov rax, QWORD PTR [rsi]|	val = *ptr;|

**Memory-to-Memory**

If you ever see a C line like *ptr_a = *ptr_b;, look closely at the assembly. You will notice it must break it into two steps:

1. `mov rax, [rsi]` (Read from source into temporary register)

2. `mov [rdi], rax` (Write from register to destination)

The x86-64 architecture physically does not have an instruction that moves data from one memory address to another in a single step.

**global_val[rip] and global_val(%rip)**

You see `global_val(%rip)` or `global_val[rip]` because of RIP-relative addressing. In 64-bit mode, the CPU calculates the address of global variables by taking the current Instruction Pointer (rip) and adding an offset to it. This makes the code "Position Independent," meaning it can be loaded anywhere in memory and still find its data.

### ARM64 (AArch64)
In ARM64 (AArch64), the philosophy is different from x86-64. ARM is a Load/Store architecture, meaning it does not allow data processing instructions (like add) or direct moves to work with memory.

In ARM64, you use STR (Store) to move data to memory and LDR (Load) to move data from memory. The MOV instruction is strictly for Register-to-Register or Immediate-to-Register operations.


**No immediate-to-memory**
- Unlike x86-64, which can do `movq $10, (%rax)`, ARM64 cannot move a constant directly into memory. You must first load the constant into a register and then store that register to memory:
```Assembly
mov w0, #10      // Load 10 into a register
str w0, [x1]     // Store that register to the address in x1
```

**Registers (x vs. w)**
- x0 - x30: 64-bit registers (equivalent to rax, rbx, etc.).
- w0 - w30: 32-bit registers (the lower half of the x-registers, equivalent to eax, ebc, etc).
- ARM64 doesn't need a q or l suffix on the instruction because the register name (x for 64-bit, w for 32-bit) tells the CPU exactly how much data to move.

**Square Brackets**
- ARM64 uses square brackets for dereferencing, similar to Intel syntax. [x1] means "the memory address contained in register x1."

**# symbol**
- Uses the # symbol to denote immediate values (constants).

|Combination|	ARM64 Assembly|	C Equivalent|
|---|---|---|
Imm → Reg|	mov x0, #0xABC|	temp = 2748;
Reg → Reg|	mov x1, x0|	dest = src;
Imm → Mem|	Requires 2 steps (see below)	global = 10;
Reg → Mem|	str x0, [x1]|	*ptr = val;|
Mem → Reg|	ldr x0, [x1]|	val = *ptr;|

