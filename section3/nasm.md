## NASM (Netwide Assembler)

While GCC (via the GNU Assembler, GAS) is a powerful tool for compiling high-level code, developers often choose NASM (Netwide Assembler) when writing assembly by hand for several key reasons: 
- Human-Friendly Syntax: NASM uses Intel syntax (mov dest, src), which is the standard found in official Intel and AMD manuals. By contrast, GCC defaults to AT&T syntax (movl %src, %dest), which many find archaic due to its heavy use of prefixes like % for registers and $ for constants.
- Direct Binary Output: NASM can generate flat binary files directly, which is essential for writing 16-bit bootloaders or shellcode where no OS headers (like ELF or PE) are wanted. GCC typically requires an external linker and a custom linker script to achieve this.
- Superior Macro System: NASM features a highly mature and powerful macro language that allows for complex multi-line macros, conditional assembly, and pre-processor logic. While GAS supports macros, developers often resort to the C preprocessor (CPP) to get similar functionality.
- Strict Operand Logic: In NASM, square brackets [] always denote a memory reference, and their absence always denotes an immediate or register value. In GCC's Intel-syntax mode, the meaning can sometimes be ambiguous depending on how a symbol was declared, leading to potential bugs.
- 16-bit Support: NASM has robust support for 16-bit segments and OMF object files, making it the better choice for legacy DOS or early-stage OS development. GAS has very limited support for 16-bit segmentation.
-Cross-Platform Portability: NASM itself is highly portable; you can use the same NASM source file and simply change the output flag (e.g., -f elf64 for Linux or -f win64 for Windows) to target different operating systems using the same assembler. 

### External references
- [Text AI generated](https://share.google/aimode/cE0bFh66fo7cd7VLA)