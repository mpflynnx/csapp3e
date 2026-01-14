	.file	"main.c"
	.text
	.globl	movq_demo
	.type	movq_demo, @function
movq_demo:
.LFB0:
	.cfi_startproc
	movq	$22136, global_val(%rip)
	movq	%rdi, global_val(%rip)
	movq	global_val(%rip), %rax
	ret
	.cfi_endproc
.LFE0:
	.size	movq_demo, .-movq_demo
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	movl	$10, %edi
	call	movq_demo
	movl	$0, %eax
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
