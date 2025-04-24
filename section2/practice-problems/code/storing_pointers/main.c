#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// https://gemini.google.com/app/8618af44cbc04036
// Best practice for storing pointers on a 64-bit machine:
// Use uintptr_t or intptr_t from <stdint.h>

void best_pointer_storage_example() {
  int my_int = 42;
  int* my_int_ptr = &my_int;

  // 1. Using uintptr_t (unsigned integer type capable of holding a pointer)
  uintptr_t ptr_as_uint = (uintptr_t)my_int_ptr;

  printf("Pointer as uintptr_t: 0x%lx\n", ptr_as_uint); // %lx for unsigned long hexadecimal

  // Converting back to a pointer:
  int* back_to_ptr = (int*)ptr_as_uint;
  printf("Value pointed to by back_to_ptr: %d\n", *back_to_ptr);

  // 2. Using intptr_t (signed integer type capable of holding a pointer)
  intptr_t ptr_as_int = (intptr_t)my_int_ptr;

  printf("Pointer as intptr_t: 0x%lx\n", ptr_as_int); // %lx for signed long hexadecimal

  // Converting back to a pointer:
  int* back_to_ptr2 = (int*)ptr_as_int;
  printf("Value pointed to by back_to_ptr2: %d\n", *back_to_ptr2);

    //3. Using void* when type information is not needed.
    void* generic_ptr = my_int_ptr;

    //Converting back to original pointer type.
    int* restored_ptr = (int*) generic_ptr;
    printf("Value pointed to by restored_ptr: %d\n", *restored_ptr);

}

int main() {
  best_pointer_storage_example();
  return 0;
}
