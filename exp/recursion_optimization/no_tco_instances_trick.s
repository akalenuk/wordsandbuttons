	.file	"no_tco_instances_trick.cpp"
	.section	.text.unlikely._Z12sum_of_firstILi2ELi4EEii,"axG",@progbits,_Z12sum_of_firstILi2ELi4EEii,comdat
.LCOLDB0:
	.section	.text._Z12sum_of_firstILi2ELi4EEii,"axG",@progbits,_Z12sum_of_firstILi2ELi4EEii,comdat
.LHOTB0:
	.p2align 4,,15
	.weak	_Z12sum_of_firstILi2ELi4EEii
	.type	_Z12sum_of_firstILi2ELi4EEii, @function
_Z12sum_of_firstILi2ELi4EEii:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movl	%edi, %ebp
	leal	-1(%rdi), %ebx
	leal	-2(%rdi), %edi
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	call	_Z12sum_of_firstILi2ELi4EEii
	addl	%ebx, %eax
	cmpl	$1, %ebx
	cmovne	%eax, %ebx
	movl	$1, %eax
	addl	%ebp, %ebx
	cmpl	$1, %ebp
	cmovne	%ebx, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE4:
	.size	_Z12sum_of_firstILi2ELi4EEii, .-_Z12sum_of_firstILi2ELi4EEii
	.section	.text.unlikely._Z12sum_of_firstILi2ELi4EEii,"axG",@progbits,_Z12sum_of_firstILi2ELi4EEii,comdat
.LCOLDE0:
	.section	.text._Z12sum_of_firstILi2ELi4EEii,"axG",@progbits,_Z12sum_of_firstILi2ELi4EEii,comdat
.LHOTE0:
	.section	.text.unlikely,"ax",@progbits
.LCOLDB1:
	.section	.text.startup,"ax",@progbits
.LHOTB1:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$4, %edi
	call	_Z12sum_of_firstILi2ELi4EEii
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	addl	$11, %eax
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
