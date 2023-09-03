	.section	.rodata
.LC0:
	.string "hello, world\n"
	.text
	.globl	main
	.type	main, @function
main:
	.cfi_startproc
	movq	$1, %rax
	movq	$1, %rdi
	leaq	.LC0(%rip), %rsi
	movq	$13, %rdx
	syscall

	movq	$60, %rax
	movq	$0, %rdi
	syscall
	.cfi_endproc
