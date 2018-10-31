	.file	"tco.cpp"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	_Z12sum_of_firsti
	.type	_Z12sum_of_firsti, @function
_Z12sum_of_firsti:
.LFB0:
	.cfi_startproc
	cmpl	$1, %edi
	je	.L4
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L3:
	addl	%edi, %eax
	subl	$1, %edi
	cmpl	$1, %edi
	jne	.L3
	addl	$1, %eax
	ret
.L4:
	movl	$1, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	_Z12sum_of_firsti, .-_Z12sum_of_firsti
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.section	.text.unlikely
.LCOLDB1:
	.section	.text.startup,"ax",@progbits
.LHOTB1:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	xorl	%edx, %edx
	movl	$65536, %eax
	.p2align 4,,10
	.p2align 3
.L8:
	addl	%eax, %edx
	subl	$1, %eax
	cmpl	$1, %eax
	jne	.L8
	leal	1(%rdx), %eax
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE1:
	.section	.text.startup
.LHOTE1:
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
