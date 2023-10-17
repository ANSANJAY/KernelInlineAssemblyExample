	.file	"userprog.c"
	.text
	.globl	inc
	.type	inc, @function
inc:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	counter.1795(%rip), %eax
	addl	$1, %eax
	movl	%eax, counter.1795(%rip)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	inc, .-inc
	.local	counter.1795
	.comm	counter.1795,4,4
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
