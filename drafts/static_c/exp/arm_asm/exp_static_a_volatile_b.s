	.syntax unified
	.arch armv7-a
	.eabi_attribute 27, 3
	.eabi_attribute 28, 1
	.fpu vfpv3-d16
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 2
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.thumb
	.file	"exp_static_a_volatile_b.c"
	.section	.text.startup,"ax",%progbits
	.align	2
	.global	main
	.thumb
	.thumb_func
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 40
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, r5, lr}
	movw	r4, #:lower16:.LANCHOR0
	fstmfdd	sp!, {d8, d9, d10, d11, d12, d13, d14, d15}
	movt	r4, #:upper16:.LANCHOR0
	ldmia	r4!, {r0, r1, r2, r3}
	fldd	d1, .L3
	sub	sp, sp, #76
	add	r5, sp, #32
	fldd	d14, .L3+8
	stmia	r5!, {r0, r1, r2, r3}
	ldmia	r4!, {r0, r1, r2, r3}
	fldd	d3, .L3+16
	stmia	r5!, {r0, r1, r2, r3}
	ldmia	r4, {r0, r1}
	fldd	d4, .L3+24
	stmia	r5, {r0, r1}
	movw	r0, #:lower16:.LC2
	fldd	d0, [sp, #32]
	movt	r0, #:upper16:.LC2
	fldd	d8, [sp, #40]
	fldd	d9, [sp, #48]
	fldd	d10, [sp, #56]
	fldd	d13, [sp, #64]
	fldd	d2, .L3+32
	fmuld	d1, d13, d1
	fldd	d5, .L3+40
	fldd	d15, .L3+48
	fldd	d6, .L3+56
	fldd	d7, .L3+64
	fldd	d11, .L3+72
	fldd	d12, .L3+80
	fmscd	d1, d10, d14
	fmuld	d3, d13, d3
	fmuld	d4, d13, d4
	fmscd	d3, d9, d14
	fldd	d9, .L3+88
	fcpyd	d10, d1
	fldd	d1, .L3+96
	fmuld	d2, d10, d2
	fmscd	d4, d8, d14
	fldd	d8, .L3+104
	fmuld	d5, d13, d5
	fmscd	d2, d3, d15
	fldd	d3, .L3+112
	fmuld	d6, d10, d6
	fmscd	d5, d0, d14
	fldd	d0, .L3+120
	fmscd	d6, d4, d15
	fldd	d4, .L3+128
	fmuld	d7, d10, d7
	fmuld	d11, d2, d11
	fmscd	d7, d5, d15
	fldd	d5, .L3+136
	fmuld	d12, d2, d12
	fmscd	d11, d6, d5
	fldd	d6, .L3+144
	fmscd	d12, d7, d5
	fldd	d5, .L3+152
	fldd	d7, .L3+160
	fmuld	d1, d11, d1
	fmscd	d1, d12, d8
	fdivd	d3, d1, d3
	fldd	d1, .L3+168
	fnmacd	d11, d3, d0
	fldd	d0, .L3+176
	fmrrd	r2, r3, d3
	fdivd	d11, d11, d8
	fnmacd	d2, d3, d9
	fstd	d11, [sp]
	fnmacd	d2, d11, d1
	fldd	d1, .L3+136
	fdivd	d2, d2, d1
	fcpyd	d1, d10
	fstd	d2, [sp, #8]
	fnmacd	d1, d3, d0
	fldd	d0, .L3+184
	fnmacd	d1, d11, d0
	fldd	d0, .L3+192
	fnmacd	d1, d2, d0
	fnmacd	d13, d3, d4
	fdivd	d1, d1, d15
	fnmacd	d13, d11, d5
	fstd	d1, [sp, #16]
	fnmacd	d13, d2, d6
	fnmacd	d13, d1, d7
	fdivd	d14, d13, d14
	fstd	d14, [sp, #24]
	bl	printf
	movs	r0, #0
	add	sp, sp, #76
	@ sp needed
	fldmfdd	sp!, {d8-d15}
	pop	{r4, r5, pc}
.L4:
	.align	3
.L3:
	.word	-2061584302
	.word	1075335659
	.word	1202590843
	.word	-1071940895
	.word	1889785610
	.word	-1071838659
	.word	687194767
	.word	-1072394404
	.word	700938662
	.word	-1070812614
	.word	1030792151
	.word	-1071425782
	.word	-577243605
	.word	1078075283
	.word	886481250
	.word	-1071744785
	.word	54975582
	.word	-1069401224
	.word	236911768
	.word	1082328925
	.word	-1811830240
	.word	1083368220
	.word	1742044232
	.word	-1065275150
	.word	1087982832
	.word	1096468689
	.word	-2109574618
	.word	1095227578
	.word	-771634347
	.word	-1027562791
	.word	2081240824
	.word	1095358424
	.word	-1889785610
	.word	1075869122
	.word	-1018708519
	.word	1084323836
	.word	-515396076
	.word	1075975290
	.word	343597384
	.word	1072777134
	.word	1374389535
	.word	1073815224
	.word	-1845343351
	.word	-1064953704
	.word	-501652180
	.word	-1068055720
	.word	-384829069
	.word	1077407671
	.word	-2144047675
	.word	-1068734281
	.size	main, .-main
	.section	.rodata
	.align	3
.LANCHOR0 = . + 0
.LC1:
	.word	-515396076
	.word	1074795642
	.word	1546188227
	.word	1075364495
	.word	-687194767
	.word	-1071615837
	.word	343597384
	.word	-1071757394
	.word	-1546188227
	.word	-1073201808
	.section	.rodata.str1.4,"aMS",%progbits,1
	.align	2
.LC2:
	.ascii	"%f, %f, %f, %f, %f\012\000"
	.ident	"GCC: (Debian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",%progbits
