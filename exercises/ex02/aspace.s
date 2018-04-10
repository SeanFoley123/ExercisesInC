	.file	"aspace.c"
	.comm	var1,4,4
	.section	.rodata
.LC0:
	.string	"Literal string"
.LC1:
	.string	"Address of main is %p\n"
.LC2:
	.string	"Address of var1 is %p\n"
.LC3:
	.string	"Address of var2 is %p\n"
.LC4:
	.string	"Address of var3 is %p\n"
.LC5:
	.string	"Address of var4 is %p\n"
.LC6:
	.string	"Address of p is %p\n"
.LC7:
	.string	"Address of q is %p\n"
.LC8:
	.string	"Address of s is %p\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$5, -44(%rbp)
	movl	$6, -40(%rbp)
	movl	$7, -36(%rbp)
	movl	$128, %edi
	call	malloc
	movq	%rax, -32(%rbp)
	movl	$128, %edi
	call	malloc
	movq	%rax, -24(%rbp)
	movq	$.LC0, -16(%rbp)
	movl	$main, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	$var1, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	leaq	-44(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	leaq	-40(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	leaq	-36(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	movq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC7, %edi
	movl	$0, %eax
	call	printf
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC8, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L3
	call	__stack_chk_fail
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
