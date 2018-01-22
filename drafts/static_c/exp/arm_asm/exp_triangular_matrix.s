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
	.file	"exp_triangular_matrix.c"
	.section	.text.startup,"ax",%progbits
	.align	2
	.global	main
	.thumb
	.thumb_func
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 368
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, r5, lr}
	movw	r4, #:lower16:.LANCHOR0
	fstmfdd	sp!, {d8, d9, d10, d11, d12, d13, d14, d15}
	movt	r4, #:upper16:.LANCHOR0
	mov	r1, r4
	movs	r2, #200
	adds	r4, r4, #200
	sub	sp, sp, #404
	add	r0, sp, #200
	add	r5, sp, #160
	bl	memcpy
	fldd	d7, [sp, #200]
	ldmia	r4!, {r0, r1, r2, r3}
	fldd	d6, [sp, #240]
	fstd	d7, [sp, #72]
	fldd	d5, [sp, #248]
	fstd	d6, [sp, #56]
	fldd	d4, [sp, #280]
	fldd	d13, [sp, #288]
	fldd	d1, [sp, #296]
	fldd	d9, [sp, #320]
	fldd	d6, [sp, #328]
	fldd	d2, [sp, #336]
	fldd	d10, [sp, #344]
	fldd	d7, [sp, #360]
	fstd	d5, [sp, #80]
	fcpyd	d12, d7
	fldd	d7, [sp, #368]
	fstd	d1, [sp, #96]
	fcpyd	d1, d7
	fldd	d7, [sp, #376]
	fldd	d5, [sp, #384]
	fldd	d11, [sp, #392]
	stmia	r5!, {r0, r1, r2, r3}
	ldmia	r4!, {r0, r1, r2, r3}
	fcpyd	d14, d5
	fldd	d3, .L3
	fstd	d4, [sp, #88]
	stmia	r5!, {r0, r1, r2, r3}
	ldmia	r4, {r0, r1}
	fmuld	d4, d7, d3
	fstd	d7, [sp, #120]
	stmia	r5, {r0, r1}
	movw	r0, #:lower16:.LC2
	fldd	d0, [sp, #160]
	movt	r0, #:upper16:.LC2
	fldd	d15, [sp, #168]
	fldd	d7, [sp, #176]
	fldd	d8, [sp, #184]
	fldd	d5, [sp, #192]
	fstd	d0, [sp, #136]
	fmuld	d0, d5, d3
	fstd	d5, [sp, #144]
	fstd	d12, [sp, #104]
	fstd	d1, [sp, #112]
	fstd	d14, [sp, #128]
	fmuld	d5, d12, d3
	fcpyd	d12, d0
	fmscd	d12, d11, d8
	fmuld	d1, d1, d3
	fcpyd	d8, d12
	fcpyd	d12, d4
	fmscd	d12, d2, d11
	fcpyd	d2, d1
	fstd	d12, [sp, #48]
	fmscd	d2, d6, d11
	fcpyd	d6, d5
	fstd	d2, [sp, #40]
	fmscd	d6, d9, d11
	fcpyd	d9, d0
	fstd	d6, [sp, #64]
	fmscd	d9, d11, d7
	fmuld	d14, d14, d3
	fmuld	d3, d11, d3
	fcpyd	d12, d9
	fstd	d3, [sp, #32]
	fcpyd	d9, d14
	fmscd	d9, d10, d11
	fldd	d10, [sp, #48]
	fsubd	d14, d3, d14
	fldd	d3, [sp, #88]
	fstd	d8, [sp, #88]
	fcpyd	d2, d1
	fmuld	d6, d14, d10
	fldd	d10, [sp, #64]
	fmscd	d2, d13, d11
	fldd	d13, [sp, #40]
	fcpyd	d7, d9
	fmuld	d13, d14, d13
	fmuld	d8, d14, d8
	fcpyd	d9, d5
	fmuld	d14, d14, d10
	fcpyd	d10, d0
	fmscd	d9, d3, d11
	fldd	d3, [sp, #96]
	fmscd	d10, d11, d15
	fcpyd	d15, d4
	fmscd	d15, d3, d11
	fldd	d3, [sp, #32]
	fstd	d15, [sp, #96]
	fsubd	d4, d3, d4
	fldd	d3, [sp, #56]
	fcpyd	d15, d5
	fmscd	d15, d3, d11
	fldd	d3, [sp, #32]
	fstd	d15, [sp, #152]
	fcpyd	d15, d8
	fmscd	d15, d7, d12
	fcpyd	d12, d13
	fstd	d15, [sp, #56]
	fmscd	d12, d7, d2
	fcpyd	d15, d6
	fcpyd	d2, d14
	fmscd	d15, d7, d4
	fmscd	d2, d7, d9
	fldd	d9, [sp, #136]
	fcpyd	d4, d15
	fcpyd	d15, d2
	fldd	d2, [sp, #80]
	fsubd	d3, d3, d1
	fmscd	d1, d2, d11
	fldd	d2, [sp, #72]
	fmscd	d5, d2, d11
	fcpyd	d2, d8
	fmscd	d2, d7, d10
	fmscd	d0, d11, d9
	fstd	d2, [sp, #32]
	fldd	d9, [sp, #96]
	fcpyd	d2, d13
	fmscd	d6, d7, d9
	fldd	d9, [sp, #152]
	fmscd	d2, d7, d3
	fcpyd	d3, d14
	fmscd	d3, d7, d9
	fcpyd	d10, d3
	fldd	d3, [sp, #56]
	fmscd	d8, d7, d0
	fmuld	d9, d4, d3
	fmuld	d3, d4, d12
	fmscd	d14, d7, d5
	fcpyd	d0, d13
	fldd	d13, [sp, #32]
	fcpyd	d5, d9
	fmscd	d5, d6, d13
	fcpyd	d13, d3
	fmscd	d13, d6, d2
	fmuld	d4, d4, d15
	fmscd	d0, d1, d7
	fcpyd	d2, d13
	fcpyd	d13, d4
	fmscd	d13, d6, d10
	fldd	d10, [sp, #48]
	fmscd	d3, d0, d6
	fmscd	d4, d6, d14
	fldd	d14, [sp, #128]
	fmscd	d9, d6, d8
	fmuld	d1, d2, d5
	fmuld	d2, d2, d13
	fmscd	d1, d3, d9
	fmscd	d2, d3, d4
	fldd	d4, [sp, #144]
	fdivd	d2, d1, d2
	fldd	d1, [sp, #64]
	fnmacd	d5, d2, d13
	fldd	d13, [sp, #40]
	fmrrd	r2, r3, d2
	fdivd	d3, d5, d3
	fldd	d5, [sp, #56]
	fnmacd	d5, d2, d15
	fstd	d3, [sp]
	fnmacd	d5, d3, d12
	fldd	d12, [sp, #104]
	fdivd	d5, d5, d6
	fldd	d6, [sp, #88]
	fnmacd	d6, d2, d1
	fldd	d1, [sp, #112]
	fstd	d5, [sp, #8]
	fnmacd	d6, d3, d13
	fnmacd	d6, d5, d10
	fnmacd	d4, d12, d2
	fdivd	d6, d6, d7
	fnmacd	d4, d1, d3
	fstd	d6, [sp, #16]
	fcpyd	d7, d4
	fldd	d4, [sp, #120]
	fnmacd	d7, d4, d5
	fnmacd	d7, d14, d6
	fdivd	d11, d7, d11
	fstd	d11, [sp, #24]
	bl	printf
	movs	r0, #0
	add	sp, sp, #404
	@ sp needed
	fldmfdd	sp!, {d8-d15}
	pop	{r4, r5, pc}
.L4:
	.align	3
.L3:
	.word	0
	.word	0
	.size	main, .-main
	.section	.rodata
	.align	3
.LANCHOR0 = . + 0
.LC0:
	.word	858993459
	.word	1075524403
	.word	858993459
	.word	-1072155853
	.word	-858993459
	.word	-1076048692
	.word	171798692
	.word	1075880919
	.word	1030792151
	.word	-1071425782
	.word	-1374389535
	.word	-1073684153
	.word	1717986918
	.word	-1073060250
	.word	171798692
	.word	1074045911
	.word	2061584302
	.word	1074114068
	.word	687194767
	.word	-1072394404
	.word	171798692
	.word	1075225559
	.word	-687194767
	.word	1075146915
	.word	-1717986918
	.word	-1073374823
	.word	1717986918
	.word	1074882150
	.word	1889785610
	.word	-1071838659
	.word	-1374389535
	.word	1075306823
	.word	1546188227
	.word	-1072577905
	.word	343597384
	.word	1070679982
	.word	2061584302
	.word	-1071862252
	.word	-2061584302
	.word	1075335659
	.word	-1889785610
	.word	1075869122
	.word	343597384
	.word	1072777134
	.word	-515396076
	.word	1075975290
	.word	1374389535
	.word	1073815224
	.word	1202590843
	.word	-1071940895
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
