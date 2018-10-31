	.file	"no_tco.cpp"
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
	testl	%edi, %edi
	jne	.L4
	xorl	%eax, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L4:
	jmp	_Z12sum_of_firsti.part.0
	.cfi_endproc
.LFE0:
	.size	_Z12sum_of_firsti, .-_Z12sum_of_firsti
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.section	.text.unlikely
.LCOLDB1:
	.text
.LHOTB1:
	.p2align 4,,15
	.type	_Z12sum_of_firsti.part.0, @function
_Z12sum_of_firsti.part.0:
.LFB2:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	%edi, %ebx
	leal	-1(%rdi), %edi
	call	_Z12sum_of_firsti
	movl	$1, %edx
	addl	%ebx, %eax
	cmpl	$1, %ebx
	cmove	%edx, %eax
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE2:
	.size	_Z12sum_of_firsti.part.0, .-_Z12sum_of_firsti.part.0
	.section	.text.unlikely
.LCOLDE1:
	.text
.LHOTE1:
	.section	.text.unlikely
.LCOLDB2:
	.section	.text.startup,"ax",@progbits
.LHOTB2:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$65535, %edi
	call	_Z12sum_of_firsti.part.0
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	addl	$65536, %eax
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE2:
	.section	.text.startup
.LHOTE2:
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
