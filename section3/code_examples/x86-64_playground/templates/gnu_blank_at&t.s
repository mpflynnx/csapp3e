#---------------------
#  GNU Assembler file
#  Syscall Hello World (AT&T Syntax)
#---------------------
.global _start
.text
_start:

  # Write your assembly below

  # sys_exit(rdi)
  movq $60, %rax          # syscall number for sys_exit
  xorq %rdi, %rdi         # exit code 0
  syscall
