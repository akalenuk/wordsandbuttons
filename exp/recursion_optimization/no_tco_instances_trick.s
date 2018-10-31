	.file	"no_tco_instances_trick.cpp"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.type	_Z12sum_of_firstILi0ELi4EEii.part.2, @function
_Z12sum_of_firstILi0ELi4EEii.part.2:
.LFB8:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movl	%edi, %ebx
	movl	%edi, %ebp
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	subl	$1, %ebx
	jne	.L28
.L2:
	addl	%ebp, %ebx
	movl	$1, %eax
	cmpl	$1, %ebp
	cmovne	%ebx, %eax
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L28:
	.cfi_restore_state
	movl	%edi, %r12d
	subl	$2, %r12d
	jne	.L29
.L3:
	addl	%ebx, %r12d
	cmpl	$1, %ebx
	cmovne	%r12d, %ebx
	jmp	.L2
	.p2align 4,,10
	.p2align 3
.L29:
	movl	%edi, %r13d
	subl	$3, %r13d
	jne	.L30
.L4:
	addl	%r12d, %r13d
	cmpl	$1, %r12d
	cmovne	%r13d, %r12d
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L30:
	movl	%edi, %eax
	subl	$4, %eax
	je	.L5
	movl	%eax, %edi
	call	_Z12sum_of_firstILi0ELi4EEii.part.2
.L5:
	addl	%r13d, %eax
	cmpl	$1, %r13d
	cmovne	%eax, %r13d
	jmp	.L4
	.cfi_endproc
.LFE8:
	.size	_Z12sum_of_firstILi0ELi4EEii.part.2, .-_Z12sum_of_firstILi0ELi4EEii.part.2
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
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$65532, %edi
	call	_Z12sum_of_firstILi0ELi4EEii.part.2
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	addl	$262138, %eax
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
