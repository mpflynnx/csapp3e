;#---------------------
;#  GNU Assembler file
;#  Syscall Hello World
;#---------------------
.intel_syntax noprefix
.global _start
.text
_start:

  ;# Write your assembly below

  ;# sys_exit
  mov rax, 60
  xor rdi, rdi
  syscall
