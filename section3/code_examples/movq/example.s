        .file   "example.c"
# GNU C17 (Compiler-Explorer-Build-gcc--binutils-2.36.1) version 11.2.0 (x86_64-linux-gnu)
#       compiled by GNU C version 7.5.0, GMP version 6.1.0, MPFR version 3.1.6, MPC version 1.0.3, isl version isl-0.18-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -mtune=generic -march=x86-64 -g -Og
        .text
.Ltext0:
        .file 0 "/app" "/app/example.c"
        .globl  movq_demo
        .type   movq_demo, @function
movq_demo:
.LVL0:
.LFB0:
        .file 1 "/app/example.c"
        .loc 1 3 32 view -0
        .cfi_startproc
        .loc 1 5 5 view .LVU1
        .loc 1 9 5 view .LVU2
        .loc 1 13 5 view .LVU3
        .loc 1 17 5 view .LVU4
# /app/example.c:17:     *ptr = 0x5678;
        .loc 1 17 10 is_stmt 0 view .LVU5
        movq    $22136, global_val(%rip)        #, MEM[(volatile long int *)&global_val]
        .loc 1 21 5 is_stmt 1 view .LVU6
# /app/example.c:21:     *ptr = b;
        .loc 1 21 10 is_stmt 0 view .LVU7
        movq    %rdi, global_val(%rip)  # param_val, MEM[(volatile long int *)&global_val]
        .loc 1 25 5 is_stmt 1 view .LVU8
# /app/example.c:25:     long c = *ptr;
        .loc 1 25 10 is_stmt 0 view .LVU9
        movq    global_val(%rip), %rax  # MEM[(volatile long int *)&global_val], c
# /app/example.c:26: }
        .loc 1 26 1 view .LVU10
        ret     
        .cfi_endproc
.LFE0:
        .size   movq_demo, .-movq_demo
        .globl  main
        .type   main, @function
main:
.LFB1:
        .loc 1 28 12 is_stmt 1 view -0
        .cfi_startproc
        .loc 1 29 5 view .LVU12
        movl    $10, %edi       #,
        call    movq_demo       #
.LVL1:
        .loc 1 30 5 view .LVU13
# /app/example.c:31: }
        .loc 1 31 1 is_stmt 0 view .LVU14
        movl    $0, %eax        #,
        ret     
        .cfi_endproc
.LFE1:
        .size   main, .-main
        .globl  global_val
        .data
        .align 8
        .type   global_val, @object
        .size   global_val, 8
global_val:
        .quad   100
        .text
.Letext0:
        .section        .debug_info,"",@progbits
.Ldebug_info0:
        .long   0xfc
        .value  0x5
        .byte   0x1
        .byte   0x8
        .long   .Ldebug_abbrev0
        .uleb128 0x2
        .long   .LASF6
        .byte   0x1d
        .long   .LASF0
        .long   .LASF1
        .quad   .Ltext0
        .quad   .Letext0-.Ltext0
        .long   .Ldebug_line0
        .uleb128 0x3
        .long   .LASF5
        .byte   0x1
        .byte   0x1
        .byte   0x6
        .long   0x44
        .uleb128 0x9
        .byte   0x3
        .quad   global_val
        .uleb128 0x4
        .byte   0x8
        .byte   0x5
        .long   .LASF2
        .uleb128 0x5
        .long   0x44
        .uleb128 0x6
        .long   .LASF3
        .byte   0x1
        .byte   0x1c
        .byte   0x5
        .long   0x86
        .quad   .LFB1
        .quad   .LFE1-.LFB1
        .uleb128 0x1
        .byte   0x9c
        .long   0x86
        .uleb128 0x7
        .quad   .LVL1
        .long   0x8d
        .uleb128 0x8
        .uleb128 0x1
        .byte   0x55
        .uleb128 0x1
        .byte   0x3a
        .byte   0
        .byte   0
        .uleb128 0x9
        .byte   0x4
        .byte   0x5
        .string "int"
        .uleb128 0xa
        .long   .LASF4
        .byte   0x1
        .byte   0x3
        .byte   0x6
        .quad   .LFB0
        .quad   .LFE0-.LFB0
        .uleb128 0x1
        .byte   0x9c
        .long   0xf9
        .uleb128 0xb
        .long   .LASF7
        .byte   0x1
        .byte   0x3
        .byte   0x15
        .long   0x44
        .uleb128 0x1
        .byte   0x55
        .uleb128 0x1
        .string "ptr"
        .byte   0x5
        .byte   0x14
        .long   0xf9
        .uleb128 0xa
        .byte   0x3
        .quad   global_val
        .byte   0x9f
        .uleb128 0xc
        .string "a"
        .byte   0x1
        .byte   0x9
        .byte   0xa
        .long   0x44
        .value  0x1234
        .uleb128 0xd
        .string "b"
        .byte   0x1
        .byte   0xd
        .byte   0xa
        .long   0x44
        .long   .LLST0
        .long   .LVUS0
        .uleb128 0x1
        .string "c"
        .byte   0x19
        .byte   0xa
        .long   0x44
        .uleb128 0x1
        .byte   0x50
        .byte   0
        .uleb128 0xe
        .byte   0x8
        .long   0x4b
        .byte   0
        .section        .debug_abbrev,"",@progbits
.Ldebug_abbrev0:
        .uleb128 0x1
        .uleb128 0x34
        .byte   0
        .uleb128 0x3
        .uleb128 0x8
        .uleb128 0x3a
        .uleb128 0x21
        .sleb128 1
        .uleb128 0x3b
        .uleb128 0xb
        .uleb128 0x39
        .uleb128 0xb
        .uleb128 0x49
        .uleb128 0x13
        .uleb128 0x2
        .uleb128 0x18
        .byte   0
        .byte   0
        .uleb128 0x2
        .uleb128 0x11
        .byte   0x1
        .uleb128 0x25
        .uleb128 0xe
        .uleb128 0x13
        .uleb128 0xb
        .uleb128 0x3
        .uleb128 0x1f
        .uleb128 0x1b
        .uleb128 0x1f
        .uleb128 0x11
        .uleb128 0x1
        .uleb128 0x12
        .uleb128 0x7
        .uleb128 0x10
        .uleb128 0x17
        .byte   0
        .byte   0
        .uleb128 0x3
        .uleb128 0x34
        .byte   0
        .uleb128 0x3
        .uleb128 0xe
        .uleb128 0x3a
        .uleb128 0xb
        .uleb128 0x3b
        .uleb128 0xb
        .uleb128 0x39
        .uleb128 0xb
        .uleb128 0x49
        .uleb128 0x13
        .uleb128 0x3f
        .uleb128 0x19
        .uleb128 0x2
        .uleb128 0x18
        .byte   0
        .byte   0
        .uleb128 0x4
        .uleb128 0x24
        .byte   0
        .uleb128 0xb
        .uleb128 0xb
        .uleb128 0x3e
        .uleb128 0xb
        .uleb128 0x3
        .uleb128 0xe
        .byte   0
        .byte   0
        .uleb128 0x5
        .uleb128 0x35
        .byte   0
        .uleb128 0x49
        .uleb128 0x13
        .byte   0
        .byte   0
        .uleb128 0x6
        .uleb128 0x2e
        .byte   0x1
        .uleb128 0x3f
        .uleb128 0x19
        .uleb128 0x3
        .uleb128 0xe
        .uleb128 0x3a
        .uleb128 0xb
        .uleb128 0x3b
        .uleb128 0xb
        .uleb128 0x39
        .uleb128 0xb
        .uleb128 0x49
        .uleb128 0x13
        .uleb128 0x11
        .uleb128 0x1
        .uleb128 0x12
        .uleb128 0x7
        .uleb128 0x40
        .uleb128 0x18
        .uleb128 0x7a
        .uleb128 0x19
        .uleb128 0x1
        .uleb128 0x13
        .byte   0
        .byte   0
        .uleb128 0x7
        .uleb128 0x48
        .byte   0x1
        .uleb128 0x7d
        .uleb128 0x1
        .uleb128 0x7f
        .uleb128 0x13
        .byte   0
        .byte   0
        .uleb128 0x8
        .uleb128 0x49
        .byte   0
        .uleb128 0x2
        .uleb128 0x18
        .uleb128 0x7e
        .uleb128 0x18
        .byte   0
        .byte   0
        .uleb128 0x9
        .uleb128 0x24
        .byte   0
        .uleb128 0xb
        .uleb128 0xb
        .uleb128 0x3e
        .uleb128 0xb
        .uleb128 0x3
        .uleb128 0x8
        .byte   0
        .byte   0
        .uleb128 0xa
        .uleb128 0x2e
        .byte   0x1
        .uleb128 0x3f
        .uleb128 0x19
        .uleb128 0x3
        .uleb128 0xe
        .uleb128 0x3a
        .uleb128 0xb
        .uleb128 0x3b
        .uleb128 0xb
        .uleb128 0x39
        .uleb128 0xb
        .uleb128 0x27
        .uleb128 0x19
        .uleb128 0x11
        .uleb128 0x1
        .uleb128 0x12
        .uleb128 0x7
        .uleb128 0x40
        .uleb128 0x18
        .uleb128 0x7a
        .uleb128 0x19
        .uleb128 0x1
        .uleb128 0x13
        .byte   0
        .byte   0
        .uleb128 0xb
        .uleb128 0x5
        .byte   0
        .uleb128 0x3
        .uleb128 0xe
        .uleb128 0x3a
        .uleb128 0xb
        .uleb128 0x3b
        .uleb128 0xb
        .uleb128 0x39
        .uleb128 0xb
        .uleb128 0x49
        .uleb128 0x13
        .uleb128 0x2
        .uleb128 0x18
        .byte   0
        .byte   0
        .uleb128 0xc
        .uleb128 0x34
        .byte   0
        .uleb128 0x3
        .uleb128 0x8
        .uleb128 0x3a
        .uleb128 0xb
        .uleb128 0x3b
        .uleb128 0xb
        .uleb128 0x39
        .uleb128 0xb
        .uleb128 0x49
        .uleb128 0x13
        .uleb128 0x1c
        .uleb128 0x5
        .byte   0
        .byte   0
        .uleb128 0xd
        .uleb128 0x34
        .byte   0
        .uleb128 0x3
        .uleb128 0x8
        .uleb128 0x3a
        .uleb128 0xb
        .uleb128 0x3b
        .uleb128 0xb
        .uleb128 0x39
        .uleb128 0xb
        .uleb128 0x49
        .uleb128 0x13
        .uleb128 0x2
        .uleb128 0x17
        .uleb128 0x2137
        .uleb128 0x17
        .byte   0
        .byte   0
        .uleb128 0xe
        .uleb128 0xf
        .byte   0
        .uleb128 0xb
        .uleb128 0xb
        .uleb128 0x49
        .uleb128 0x13
        .byte   0
        .byte   0
        .byte   0
        .section        .debug_loclists,"",@progbits
        .long   .Ldebug_loc3-.Ldebug_loc2
.Ldebug_loc2:
        .value  0x5
        .byte   0x8
        .byte   0
        .long   0
.Ldebug_loc0:
.LVUS0:
        .uleb128 .LVU4
        .uleb128 0
.LLST0:
        .byte   0x4
        .uleb128 .LVL0-.Ltext0
        .uleb128 .LFE0-.Ltext0
        .uleb128 0x1
        .byte   0x55
        .byte   0
.Ldebug_loc3:
        .section        .debug_aranges,"",@progbits
        .long   0x2c
        .value  0x2
        .long   .Ldebug_info0
        .byte   0x8
        .byte   0
        .value  0
        .value  0
        .quad   .Ltext0
        .quad   .Letext0-.Ltext0
        .quad   0
        .quad   0
        .section        .debug_line,"",@progbits
.Ldebug_line0:
        .section        .debug_str,"MS",@progbits,1
.LASF4:
        .string "movq_demo"
.LASF6:
        .string "GNU C17 11.2.0 -mtune=generic -march=x86-64 -g -Og"
.LASF7:
        .string "param_val"
.LASF2:
        .string "long int"
.LASF3:
        .string "main"
.LASF5:
        .string "global_val"
        .section        .debug_line_str,"MS",@progbits,1
.LASF0:
        .string "/app/example.c"
.LASF1:
        .string "/app"
        .ident  "GCC: (Compiler-Explorer-Build-gcc--binutils-2.36.1) 11.2.0"
        .section        .note.GNU-stack,"",@progbits
