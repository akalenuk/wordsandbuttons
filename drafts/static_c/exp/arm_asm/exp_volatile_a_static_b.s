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
	.file	"exp_volatile_a_static_b.c"
	.section	.text.startup,"ax",%progbits
	.align	2
	.global	main
	.thumb
	.thumb_func
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 368
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{lr}
	movw	r1, #:lower16:.LANCHOR0
	fstmfdd	sp!, {d8, d9, d10, d11, d12, d13, d14, d15}
	movt	r1, #:upper16:.LANCHOR0
	movs	r2, #200
	sub	sp, sp, #404
	add	r0, sp, #200
	bl	memcpy
	fldd	d7, [sp, #200]
	movw	r0, #:lower16:.LC2
	movt	r0, #:upper16:.LC2
	fldd	d6, [sp, #208]
	fldd	d5, [sp, #216]
	fldd	d3, [sp, #224]
	fldd	d12, [sp, #232]
	fldd	d2, [sp, #240]
	fldd	d1, [sp, #248]
	fldd	d8, [sp, #256]
	fstd	d7, [sp, #120]
	fstd	d8, [sp, #136]
	fldd	d8, [sp, #264]
	fldd	d13, [sp, #272]
	fldd	d9, [sp, #280]
	fldd	d10, [sp, #288]
	fldd	d11, [sp, #296]
	fldd	d14, [sp, #304]
	fstd	d6, [sp, #96]
	fstd	d5, [sp, #104]
	fldd	d6, [sp, #312]
	fstd	d14, [sp, #64]
	fldd	d7, [sp, #320]
	fldd	d14, [sp, #328]
	fldd	d15, [sp, #336]
	fldd	d5, [sp, #344]
	fstd	d3, [sp, #72]
	fstd	d2, [sp, #112]
	fstd	d1, [sp, #128]
	fstd	d9, [sp, #144]
	fstd	d10, [sp, #152]
	fstd	d11, [sp, #160]
	fstd	d5, [sp, #176]
	fldd	d11, [sp, #352]
	fstd	d7, [sp, #168]
	fldd	d7, [sp, #360]
	fldd	d3, .L3
	fcpyd	d4, d7
	fldd	d7, [sp, #368]
	fstd	d4, [sp, #32]
	fcpyd	d5, d7
	fldd	d7, [sp, #376]
	fmuld	d0, d11, d5
	fstd	d5, [sp, #40]
	fcpyd	d1, d7
	fmuld	d7, d11, d3
	fldd	d3, [sp, #384]
	fstd	d1, [sp, #48]
	fcpyd	d9, d3
	fstd	d7, [sp, #80]
	fmuld	d2, d13, d9
	fldd	d7, [sp, #392]
	fldd	d3, .L3+8
	fstd	d9, [sp, #88]
	fmuld	d5, d6, d9
	fmuld	d1, d11, d1
	fcpyd	d10, d2
	fldd	d2, [sp, #80]
	fmscd	d10, d8, d7
	fcpyd	d8, d0
	fldd	d0, [sp, #88]
	fmscd	d8, d14, d7
	fldd	d14, [sp, #64]
	fmscd	d5, d14, d7
	fstd	d8, [sp, #56]
	fcpyd	d14, d1
	fldd	d1, [sp, #48]
	fmscd	d14, d15, d7
	fldd	d15, [sp, #72]
	fmuld	d4, d11, d4
	fstd	d14, [sp, #64]
	fldd	d14, [sp, #168]
	fmscd	d2, d7, d3
	fcpyd	d3, d4
	fldd	d4, [sp, #32]
	fmscd	d3, d14, d7
	fldd	d14, [sp, #176]
	fstd	d2, [sp, #80]
	fldd	d2, .L3+16
	fmuld	d9, d12, d9
	fstd	d3, [sp, #72]
	fldd	d3, [sp, #40]
	fmuld	d8, d13, d1
	fmuld	d11, d11, d0
	fmuld	d0, d6, d3
	fmuld	d1, d12, d1
	fmscd	d9, d15, d7
	fldd	d15, .L3
	fmscd	d11, d14, d7
	fmuld	d3, d6, d15
	fldd	d15, [sp, #136]
	fcpyd	d14, d8
	fldd	d8, [sp, #152]
	fmscd	d14, d15, d7
	fcpyd	d15, d0
	fldd	d0, [sp, #104]
	fmscd	d15, d8, d7
	fmuld	d4, d6, d4
	fcpyd	d8, d1
	fldd	d1, [sp, #48]
	fmscd	d8, d0, d7
	fldd	d0, [sp, #144]
	fmscd	d3, d7, d2
	fstd	d8, [sp, #104]
	fmscd	d4, d0, d7
	fldd	d0, [sp, #32]
	fstd	d3, [sp, #152]
	fldd	d3, [sp, #40]
	fmuld	d8, d12, d0
	fstd	d4, [sp, #168]
	fmuld	d6, d6, d1
	fstd	d8, [sp, #192]
	fldd	d1, .L3+24
	fldd	d8, [sp, #56]
	fmuld	d4, d12, d3
	fldd	d3, .L3
	fmuld	d2, d13, d3
	fmuld	d3, d13, d0
	fldd	d0, [sp, #160]
	fmscd	d6, d0, d7
	fldd	d0, .L3
	fstd	d6, [sp, #136]
	fldd	d6, [sp, #96]
	fmscd	d2, d7, d1
	fmscd	d4, d6, d7
	fldd	d6, [sp, #64]
	fstd	d2, [sp, #160]
	fldd	d2, [sp, #112]
	fstd	d4, [sp, #144]
	fmuld	d4, d10, d6
	fmuld	d12, d12, d0
	fmscd	d4, d11, d14
	fstd	d12, [sp, #184]
	fcpyd	d12, d3
	fmuld	d8, d8, d5
	fmscd	d12, d2, d7
	fcpyd	d14, d4
	fstd	d12, [sp, #176]
	fcpyd	d4, d8
	fldd	d12, [sp, #80]
	fmscd	d4, d11, d15
	fldd	d8, [sp, #152]
	fldd	d15, [sp, #104]
	fmuld	d0, d5, d12
	fstd	d4, [sp, #96]
	fmuld	d1, d6, d9
	fldd	d6, [sp, #40]
	fmuld	d3, d13, d6
	fldd	d13, [sp, #72]
	fldd	d6, .L3+32
	fmuld	d2, d5, d13
	fcpyd	d4, d0
	fmscd	d4, d11, d8
	fldd	d8, [sp, #168]
	fmscd	d2, d11, d8
	fstd	d4, [sp, #104]
	fldd	d4, [sp, #64]
	fldd	d8, [sp, #56]
	fmscd	d1, d11, d15
	fstd	d2, [sp, #112]
	fldd	d2, [sp, #192]
	fmuld	d5, d5, d4
	fldd	d4, [sp, #120]
	fmscd	d2, d4, d7
	fcpyd	d15, d1
	fldd	d1, [sp, #128]
	fmuld	d8, d8, d9
	fstd	d2, [sp, #120]
	fldd	d2, [sp, #56]
	fmscd	d3, d1, d7
	fldd	d1, [sp, #184]
	fcpyd	d0, d12
	fmuld	d12, d10, d12
	fmuld	d13, d10, d13
	fmscd	d1, d7, d6
	fldd	d6, [sp, #136]
	fmscd	d5, d11, d6
	fldd	d6, [sp, #144]
	fmscd	d8, d11, d6
	fldd	d6, [sp, #160]
	fmscd	d12, d11, d6
	fldd	d6, [sp, #176]
	fmscd	d13, d11, d6
	fldd	d6, [sp, #72]
	fmuld	d2, d10, d2
	fcpyd	d4, d3
	fldd	d3, [sp, #96]
	fmuld	d10, d9, d0
	fmuld	d9, d9, d6
	fldd	d6, [sp, #104]
	fldd	d0, [sp, #112]
	fmuld	d0, d14, d0
	fmuld	d6, d14, d6
	fmuld	d3, d3, d15
	fmscd	d2, d4, d11
	fldd	d4, [sp, #120]
	fmscd	d10, d11, d1
	fmscd	d9, d11, d4
	fmscd	d0, d5, d13
	fldd	d13, [sp, #96]
	fmscd	d6, d5, d12
	fldd	d12, [sp, #104]
	fmuld	d4, d14, d13
	fldd	d14, [sp, #112]
	fmscd	d3, d5, d8
	fmuld	d1, d15, d14
	fmuld	d8, d15, d12
	fmscd	d4, d2, d5
	fmscd	d8, d5, d10
	fldd	d10, [sp, #80]
	fmscd	d1, d5, d9
	fmuld	d2, d3, d6
	fmuld	d3, d3, d0
	fmscd	d2, d4, d8
	fmscd	d3, d4, d1
	fldd	d1, [sp, #48]
	fdivd	d3, d2, d3
	fldd	d2, [sp, #56]
	fnmacd	d6, d3, d0
	fldd	d0, [sp, #32]
	fmrrd	r2, r3, d3
	fdivd	d4, d6, d4
	fnmacd	d12, d3, d14
	fstd	d4, [sp]
	fcpyd	d6, d12
	fnmacd	d6, d4, d13
	fldd	d13, [sp, #72]
	fdivd	d6, d6, d5
	fldd	d5, [sp, #64]
	fnmacd	d10, d3, d13
	fstd	d6, [sp, #8]
	fnmacd	d10, d4, d2
	fnmacd	d10, d6, d5
	fldd	d5, .L3
	fnmacd	d5, d0, d3
	fldd	d3, [sp, #40]
	fldd	d0, [sp, #88]
	fdivd	d10, d10, d11
	fnmacd	d5, d3, d4
	fstd	d10, [sp, #16]
	fnmacd	d5, d1, d6
	fcpyd	d6, d5
	fnmacd	d6, d0, d10
	fdivd	d7, d6, d7
	fstd	d7, [sp, #24]
	bl	printf
	movs	r0, #0
	add	sp, sp, #404
	@ sp needed
	fldmfdd	sp!, {d8-d15}
	ldr	pc, [sp], #4
.L4:
	.align	3
.L3:
	.word	-1546188227
	.word	-1073201808
	.word	343597384
	.word	-1071757394
	.word	-687194767
	.word	-1071615837
	.word	1546188227
	.word	1075364495
	.word	-515396076
	.word	1074795642
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
	.section	.rodata.str1.4,"aMS",%progbits,1
	.align	2
.LC2:
	.ascii	"%f, %f, %f, %f, %f\012\000"
	.ident	"GCC: (Debian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",%progbits
