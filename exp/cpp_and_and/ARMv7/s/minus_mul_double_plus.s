	.text
	.syntax unified
	.cpu	cortex-a8
	.eabi_attribute	6, 10	@ Tag_CPU_arch
	.eabi_attribute	7, 65	@ Tag_CPU_arch_profile
	.eabi_attribute	8, 1	@ Tag_ARM_ISA_use
	.eabi_attribute	9, 2	@ Tag_THUMB_ISA_use
	.fpu	neon
	.eabi_attribute	17, 1	@ Tag_ABI_PCS_GOT_use
	.eabi_attribute	20, 1	@ Tag_ABI_FP_denormal
	.eabi_attribute	21, 1	@ Tag_ABI_FP_exceptions
	.eabi_attribute	23, 3	@ Tag_ABI_FP_number_model
	.eabi_attribute	24, 1	@ Tag_ABI_align_needed
	.eabi_attribute	25, 1	@ Tag_ABI_align_preserved
	.eabi_attribute	28, 1	@ Tag_ABI_VFP_args
	.eabi_attribute	18, 4	@ Tag_ABI_PCS_wchar_t
	.eabi_attribute	26, 2	@ Tag_ABI_enum_size
	.eabi_attribute	68, 1	@ Tag_Virtualization_use
	.file	"minus_mul_plus_double.cpp"
	.globl	_Z2sqd
	.align	2
	.type	_Z2sqd,%function
_Z2sqd:                                 @ @_Z2sqd
	.fnstart
.Leh_func_begin0:
@ BB#0:
	vmul.f64	d0, d0, d0
	bx	lr
.Ltmp0:
	.size	_Z2sqd, .Ltmp0-_Z2sqd
	.cantunwind
	.fnend

	.globl	main
	.align	3
	.type	main,%function
main:                                   @ @main
	.fnstart
.Leh_func_begin1:
@ BB#0:
	.save	{r4, r5, r6, r7, r8, r10, r11, lr}
	push	{r4, r5, r6, r7, r8, r10, r11, lr}
	.setfp	r11, sp, #24
	add	r11, sp, #24
	.pad	#488
	sub	sp, sp, #488
	.pad	#2048
	sub	sp, sp, #2048
	movw	r2, #35173
	add	r3, sp, #32
	mov	r0, #0
	mov	r1, #1
	movt	r2, #27655
	str	r0, [sp, #32]
.LBB1_1:                                @ =>This Inner Loop Header: Depth=1
	eor	r0, r0, r0, lsr #30
	mla	r0, r0, r2, r1
	str	r0, [r3, r1, lsl #2]
	add	r1, r1, #1
	cmp	r1, #624
	bne	.LBB1_1
@ BB#2:                                 @ %_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEC2Ej.exit
	mov	r0, #624
	mov	r5, #0
	str	r0, [sp, #2528]
	mov	r0, #1
	str	r5, [sp, #24]
	str	r0, [sp, #28]
.Ltmp1:
	movw	r8, #8192
	movt	r8, #1953
	mov	r0, r8
	bl	_Znwj
	mov	r4, r0
.Ltmp2:
@ BB#3:                                 @ %.lr.ph
	mov	r0, r4
	mov	r1, r8
	mov	r2, #0
	bl	__aeabi_memset
	add	r6, sp, #32
	add	r7, sp, #24
.LBB1_4:                                @ =>This Inner Loop Header: Depth=1
	mov	r0, r7
	mov	r1, r6
	mov	r2, r7
	bl	_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_RKNS0_10param_typeE
	vmov	s0, r0
	add	r0, r4, r5
	add	r5, r5, #8
	vcvt.f64.s32	d16, s0
	cmp	r5, r8
	vstr	d16, [r0]
	bne	.LBB1_4
@ BB#5:                                 @ %._crit_edge
	add	r0, sp, #8
	mov	r5, #0
	str	r5, [sp, #20]
	bl	_ZNSt6chrono3_V212system_clock3nowEv
	vmov.f64	d16, #-1.000000e+00
	movw	r0, #8168
	movt	r0, #1953
.LBB1_6:                                @ =>This Inner Loop Header: Depth=1
	add	r1, r4, r5
	add	r5, r5, #8
	vldmia	r1, {d17, d18, d19, d20}
	vadd.f64	d18, d18, d16
	vadd.f64	d17, d17, d16
	vadd.f64	d19, d19, d16
	vmul.f64	d18, d18, d18
	vmul.f64	d17, d17, d17
	vadd.f64	d20, d20, d16
	vmul.f64	d19, d19, d19
	vadd.f64	d17, d17, d18
	vmul.f64	d18, d20, d20
	vadd.f64	d17, d17, d19
	vadd.f64	d17, d17, d18
	vcmpe.f64	d17, #0
	vmrs	APSR_nzcv, fpscr
	ldreq	r1, [sp, #20]
	addeq	r1, r1, #1
	streq	r1, [sp, #20]
	cmp	r5, r0
	bne	.LBB1_6
@ BB#7:
	mov	r0, sp
	bl	_ZNSt6chrono3_V212system_clock3nowEv
.Ltmp4:
	movw	r0, :lower16:_ZSt4cout
	movw	r1, :lower16:.L.str
	movt	r0, :upper16:_ZSt4cout
	movt	r1, :upper16:.L.str
	mov	r2, #6
	bl	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
.Ltmp5:
@ BB#8:
	ldr	r0, [sp, #8]
	ldr	r1, [sp, #12]
	ldm	sp, {r2, r3}
	subs	r0, r2, r0
	sbc	r1, r3, r1
	bl	__aeabi_l2d
	vldr	d16, .LCPI1_0
	vmov	d17, r0, r1
	vmul.f64	d0, d17, d16
.Ltmp6:
	movw	r0, :lower16:_ZSt4cout
	movt	r0, :upper16:_ZSt4cout
	bl	_ZNSo9_M_insertIdEERSoT_
	mov	r5, r0
.Ltmp7:
@ BB#9:                                 @ %_ZNSolsEd.exit
.Ltmp8:
	movw	r1, :lower16:.L.str1
	mov	r0, r5
	movt	r1, :upper16:.L.str1
	mov	r2, #9
	bl	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
.Ltmp9:
@ BB#10:                                @ %_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc.exit2
	ldr	r1, [sp, #20]
.Ltmp10:
	mov	r0, r5
	bl	_ZNSo9_M_insertImEERSoT_
.Ltmp11:
@ BB#11:                                @ %_ZNSolsEj.exit
.Ltmp12:
	movw	r1, :lower16:.L.str2
	mov	r2, #1
	movt	r1, :upper16:.L.str2
	bl	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
.Ltmp13:
@ BB#12:                                @ %_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc.exit
	cmp	r4, #0
	beq	.LBB1_14
@ BB#13:
	mov	r0, r4
	bl	_ZdlPv
.LBB1_14:                               @ %_ZNSt6vectorIdSaIdEED2Ev.exit
	mov	r0, #0
	sub	sp, r11, #24
	pop	{r4, r5, r6, r7, r8, r10, r11, pc}
.LBB1_15:
.Ltmp14:
	mov	r5, r0
	cmp	r4, #0
	beq	.LBB1_18
@ BB#16:
	mov	r0, r4
	bl	_ZdlPv
	mov	r0, r5
	bl	_Unwind_Resume
.LBB1_17:
.Ltmp3:
	mov	r5, r0
.LBB1_18:                               @ %_ZNSt6vectorIdSaIdEED2Ev.exit4
	mov	r0, r5
	bl	_Unwind_Resume
	.align	3
@ BB#19:
.LCPI1_0:
	.long	3894859413              @ double 1.0000000000000001E-9
	.long	1041313291
.Ltmp15:
	.size	main, .Ltmp15-main
.Leh_func_end1:
	.globl	__gxx_personality_v0
	.personality __gxx_personality_v0
	.handlerdata
	.align	2
GCC_except_table1:
.Lexception1:
	.byte	255                     @ @LPStart Encoding = omit
	.byte	0                       @ @TType Encoding = absptr
	.asciz	"\320"                  @ @TType base offset
	.byte	3                       @ Call site Encoding = udata4
	.byte	78                      @ Call site table length
.Lset0 = .Ltmp1-.Leh_func_begin1        @ >> Call Site 1 <<
	.long	.Lset0
.Lset1 = .Ltmp2-.Ltmp1                  @   Call between .Ltmp1 and .Ltmp2
	.long	.Lset1
.Lset2 = .Ltmp3-.Leh_func_begin1        @     jumps to .Ltmp3
	.long	.Lset2
	.byte	0                       @   On action: cleanup
.Lset3 = .Ltmp2-.Leh_func_begin1        @ >> Call Site 2 <<
	.long	.Lset3
.Lset4 = .Ltmp4-.Ltmp2                  @   Call between .Ltmp2 and .Ltmp4
	.long	.Lset4
	.long	0                       @     has no landing pad
	.byte	0                       @   On action: cleanup
.Lset5 = .Ltmp4-.Leh_func_begin1        @ >> Call Site 3 <<
	.long	.Lset5
.Lset6 = .Ltmp5-.Ltmp4                  @   Call between .Ltmp4 and .Ltmp5
	.long	.Lset6
.Lset7 = .Ltmp14-.Leh_func_begin1       @     jumps to .Ltmp14
	.long	.Lset7
	.byte	0                       @   On action: cleanup
.Lset8 = .Ltmp5-.Leh_func_begin1        @ >> Call Site 4 <<
	.long	.Lset8
.Lset9 = .Ltmp6-.Ltmp5                  @   Call between .Ltmp5 and .Ltmp6
	.long	.Lset9
	.long	0                       @     has no landing pad
	.byte	0                       @   On action: cleanup
.Lset10 = .Ltmp6-.Leh_func_begin1       @ >> Call Site 5 <<
	.long	.Lset10
.Lset11 = .Ltmp13-.Ltmp6                @   Call between .Ltmp6 and .Ltmp13
	.long	.Lset11
.Lset12 = .Ltmp14-.Leh_func_begin1      @     jumps to .Ltmp14
	.long	.Lset12
	.byte	0                       @   On action: cleanup
.Lset13 = .Ltmp13-.Leh_func_begin1      @ >> Call Site 6 <<
	.long	.Lset13
.Lset14 = .Leh_func_end1-.Ltmp13        @   Call between .Ltmp13 and .Leh_func_end1
	.long	.Lset14
	.long	0                       @     has no landing pad
	.byte	0                       @   On action: cleanup
	.align	2
	.fnend

	.section	.text._ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_RKNS0_10param_typeE,"axG",%progbits,_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_RKNS0_10param_typeE,comdat
	.weak	_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_RKNS0_10param_typeE
	.align	2
	.type	_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_RKNS0_10param_typeE,%function
_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_RKNS0_10param_typeE: @ @_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_RKNS0_10param_typeE
	.fnstart
.Leh_func_begin2:
@ BB#0:
	.save	{r4, r5, r6, r7, r8, r9, r11, lr}
	push	{r4, r5, r6, r7, r8, r9, r11, lr}
	.setfp	r11, sp, #24
	add	r11, sp, #24
	mov	r9, r2
	mov	r5, r1
	ldm	r9, {r0, r1}
	sub	r0, r1, r0
	cmn	r0, #1
	beq	.LBB2_6
@ BB#1:
	add	r7, r0, #1
	mvn	r0, #0
	mov	r1, r7
	bl	__aeabi_uidiv
	mov	r8, r0
	ldr	r1, [r5, #2496]
	mul	r7, r8, r7
	movw	r6, #22144
	movw	r4, #0
	movt	r6, #40236
	movt	r4, #61382
.LBB2_2:                                @ =>This Inner Loop Header: Depth=1
	cmp	r1, #624
	blo	.LBB2_4
@ BB#3:                                 @   in Loop: Header=BB2_2 Depth=1
	mov	r0, r5
	bl	_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv
	ldr	r1, [r5, #2496]
.LBB2_4:                                @ %_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv.exit2
                                        @   in Loop: Header=BB2_2 Depth=1
	add	r2, r1, #1
	str	r2, [r5, #2496]
	ldr	r0, [r5, r1, lsl #2]
	eor	r0, r0, r0, lsr #11
	and	r1, r6, r0, lsl #7
	eor	r0, r1, r0
	and	r1, r4, r0, lsl #15
	eor	r0, r1, r0
	mov	r1, r2
	eor	r0, r0, r0, lsr #18
	cmp	r0, r7
	bhs	.LBB2_2
@ BB#5:
	mov	r1, r8
	bl	__aeabi_uidiv
	b	.LBB2_9
.LBB2_6:
	ldr	r0, [r5, #2496]
	cmp	r0, #624
	blo	.LBB2_8
@ BB#7:
	mov	r0, r5
	bl	_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv
	ldr	r0, [r5, #2496]
.LBB2_8:                                @ %_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv.exit
	add	r1, r0, #1
	str	r1, [r5, #2496]
	ldr	r0, [r5, r0, lsl #2]
	movw	r1, #22144
	movt	r1, #40236
	eor	r0, r0, r0, lsr #11
	and	r1, r1, r0, lsl #7
	eor	r0, r1, r0
	movw	r1, #0
	movt	r1, #61382
	and	r1, r1, r0, lsl #15
	eor	r0, r1, r0
	eor	r0, r0, r0, lsr #18
.LBB2_9:
	ldr	r1, [r9]
	add	r0, r1, r0
	pop	{r4, r5, r6, r7, r8, r9, r11, pc}
.Ltmp16:
	.size	_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_RKNS0_10param_typeE, .Ltmp16-_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_RKNS0_10param_typeE
	.cantunwind
	.fnend

	.section	.text._ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv,"axG",%progbits,_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv,comdat
	.weak	_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv
	.align	2
	.type	_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv,%function
_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv: @ @_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv
	.fnstart
.Leh_func_begin3:
@ BB#0:
	.save	{r4, r5, r11, lr}
	push	{r4, r5, r11, lr}
	ldr	lr, [r0]
	movw	r12, #45279
	mov	r2, #0
	movt	r12, #39176
.LBB3_1:                                @ =>This Inner Loop Header: Depth=1
	add	r1, r0, r2
	ldr	r3, [r1, #4]
	ldr	r5, [r1, #1588]
	and	r1, lr, #-2147483648
	bic	r4, r3, #-2147483647
	tst	r3, #1
	orr	r1, r4, r1
	mov	lr, r3
	eor	r1, r5, r1, lsr #1
	eorne	r1, r1, r12
	str	r1, [r0, r2]
	add	r2, r2, #4
	cmp	r2, #908
	bne	.LBB3_1
@ BB#2:                                 @ %.preheader
	ldr	r4, [r0, #908]
	mov	r2, #0
.LBB3_3:                                @ =>This Inner Loop Header: Depth=1
	rsb	r1, r2, #0
	mov	r5, r0
	and	r4, r4, #-2147483648
	sub	r2, r2, #1
	ldr	lr, [r5, r1, lsl #2]!
	ldr	r3, [r5, #912]
	bic	r1, r3, #-2147483647
	tst	r3, #1
	orr	r1, r1, r4
	mov	r4, r3
	eor	r1, lr, r1, lsr #1
	eorne	r1, r1, r12
	str	r1, [r5, #908]
	cmn	r2, #396
	bne	.LBB3_3
@ BB#4:
	ldr	r1, [r0, #2492]
	ldr	r2, [r0]
	and	r1, r1, #-2147483648
	ldr	r3, [r0, #1584]
	bic	r5, r2, #-2147483647
	tst	r2, #1
	orr	r1, r5, r1
	mov	r2, #0
	eor	r1, r3, r1, lsr #1
	eorne	r1, r1, r12
	str	r1, [r0, #2492]
	str	r2, [r0, #2496]
	pop	{r4, r5, r11, pc}
.Ltmp17:
	.size	_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv, .Ltmp17-_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv
	.cantunwind
	.fnend

	.section	.text.startup,"ax",%progbits
	.align	2
	.type	_GLOBAL__sub_I_minus_mul_plus_double.cpp,%function
_GLOBAL__sub_I_minus_mul_plus_double.cpp: @ @_GLOBAL__sub_I_minus_mul_plus_double.cpp
	.fnstart
.Leh_func_begin4:
@ BB#0:
	.save	{r4, r10, r11, lr}
	push	{r4, r10, r11, lr}
	.setfp	r11, sp, #8
	add	r11, sp, #8
	movw	r4, :lower16:_ZStL8__ioinit
	movt	r4, :upper16:_ZStL8__ioinit
	mov	r0, r4
	bl	_ZNSt8ios_base4InitC1Ev
	movw	r0, :lower16:_ZNSt8ios_base4InitD1Ev
	movw	r2, :lower16:__dso_handle
	movt	r0, :upper16:_ZNSt8ios_base4InitD1Ev
	movt	r2, :upper16:__dso_handle
	mov	r1, r4
	pop	{r4, r10, r11, lr}
	b	__cxa_atexit
.Ltmp18:
	.size	_GLOBAL__sub_I_minus_mul_plus_double.cpp, .Ltmp18-_GLOBAL__sub_I_minus_mul_plus_double.cpp
.Leh_func_end4:
	.fnend

	.type	_ZStL8__ioinit,%object  @ @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.type	.L.str,%object          @ @.str
	.section	.rodata.str1.1,"aMS",%progbits,1
.L.str:
	.asciz	"time: "
	.size	.L.str, 7

	.type	.L.str1,%object         @ @.str1
.L.str1:
	.asciz	"  1111s: "
	.size	.L.str1, 10

	.type	.L.str2,%object         @ @.str2
.L.str2:
	.asciz	"\n"
	.size	.L.str2, 2

	.section	.init_array,"aw",%init_array
	.align	2
	.long	_GLOBAL__sub_I_minus_mul_plus_double.cpp(target1)

	.ident	"Debian clang version 3.5.0-10 (tags/RELEASE_350/final) (based on LLVM 3.5.0)"
