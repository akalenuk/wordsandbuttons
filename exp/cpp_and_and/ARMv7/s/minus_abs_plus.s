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
	.file	"minus_abs_plus.cpp"
	.globl	main
	.align	3
	.type	main,%function
main:                                   @ @main
	.fnstart
.Leh_func_begin0:
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
.LBB0_1:                                @ =>This Inner Loop Header: Depth=1
	eor	r0, r0, r0, lsr #30
	mla	r0, r0, r2, r1
	str	r0, [r3, r1, lsl #2]
	add	r1, r1, #1
	cmp	r1, #624
	bne	.LBB0_1
@ BB#2:                                 @ %_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEC2Ej.exit
	mov	r0, #624
	mov	r5, #0
	str	r0, [sp, #2528]
	mov	r0, #1
	str	r5, [sp, #24]
	str	r0, [sp, #28]
.Ltmp0:
	movw	r8, #36864
	movt	r8, #976
	mov	r0, r8
	bl	_Znwj
	mov	r4, r0
.Ltmp1:
@ BB#3:                                 @ %.lr.ph
	mov	r0, r4
	mov	r1, r8
	mov	r2, #0
	bl	__aeabi_memset
	add	r6, sp, #32
	add	r7, sp, #24
.LBB0_4:                                @ =>This Inner Loop Header: Depth=1
	mov	r0, r7
	mov	r1, r6
	mov	r2, r7
	bl	_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_RKNS0_10param_typeE
	str	r0, [r4, r5]
	add	r5, r5, #4
	cmp	r5, r8
	bne	.LBB0_4
@ BB#5:                                 @ %._crit_edge
	add	r0, sp, #8
	mov	r5, #0
	str	r5, [sp, #20]
	bl	_ZNSt6chrono3_V212system_clock3nowEv
	movw	r0, #36852
	movt	r0, #976
.LBB0_6:                                @ =>This Inner Loop Header: Depth=1
	mov	r1, r4
	ldr	r2, [r1, r5]!
	add	r5, r5, #4
	ldmib	r1, {r3, r7}
	rsb	r6, r2, #1
	cmp	r2, #0
	subgt	r6, r2, #1
	rsb	r2, r3, #1
	cmp	r3, #0
	ldr	r1, [r1, #12]
	subgt	r2, r3, #1
	rsb	r3, r7, #1
	cmp	r7, #0
	add	r2, r2, r6
	subgt	r3, r7, #1
	cmp	r1, #0
	add	r2, r2, r3
	rsb	r3, r1, #1
	subgt	r3, r1, #1
	cmn	r2, r3
	ldreq	r1, [sp, #20]
	addeq	r1, r1, #1
	streq	r1, [sp, #20]
	cmp	r5, r0
	bne	.LBB0_6
@ BB#7:
	mov	r0, sp
	bl	_ZNSt6chrono3_V212system_clock3nowEv
.Ltmp3:
	movw	r0, :lower16:_ZSt4cout
	movw	r1, :lower16:.L.str
	movt	r0, :upper16:_ZSt4cout
	movt	r1, :upper16:.L.str
	mov	r2, #6
	bl	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
.Ltmp4:
@ BB#8:
	ldr	r0, [sp, #8]
	ldr	r1, [sp, #12]
	ldm	sp, {r2, r3}
	subs	r0, r2, r0
	sbc	r1, r3, r1
	bl	__aeabi_l2d
	vldr	d16, .LCPI0_0
	vmov	d17, r0, r1
	vmul.f64	d0, d17, d16
.Ltmp5:
	movw	r0, :lower16:_ZSt4cout
	movt	r0, :upper16:_ZSt4cout
	bl	_ZNSo9_M_insertIdEERSoT_
	mov	r5, r0
.Ltmp6:
@ BB#9:                                 @ %_ZNSolsEd.exit
.Ltmp7:
	movw	r1, :lower16:.L.str1
	mov	r0, r5
	movt	r1, :upper16:.L.str1
	mov	r2, #9
	bl	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
.Ltmp8:
@ BB#10:                                @ %_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc.exit8
	ldr	r1, [sp, #20]
.Ltmp9:
	mov	r0, r5
	bl	_ZNSo9_M_insertImEERSoT_
.Ltmp10:
@ BB#11:                                @ %_ZNSolsEj.exit
.Ltmp11:
	movw	r1, :lower16:.L.str2
	mov	r2, #1
	movt	r1, :upper16:.L.str2
	bl	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
.Ltmp12:
@ BB#12:                                @ %_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc.exit
	cmp	r4, #0
	beq	.LBB0_14
@ BB#13:
	mov	r0, r4
	bl	_ZdlPv
.LBB0_14:                               @ %_ZNSt6vectorIiSaIiEED2Ev.exit
	mov	r0, #0
	sub	sp, r11, #24
	pop	{r4, r5, r6, r7, r8, r10, r11, pc}
.LBB0_15:
.Ltmp13:
	mov	r5, r0
	cmp	r4, #0
	beq	.LBB0_18
@ BB#16:
	mov	r0, r4
	bl	_ZdlPv
	mov	r0, r5
	bl	_Unwind_Resume
.LBB0_17:
.Ltmp2:
	mov	r5, r0
.LBB0_18:                               @ %_ZNSt6vectorIiSaIiEED2Ev.exit10
	mov	r0, r5
	bl	_Unwind_Resume
	.align	3
@ BB#19:
.LCPI0_0:
	.long	3894859413              @ double 1.0000000000000001E-9
	.long	1041313291
.Ltmp14:
	.size	main, .Ltmp14-main
.Leh_func_end0:
	.globl	__gxx_personality_v0
	.personality __gxx_personality_v0
	.handlerdata
	.align	2
GCC_except_table0:
.Lexception0:
	.byte	255                     @ @LPStart Encoding = omit
	.byte	0                       @ @TType Encoding = absptr
	.asciz	"\320"                  @ @TType base offset
	.byte	3                       @ Call site Encoding = udata4
	.byte	78                      @ Call site table length
.Lset0 = .Ltmp0-.Leh_func_begin0        @ >> Call Site 1 <<
	.long	.Lset0
.Lset1 = .Ltmp1-.Ltmp0                  @   Call between .Ltmp0 and .Ltmp1
	.long	.Lset1
.Lset2 = .Ltmp2-.Leh_func_begin0        @     jumps to .Ltmp2
	.long	.Lset2
	.byte	0                       @   On action: cleanup
.Lset3 = .Ltmp1-.Leh_func_begin0        @ >> Call Site 2 <<
	.long	.Lset3
.Lset4 = .Ltmp3-.Ltmp1                  @   Call between .Ltmp1 and .Ltmp3
	.long	.Lset4
	.long	0                       @     has no landing pad
	.byte	0                       @   On action: cleanup
.Lset5 = .Ltmp3-.Leh_func_begin0        @ >> Call Site 3 <<
	.long	.Lset5
.Lset6 = .Ltmp4-.Ltmp3                  @   Call between .Ltmp3 and .Ltmp4
	.long	.Lset6
.Lset7 = .Ltmp13-.Leh_func_begin0       @     jumps to .Ltmp13
	.long	.Lset7
	.byte	0                       @   On action: cleanup
.Lset8 = .Ltmp4-.Leh_func_begin0        @ >> Call Site 4 <<
	.long	.Lset8
.Lset9 = .Ltmp5-.Ltmp4                  @   Call between .Ltmp4 and .Ltmp5
	.long	.Lset9
	.long	0                       @     has no landing pad
	.byte	0                       @   On action: cleanup
.Lset10 = .Ltmp5-.Leh_func_begin0       @ >> Call Site 5 <<
	.long	.Lset10
.Lset11 = .Ltmp12-.Ltmp5                @   Call between .Ltmp5 and .Ltmp12
	.long	.Lset11
.Lset12 = .Ltmp13-.Leh_func_begin0      @     jumps to .Ltmp13
	.long	.Lset12
	.byte	0                       @   On action: cleanup
.Lset13 = .Ltmp12-.Leh_func_begin0      @ >> Call Site 6 <<
	.long	.Lset13
.Lset14 = .Leh_func_end0-.Ltmp12        @   Call between .Ltmp12 and .Leh_func_end0
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
.Leh_func_begin1:
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
	beq	.LBB1_6
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
.LBB1_2:                                @ =>This Inner Loop Header: Depth=1
	cmp	r1, #624
	blo	.LBB1_4
@ BB#3:                                 @   in Loop: Header=BB1_2 Depth=1
	mov	r0, r5
	bl	_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv
	ldr	r1, [r5, #2496]
.LBB1_4:                                @ %_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv.exit2
                                        @   in Loop: Header=BB1_2 Depth=1
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
	bhs	.LBB1_2
@ BB#5:
	mov	r1, r8
	bl	__aeabi_uidiv
	b	.LBB1_9
.LBB1_6:
	ldr	r0, [r5, #2496]
	cmp	r0, #624
	blo	.LBB1_8
@ BB#7:
	mov	r0, r5
	bl	_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv
	ldr	r0, [r5, #2496]
.LBB1_8:                                @ %_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEclEv.exit
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
.LBB1_9:
	ldr	r1, [r9]
	add	r0, r1, r0
	pop	{r4, r5, r6, r7, r8, r9, r11, pc}
.Ltmp15:
	.size	_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_RKNS0_10param_typeE, .Ltmp15-_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EEEEiRT_RKNS0_10param_typeE
	.cantunwind
	.fnend

	.section	.text._ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv,"axG",%progbits,_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv,comdat
	.weak	_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv
	.align	2
	.type	_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv,%function
_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv: @ @_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv
	.fnstart
.Leh_func_begin2:
@ BB#0:
	.save	{r4, r5, r11, lr}
	push	{r4, r5, r11, lr}
	ldr	lr, [r0]
	movw	r12, #45279
	mov	r2, #0
	movt	r12, #39176
.LBB2_1:                                @ =>This Inner Loop Header: Depth=1
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
	bne	.LBB2_1
@ BB#2:                                 @ %.preheader
	ldr	r4, [r0, #908]
	mov	r2, #0
.LBB2_3:                                @ =>This Inner Loop Header: Depth=1
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
	bne	.LBB2_3
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
.Ltmp16:
	.size	_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv, .Ltmp16-_ZNSt23mersenne_twister_engineIjLj32ELj624ELj397ELj31ELj2567483615ELj11ELj4294967295ELj7ELj2636928640ELj15ELj4022730752ELj18ELj1812433253EE11_M_gen_randEv
	.cantunwind
	.fnend

	.section	.text.startup,"ax",%progbits
	.align	2
	.type	_GLOBAL__sub_I_minus_abs_plus.cpp,%function
_GLOBAL__sub_I_minus_abs_plus.cpp:      @ @_GLOBAL__sub_I_minus_abs_plus.cpp
	.fnstart
.Leh_func_begin3:
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
.Ltmp17:
	.size	_GLOBAL__sub_I_minus_abs_plus.cpp, .Ltmp17-_GLOBAL__sub_I_minus_abs_plus.cpp
.Leh_func_end3:
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
	.long	_GLOBAL__sub_I_minus_abs_plus.cpp(target1)

	.ident	"Debian clang version 3.5.0-10 (tags/RELEASE_350/final) (based on LLVM 3.5.0)"
