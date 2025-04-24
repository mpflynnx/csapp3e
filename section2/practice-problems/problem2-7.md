## Practice Problem 2.7

- [main.c](./code/problem2dot7/main.c)

What would be printed as a result of the following call to show_bytes?

```c
const char *s = "abcdef";
show_bytes((byte_pointer) s, strlen(s));
```

- It prints to screen
```bash
61 62 63 64 65 66
```
- gdb debugging view

```bash
(gdb) x /8bx &*s
0x40200a:	0x61	0x62	0x63	0x64	0x65	0x66	0x00	0x00
```
- const char s[] = "abcdef"; // same as const char *s = "abcdef";

```bash
(gdb) p /x s
$4 = {[0x0] = 0x61, [0x1] = 0x62, [0x2] = 0x63, [0x3] = 0x64, [0x4] = 0x65, 
  [0x5] = 0x66, [0x6] = 0x0}

```