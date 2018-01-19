	.file	"exp_volatile_a_b.c"
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
	subq	$472, %rsp
	.cfi_def_cfa_offset 480
	movl	$.LC0, %esi
	movl	$25, %ecx
	movq	%fs:40, %rax
	movq	%rax, 456(%rsp)
	xorl	%eax, %eax
	leaq	256(%rsp), %rdi
	movabsq	$4616212136052895252, %rax
	rep movsq
	movl	$.LC6, %esi
	movl	$1, %edi
	movsd	256(%rsp), %xmm3
	movsd	264(%rsp), %xmm5
	movsd	272(%rsp), %xmm7
	movsd	280(%rsp), %xmm4
	movsd	%xmm7, 104(%rsp)
	movsd	288(%rsp), %xmm7
	movsd	296(%rsp), %xmm0
	movsd	%xmm7, 32(%rsp)
	movsd	304(%rsp), %xmm10
	movsd	312(%rsp), %xmm9
	movsd	320(%rsp), %xmm11
	movsd	328(%rsp), %xmm13
	movsd	336(%rsp), %xmm2
	movsd	344(%rsp), %xmm1
	movsd	352(%rsp), %xmm7
	movsd	360(%rsp), %xmm12
	movsd	368(%rsp), %xmm8
	movsd	376(%rsp), %xmm14
	movsd	%xmm3, 88(%rsp)
	movsd	384(%rsp), %xmm6
	movsd	%xmm5, 96(%rsp)
	movsd	%xmm4, 112(%rsp)
	movsd	%xmm2, 128(%rsp)
	movsd	%xmm8, 8(%rsp)
	movsd	392(%rsp), %xmm2
	movsd	%xmm14, 136(%rsp)
	movsd	400(%rsp), %xmm4
	movsd	%xmm0, 120(%rsp)
	movsd	408(%rsp), %xmm0
	movsd	416(%rsp), %xmm3
	movsd	%xmm3, 16(%rsp)
	movsd	424(%rsp), %xmm3
	movsd	432(%rsp), %xmm5
	movsd	440(%rsp), %xmm15
	movsd	%xmm5, 40(%rsp)
	movapd	%xmm15, %xmm8
	movsd	.LC1(%rip), %xmm15
	movsd	448(%rsp), %xmm5
	movsd	%xmm15, 208(%rsp)
	movq	%rax, 160(%rsp)
	movabsq	$4618655338850743747, %rax
	movsd	.LC2(%rip), %xmm15
	movq	%rax, 168(%rsp)
	movabsq	$-4602554970182894223, %rax
	mulsd	%xmm5, %xmm4
	movsd	%xmm8, 48(%rsp)
	movsd	%xmm15, 216(%rsp)
	movq	%rax, 176(%rsp)
	movabsq	$-4603162956132589240, %rax
	movsd	.LC3(%rip), %xmm15
	movq	%rax, 184(%rsp)
	mulsd	%xmm0, %xmm8
	movabsq	$-4609366664619292099, %rax
	movsd	%xmm15, 224(%rsp)
	movq	%rax, 192(%rsp)
	mulsd	%xmm5, %xmm11
	movsd	.LC4(%rip), %xmm15
	movl	$5, %eax
	movsd	%xmm3, 24(%rsp)
	mulsd	%xmm5, %xmm6
	movsd	%xmm15, 232(%rsp)
	subsd	%xmm8, %xmm4
	mulsd	%xmm5, %xmm12
	movsd	.LC5(%rip), %xmm15
	mulsd	%xmm5, %xmm2
	movsd	%xmm15, 240(%rsp)
	mulsd	%xmm5, %xmm7
	movsd	160(%rsp), %xmm15
	movsd	168(%rsp), %xmm14
	movsd	%xmm15, 144(%rsp)
	mulsd	%xmm5, %xmm9
	movsd	176(%rsp), %xmm15
	movsd	%xmm14, 152(%rsp)
	mulsd	%xmm5, %xmm1
	movsd	184(%rsp), %xmm3
	movsd	192(%rsp), %xmm14
	movsd	48(%rsp), %xmm8
	mulsd	%xmm5, %xmm10
	mulsd	%xmm13, %xmm8
	mulsd	%xmm5, %xmm3
	mulsd	%xmm5, %xmm15
	subsd	%xmm8, %xmm11
	movsd	24(%rsp), %xmm8
	mulsd	%xmm0, %xmm8
	subsd	%xmm8, %xmm6
	movsd	40(%rsp), %xmm8
	movsd	%xmm6, 56(%rsp)
	movsd	48(%rsp), %xmm6
	mulsd	8(%rsp), %xmm6
	subsd	%xmm6, %xmm12
	movapd	%xmm8, %xmm6
	mulsd	%xmm0, %xmm6
	subsd	%xmm6, %xmm2
	movapd	%xmm8, %xmm6
	movsd	%xmm2, 64(%rsp)
	movsd	8(%rsp), %xmm2
	mulsd	%xmm8, %xmm2
	movsd	64(%rsp), %xmm8
	subsd	%xmm2, %xmm7
	movapd	%xmm8, %xmm2
	mulsd	%xmm12, %xmm2
	mulsd	%xmm4, %xmm7
	subsd	%xmm2, %xmm7
	movapd	%xmm6, %xmm2
	movsd	56(%rsp), %xmm6
	mulsd	%xmm13, %xmm2
	subsd	%xmm2, %xmm9
	movapd	%xmm8, %xmm2
	movsd	24(%rsp), %xmm8
	mulsd	%xmm11, %xmm2
	mulsd	%xmm4, %xmm9
	subsd	%xmm2, %xmm9
	movsd	8(%rsp), %xmm2
	mulsd	%xmm8, %xmm2
	subsd	%xmm2, %xmm1
	movapd	%xmm6, %xmm2
	mulsd	%xmm12, %xmm2
	mulsd	%xmm4, %xmm1
	subsd	%xmm2, %xmm1
	movapd	%xmm8, %xmm2
	mulsd	%xmm13, %xmm2
	movsd	%xmm1, 72(%rsp)
	movapd	%xmm10, %xmm1
	movapd	%xmm6, %xmm10
	subsd	%xmm2, %xmm1
	movsd	32(%rsp), %xmm6
	mulsd	%xmm11, %xmm10
	movapd	%xmm15, %xmm2
	movsd	8(%rsp), %xmm15
	mulsd	%xmm4, %xmm1
	mulsd	%xmm14, %xmm15
	subsd	%xmm10, %xmm1
	movsd	72(%rsp), %xmm10
	subsd	%xmm15, %xmm2
	movapd	%xmm12, %xmm15
	mulsd	%xmm9, %xmm10
	mulsd	%xmm7, %xmm1
	mulsd	%xmm4, %xmm2
	subsd	%xmm10, %xmm1
	movsd	112(%rsp), %xmm10
	mulsd	%xmm5, %xmm10
	movsd	%xmm1, 80(%rsp)
	movsd	48(%rsp), %xmm1
	mulsd	%xmm6, %xmm1
	subsd	%xmm1, %xmm10
	movapd	%xmm14, %xmm1
	mulsd	%xmm0, %xmm1
	subsd	%xmm1, %xmm3
	movsd	104(%rsp), %xmm1
	mulsd	%xmm5, %xmm1
	mulsd	%xmm3, %xmm15
	movapd	%xmm1, %xmm8
	movsd	40(%rsp), %xmm1
	subsd	%xmm15, %xmm2
	movsd	96(%rsp), %xmm15
	mulsd	%xmm6, %xmm1
	movsd	%xmm14, 96(%rsp)
	mulsd	%xmm5, %xmm15
	mulsd	%xmm13, %xmm14
	subsd	%xmm1, %xmm8
	movsd	64(%rsp), %xmm1
	movapd	%xmm15, %xmm6
	mulsd	%xmm10, %xmm1
	movsd	72(%rsp), %xmm15
	mulsd	%xmm4, %xmm8
	subsd	%xmm1, %xmm8
	movsd	32(%rsp), %xmm1
	mulsd	24(%rsp), %xmm1
	mulsd	%xmm8, %xmm15
	subsd	%xmm1, %xmm6
	movsd	56(%rsp), %xmm1
	mulsd	%xmm10, %xmm1
	mulsd	%xmm4, %xmm6
	subsd	%xmm1, %xmm6
	movsd	152(%rsp), %xmm1
	mulsd	%xmm5, %xmm1
	mulsd	%xmm7, %xmm6
	subsd	%xmm14, %xmm1
	movsd	16(%rsp), %xmm14
	subsd	%xmm15, %xmm6
	movapd	%xmm11, %xmm15
	mulsd	%xmm14, %xmm0
	mulsd	%xmm3, %xmm15
	mulsd	%xmm4, %xmm1
	subsd	%xmm15, %xmm1
	movapd	%xmm9, %xmm15
	mulsd	%xmm2, %xmm15
	mulsd	%xmm7, %xmm1
	subsd	%xmm15, %xmm1
	movsd	136(%rsp), %xmm15
	mulsd	%xmm5, %xmm15
	subsd	%xmm0, %xmm15
	movsd	128(%rsp), %xmm0
	mulsd	8(%rsp), %xmm14
	mulsd	%xmm5, %xmm0
	mulsd	16(%rsp), %xmm13
	mulsd	%xmm15, %xmm12
	mulsd	%xmm15, %xmm11
	subsd	%xmm14, %xmm0
	movsd	96(%rsp), %xmm14
	mulsd	%xmm4, %xmm0
	subsd	%xmm12, %xmm0
	movapd	%xmm0, %xmm12
	movsd	120(%rsp), %xmm0
	mulsd	%xmm12, %xmm9
	mulsd	%xmm5, %xmm0
	subsd	%xmm13, %xmm0
	movsd	32(%rsp), %xmm13
	mulsd	%xmm4, %xmm0
	subsd	%xmm11, %xmm0
	movapd	%xmm0, %xmm11
	movsd	144(%rsp), %xmm0
	mulsd	%xmm7, %xmm11
	mulsd	%xmm5, %xmm0
	subsd	%xmm9, %xmm11
	movapd	%xmm13, %xmm9
	mulsd	16(%rsp), %xmm13
	mulsd	%xmm14, %xmm9
	subsd	%xmm9, %xmm0
	movapd	%xmm10, %xmm9
	mulsd	%xmm15, %xmm10
	mulsd	%xmm3, %xmm9
	mulsd	%xmm4, %xmm0
	subsd	%xmm9, %xmm0
	movapd	%xmm8, %xmm9
	mulsd	%xmm12, %xmm8
	mulsd	%xmm2, %xmm9
	mulsd	%xmm7, %xmm0
	subsd	%xmm9, %xmm0
	movapd	%xmm6, %xmm9
	mulsd	%xmm11, %xmm6
	mulsd	%xmm1, %xmm9
	mulsd	80(%rsp), %xmm0
	subsd	%xmm9, %xmm0
	movsd	88(%rsp), %xmm9
	mulsd	%xmm5, %xmm9
	subsd	%xmm13, %xmm9
	movsd	72(%rsp), %xmm13
	mulsd	%xmm4, %xmm9
	subsd	%xmm10, %xmm9
	movsd	80(%rsp), %xmm10
	mulsd	%xmm7, %xmm9
	subsd	%xmm8, %xmm9
	mulsd	%xmm10, %xmm9
	subsd	%xmm6, %xmm9
	movsd	24(%rsp), %xmm6
	divsd	%xmm9, %xmm0
	mulsd	%xmm0, %xmm11
	mulsd	%xmm0, %xmm12
	mulsd	%xmm0, %xmm15
	subsd	%xmm11, %xmm1
	subsd	%xmm12, %xmm2
	subsd	%xmm15, %xmm3
	divsd	%xmm10, %xmm1
	mulsd	%xmm1, %xmm13
	mulsd	%xmm1, %xmm6
	subsd	%xmm13, %xmm2
	divsd	%xmm7, %xmm2
	movsd	56(%rsp), %xmm7
	mulsd	%xmm1, %xmm7
	subsd	%xmm7, %xmm3
	movsd	64(%rsp), %xmm7
	mulsd	%xmm2, %xmm7
	subsd	%xmm7, %xmm3
	divsd	%xmm4, %xmm3
	movsd	16(%rsp), %xmm4
	mulsd	%xmm0, %xmm4
	subsd	%xmm4, %xmm14
	movapd	%xmm14, %xmm4
	subsd	%xmm6, %xmm4
	movsd	40(%rsp), %xmm6
	mulsd	%xmm2, %xmm6
	subsd	%xmm6, %xmm4
	movsd	48(%rsp), %xmm6
	mulsd	%xmm3, %xmm6
	subsd	%xmm6, %xmm4
	divsd	%xmm5, %xmm4
	call	__printf_chk
	movq	456(%rsp), %rdx
	xorq	%fs:40, %rdx
	jne	.L5
	xorl	%eax, %eax
	addq	$472, %rsp
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
