## `swap` function program example
- This code example demonstrates pointer dereferencing and memory swapping using the x86-64 calling convention.

- [C code file main.c](./main.c)
- [AT&T syntax assembly code file main.s](./main.s)
- [Intel syntax assembly code file main.s](./main-intel.s)

### The`swap` function 

**C code for swap function**
```c
void swap (uint64_t *xp, uint64_t *yp) {
    uint64_t t0 = *xp;
    uint64_t t1 = *yp;
    *xp = t1;
    *yp = t0;
}
```



**AT&T Assembly code for swap function**
```Assembly
swap:
    movq    (%rdi), %rax    # Load the value at address %rdi (xp) into %rax
    movq    (%rsi), %rdx    # Load the value at address %rsi (yp) into %rdx
    movq    %rdx, (%rdi)    # Store the value from %rdx into the address at %rdi
    movq    %rax, (%rsi)    # Store the value from %rax into the address at %rsi
    ret                     # Return to caller
```

### Reading from memory through pointers

- The movq instruction (move 64-bit value) loads 8 bytes from memory into registers %rax and %rdx

```Assembly
movq    (%rdi), %rax    # Load the value at address %rdi (xp) into %rax
movq    (%rsi), %rdx    # Load the value at address %rsi (yp) into %rdx
```
The swap function receives two pointers (memory addresses) as parameters:
- %rdi contains the address of the first variable `xp`
- %rsi contains the address of the second variable `yp`

### Writing back to memory

```Assembly
movq    %rdx, (%rdi)    # Store the value from %rdx into the address at %rdi
movq    %rax, (%rsi)    # Store the value from %rax into the address at %rsi
ret                     # Return to caller
```
- Dereferencing: The parentheses in (%rdi) indicate a memory access (like *xp in C).

- Now the values are swapped: we write %rdx (which held *yp) to the location *xp, and %rax (which held *xp) to the location *yp.
- No Stack Usage: Notice swap doesn't use the stack; it does everything in registers %rax and %rdx, which is very fast.
### The `main` function

The `main` function sets up the swap operation

**C code for swap function**
```c
int main() {
    uint64_t xp = 0x749B2F1A;
    uint64_t yp = 0x52D109E4;
    swap(&xp, &yp); // Passes addresses, not values
    return 0;
}
```

**AT&T Assembly code for `main` function**
```Assembly
main:
	subq	$16, %rsp
	movq	$1956327194, 8(%rsp)
	movq	$1389431268, (%rsp)
	movq	%rsp, %rsi
	leaq	8(%rsp), %rdi
	call	swap
	movl	$0, %eax
	addq	$16, %rsp
	ret                             
```

### Stack allocation
This creates local storage. The stack grows downwards. This creates space for two 8-byte (64-bit) integers.
```Assembly
subq	$16, %rsp # Make 16 bytes of space on the stack
```
### Storing values
```Assembly
movq    $1956327194, 8(%rsp)    # Store 0x749B2F1A at offset 8
movq    $1389431268, (%rsp)     # Store 0x52D109E4 at offset 0
```
- The values are placed on the stack. Notice the offsets: 8(%rsp) means "8 bytes above the stack pointer" and (%rsp) means "at the stack pointer."

### Computing addresses and calling `swap` function
```Assembly
movq	%rsp, %rsi      # %rsi = address of yp (at %rsp)
leaq	8(%rsp), %rdi   # %rdi = address of xp (at %rsp + 8)
call	swap            # calls the swap function
```
- The leaq instruction (load effective address) computes an address without accessing memory — it just calculates %rsp + 8 and stores that address in %rdi. This is how we pass pointers: we compute the memory addresses of our local variables and pass them to `swap`. This is the assembly equivalent of the & operator in C.

### Cleanup and return
- The stack space is freed by adding 16 back to %rsp, restoring the stack pointer to its original position.
```Assembly
movl	$0, %eax    # Set return value to 0 (return 0;) 
addq	$16, %rsp   # Deallocate stack space (move pointer back up)
ret                 # Exit program
```