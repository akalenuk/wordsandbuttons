	.file	"exp_forced_inline.cpp"
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
.LFB2242:
	.cfi_startproc
	vxorpd	%xmm0, %xmm0, %xmm0
	subq	$520, %rsp
	.cfi_def_cfa_offset 528
	movq	%fs:40, %rax
	movq	%rax, 504(%rsp)
	xorl	%eax, %eax
	leaq	304(%rsp), %r9
	movl	$1000000, %edx
	movl	$.LC0, %r8d
	vmovsd	%xmm0, 160(%rsp)
	vmovsd	%xmm0, 168(%rsp)
	vmovsd	%xmm0, 176(%rsp)
	vmovsd	%xmm0, 184(%rsp)
	vmovsd	%xmm0, 192(%rsp)
	vmovsd	%xmm0, 152(%rsp)
	.p2align 4,,10
	.p2align 3
.L5:
	vmovsd	.LC2(%rip), %xmm4
	movl	$25, %ecx
	movq	%r9, %rdi
	movq	%r8, %rsi
	vmovsd	.LC5(%rip), %xmm2
	rep movsq
	vmovsd	%xmm4, 208(%rsp)
	xorl	%eax, %eax
	vmovsd	.LC3(%rip), %xmm4
	vmovsd	%xmm2, 232(%rsp)
	vmovsd	%xmm4, 216(%rsp)
	vmovsd	.LC4(%rip), %xmm4
	vmovsd	304(%rsp), %xmm2
	vmovsd	%xmm4, 224(%rsp)
	vmovsd	.LC6(%rip), %xmm4
	vmovsd	312(%rsp), %xmm7
	vmovsd	%xmm4, 240(%rsp)
	vmovsd	320(%rsp), %xmm4
	vmovsd	328(%rsp), %xmm12
	vmovsd	336(%rsp), %xmm6
	vmovsd	%xmm7, 104(%rsp)
	vmovsd	344(%rsp), %xmm0
	vmovsd	%xmm6, 24(%rsp)
	vmovsd	352(%rsp), %xmm11
	vmovsd	360(%rsp), %xmm6
	vmovsd	368(%rsp), %xmm13
	vmovsd	376(%rsp), %xmm7
	vmovsd	384(%rsp), %xmm3
	vmovapd	%xmm7, %xmm14
	vmovsd	392(%rsp), %xmm10
	vmovsd	%xmm2, 96(%rsp)
	vmovsd	%xmm4, 72(%rsp)
	vmovsd	%xmm0, 112(%rsp)
	vmovsd	%xmm3, 120(%rsp)
	vmovsd	400(%rsp), %xmm0
	vmovsd	408(%rsp), %xmm5
	vmovsd	416(%rsp), %xmm7
	vmovsd	424(%rsp), %xmm1
	vmovsd	%xmm7, (%rsp)
	vmovsd	432(%rsp), %xmm8
	vmovsd	440(%rsp), %xmm7
	vmovsd	448(%rsp), %xmm4
	vmovsd	456(%rsp), %xmm15
	vmovsd	464(%rsp), %xmm2
	vmovsd	472(%rsp), %xmm9
	vmovsd	%xmm2, 56(%rsp)
	vmovsd	%xmm9, 8(%rsp)
	vmovsd	480(%rsp), %xmm2
	vmovsd	488(%rsp), %xmm9
	vmovsd	%xmm1, 128(%rsp)
	vmovapd	%xmm9, %xmm1
	vmovsd	%xmm2, 16(%rsp)
	vmovsd	496(%rsp), %xmm2
	vmovsd	%xmm1, 40(%rsp)
	vmulsd	%xmm1, %xmm15, %xmm1
	vmovsd	%xmm14, 32(%rsp)
	vmovsd	208(%rsp), %xmm3
	vmovsd	216(%rsp), %xmm9
	vfmsub132sd	%xmm2, %xmm1, %xmm4
	vmovsd	40(%rsp), %xmm1
	vmovsd	%xmm3, 136(%rsp)
	vmulsd	%xmm14, %xmm1, %xmm1
	vmovsd	%xmm9, 144(%rsp)
	vmovsd	40(%rsp), %xmm14
	vmovsd	232(%rsp), %xmm9
	vmovsd	240(%rsp), %xmm3
	vfmsub132sd	%xmm2, %xmm1, %xmm13
	vmulsd	8(%rsp), %xmm15, %xmm1
	vfmsub132sd	%xmm2, %xmm1, %xmm8
	vmovsd	%xmm8, 48(%rsp)
	vmovsd	(%rsp), %xmm8
	vmulsd	%xmm8, %xmm14, %xmm14
	vfmsub231sd	%xmm2, %xmm5, %xmm14
	vmovsd	16(%rsp), %xmm5
	vmulsd	%xmm5, %xmm15, %xmm1
	vfmsub132sd	%xmm2, %xmm1, %xmm7
	vmulsd	%xmm7, %xmm14, %xmm1
	vmovsd	%xmm7, 64(%rsp)
	vmulsd	%xmm8, %xmm5, %xmm7
	vmulsd	64(%rsp), %xmm13, %xmm5
	vfmsub231sd	%xmm2, %xmm0, %xmm7
	vfmsub132sd	%xmm4, %xmm1, %xmm7
	vmovsd	16(%rsp), %xmm1
	vmovsd	32(%rsp), %xmm8
	vmulsd	%xmm8, %xmm1, %xmm0
	vmovsd	(%rsp), %xmm1
	vmulsd	8(%rsp), %xmm1, %xmm1
	vfmsub231sd	%xmm2, %xmm6, %xmm0
	vfmsub132sd	%xmm4, %xmm5, %xmm0
	vmulsd	48(%rsp), %xmm14, %xmm5
	vmulsd	48(%rsp), %xmm13, %xmm6
	vfmsub231sd	%xmm2, %xmm10, %xmm1
	vmovapd	%xmm1, %xmm10
	vfmsub132sd	%xmm4, %xmm5, %xmm10
	vmulsd	%xmm10, %xmm0, %xmm1
	vmovsd	%xmm10, 80(%rsp)
	vmovsd	8(%rsp), %xmm10
	vmulsd	%xmm8, %xmm10, %xmm5
	vmovsd	24(%rsp), %xmm10
	vfmsub231sd	%xmm2, %xmm11, %xmm5
	vfmsub132sd	%xmm4, %xmm6, %xmm5
	vmovapd	%xmm5, %xmm11
	vmovsd	72(%rsp), %xmm6
	vfmsub132sd	%xmm7, %xmm1, %xmm11
	vmovsd	%xmm11, 88(%rsp)
	vmulsd	(%rsp), %xmm3, %xmm1
	vmovsd	40(%rsp), %xmm11
	vmulsd	%xmm10, %xmm11, %xmm11
	vfmsub231sd	.LC4(%rip), %xmm2, %xmm1
	vfmsub231sd	%xmm2, %xmm12, %xmm11
	vmulsd	%xmm3, %xmm15, %xmm12
	vmulsd	64(%rsp), %xmm11, %xmm5
	vfmsub231sd	%xmm9, %xmm2, %xmm12
	vmulsd	16(%rsp), %xmm10, %xmm9
	vfmsub132sd	%xmm2, %xmm9, %xmm6
	vfmsub132sd	%xmm4, %xmm5, %xmm6
	vmulsd	%xmm12, %xmm14, %xmm5
	vmovapd	%xmm6, %xmm9
	vfmsub132sd	%xmm4, %xmm5, %xmm1
	vmovsd	%xmm1, 72(%rsp)
	vmulsd	8(%rsp), %xmm10, %xmm1
	vmulsd	80(%rsp), %xmm6, %xmm5
	vmulsd	48(%rsp), %xmm11, %xmm6
	vfmsub231sd	104(%rsp), %xmm2, %xmm1
	vmovapd	%xmm1, %xmm8
	vmulsd	%xmm12, %xmm13, %xmm1
	vfmsub132sd	%xmm4, %xmm6, %xmm8
	vfmsub132sd	%xmm7, %xmm5, %xmm8
	vmulsd	32(%rsp), %xmm3, %xmm5
	vmulsd	72(%rsp), %xmm0, %xmm6
	vfmsub231sd	144(%rsp), %xmm2, %xmm5
	vfmsub132sd	%xmm4, %xmm1, %xmm5
	vmovsd	56(%rsp), %xmm1
	vmovapd	%xmm5, %xmm10
	vmovsd	(%rsp), %xmm5
	vfmsub132sd	%xmm7, %xmm6, %xmm10
	vmulsd	%xmm1, %xmm15, %xmm6
	vmulsd	%xmm1, %xmm5, %xmm5
	vmulsd	32(%rsp), %xmm1, %xmm1
	vmulsd	%xmm12, %xmm11, %xmm15
	vfmsub231sd	128(%rsp), %xmm2, %xmm6
	vmulsd	%xmm6, %xmm14, %xmm14
	vfmsub231sd	120(%rsp), %xmm2, %xmm5
	vmulsd	%xmm6, %xmm13, %xmm13
	vmulsd	%xmm6, %xmm11, %xmm11
	vfmsub132sd	%xmm4, %xmm14, %xmm5
	vmulsd	%xmm5, %xmm0, %xmm0
	vfmsub231sd	112(%rsp), %xmm2, %xmm1
	vmulsd	72(%rsp), %xmm9, %xmm14
	vfmsub231sd	%xmm1, %xmm4, %xmm13
	vmulsd	%xmm5, %xmm9, %xmm9
	vfmsub132sd	%xmm7, %xmm0, %xmm13
	vmulsd	24(%rsp), %xmm3, %xmm0
	vmovapd	%xmm13, %xmm1
	vmulsd	%xmm10, %xmm8, %xmm13
	vmulsd	%xmm1, %xmm8, %xmm8
	vfmsub231sd	136(%rsp), %xmm2, %xmm0
	vfmsub132sd	%xmm4, %xmm15, %xmm0
	vmovsd	56(%rsp), %xmm15
	vfmsub132sd	%xmm7, %xmm14, %xmm0
	vmovsd	24(%rsp), %xmm14
	vfmsub231sd	88(%rsp), %xmm0, %xmm13
	vmulsd	%xmm15, %xmm14, %xmm0
	vfmsub231sd	96(%rsp), %xmm2, %xmm0
	vfmsub231sd	%xmm0, %xmm4, %xmm11
	vmovsd	88(%rsp), %xmm0
	vfmsub231sd	%xmm11, %xmm7, %xmm9
	vfmsub231sd	%xmm0, %xmm9, %xmm8
	vdivsd	%xmm8, %xmm13, %xmm13
	vfnmadd132sd	%xmm13, %xmm10, %xmm1
	vdivsd	%xmm0, %xmm1, %xmm1
	vfnmadd213sd	72(%rsp), %xmm13, %xmm5
	vfnmadd132sd	%xmm13, %xmm12, %xmm6
	vmovapd	%xmm6, %xmm8
	vmovsd	%xmm13, 256(%rsp)
	vmovapd	%xmm15, %xmm10
	vfnmadd132sd	%xmm13, %xmm3, %xmm10
	vmovsd	152(%rsp), %xmm3
	vfnmadd231sd	80(%rsp), %xmm1, %xmm5
	vdivsd	%xmm7, %xmm5, %xmm7
	vfnmadd231sd	48(%rsp), %xmm1, %xmm8
	vmovsd	%xmm1, 264(%rsp)
	vfnmadd132sd	8(%rsp), %xmm10, %xmm1
	vfnmadd231sd	64(%rsp), %xmm7, %xmm8
	vdivsd	%xmm4, %xmm8, %xmm4
	vfnmadd231sd	16(%rsp), %xmm7, %xmm1
	vmovsd	%xmm7, 272(%rsp)
	vmovsd	%xmm4, 280(%rsp)
	vfnmadd132sd	40(%rsp), %xmm1, %xmm4
	vdivsd	%xmm2, %xmm4, %xmm2
	vmovsd	%xmm2, 288(%rsp)
.L3:
	vaddsd	%xmm3, %xmm13, %xmm3
	vmovsd	%xmm3, 160(%rsp,%rax)
	addq	$8, %rax
	cmpq	$40, %rax
	je	.L2
	vmovsd	256(%rsp,%rax), %xmm13
	vmovsd	160(%rsp,%rax), %xmm3
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L2:
	subl	$1, %edx
	je	.L4
	vmovsd	160(%rsp), %xmm4
	vmovsd	%xmm4, 152(%rsp)
	jmp	.L5
.L4:
	vmovsd	192(%rsp), %xmm1
	movl	$_ZSt4cout, %edi
	vmovsd	184(%rsp), %xmm2
	vmovsd	176(%rsp), %xmm3
	vmovsd	168(%rsp), %xmm4
	vmovsd	160(%rsp), %xmm0
	vmovsd	%xmm1, 24(%rsp)
	vmovsd	%xmm2, 16(%rsp)
	vmovsd	%xmm3, 8(%rsp)
	vmovsd	%xmm4, (%rsp)
	call	_ZNSo9_M_insertIdEERSoT_
	movl	$32, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	vmovsd	(%rsp), %xmm4
	movq	%rax, %rdi
	vmovapd	%xmm4, %xmm0
	call	_ZNSo9_M_insertIdEERSoT_
	movl	$32, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	vmovsd	8(%rsp), %xmm3
	movq	%rax, %rdi
	vmovapd	%xmm3, %xmm0
	call	_ZNSo9_M_insertIdEERSoT_
	movl	$32, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	vmovsd	16(%rsp), %xmm2
	movq	%rax, %rdi
	vmovapd	%xmm2, %xmm0
	call	_ZNSo9_M_insertIdEERSoT_
	movl	$32, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	vmovsd	24(%rsp), %xmm1
	movq	%rax, %rdi
	vmovapd	%xmm1, %xmm0
	call	_ZNSo9_M_insertIdEERSoT_
	movl	$10, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	xorl	%eax, %eax
	movq	504(%rsp), %rdx
	xorq	%fs:40, %rdx
	jne	.L10
	addq	$520, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L10:
	.cfi_restore_state
	call	__stack_chk_fail
	.cfi_endproc
.LFE2242:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE7:
	.section	.text.startup
.LHOTE7:
	.section	.text.unlikely
.LCOLDB8:
	.section	.text.startup
.LHOTB8:
	.p2align 4,,15
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB2729:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	jmp	__cxa_atexit
	.cfi_endproc
.LFE2729:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.text.unlikely
.LCOLDE8:
	.section	.text.startup
.LHOTE8:
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC2:
	.long	3779571220
	.long	1074795642
	.align 8
.LC3:
	.long	1546188227
	.long	1075364495
	.align 8
.LC4:
	.long	3607772529
	.long	-1071615837
	.align 8
.LC5:
	.long	343597384
	.long	-1071757394
	.align 8
.LC6:
	.long	2748779069
	.long	-1073201808
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
