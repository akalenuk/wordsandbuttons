	.file	"exp_static_a_volatile_b.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC31:
	.string	"%f, %f, %f, %f, %f\n"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB32:
	.section	.text.startup,"ax",@progbits
.LHOTB32:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB22:
	.cfi_startproc
	subq	$104, %rsp
	.cfi_def_cfa_offset 112
	movl	$.LC31, %esi
	movl	$1, %edi
	movsd	.LC1(%rip), %xmm5
	movq	%fs:40, %rax
	movq	%rax, 88(%rsp)
	xorl	%eax, %eax
	movsd	%xmm5, 48(%rsp)
	movabsq	$4616212136052895252, %rax
	movsd	.LC2(%rip), %xmm5
	movq	%rax, (%rsp)
	movabsq	$4618655338850743747, %rax
	movq	%rax, 8(%rsp)
	movabsq	$-4602554970182894223, %rax
	movsd	%xmm5, 56(%rsp)
	movq	%rax, 16(%rsp)
	movabsq	$-4603162956132589240, %rax
	movsd	.LC3(%rip), %xmm5
	movq	%rax, 24(%rsp)
	movabsq	$-4609366664619292099, %rax
	movsd	.LC7(%rip), %xmm6
	movsd	%xmm5, 64(%rsp)
	movq	%rax, 32(%rsp)
	movl	$5, %eax
	movsd	.LC4(%rip), %xmm5
	movsd	(%rsp), %xmm0
	movsd	%xmm5, 72(%rsp)
	movsd	.LC5(%rip), %xmm5
	movsd	8(%rsp), %xmm1
	movsd	%xmm5, 80(%rsp)
	movsd	16(%rsp), %xmm2
	movsd	.LC6(%rip), %xmm5
	movsd	24(%rsp), %xmm3
	movsd	32(%rsp), %xmm4
	mulsd	%xmm5, %xmm3
	mulsd	%xmm4, %xmm6
	mulsd	%xmm5, %xmm2
	movsd	.LC10(%rip), %xmm7
	mulsd	%xmm5, %xmm1
	subsd	%xmm6, %xmm3
	movsd	.LC8(%rip), %xmm6
	movsd	.LC14(%rip), %xmm8
	mulsd	%xmm4, %xmm6
	mulsd	%xmm5, %xmm0
	mulsd	%xmm3, %xmm7
	subsd	%xmm6, %xmm2
	movsd	.LC9(%rip), %xmm6
	mulsd	%xmm6, %xmm2
	subsd	%xmm7, %xmm2
	movsd	.LC11(%rip), %xmm7
	mulsd	%xmm4, %xmm7
	mulsd	%xmm2, %xmm8
	subsd	%xmm7, %xmm1
	movsd	.LC12(%rip), %xmm7
	mulsd	%xmm3, %xmm7
	mulsd	%xmm6, %xmm1
	subsd	%xmm7, %xmm1
	movsd	.LC13(%rip), %xmm7
	mulsd	%xmm7, %xmm1
	subsd	%xmm8, %xmm1
	movsd	.LC15(%rip), %xmm8
	mulsd	%xmm4, %xmm8
	subsd	%xmm8, %xmm0
	movsd	.LC16(%rip), %xmm8
	movsd	.LC19(%rip), %xmm9
	mulsd	%xmm3, %xmm8
	mulsd	%xmm1, %xmm9
	mulsd	%xmm6, %xmm0
	subsd	%xmm8, %xmm0
	movsd	.LC17(%rip), %xmm8
	mulsd	%xmm2, %xmm8
	mulsd	%xmm7, %xmm0
	subsd	%xmm8, %xmm0
	movsd	.LC18(%rip), %xmm8
	mulsd	%xmm8, %xmm0
	subsd	%xmm9, %xmm0
	movsd	.LC21(%rip), %xmm9
	divsd	.LC20(%rip), %xmm0
	mulsd	%xmm0, %xmm9
	subsd	%xmm9, %xmm1
	divsd	%xmm8, %xmm1
	movsd	.LC22(%rip), %xmm8
	mulsd	%xmm0, %xmm8
	subsd	%xmm8, %xmm2
	movsd	.LC23(%rip), %xmm8
	mulsd	%xmm1, %xmm8
	subsd	%xmm8, %xmm2
	divsd	%xmm7, %xmm2
	movsd	.LC24(%rip), %xmm7
	mulsd	%xmm0, %xmm7
	subsd	%xmm7, %xmm3
	movsd	.LC25(%rip), %xmm7
	mulsd	%xmm1, %xmm7
	subsd	%xmm7, %xmm3
	movsd	.LC26(%rip), %xmm7
	mulsd	%xmm2, %xmm7
	subsd	%xmm7, %xmm3
	divsd	%xmm6, %xmm3
	movsd	.LC27(%rip), %xmm6
	mulsd	%xmm0, %xmm6
	subsd	%xmm6, %xmm4
	movsd	.LC28(%rip), %xmm6
	mulsd	%xmm1, %xmm6
	subsd	%xmm6, %xmm4
	movsd	.LC29(%rip), %xmm6
	mulsd	%xmm2, %xmm6
	subsd	%xmm6, %xmm4
	movsd	.LC30(%rip), %xmm6
	mulsd	%xmm3, %xmm6
	subsd	%xmm6, %xmm4
	divsd	%xmm5, %xmm4
	call	__printf_chk
	movq	88(%rsp), %rdx
	xorq	%fs:40, %rdx
	jne	.L5
	xorl	%eax, %eax
	addq	$104, %rsp
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
.LCOLDE32:
	.section	.text.startup
.LHOTE32:
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
	.align 8
.LC6:
	.long	1202590843
	.long	-1071940895
	.align 8
.LC7:
	.long	2233382994
	.long	1075335659
	.align 8
.LC8:
	.long	1889785610
	.long	-1071838659
	.align 8
.LC9:
	.long	3717723691
	.long	1078075283
	.align 8
.LC10:
	.long	700938662
	.long	-1070812614
	.align 8
.LC11:
	.long	687194767
	.long	-1072394404
	.align 8
.LC12:
	.long	886481250
	.long	-1071744785
	.align 8
.LC13:
	.long	3276258777
	.long	1084323836
	.align 8
.LC14:
	.long	236911768
	.long	1082328925
	.align 8
.LC15:
	.long	1030792151
	.long	-1071425782
	.align 8
.LC16:
	.long	54975582
	.long	-1069401224
	.align 8
.LC17:
	.long	2483137056
	.long	1083368220
	.align 8
.LC18:
	.long	2185392678
	.long	1095227578
	.align 8
.LC19:
	.long	1087982832
	.long	1096468689
	.align 8
.LC20:
	.long	3523332949
	.long	-1027562791
	.align 8
.LC21:
	.long	2081240824
	.long	1095358424
	.align 8
.LC22:
	.long	1742044232
	.long	-1065275150
	.align 8
.LC23:
	.long	2449623945
	.long	-1064953704
	.align 8
.LC24:
	.long	3793315116
	.long	-1068055720
	.align 8
.LC25:
	.long	3910138227
	.long	1077407671
	.align 8
.LC26:
	.long	2150919621
	.long	-1068734281
	.align 8
.LC27:
	.long	2405181686
	.long	1075869122
	.align 8
.LC28:
	.long	343597384
	.long	1072777134
	.align 8
.LC29:
	.long	3779571220
	.long	1075975290
	.align 8
.LC30:
	.long	1374389535
	.long	1073815224
	.ident	"GCC: (Ubuntu 5.4.1-2ubuntu1~16.04) 5.4.1 20160904"
	.section	.note.GNU-stack,"",@progbits
