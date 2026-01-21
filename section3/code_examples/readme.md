## Compilation instructions for sum.c using separate assembly and object files

- Full sequence, C file .c -> assembly file .s -> object file .o -> executable binary
```bash
$ gcc -Og -S sum.c
$ gcc -c sum.s -o sum.o
$ gcc sum.o -o sum
$./sum 5 4
5 + 4 --> 9
```

### Compilation static linking instructions one liner
- Compile with static linking: To ensure the resulting binary is a "statically linked" executable and not a "shared object," use the -static flag. You may also need -no-pie to strictly produce the ELF 64-bit LSB executable type.

```
% gcc -static -no-pie main.c -o main_static
```
