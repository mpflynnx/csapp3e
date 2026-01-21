.intel_syntax noprefix

.section .data
    global_val: .quad 100       # global long global_val = 100;

.section .text
    .globl _start

_start:
    # --- Function Prologue ---
    push rbp                    # Save old base pointer
    mov rbp, rsp                # Set current stack pointer as base pointer
    sub rsp, 16                 # Allocate 16 bytes on stack for local variables

    # --- volatile long *ptr = &global_val; ---
    lea rax, [rip + global_val] # Get address of global_val (RIP-relative)
    mov [rbp-8], rax            # Store address in local stack variable (ptr)

    # --- 1. Immediate to Register ---
    # long a = 0x1234;
    mov rax, 0x1234             # Move constant 0x1234 into RAX

    # --- 2. Register to Register ---
    # long b = 10;
    mov rbx, 10                 # Load 10 into RBX (representing variable 'b')

    # --- 3. Immediate to Memory ---
    # *ptr = 0x5678;
    mov rdx, [rbp-8]            # Load the address stored in 'ptr' into RDX
    mov qword ptr [rdx], 0x5678 # Move constant 0x5678 to the address in RDX

    # --- 4. Register to Memory ---
    # *ptr = b;
    mov qword ptr [rdx], rbx    # Move value of RBX (b) to the address in RDX

    # --- 5. Memory to Register ---
    # long c = *ptr;
    mov rcx, [rdx]              # Load value from address in RDX into RCX (c)

    # --- System Exit ---
    mov rax, 60                 # syscall: exit
    xor rdi, rdi                # status: 0
    syscall                     # invoke kernel
