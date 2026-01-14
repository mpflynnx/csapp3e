## Compilation instructions sum.c

- Full sequence, C file .c -> assembly file .s -> object file .o -> executable binary
```bash
$ gcc -Og -S sum.c
$ gcc -c sum.s -o sum.o
$ gcc sum.o -o sum
$./sum 5 4
5 + 4 --> 9
```
