### x86-64 playground

The x86-64 Playground is an open-source, web-based platform designed for writing, executing, and debugging x86-64 assembly code. It is specifically built as an educational tool to help students and developers understand low-level programming without the complexity of setting up a local development environment. It supports multiple assemblers. You can switch between popular assemblers including NASM, FASM, and GNU Assembler (gas).

- [x86-64 playground](https://app.x64.halb.it/)
- [`GNU as` and `Intel` syntax assembly file](gnu_syscall_mov.s)
- [citation](https://share.google/aimode/XpjFWa1XMZ2SkZbHL)
- [citation](https://gemini.google.com/app/65b2e5930539e43d)

### Using the x86-64 editor
- Use must use the correct syntax for the selected compiler else the code will fail to compile.
- Select from the dropdown `GNU as`
- Intel syntax assembly must contain `.intel_syntax noprefix` else AT&T syntax is assumed.
- Assembly can be copied and pasted from files such as [gnu_syscall_mov](./gnu_syscall_mov.s)
- Click `compile` button.
- Click `stepi` button to single step through each instruction.

### Compiling and linking assembly files to create an executable to work on x86-64 playground
- x86-64 needs a statically linked elf.
- The pure assembly way (using no C Libraries)
- If your assembly code defines its own entry point (usually _start) and uses direct system calls rather than `libc` functions, this is the cleanest method.

```bash
$ as -o gnu_syscall_mov.o gnu_syscall_mov.s

$ ld -o gnu_syscall_mov gnu_syscall_mov.o
```

### Using the file with x86-64 playground
- Select: File | Load executable from your files
- Select: executable i.e `gnu_syscall_mov`
- Use `stepi` button to single step through the program

### Including debug symbols in your executable while using _start.
- x86-64 Playground may not show all the memory locations. If the assembly code is compiled with debug symbols, gdb can be used.
- To get full debugging support (source-level stepping) for assembly, follow these steps:
- You must use the `-g` flag during the assembly stage. This tells the GNU Assembler (as) to generate a debug symbol table that maps machine instructions back to your `.s` file line numbers

```bash
$ as -g -o gnu_syscall_mov.o gnu_syscall_mov.s
```
- When you link with ld, avoid using the -s (strip) flag, as it removes all debug symbols you just created.
```bash
$ ld -o gnu_syscall_mov gnu_syscall_mov.o
```
(Note: ld does not need -g itself; it just preserves the information already in the .o file).

- Once built, you can verify the debug symbols are present using objdump:
```bash
$ objdump --syms ./gnu_syscall_mov

./gnu_syscall_mov:     file format elf64-x86-64

SYMBOL TABLE:
0000000000000000 l    df *ABS*	0000000000000000 gnu_syscall_mov.o
0000000000402000 l       .data	0000000000000000 global_val
0000000000401000 g       .text	0000000000000000 _start
0000000000402008 g       .data	0000000000000000 __bss_start
0000000000402008 g       .data	0000000000000000 _edata
0000000000402008 g       .data	0000000000000000 _end
```

### Debugging with GDB
With these symbols, GDB will allow you to see your source code while you step through it:
1. Start: gdb ./my_program
1. Set breakpoint: break _start
1. Run: run
1. View code: list or use layout tui mode with ctrl+x then a type: asm / layout regs for a better assembly view.


```bash
(gdb) (gdb) x/gx $rdx
0x402000:	0x0000000000005678
```

- Examine the first 20 "giant words" (64-bit) starting at the stack pointer.

```bash
(gdb) x/20gx $sp
```