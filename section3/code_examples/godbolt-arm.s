        .file   "example.c"
        .text
        .globl  copy_val                        // -- Begin function copy_val
        .p2align        2
        .type   copy_val,@function
copy_val:                               // @copy_val
.Lfunc_begin0:
        .file   0 "/app" "/app/example.c" md5 0xbf66f29da7521fed3b79668573ce614f
        .cfi_startproc
// %bb.0:
        //DEBUG_VALUE: copy_val:dest <- $x0
        //DEBUG_VALUE: copy_val:src <- $x1
        .file   1 "example.c" md5 0xbf66f29da7521fed3b79668573ce614f
        .loc    1 2 13 prologue_end             // example.c:2:13
        ldr     x8, [x1]
        .loc    1 2 11 is_stmt 0                // example.c:2:11
        str     x8, [x0]
                                        // fake_use: $x1
                                        // fake_use: $x0
        .loc    1 3 1 is_stmt 1                 // example.c:3:1
        ret
.Ltmp0:
.Lfunc_end0:
        .size   copy_val, .Lfunc_end0-copy_val
        .cfi_endproc
                                        // -- End function
        .section        .debug_abbrev,"",@progbits
        .byte   1                               // Abbreviation Code
        .byte   17                              // DW_TAG_compile_unit
        .byte   1                               // DW_CHILDREN_yes
        .byte   37                              // DW_AT_producer
        .byte   37                              // DW_FORM_strx1
        .byte   19                              // DW_AT_language
        .byte   5                               // DW_FORM_data2
        .byte   3                               // DW_AT_name
        .byte   37                              // DW_FORM_strx1
        .byte   114                             // DW_AT_str_offsets_base
        .byte   23                              // DW_FORM_sec_offset
        .byte   16                              // DW_AT_stmt_list
        .byte   23                              // DW_FORM_sec_offset
        .byte   27                              // DW_AT_comp_dir
        .byte   37                              // DW_FORM_strx1
        .byte   17                              // DW_AT_low_pc
        .byte   27                              // DW_FORM_addrx
        .byte   18                              // DW_AT_high_pc
        .byte   6                               // DW_FORM_data4
        .byte   115                             // DW_AT_addr_base
        .byte   23                              // DW_FORM_sec_offset
        .byte   0                               // EOM(1)
        .byte   0                               // EOM(2)
        .byte   2                               // Abbreviation Code
        .byte   46                              // DW_TAG_subprogram
        .byte   1                               // DW_CHILDREN_yes
        .byte   17                              // DW_AT_low_pc
        .byte   27                              // DW_FORM_addrx
        .byte   18                              // DW_AT_high_pc
        .byte   6                               // DW_FORM_data4
        .byte   64                              // DW_AT_frame_base
        .byte   24                              // DW_FORM_exprloc
        .byte   122                             // DW_AT_call_all_calls
        .byte   25                              // DW_FORM_flag_present
        .byte   3                               // DW_AT_name
        .byte   37                              // DW_FORM_strx1
        .byte   58                              // DW_AT_decl_file
        .byte   11                              // DW_FORM_data1
        .byte   59                              // DW_AT_decl_line
        .byte   11                              // DW_FORM_data1
        .byte   39                              // DW_AT_prototyped
        .byte   25                              // DW_FORM_flag_present
        .byte   63                              // DW_AT_external
        .byte   25                              // DW_FORM_flag_present
        .byte   0                               // EOM(1)
        .byte   0                               // EOM(2)
        .byte   3                               // Abbreviation Code
        .byte   5                               // DW_TAG_formal_parameter
        .byte   0                               // DW_CHILDREN_no
        .byte   2                               // DW_AT_location
        .byte   24                              // DW_FORM_exprloc
        .byte   3                               // DW_AT_name
        .byte   37                              // DW_FORM_strx1
        .byte   58                              // DW_AT_decl_file
        .byte   11                              // DW_FORM_data1
        .byte   59                              // DW_AT_decl_line
        .byte   11                              // DW_FORM_data1
        .byte   73                              // DW_AT_type
        .byte   19                              // DW_FORM_ref4
        .byte   0                               // EOM(1)
        .byte   0                               // EOM(2)
        .byte   4                               // Abbreviation Code
        .byte   15                              // DW_TAG_pointer_type
        .byte   0                               // DW_CHILDREN_no
        .byte   73                              // DW_AT_type
        .byte   19                              // DW_FORM_ref4
        .byte   0                               // EOM(1)
        .byte   0                               // EOM(2)
        .byte   5                               // Abbreviation Code
        .byte   36                              // DW_TAG_base_type
        .byte   0                               // DW_CHILDREN_no
        .byte   3                               // DW_AT_name
        .byte   37                              // DW_FORM_strx1
        .byte   62                              // DW_AT_encoding
        .byte   11                              // DW_FORM_data1
        .byte   11                              // DW_AT_byte_size
        .byte   11                              // DW_FORM_data1
        .byte   0                               // EOM(1)
        .byte   0                               // EOM(2)
        .byte   0                               // EOM(3)
        .section        .debug_info,"",@progbits
.Lcu_begin0:
        .word   .Ldebug_info_end0-.Ldebug_info_start0 // Length of Unit
.Ldebug_info_start0:
        .hword  5                               // DWARF version number
        .byte   1                               // DWARF Unit Type
        .byte   8                               // Address Size (in bytes)
        .word   .debug_abbrev                   // Offset Into Abbrev. Section
        .byte   1                               // Abbrev [1] 0xc:0x41 DW_TAG_compile_unit
        .byte   0                               // DW_AT_producer
        .hword  29                              // DW_AT_language
        .byte   1                               // DW_AT_name
        .word   .Lstr_offsets_base0             // DW_AT_str_offsets_base
        .word   .Lline_table_start0             // DW_AT_stmt_list
        .byte   2                               // DW_AT_comp_dir
        .byte   0                               // DW_AT_low_pc
        .word   .Lfunc_end0-.Lfunc_begin0       // DW_AT_high_pc
        .word   .Laddr_table_base0              // DW_AT_addr_base
        .byte   2                               // Abbrev [2] 0x23:0x20 DW_TAG_subprogram
        .byte   0                               // DW_AT_low_pc
        .word   .Lfunc_end0-.Lfunc_begin0       // DW_AT_high_pc
        .byte   1                               // DW_AT_frame_base
        .byte   111
                                        // DW_AT_call_all_calls
        .byte   3                               // DW_AT_name
        .byte   1                               // DW_AT_decl_file
        .byte   1                               // DW_AT_decl_line
                                        // DW_AT_prototyped
                                        // DW_AT_external
        .byte   3                               // Abbrev [3] 0x2e:0xa DW_TAG_formal_parameter
        .byte   1                               // DW_AT_location
        .byte   80
        .byte   4                               // DW_AT_name
        .byte   1                               // DW_AT_decl_file
        .byte   1                               // DW_AT_decl_line
        .word   67                              // DW_AT_type
        .byte   3                               // Abbrev [3] 0x38:0xa DW_TAG_formal_parameter
        .byte   1                               // DW_AT_location
        .byte   81
        .byte   6                               // DW_AT_name
        .byte   1                               // DW_AT_decl_file
        .byte   1                               // DW_AT_decl_line
        .word   67                              // DW_AT_type
        .byte   0                               // End Of Children Mark
        .byte   4                               // Abbrev [4] 0x43:0x5 DW_TAG_pointer_type
        .word   72                              // DW_AT_type
        .byte   5                               // Abbrev [5] 0x48:0x4 DW_TAG_base_type
        .byte   5                               // DW_AT_name
        .byte   5                               // DW_AT_encoding
        .byte   8                               // DW_AT_byte_size
        .byte   0                               // End Of Children Mark
.Ldebug_info_end0:
        .section        .debug_str_offsets,"",@progbits
        .word   32                              // Length of String Offsets Set
        .hword  5
        .hword  0
.Lstr_offsets_base0:
        .section        .debug_str,"MS",@progbits,1
.Linfo_string0:
        .asciz  "clang version 21.1.0 (https://github.com/llvm/llvm-project.git 3623fe661ae35c6c80ac221f14d85be76aa870f1)" // string offset=0
.Linfo_string1:
        .asciz  "/app/example.c"                // string offset=105
.Linfo_string2:
        .asciz  "/app"                          // string offset=120
.Linfo_string3:
        .asciz  "copy_val"                      // string offset=125
.Linfo_string4:
        .asciz  "dest"                          // string offset=134
.Linfo_string5:
        .asciz  "long"                          // string offset=139
.Linfo_string6:
        .asciz  "src"                           // string offset=144
        .section        .debug_str_offsets,"",@progbits
        .word   .Linfo_string0
        .word   .Linfo_string1
        .word   .Linfo_string2
        .word   .Linfo_string3
        .word   .Linfo_string4
        .word   .Linfo_string5
        .word   .Linfo_string6
        .section        .debug_addr,"",@progbits
        .word   .Ldebug_addr_end0-.Ldebug_addr_start0 // Length of contribution
.Ldebug_addr_start0:
        .hword  5                               // DWARF version number
        .byte   8                               // Address size
        .byte   0                               // Segment selector size
.Laddr_table_base0:
        .xword  .Lfunc_begin0
.Ldebug_addr_end0:
        .ident  "clang version 21.1.0 (https://github.com/llvm/llvm-project.git 3623fe661ae35c6c80ac221f14d85be76aa870f1)"
        .section        ".note.GNU-stack","",@progbits
        .addrsig
        .section        .debug_line,"",@progbits
.Lline_table_start0: