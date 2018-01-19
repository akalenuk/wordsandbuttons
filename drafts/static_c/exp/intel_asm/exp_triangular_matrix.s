	.file	"exp_triangular_matrix.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC7:
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
.LCOLDB8:
	.section	.text.startup,"ax",@progbits
.LHOTB8:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB22:
	.cfi_startproc
	subq	$440, %rsp
	.cfi_def_cfa_offset 448
	movl	$.LC0, %esi
	movl	$25, %ecx
	movq	%fs:40, %rax
	movq	%rax, 424(%rsp)
	xorl	%eax, %eax
	leaq	224(%rsp), %rdi
	movsd	.LC1(%rip), %xmm3
	rep movsq
	movsd	%xmm3, 176(%rsp)
	movabsq	$4616212136052895252, %rax
	movl	$.LC7, %esi
	movsd	.LC2(%rip), %xmm3
	movl	$1, %edi
	pxor	%xmm9, %xmm9
	movsd	%xmm3, 184(%rsp)
	movsd	.LC3(%rip), %xmm3
	movsd	224(%rsp), %xmm7
	movsd	264(%rsp), %xmm5
	movsd	%xmm7, 24(%rsp)
	movsd	272(%rsp), %xmm7
	movsd	304(%rsp), %xmm4
	movsd	%xmm5, 32(%rsp)
	movsd	312(%rsp), %xmm8
	movsd	%xmm4, 40(%rsp)
	movsd	320(%rsp), %xmm6
	movsd	344(%rsp), %xmm0
	movsd	352(%rsp), %xmm1
	movsd	360(%rsp), %xmm13
	movsd	368(%rsp), %xmm4
	movsd	384(%rsp), %xmm5
	movsd	%xmm0, 48(%rsp)
	movsd	%xmm5, 8(%rsp)
	movsd	392(%rsp), %xmm5
	movsd	%xmm3, 192(%rsp)
	movapd	%xmm5, %xmm0
	movsd	400(%rsp), %xmm5
	movsd	.LC4(%rip), %xmm3
	movapd	%xmm5, %xmm15
	movsd	408(%rsp), %xmm5
	movsd	%xmm3, 200(%rsp)
	movapd	%xmm5, %xmm12
	movsd	416(%rsp), %xmm5
	movsd	.LC5(%rip), %xmm3
	movq	%rax, 128(%rsp)
	movabsq	$4618655338850743747, %rax
	movsd	%xmm12, 72(%rsp)
	movq	%rax, 136(%rsp)
	movabsq	$-4602554970182894223, %rax
	movsd	%xmm3, 208(%rsp)
	movq	%rax, 144(%rsp)
	movabsq	$-4603162956132589240, %rax
	mulsd	%xmm5, %xmm4
	movq	%rax, 152(%rsp)
	movapd	%xmm12, %xmm10
	movabsq	$-4609366664619292099, %rax
	movapd	%xmm5, %xmm12
	movq	%rax, 160(%rsp)
	mulsd	%xmm9, %xmm10
	movsd	%xmm15, 64(%rsp)
	movsd	128(%rsp), %xmm3
	movl	$5, %eax
	mulsd	%xmm9, %xmm12
	movsd	%xmm0, 56(%rsp)
	movsd	136(%rsp), %xmm11
	movsd	%xmm3, 80(%rsp)
	subsd	%xmm10, %xmm4
	mulsd	%xmm5, %xmm13
	movsd	144(%rsp), %xmm2
	movsd	152(%rsp), %xmm14
	movsd	160(%rsp), %xmm3
	mulsd	%xmm5, %xmm6
	movsd	%xmm3, 16(%rsp)
	movapd	%xmm12, %xmm3
	subsd	%xmm10, %xmm12
	movapd	%xmm15, %xmm10
	movapd	%xmm3, %xmm15
	mulsd	%xmm9, %xmm0
	mulsd	%xmm9, %xmm10
	mulsd	%xmm5, %xmm1
	mulsd	%xmm5, %xmm8
	mulsd	%xmm5, %xmm7
	subsd	%xmm0, %xmm3
	subsd	%xmm10, %xmm15
	mulsd	%xmm5, %xmm14
	subsd	%xmm10, %xmm13
	mulsd	%xmm5, %xmm2
	subsd	%xmm10, %xmm6
	subsd	%xmm0, %xmm1
	mulsd	%xmm4, %xmm3
	movapd	%xmm15, %xmm10
	movapd	%xmm11, %xmm15
	movsd	%xmm13, 96(%rsp)
	subsd	%xmm0, %xmm8
	mulsd	%xmm12, %xmm13
	mulsd	%xmm4, %xmm6
	subsd	%xmm0, %xmm7
	mulsd	%xmm4, %xmm10
	movsd	%xmm1, 88(%rsp)
	mulsd	%xmm5, %xmm15
	mulsd	%xmm12, %xmm1
	subsd	%xmm13, %xmm6
	mulsd	%xmm4, %xmm8
	subsd	%xmm13, %xmm10
	mulsd	%xmm4, %xmm7
	movsd	16(%rsp), %xmm13
	subsd	%xmm1, %xmm3
	movsd	80(%rsp), %xmm0
	mulsd	%xmm9, %xmm13
	subsd	%xmm1, %xmm8
	subsd	%xmm1, %xmm7
	movapd	%xmm15, %xmm1
	mulsd	%xmm5, %xmm0
	mulsd	%xmm6, %xmm3
	subsd	%xmm13, %xmm14
	movsd	%xmm8, 104(%rsp)
	mulsd	%xmm10, %xmm8
	subsd	%xmm13, %xmm2
	mulsd	%xmm6, %xmm7
	subsd	%xmm13, %xmm1
	mulsd	8(%rsp), %xmm9
	subsd	%xmm13, %xmm0
	movsd	48(%rsp), %xmm11
	movsd	%xmm14, 112(%rsp)
	mulsd	%xmm12, %xmm14
	subsd	%xmm8, %xmm3
	mulsd	%xmm4, %xmm2
	subsd	%xmm8, %xmm7
	mulsd	%xmm4, %xmm1
	mulsd	%xmm4, %xmm0
	movsd	40(%rsp), %xmm8
	subsd	%xmm14, %xmm2
	mulsd	%xmm5, %xmm11
	subsd	%xmm14, %xmm1
	mulsd	%xmm5, %xmm8
	subsd	%xmm14, %xmm0
	movsd	24(%rsp), %xmm14
	movsd	%xmm2, 120(%rsp)
	mulsd	%xmm10, %xmm2
	subsd	%xmm9, %xmm11
	mulsd	%xmm6, %xmm1
	subsd	%xmm9, %xmm8
	mulsd	%xmm5, %xmm14
	mulsd	%xmm6, %xmm0
	movapd	%xmm2, %xmm15
	mulsd	%xmm11, %xmm12
	subsd	%xmm2, %xmm1
	movsd	32(%rsp), %xmm2
	movapd	%xmm14, %xmm13
	mulsd	%xmm4, %xmm8
	mulsd	%xmm5, %xmm2
	subsd	%xmm15, %xmm0
	subsd	%xmm9, %xmm13
	movapd	%xmm3, %xmm15
	subsd	%xmm12, %xmm8
	mulsd	%xmm1, %xmm15
	subsd	%xmm9, %xmm2
	mulsd	%xmm7, %xmm0
	mulsd	%xmm4, %xmm13
	mulsd	%xmm8, %xmm10
	mulsd	%xmm4, %xmm2
	subsd	%xmm15, %xmm0
	subsd	%xmm12, %xmm13
	subsd	%xmm12, %xmm2
	mulsd	%xmm6, %xmm13
	mulsd	%xmm6, %xmm2
	subsd	%xmm10, %xmm13
	subsd	%xmm10, %xmm2
	mulsd	%xmm7, %xmm13
	mulsd	%xmm2, %xmm3
	subsd	%xmm3, %xmm13
	movsd	104(%rsp), %xmm3
	divsd	%xmm13, %xmm0
	mulsd	%xmm0, %xmm2
	mulsd	%xmm0, %xmm8
	mulsd	%xmm0, %xmm11
	subsd	%xmm2, %xmm1
	movsd	120(%rsp), %xmm2
	subsd	%xmm8, %xmm2
	divsd	%xmm7, %xmm1
	mulsd	%xmm1, %xmm3
	subsd	%xmm3, %xmm2
	movsd	112(%rsp), %xmm3
	subsd	%xmm11, %xmm3
	divsd	%xmm6, %xmm2
	movsd	88(%rsp), %xmm6
	movsd	16(%rsp), %xmm13
	mulsd	%xmm1, %xmm6
	subsd	%xmm6, %xmm3
	movsd	96(%rsp), %xmm6
	mulsd	%xmm2, %xmm6
	subsd	%xmm6, %xmm3
	movsd	56(%rsp), %xmm6
	mulsd	%xmm1, %xmm6
	divsd	%xmm4, %xmm3
	movsd	8(%rsp), %xmm4
	mulsd	%xmm0, %xmm4
	subsd	%xmm4, %xmm13
	movapd	%xmm13, %xmm4
	subsd	%xmm6, %xmm4
	movsd	64(%rsp), %xmm6
	mulsd	%xmm2, %xmm6
	subsd	%xmm6, %xmm4
	movsd	72(%rsp), %xmm6
	mulsd	%xmm3, %xmm6
	subsd	%xmm6, %xmm4
	divsd	%xmm5, %xmm4
	call	__printf_chk
	movq	424(%rsp), %rdx
	xorq	%fs:40, %rdx
	jne	.L5
	xorl	%eax, %eax
	addq	$440, %rsp
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
.LCOLDE8:
	.section	.text.startup
.LHOTE8:
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	3779571220
	.long	1074795642
	.align 8
.LC2:
	.long	1546188227
	.long	1075364495
	.align 8
.LC3:
	.long	3607772529
	.long	-1071615837
	.align 8
.LC4:
	.long	343597384
	.long	-1071757394
	.align 8
.LC5:
	.long	2748779069
	.long	-1073201808
	.ident	"GCC: (Ubuntu 5.4.1-2ubuntu1~16.04) 5.4.1 20160904"
	.section	.note.GNU-stack,"",@progbits
