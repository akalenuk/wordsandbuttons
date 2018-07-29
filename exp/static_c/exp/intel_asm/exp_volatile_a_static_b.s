	.file	"exp_volatile_a_static_b.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC6:
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
	subq	$328, %rsp
	.cfi_def_cfa_offset 336
	movl	$.LC0, %esi
	movl	$25, %ecx
	movq	%fs:40, %rax
	movq	%rax, 312(%rsp)
	xorl	%eax, %eax
	leaq	112(%rsp), %rdi
	movl	$5, %eax
	rep movsq
	movl	$.LC6, %esi
	movl	$1, %edi
	movsd	112(%rsp), %xmm7
	movsd	120(%rsp), %xmm5
	movsd	%xmm7, 72(%rsp)
	movsd	128(%rsp), %xmm15
	movsd	136(%rsp), %xmm10
	movsd	144(%rsp), %xmm7
	movsd	152(%rsp), %xmm4
	movsd	%xmm7, 48(%rsp)
	movsd	160(%rsp), %xmm1
	movsd	168(%rsp), %xmm9
	movsd	176(%rsp), %xmm11
	movsd	184(%rsp), %xmm13
	movsd	192(%rsp), %xmm0
	movsd	200(%rsp), %xmm2
	movsd	208(%rsp), %xmm7
	movsd	216(%rsp), %xmm12
	movsd	224(%rsp), %xmm14
	movsd	232(%rsp), %xmm3
	movsd	%xmm5, 80(%rsp)
	movsd	240(%rsp), %xmm6
	movsd	%xmm4, 88(%rsp)
	movsd	%xmm0, 96(%rsp)
	movsd	%xmm3, 104(%rsp)
	movsd	248(%rsp), %xmm3
	movsd	256(%rsp), %xmm4
	movsd	264(%rsp), %xmm0
	movsd	272(%rsp), %xmm5
	movsd	%xmm5, 8(%rsp)
	movsd	280(%rsp), %xmm5
	movsd	%xmm5, (%rsp)
	movsd	288(%rsp), %xmm5
	movsd	296(%rsp), %xmm8
	movsd	%xmm5, 16(%rsp)
	movsd	304(%rsp), %xmm5
	movsd	%xmm8, 24(%rsp)
	mulsd	%xmm0, %xmm8
	mulsd	%xmm5, %xmm4
	mulsd	%xmm5, %xmm11
	mulsd	%xmm5, %xmm6
	mulsd	%xmm5, %xmm12
	subsd	%xmm8, %xmm4
	movsd	24(%rsp), %xmm8
	mulsd	%xmm5, %xmm3
	mulsd	%xmm13, %xmm8
	mulsd	%xmm5, %xmm7
	mulsd	%xmm5, %xmm9
	mulsd	%xmm5, %xmm2
	subsd	%xmm8, %xmm11
	movsd	(%rsp), %xmm8
	mulsd	%xmm5, %xmm1
	mulsd	%xmm0, %xmm8
	mulsd	%xmm5, %xmm10
	mulsd	%xmm5, %xmm15
	subsd	%xmm8, %xmm6
	movsd	16(%rsp), %xmm8
	movsd	%xmm6, 32(%rsp)
	movsd	24(%rsp), %xmm6
	mulsd	%xmm14, %xmm6
	subsd	%xmm6, %xmm12
	movapd	%xmm8, %xmm6
	mulsd	%xmm0, %xmm6
	subsd	%xmm6, %xmm3
	movapd	%xmm8, %xmm6
	movsd	%xmm3, 40(%rsp)
	movapd	%xmm8, %xmm3
	mulsd	%xmm14, %xmm3
	movsd	40(%rsp), %xmm8
	subsd	%xmm3, %xmm7
	movapd	%xmm8, %xmm3
	mulsd	%xmm12, %xmm3
	mulsd	%xmm4, %xmm7
	subsd	%xmm3, %xmm7
	movapd	%xmm6, %xmm3
	mulsd	%xmm13, %xmm3
	subsd	%xmm3, %xmm9
	movapd	%xmm8, %xmm3
	movsd	(%rsp), %xmm8
	mulsd	%xmm11, %xmm3
	movapd	%xmm8, %xmm6
	mulsd	%xmm4, %xmm9
	mulsd	%xmm13, %xmm6
	subsd	%xmm3, %xmm9
	movapd	%xmm8, %xmm3
	subsd	%xmm6, %xmm1
	movapd	%xmm15, %xmm8
	mulsd	%xmm14, %xmm3
	mulsd	%xmm4, %xmm1
	subsd	%xmm3, %xmm2
	movsd	32(%rsp), %xmm3
	mulsd	%xmm12, %xmm3
	mulsd	%xmm4, %xmm2
	subsd	%xmm3, %xmm2
	movapd	%xmm2, %xmm3
	movsd	32(%rsp), %xmm2
	movsd	%xmm3, 56(%rsp)
	mulsd	%xmm11, %xmm2
	subsd	%xmm2, %xmm1
	movapd	%xmm3, %xmm2
	mulsd	%xmm9, %xmm2
	mulsd	%xmm7, %xmm1
	subsd	%xmm2, %xmm1
	movsd	48(%rsp), %xmm2
	movapd	%xmm2, %xmm15
	movsd	%xmm1, 64(%rsp)
	movsd	24(%rsp), %xmm1
	mulsd	%xmm2, %xmm1
	subsd	%xmm1, %xmm10
	movsd	.LC1(%rip), %xmm1
	mulsd	%xmm5, %xmm1
	movapd	%xmm1, %xmm3
	movsd	.LC2(%rip), %xmm1
	mulsd	%xmm0, %xmm1
	subsd	%xmm1, %xmm3
	movsd	16(%rsp), %xmm1
	mulsd	%xmm2, %xmm1
	movsd	.LC3(%rip), %xmm2
	mulsd	%xmm5, %xmm2
	subsd	%xmm1, %xmm8
	movsd	40(%rsp), %xmm1
	mulsd	%xmm10, %xmm1
	mulsd	%xmm4, %xmm8
	subsd	%xmm1, %xmm8
	movsd	.LC2(%rip), %xmm1
	mulsd	%xmm14, %xmm1
	subsd	%xmm1, %xmm2
	movapd	%xmm12, %xmm1
	mulsd	%xmm3, %xmm1
	mulsd	%xmm4, %xmm2
	subsd	%xmm1, %xmm2
	movsd	80(%rsp), %xmm1
	mulsd	%xmm5, %xmm1
	movapd	%xmm1, %xmm6
	movsd	(%rsp), %xmm1
	mulsd	%xmm15, %xmm1
	movsd	56(%rsp), %xmm15
	mulsd	%xmm8, %xmm15
	subsd	%xmm1, %xmm6
	movsd	32(%rsp), %xmm1
	mulsd	%xmm10, %xmm1
	mulsd	%xmm4, %xmm6
	subsd	%xmm1, %xmm6
	mulsd	%xmm7, %xmm6
	subsd	%xmm15, %xmm6
	movsd	.LC4(%rip), %xmm15
	mulsd	%xmm5, %xmm15
	movapd	%xmm15, %xmm1
	movsd	.LC2(%rip), %xmm15
	mulsd	8(%rsp), %xmm0
	mulsd	%xmm13, %xmm15
	mulsd	8(%rsp), %xmm14
	mulsd	8(%rsp), %xmm13
	subsd	%xmm15, %xmm1
	movapd	%xmm11, %xmm15
	mulsd	%xmm3, %xmm15
	mulsd	%xmm4, %xmm1
	subsd	%xmm15, %xmm1
	movapd	%xmm9, %xmm15
	mulsd	%xmm2, %xmm15
	mulsd	%xmm7, %xmm1
	subsd	%xmm15, %xmm1
	movsd	104(%rsp), %xmm15
	mulsd	%xmm5, %xmm15
	subsd	%xmm0, %xmm15
	movsd	96(%rsp), %xmm0
	mulsd	%xmm5, %xmm0
	mulsd	%xmm15, %xmm12
	mulsd	%xmm15, %xmm11
	subsd	%xmm14, %xmm0
	movapd	%xmm0, %xmm14
	movsd	.LC5(%rip), %xmm0
	mulsd	%xmm4, %xmm14
	mulsd	%xmm5, %xmm0
	subsd	%xmm12, %xmm14
	movsd	88(%rsp), %xmm12
	mulsd	%xmm5, %xmm12
	mulsd	%xmm14, %xmm9
	subsd	%xmm13, %xmm12
	movsd	48(%rsp), %xmm13
	mulsd	%xmm4, %xmm12
	subsd	%xmm11, %xmm12
	movapd	%xmm13, %xmm11
	mulsd	%xmm7, %xmm12
	subsd	%xmm9, %xmm12
	movsd	.LC2(%rip), %xmm9
	mulsd	%xmm13, %xmm9
	movsd	8(%rsp), %xmm13
	mulsd	%xmm13, %xmm11
	subsd	%xmm9, %xmm0
	movapd	%xmm10, %xmm9
	mulsd	%xmm15, %xmm10
	mulsd	%xmm3, %xmm9
	mulsd	%xmm4, %xmm0
	subsd	%xmm9, %xmm0
	movapd	%xmm8, %xmm9
	mulsd	%xmm14, %xmm8
	mulsd	%xmm2, %xmm9
	mulsd	%xmm7, %xmm0
	subsd	%xmm9, %xmm0
	movapd	%xmm6, %xmm9
	mulsd	%xmm12, %xmm6
	mulsd	%xmm1, %xmm9
	mulsd	64(%rsp), %xmm0
	subsd	%xmm9, %xmm0
	movsd	72(%rsp), %xmm9
	mulsd	%xmm5, %xmm9
	subsd	%xmm11, %xmm9
	movsd	64(%rsp), %xmm11
	mulsd	%xmm4, %xmm9
	subsd	%xmm10, %xmm9
	movsd	56(%rsp), %xmm10
	mulsd	%xmm7, %xmm9
	subsd	%xmm8, %xmm9
	mulsd	%xmm11, %xmm9
	subsd	%xmm6, %xmm9
	movsd	(%rsp), %xmm6
	divsd	%xmm9, %xmm0
	mulsd	%xmm0, %xmm12
	mulsd	%xmm0, %xmm14
	mulsd	%xmm0, %xmm15
	subsd	%xmm12, %xmm1
	subsd	%xmm14, %xmm2
	subsd	%xmm15, %xmm3
	divsd	%xmm11, %xmm1
	mulsd	%xmm1, %xmm10
	mulsd	%xmm1, %xmm6
	subsd	%xmm10, %xmm2
	divsd	%xmm7, %xmm2
	movsd	32(%rsp), %xmm7
	mulsd	%xmm1, %xmm7
	subsd	%xmm7, %xmm3
	movsd	40(%rsp), %xmm7
	mulsd	%xmm2, %xmm7
	subsd	%xmm7, %xmm3
	movsd	.LC2(%rip), %xmm7
	divsd	%xmm4, %xmm3
	movapd	%xmm13, %xmm4
	mulsd	%xmm0, %xmm4
	subsd	%xmm4, %xmm7
	movapd	%xmm7, %xmm4
	subsd	%xmm6, %xmm4
	movsd	16(%rsp), %xmm6
	mulsd	%xmm2, %xmm6
	subsd	%xmm6, %xmm4
	movsd	24(%rsp), %xmm6
	mulsd	%xmm3, %xmm6
	subsd	%xmm6, %xmm4
	divsd	%xmm5, %xmm4
	call	__printf_chk
	movq	312(%rsp), %rdx
	xorq	%fs:40, %rdx
	jne	.L5
	xorl	%eax, %eax
	addq	$328, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L5:
	.cfi_restore_state
	call	__stack_chk_fail
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
	.long	343597384
	.long	-1071757394
	.align 8
.LC2:
	.long	2748779069
	.long	-1073201808
	.align 8
.LC3:
	.long	3607772529
	.long	-1071615837
	.align 8
.LC4:
	.long	1546188227
	.long	1075364495
	.align 8
.LC5:
	.long	3779571220
	.long	1074795642
	.ident	"GCC: (Ubuntu 5.4.1-2ubuntu1~16.04) 5.4.1 20160904"
	.section	.note.GNU-stack,"",@progbits
