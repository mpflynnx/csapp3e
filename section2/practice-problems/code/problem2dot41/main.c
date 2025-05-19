#include <stdio.h>

// Function to multiply x by a constant k using bitwise analysis
// This simulates a compiler's optimization for constant multiplication.
// Note: This simplified version works best for unsigned integers
// and demonstrates the principle. Real compilers handle signed numbers,
// overflow, and different architectures more elaborately.
unsigned int multiply_by_constant_optimized(unsigned int x, unsigned int k) {
    unsigned int result = 0;
    int bit_pos = 0; // Current bit position (0 for LSB)

    printf("Performing multiplication of %u * %u using bit analysis...\n", x, k);
    printf("Binary representation of multiplier %u: ", k);

    // Optional: Print binary representation of k for clarity
    for (int i = sizeof(unsigned int) * 8 - 1; i >= 0; --i) {
        printf("%d", (k >> i) & 1);
        if (i % 8 == 0 && i > 0) printf(" "); // Add space for readability
    }
    printf("\n");

    // Iterate through each bit of the constant k
    // We make a copy as we'll modify the value in the loop
    unsigned int temp_k = k;

    while (temp_k > 0) {
        // Check the least significant bit (LSB) of the current temp_k
        if (temp_k & 1) {
            // If the LSB is 1, it means 2^bit_pos is part of the constant k.
            // So, we need to add x * 2^bit_pos to our result.
            // x * 2^bit_pos is efficiently computed as x << bit_pos.
            unsigned int term = x << bit_pos;
            printf("  Bit at position %d is set. Adding term: %u << %d (%u)\n", bit_pos, x, bit_pos, term);
            result += term;
        }

        // Move to the next bit: right shift temp_k by 1
        temp_k >>= 1;

        // Increment the bit position counter
        bit_pos++;
    }

     // Handle the case where k was initially 0
    if (k == 0) {
        printf("  Multiplier is 0. Result is 0.\n");
        result = 0;
    }


    printf("Analysis complete.\n");
    return result;
}

int main() {
    unsigned int number = 15;

    // Example 1: Multiply by 14 (binary 1110)
    unsigned int multiplier1 = 14;
    unsigned int res1 = multiply_by_constant_optimized(number, multiplier1);
    printf("Result of optimized multiplication: %u\n", res1);
    printf("Direct calculation check: %u * %u = %u\n\n", number, multiplier1, number * multiplier1);

    // Example 2: Multiply by 20 (binary 10100)
    unsigned int multiplier2 = 20;
    unsigned int res2 = multiply_by_constant_optimized(number, multiplier2);
    printf("Result of optimized multiplication: %u\n", res2);
    printf("Direct calculation check: %u * %u = %u\n\n", number, multiplier2, number * multiplier2);

     // Example 3: Multiply by 7 (binary 111) - illustrates contiguous bits for Form B potential
    unsigned int multiplier3 = 7;
    unsigned int res3 = multiply_by_constant_optimized(number, multiplier3);
    printf("Result of optimized multiplication: %u\n", res3);
    printf("Direct calculation check: %u * %u = %u\n\n", number, multiplier3, number * multiplier3);

     // Example 4: Multiply by 8 (binary 1000) - illustrates a power of 2
    unsigned int multiplier4 = 8;
    unsigned int res4 = multiply_by_constant_optimized(number, multiplier4);
    printf("Result of optimized multiplication: %u\n", res4);
    printf("Direct calculation check: %u * %u = %u\n\n", number, multiplier4, number * multiplier4);

     // Example 5: Multiply by 0
    unsigned int multiplier5 = 0;
    unsigned int res5 = multiply_by_constant_optimized(number, multiplier5);
    printf("Result of optimized multiplication: %u\n", res5);
    printf("Direct calculation check: %u * %u = %u\n\n", number, multiplier5, number * multiplier5);


    return 0;
}