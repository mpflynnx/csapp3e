.intel_syntax noprefix

.section .data
    global_val: .quad 100

.section .text
    .globl _start

_start:
    push rbp
    mov rbp, rsp
    sub rsp, 16

    lea rax, [rip + global_val]
    mov [rbp-8], rax

    mov rax, 0x1234

    mov rbx, 10

    mov rdx, [rbp-8]
    mov qword ptr [rdx], 0x5678

    mov qword ptr [rdx], rbx

    mov rcx, [rdx]

    mov rax, 60
    xor rdi, rdi
    syscall
