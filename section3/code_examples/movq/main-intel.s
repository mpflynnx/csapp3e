	.file	"main.c"
	.intel_syntax noprefix
	.text
	.globl	movq_demo
	.type	movq_demo, @function
movq_demo:
.LFB0:
	.cfi_startproc
	mov	QWORD PTR global_val[rip], 22136
	mov	QWORD PTR global_val[rip], rdi
	mov	rax, QWORD PTR global_val[rip]
	ret
	.cfi_endproc
.LFE0:
	.size	movq_demo, .-movq_demo
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	mov	edi, 10
	call	movq_demo
	mov	eax, 0
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.globl	global_val
	.data
	.align 8
	.type	global_val, @object
	.size	global_val, 8
global_val:
	.quad	100
	.ident	"GCC: (GNU) 11.2.0"
	.section	.note.GNU-stack,"",@progbits
