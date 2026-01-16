	.file	"main.c"
	.text
	.globl	swap
	.type	swap, @function
swap:
.LFB0:
	.cfi_startproc
	movq	(%rdi), %rax
	movq	(%rsi), %rdx
	movq	%rdx, (%rdi)
	movq	%rax, (%rsi)
	ret
	.cfi_endproc
.LFE0:
	.size	swap, .-swap
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	subq	$16, %rsp
	.cfi_def_cfa_offset 24
	movq	$1956327194, 8(%rsp)
	movq	$1389431268, (%rsp)
	movq	%rsp, %rsi
	leaq	8(%rsp), %rdi
	call	swap
	movl	$0, %eax
	addq	$16, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.2.0"
	.section	.note.GNU-stack,"",@progbits
