.section .data
    global_val: .quad 100

.section .text
    .globl _start

_start:
    pushq %rbp
    movq  %rsp, %rbp
    subq  $16, %rsp

    # RIP-relative addressing: [rip + global_val] -> global_val(%rip)
    leaq  global_val(%rip), %rax
    movq  %rax, -8(%rbp)

    movq  $0x1234, %rax

    movq  $10, %rbx

    # Indirect addressing using the pointer stored on the stack
    movq  -8(%rbp), %rdx
    
    # mov qword ptr [rdx], 0x5678 -> movq $imm, (%reg)
    movq  $0x5678, (%rdx)

    # mov qword ptr [rdx], rbx -> movq %reg, (%reg)
    movq  %rbx, (%rdx)

    movq  (%rdx), %rcx

    # sys_exit
    movq  $60, %rax
    xorq  %rdi, %rdi
    syscall
