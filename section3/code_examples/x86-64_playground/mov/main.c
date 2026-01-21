
long global_val = 100;

int main() {
    
    // We use a volatile pointer to force memory access
    volatile long *ptr = &global_val;

    // 1. Immediate to Register
    // Loading a constant into a register
    long a = 0x1234; 

    // 2. Register to Register
    // Moving the parameter (rdi) to another register
    long b = 10;

    // 3. Immediate to Memory
    // Moving a constant directly to a memory address
    *ptr = 0x5678;

    // 4. Register to Memory
    // Moving a value from a register to a memory address
    *ptr = b;

    // 5. Memory to Register
    // Loading a value from a memory address into a register
    long c = *ptr;
    
    return 0;
}
