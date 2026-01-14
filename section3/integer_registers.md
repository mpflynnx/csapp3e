## x86-64 Integer Registers

**Registers**  
Registers are areas in the CPU where data can be processed. CPUs don’t operate on memory directly, but instead data is loaded into registers, processed, and written back to memory. In assembly language, generally, you cannot directly copy data from one memory location to another without first passing that data through a register.

![ Alt text](./x86-64-integer-registers.jpg)

To recap:
* **b**ytes - 8-bit data  
* **w**ords - 16-bit data  
* **d**oublewords - 32-bit data  
* **q**uadwords - 64-bit data  
* **d**ouble **q**uadwords - 128-bit data

The bold characters will be important later.

**General Purpose Registers**  
The first type of register is what is known as a General Purpose Register (GPR). GPRs are referred to as general purpose because they can contain either data, in this case up to a 64-bit value, or a memory address (a pointer). A value in a GPR can be processed through operations like addition, multiplication, shifting, etc. 

AT&T Syntax:
- %rax, %rcx, %rdx, %rbx, %rsi, %rdi - 64bit quad word
- %eax, %ecx, %edx, %ebx, %esi, %edi - 32bit double word (the lower half of the %rax, %rcx etc. -registers).
- %r8 through %r15

**Special Registers**
- %rip - Instruction pointer 
- %rsp - Stack Pointer
- %rflags - Flags register (Carry, zero, sign, etc..)


### External References
- [FFmpeg Assembly Language Lesson One](https://github.com/FFmpeg/asm-lessons/blob/main/lesson_01/index.md)
- [x86-64 Registers](https://libsiowdujmvaygtfygf.supabase.co/storage/v1/object/sign/images/public/x86_64_registers_big-17054047616301364467.png?token=eyJraWQiOiJzdG9yYWdlLXVybC1zaWduaW5nLWtleV85MzRlMGFiYi00Yzk2LTQ4OWMtOWJhMC1jMWRlZjlhMGQwZTIiLCJhbGciOiJIUzI1NiJ9.eyJ1cmwiOiJpbWFnZXMvcHVibGljL3g4Nl82NF9yZWdpc3RlcnNfYmlnLTE3MDU0MDQ3NjE2MzAxMzY0NDY3LnBuZyIsImlhdCI6MTc2ODI5Nzg4NCwiZXhwIjoxNzY4Mzg0Mjg0fQ.ZwszrM_7su40HjDY_b1ubZq8Gm8tionh4X0_rPaDEWE)
- [youtube.com | Kay Lack | from ARM64 to x86-64](https://www.youtube.com/watch?v=feqD9k0Inds)