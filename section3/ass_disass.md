## Assemblers and Disassemblers

- Assemblers convert text representation of instructions to byte level 

### Generate an assembly code file from a C code file using gcc
- Flag `-Og`: Optimize argument with `g` for debugging
- Only generates assembly code file `sum.s` from C code file `sum.c` using `-S` gcc argument
```bash
$ gcc -Og -S sum.c
```
- The defaults to generating the file in `AT&T` x86-64 syntax.
- Use flag `-masm=intel` for `Intel` x86-64 syntax assembly. See [NASM alternative to GCC](../nasm.md)
- The `-fverbose-asm` flag adds comments explaining which C variables correspond to which registers, making the code much easier to read

### Generate a file that contains the expanded C code after preprocessing
### 
```bash
$ gcc -E -o sum.o sum.c
```
- `-E`: This is the "Stop after Preprocessing" flag. It tells GCC not to compile the code into machine instructions. Instead, it just handles #include files, expands #define macros, and strips out comments.
- `-o sum.o`: Even though the output ends in .o, in this specific case, it will actually be a plain text file containing the expanded C code, not a binary object file.
- `sum.o` could contain thousands of lines of code (all the headers you included, like stdio.h, pasted directly into the file).
- Your original code at the very bottom, but with all the macros replaced by their actual values.
- The output of `-E` cannot be linked, just for viewing the result of the preprocessor stage

### Compile an assembly `.s` file to a object file `.o`

```bash
$ gcc -c sum.s -o sum.o
```

### Convert an object file to a executable binary using a gcc linker syntax
```bash
$ gcc sum.o -o sum
```
- Execute the binary
```bash
$ ./sum 5 4
5 + 4 --> 9
```

- Full sequence, C file .c -> assembly file .s -> object file .o -> executable binary
```bash
$ gcc -Og -S sum.c
$ gcc -c sum.s -o sum.o
$ gcc sum.o -o sum
$./sum 5 4
5 + 4 --> 9
```


### Disassemblers

- Produces a text representation from a byte level file
- Can be run on object files `.o` or binary executables
- Any executable can be disassembled

```bash
$ objdump -d sum > sum.d
```
- `-d` (disassemble): This turns the binary 0s and 1s back into human-readable assembly instructions.
- Defaults to AT&T assembly syntax
- Use flag `-M intel` for Intel assembly syntax

- (Note: If the output is empty or lacks C code, ensure you compiled with -g and that the file hasn't been stripped).

- Use -S or --source to intermix source code with disassembly
```bash
$ objdump -S -M intel sum.o > sum.d
```


### Using GDB (Gnu Debugger) to view disassemble

```bash
$ gdb -q ./sum
```
- View the disassemble of function `sumstore`
```bash
(gdb) disassemble sumstore
Dump of assembler code for function sumstore:
   0x000000000040112b <+0>:	push   %rbx
   0x000000000040112c <+1>:	mov    %rdx,%rbx
   0x000000000040112f <+4>:	call   0x401126 <plus>
   0x0000000000401134 <+9>:	mov    %rax,(%rbx)
   0x0000000000401137 <+12>:	pop    %rbx
   0x0000000000401138 <+13>:	ret    
End of assembler dump.
```
- Debug running program
```bash
$ gdb --args ./sum 5 3
(gdb) b sumstore
(gdb) r
```

- Change the view to TUI
- ctrl+x then press 1 to see source code
- Type `layout regs` (to see the CPU registers at the top)
- Step through instructions
```bash
(gdb) si
```
- View a registers value
```bash
(gdb) info registers rax
rax 0x8
```
- Examine the 14 bytes in hex starting at address of function `sumstore`
```bash
(gdb) x/14xb sumstore
```