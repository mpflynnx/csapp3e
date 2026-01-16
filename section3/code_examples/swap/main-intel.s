	.file	"main.c"
	.intel_syntax noprefix
	.text
	.globl	swap
	.type	swap, @function
swap:
.LFB0:
	.cfi_startproc
	mov	rax, QWORD PTR [rdi]
	mov	rdx, QWORD PTR [rsi]
	mov	QWORD PTR [rdi], rdx
	mov	QWORD PTR [rsi], rax
	ret
	.cfi_endproc
.LFE0:
	.size	swap, .-swap
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	sub	rsp, 16
	.cfi_def_cfa_offset 24
	mov	QWORD PTR [rsp+8], 1956327194
	mov	QWORD PTR [rsp], 1389431268
	mov	rsi, rsp
	lea	rdi, [rsp+8]
	call	swap
	mov	eax, 0
	add	rsp, 16
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.2.0"
	.section	.note.GNU-stack,"",@progbits
