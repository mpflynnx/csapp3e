// https://gemini.google.com/app/e92088aa5833ea84

long global_val = 100;

void movq_demo(long param_val) {
    // We use a volatile pointer to force memory access
    volatile long *ptr = &global_val;

    // 1. Immediate to Register
    // Loading a constant into a register
    long a = 0x1234; 

    // 2. Register to Register
    // Moving the parameter (rdi) to another register
    long b = param_val;

    // 3. Immediate to Memory
    // Moving a constant directly to a memory address
    *ptr = 0x5678;

    // 4. Register to Memory
    // Moving a value from a register to a memory address
    *ptr = b;

    // 5. Memory to Register
    // Loading a value from a memory address into a register
    long c = *ptr;
}

int main() {
    movq_demo(10);
    return 0;
}