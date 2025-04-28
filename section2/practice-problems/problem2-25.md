## Practice Problem 2.25 hardback page 83

### Advice on Signed versus Unsigned

- The following code attempts to sum the elements of an array where the number of elements is given by `length`
- When an array is passed to a function, it "decays" into a pointer to its first element.
- Therefore, if you need to loop through an array passed to a function, you must pass its length as a separate argument:

```c
/* WARNING: This is buggy code */
float sum_elements(float a[], unsigned length){

    float result = 0;

    for (int i = 0; i <= length-1; i++){
        result += a[i];
    }

    return result;

}
```

```c
int main(){

    float a[] = {0.0,1.0,2.0,3.0};
    float sum = sum_elements(a, 4);

	return 0;

}
```

- When function `sum_elements` is called with `length 0`. The bug is detected with `valgrind`.

```bash
$ valgrind ./main
==2101== Memcheck, a memory error detector
==2101== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==2101== Using Valgrind-3.25.0 and LibVEX; rerun with -h for copyright info
==2101== Command: ./main
==2101== 
==2101== Invalid read of size 4
==2101==    at 0x804917C: sum_elements (main.c:9)
==2101==    by 0x80491C5: main (main.c:19)
==2101==  Address 0xbe80d000 is not stack'd, malloc'd or (recently) free'd
==2101== 
==2101== 
==2101== Process terminating with default action of signal 11 (SIGSEGV)
==2101==  Access not within mapped region at address 0xBE80D000
==2101==    at 0x804917C: sum_elements (main.c:9)
==2101==    by 0x80491C5: main (main.c:19)
==2101==  If you believe this happened as a result of a stack
==2101==  overflow in your program's main thread (unlikely but
==2101==  possible), you can try to increase the size of the
==2101==  main thread stack using the --main-stacksize= flag.
==2101==  The main thread stack size used in this run was 8388608.
==2101== 
==2101== HEAP SUMMARY:
==2101==     in use at exit: 0 bytes in 0 blocks
==2101==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==2101== 
==2101== All heap blocks were freed -- no leaks are possible
==2101== 
==2101== For lists of detected and suppressed errors, rerun with: -s
==2101== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
Segmentation fault
```

- As array indexes start at 0, length will be 4 for array indexes 0,1,2,3
- To find the last index if given a length of 4, we subtract 1 from 4 to get index 3.
- length - 1 is used to get the last index of the array.
- If length given is 0 using unsigned arithmetic
- 0 - 1 is not -1 it is UMax 4294967295
- The loop will continue until i <= 4294967295.
- We do not want a loop to stop at 4294967295
- The end condition i <= length needs to change
- or the type for length needs to change


```c
for (int i = 0; i <= length-1; i++){
    result += a[i];
}
```

### Solution
- We really just want to end on the last index
- If array is of length 0, one less than this is -1 for signed integers
- We could change the length type to signed
- We could end when i < length -1

###  Best practice
- Use size_t
- size_t is an unsigned integer type defined in <stddef.h>

```c
float sum_elements(float a[], size_t length){

    float result = 0;

    for (size_t i = 0; i < length; ++i){
        result += a[i];
    }

    return result;

}
```