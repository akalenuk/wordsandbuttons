	.file	"exp_static_a_b.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC6:
	.string	"%f, %f, %f, %f, %f\n"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB7:
	.section	.text.startup,"ax",@progbits
.LHOTB7:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB22:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$.LC6, %esi
	movl	$1, %edi
	movsd	.LC1(%rip), %xmm4
	movl	$5, %eax
	movsd	.LC2(%rip), %xmm3
	movsd	.LC3(%rip), %xmm2
	movsd	.LC4(%rip), %xmm1
	movsd	.LC5(%rip), %xmm0
	call	__printf_chk
	xorl	%eax, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE22:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE7:
	.section	.text.startup
.LHOTE7:
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	3174655768
	.long	1071782572
	.align 8
.LC2:
	.long	3230994035
	.long	1073030601
	.align 8
.LC3:
	.long	83248120
	.long	1071841626
	.align 8
.LC4:
	.long	232640199
	.long	-1075429521
	.align 8
.LC5:
	.long	87906252
	.long	-1075208333
	.ident	"GCC: (Ubuntu 5.4.1-2ubuntu1~16.04) 5.4.1 20160904"
	.section	.note.GNU-stack,"",@progbits
