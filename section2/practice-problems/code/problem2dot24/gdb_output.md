## gdb_output.md

```bash
6	    int x = 53191;
(gdb) s
7	    short sx = (short) x; /* -12345 */
(gdb) x /x &x
0xbffff3f4:	0x0000cfc7
(gdb) x /t &x
0xbffff3f4:	00000000000000001100111111000111
```

- integer x 4bytes 32bits
- integer x = 
00000000000000001100111111000111


= short 2bytes 16bits
- short sx = 
1100111111000111

- Casting short sx to a integer y 4bytes 32bits
- integer y = 
11111111111111111100111111000111
                1100111111000111
0xFFFFCFC7
