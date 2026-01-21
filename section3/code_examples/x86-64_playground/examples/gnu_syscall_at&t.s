#---------------------
#  GNU Assembler file
#  Syscall Hello World (AT&T Syntax)
#---------------------
.global _start
.text
_start:

  # sys_write(rdi, rsi, rdx)
  movq $1, %rax           # syscall number for sys_write
  movq $1, %rdi           # file descriptor 1 (stdout)
  leaq hello_string, %rsi # pointer to string
  movq $14, %rdx          # length of string
  syscall

  # sys_exit(rdi)
  movq $60, %rax          # syscall number for sys_exit
  xorq %rdi, %rdi         # exit code 0
  syscall

.data
hello_string:
        .asciz  "Hello, world!\n"
