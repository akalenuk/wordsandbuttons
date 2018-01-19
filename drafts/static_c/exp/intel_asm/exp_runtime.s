	.file	"exp_runtime.c"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB1:
	.text
.LHOTB1:
	.p2align 4,,15
	.globl	aijn
	.type	aijn, @function
aijn:
.LFB12:
	.cfi_startproc
	cmpl	%r9d, %r8d
	je	.L5
	jmp	aijn.part.0
	.p2align 4,,10
	.p2align 3
.L5:
	imull	%edx, %r8d
	addl	%r8d, %ecx
	movslq	%ecx, %rcx
	movsd	(%rdi,%rcx,8), %xmm0
	ret
	.cfi_endproc
.LFE12:
	.size	aijn, .-aijn
	.section	.text.unlikely
.LCOLDE1:
	.text
.LHOTE1:
	.section	.text.unlikely
.LCOLDB2:
	.text
.LHOTB2:
	.p2align 4,,15
	.type	aijn.part.0, @function
aijn.part.0:
.LFB17:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movl	%r9d, %r14d
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	leal	1(%r8), %r13d
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rdi, %rbp
	movl	%r8d, %ebx
	movq	%rsi, %r12
	movl	%r13d, %r8d
	subq	$40, %rsp
	.cfi_def_cfa_offset 96
	movl	%ecx, %r15d
	movl	%edx, 28(%rsp)
	call	aijn
	movl	%r14d, %r9d
	movl	%r13d, %r8d
	movl	%ebx, %ecx
	movl	%ebx, %edx
	movq	%r12, %rsi
	movq	%rbp, %rdi
	movsd	%xmm0, 8(%rsp)
	call	aijn
	movsd	8(%rsp), %xmm1
	movl	%r14d, %r9d
	movl	28(%rsp), %eax
	movl	%r13d, %r8d
	movl	%ebx, %ecx
	mulsd	%xmm0, %xmm1
	movq	%r12, %rsi
	movq	%rbp, %rdi
	movl	%eax, %edx
	movsd	%xmm1, 16(%rsp)
	call	aijn
	movl	%r14d, %r9d
	movl	%r13d, %r8d
	movl	%r15d, %ecx
	movl	%ebx, %edx
	movq	%r12, %rsi
	movq	%rbp, %rdi
	movsd	%xmm0, 8(%rsp)
	call	aijn
	mulsd	8(%rsp), %xmm0
	movsd	16(%rsp), %xmm1
	addq	$40, %rsp
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	subsd	%xmm0, %xmm1
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	movapd	%xmm1, %xmm0
	ret
	.cfi_endproc
.LFE17:
	.size	aijn.part.0, .-aijn.part.0
	.section	.text.unlikely
.LCOLDE2:
	.text
.LHOTE2:
	.section	.text.unlikely
.LCOLDB3:
	.text
.LHOTB3:
	.p2align 4,,15
	.globl	bin
	.type	bin, @function
bin:
.LFB13:
	.cfi_startproc
	cmpl	%r8d, %ecx
	je	.L15
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	leal	1(%rcx), %r15d
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	movq	%rsi, %r14
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movl	%ecx, %ebp
	movl	%r8d, %ebx
	movl	%edx, %r12d
	movq	%rdi, %r13
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	cmpl	%r15d, %r8d
	je	.L16
	movl	%r8d, %r9d
	movl	%ecx, %edx
	movl	%r15d, %r8d
	call	aijn.part.0
	movl	%ebx, %r8d
	movl	%r15d, %ecx
	movl	%r12d, %edx
	movq	%r14, %rsi
	movq	%r13, %rdi
	movsd	%xmm0, (%rsp)
	call	bin
	movsd	(%rsp), %xmm3
	movl	%ebx, %r9d
	movl	%r15d, %r8d
	movl	%ebp, %ecx
	movl	%r12d, %edx
	mulsd	%xmm0, %xmm3
	movq	%r14, %rsi
	movq	%r13, %rdi
	movsd	%xmm3, 8(%rsp)
	call	aijn.part.0
	movsd	%xmm0, (%rsp)
.L13:
	movl	%ebx, %r8d
	movl	%r15d, %ecx
	movl	%ebp, %edx
	movq	%r14, %rsi
	movq	%r13, %rdi
	call	bin
	mulsd	(%rsp), %xmm0
	movsd	8(%rsp), %xmm1
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_restore 3
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_restore 12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_restore 13
	.cfi_def_cfa_offset 24
	subsd	%xmm0, %xmm1
	popq	%r14
	.cfi_restore 14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_restore 15
	.cfi_def_cfa_offset 8
	movapd	%xmm1, %xmm0
	ret
	.p2align 4,,10
	.p2align 3
.L16:
	.cfi_restore_state
	movl	%r8d, %ecx
	call	bin
	movl	%ebp, %eax
	imull	%ebx, %eax
	imull	%ebx, %r12d
	addl	%ebp, %eax
	cltq
	addl	%ebp, %r12d
	mulsd	0(%r13,%rax,8), %xmm0
	movslq	%r12d, %r12
	movsd	0(%r13,%r12,8), %xmm5
	movsd	%xmm5, (%rsp)
	movsd	%xmm0, 8(%rsp)
	jmp	.L13
	.p2align 4,,10
	.p2align 3
.L15:
	.cfi_def_cfa_offset 8
	.cfi_restore 3
	.cfi_restore 6
	.cfi_restore 12
	.cfi_restore 13
	.cfi_restore 14
	.cfi_restore 15
	movslq	%edx, %rdx
	movsd	(%rsi,%rdx,8), %xmm0
	ret
	.cfi_endproc
.LFE13:
	.size	bin, .-bin
	.section	.text.unlikely
.LCOLDE3:
	.text
.LHOTE3:
	.section	.text.unlikely
.LCOLDB4:
	.text
.LHOTB4:
	.p2align 4,,15
	.globl	solve_xi
	.type	solve_xi, @function
solve_xi:
.LFB14:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	leal	1(%rcx), %r15d
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	movq	%rdx, %r13
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movl	%ecx, %ebx
	movl	%ebx, %edx
	movl	%r15d, %ecx
	movq	%rdi, %rbp
	subq	$40, %rsp
	.cfi_def_cfa_offset 96
	movl	%r8d, %r14d
	movq	%rsi, 16(%rsp)
	call	bin
	testl	%ebx, %ebx
	movapd	%xmm0, %xmm1
	jle	.L18
	movl	%r15d, %eax
	leal	-1(%rbx), %r12d
	imull	%ebx, %eax
	movl	%eax, 28(%rsp)
	leaq	1(%r12), %rax
	xorl	%r12d, %r12d
	movq	%rax, (%rsp)
	jmp	.L21
	.p2align 4,,10
	.p2align 3
.L26:
	movl	28(%rsp), %eax
	leal	(%rax,%r12), %edx
	movslq	%edx, %rdx
	movsd	0(%rbp,%rdx,8), %xmm0
.L20:
	mulsd	0(%r13,%r12,8), %xmm0
	addq	$1, %r12
	cmpq	(%rsp), %r12
	subsd	%xmm0, %xmm1
	je	.L18
.L21:
	cmpl	%r14d, %r15d
	je	.L26
	movq	16(%rsp), %rsi
	movl	%r14d, %r9d
	movl	%r15d, %r8d
	movl	%r12d, %ecx
	movl	%ebx, %edx
	movq	%rbp, %rdi
	movsd	%xmm1, 8(%rsp)
	call	aijn.part.0
	movsd	8(%rsp), %xmm1
	jmp	.L20
	.p2align 4,,10
	.p2align 3
.L18:
	movslq	%ebx, %rax
	cmpl	%r14d, %r15d
	leaq	0(%r13,%rax,8), %r12
	je	.L27
	movq	16(%rsp), %rsi
	movl	%r14d, %r9d
	movl	%r15d, %r8d
	movl	%ebx, %ecx
	movl	%ebx, %edx
	movq	%rbp, %rdi
	movsd	%xmm1, (%rsp)
	call	aijn.part.0
	movsd	(%rsp), %xmm1
.L23:
	divsd	%xmm0, %xmm1
	movsd	%xmm1, (%r12)
	addq	$40, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L27:
	.cfi_restore_state
	movl	%r15d, %r10d
	imull	%ebx, %r10d
	addl	%r10d, %ebx
	movslq	%ebx, %rbx
	movsd	0(%rbp,%rbx,8), %xmm0
	jmp	.L23
	.cfi_endproc
.LFE14:
	.size	solve_xi, .-solve_xi
	.section	.text.unlikely
.LCOLDE4:
	.text
.LHOTE4:
	.section	.text.unlikely
.LCOLDB5:
	.text
.LHOTB5:
	.p2align 4,,15
	.globl	runtime_solve
	.type	runtime_solve, @function
runtime_solve:
.LFB15:
	.cfi_startproc
	testl	%ecx, %ecx
	jle	.L36
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	movq	%rdi, %r14
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	movq	%rsi, %r13
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	movq	%rdx, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	movl	%ecx, %ebp
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	xorl	%ebx, %ebx
	.p2align 4,,10
	.p2align 3
.L32:
	movl	%ebx, %ecx
	movl	%ebp, %r8d
	movq	%r12, %rdx
	movq	%r13, %rsi
	movq	%r14, %rdi
	addl	$1, %ebx
	call	solve_xi
	cmpl	%ebx, %ebp
	jne	.L32
	popq	%rbx
	.cfi_restore 3
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_restore 12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_restore 13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_restore 14
	.cfi_def_cfa_offset 8
.L36:
	rep ret
	.cfi_endproc
.LFE15:
	.size	runtime_solve, .-runtime_solve
	.section	.text.unlikely
.LCOLDE5:
	.text
.LHOTE5:
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC11:
	.string	"%f, %f, %f, %f, %f\n"
	.section	.rodata
	.align 32
.LC0:
	.long	858993459
	.long	1075524403
	.long	858993459
	.long	-1072155853
	.long	3435973837
	.long	-1076048692
	.long	171798692
	.long	1075880919
	.long	1030792151
	.long	-1071425782
	.long	2920577761
	.long	-1073684153
	.long	1717986918
	.long	-1073060250
	.long	171798692
	.long	1074045911
	.long	2061584302
	.long	1074114068
	.long	687194767
	.long	-1072394404
	.long	171798692
	.long	1075225559
	.long	3607772529
	.long	1075146915
	.long	2576980378
	.long	-1073374823
	.long	1717986918
	.long	1074882150
	.long	1889785610
	.long	-1071838659
	.long	2920577761
	.long	1075306823
	.long	1546188227
	.long	-1072577905
	.long	343597384
	.long	1070679982
	.long	2061584302
	.long	-1071862252
	.long	2233382994
	.long	1075335659
	.long	2405181686
	.long	1075869122
	.long	343597384
	.long	1072777134
	.long	3779571220
	.long	1075975290
	.long	1374389535
	.long	1073815224
	.long	1202590843
	.long	-1071940895
	.section	.text.unlikely
.LCOLDB12:
	.section	.text.startup,"ax",@progbits
.LHOTB12:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB16:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movl	$.LC0, %esi
	movl	$25, %ecx
	xorl	%ebx, %ebx
	subq	$312, %rsp
	.cfi_def_cfa_offset 336
	leaq	96(%rsp), %rbp
	movsd	.LC6(%rip), %xmm5
	movsd	.LC7(%rip), %xmm6
	movq	%rbp, %rdi
	movsd	.LC8(%rip), %xmm7
	rep movsq
	movsd	.LC9(%rip), %xmm0
	movsd	.LC10(%rip), %xmm1
	movq	%fs:40, %rax
	movq	%rax, 296(%rsp)
	xorl	%eax, %eax
	movsd	%xmm5, (%rsp)
	movsd	%xmm6, 8(%rsp)
	movsd	%xmm7, 16(%rsp)
	movsd	%xmm0, 24(%rsp)
	movsd	%xmm1, 32(%rsp)
.L38:
	leaq	48(%rsp), %rdx
	movl	%ebx, %ecx
	movl	$5, %r8d
	movq	%rsp, %rsi
	movq	%rbp, %rdi
	addl	$1, %ebx
	call	solve_xi
	cmpl	$5, %ebx
	jne	.L38
	movsd	80(%rsp), %xmm4
	movl	$.LC11, %esi
	movl	$1, %edi
	movsd	72(%rsp), %xmm3
	movl	$5, %eax
	movsd	64(%rsp), %xmm2
	movsd	56(%rsp), %xmm1
	movsd	48(%rsp), %xmm0
	call	__printf_chk
	xorl	%eax, %eax
	movq	296(%rsp), %rcx
	xorq	%fs:40, %rcx
	jne	.L42
	addq	$312, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L42:
	.cfi_restore_state
	call	__stack_chk_fail
	.cfi_endproc
.LFE16:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE12:
	.section	.text.startup
.LHOTE12:
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC6:
	.long	3779571220
	.long	1074795642
	.align 8
.LC7:
	.long	1546188227
	.long	1075364495
	.align 8
.LC8:
	.long	3607772529
	.long	-1071615837
	.align 8
.LC9:
	.long	343597384
	.long	-1071757394
	.align 8
.LC10:
	.long	2748779069
	.long	-1073201808
	.ident	"GCC: (Ubuntu 5.4.1-2ubuntu1~16.04) 5.4.1 20160904"
	.section	.note.GNU-stack,"",@progbits
