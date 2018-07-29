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
	.file	"exp_runtime.c"
	.text
	.align	2
	.global	aijn
	.thumb
	.thumb_func
	.type	aijn, %function
aijn:
	@ args = 8, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, r5, r6, r7, r8, r9, r10, lr}
	mov	r5, r0
	fstmfdd	sp!, {d8, d9}
	mov	lr, r2
	mov	r9, r3
	sub	sp, sp, #8
	ldr	r4, [sp, #56]
	ldr	r6, [sp, #60]
	cmp	r4, r6
	beq	.L6
	add	r10, r4, #1
	str	r6, [sp, #4]
	str	r10, [sp]
	mov	r7, r1
	mov	r8, r2
	bl	aijn
	mov	r0, r5
	mov	r1, r7
	mov	r2, r4
	mov	r3, r4
	str	r10, [sp]
	str	r6, [sp, #4]
	fcpyd	d8, d0
	bl	aijn
	mov	r2, r8
	mov	r0, r5
	mov	r1, r7
	mov	r3, r4
	str	r10, [sp]
	str	r6, [sp, #4]
	fmuld	d8, d8, d0
	bl	aijn
	str	r10, [sp]
	mov	r0, r5
	str	r6, [sp, #4]
	mov	r1, r7
	mov	r2, r4
	mov	r3, r9
	fcpyd	d9, d0
	bl	aijn
	fnmacd	d8, d9, d0
	fcpyd	d0, d8
	add	sp, sp, #8
	@ sp needed
	fldmfdd	sp!, {d8-d9}
	pop	{r4, r5, r6, r7, r8, r9, r10, pc}
.L6:
	mla	r4, r2, r4, r3
	add	r5, r0, r4, lsl #3
	fldd	d0, [r5]
	add	sp, sp, #8
	@ sp needed
	fldmfdd	sp!, {d8-d9}
	pop	{r4, r5, r6, r7, r8, r9, r10, pc}
	.size	aijn, .-aijn
	.align	2
	.global	bin
	.thumb
	.thumb_func
	.type	bin, %function
bin:
	@ args = 4, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, r5, r6, r7, r8, r9, lr}
	mov	r5, r1
	fstmfdd	sp!, {d8, d9}
	mov	r4, r3
	sub	sp, sp, #12
	ldr	r6, [sp, #56]
	cmp	r3, r6
	beq	.L11
	add	r9, r3, #1
	mov	r8, r2
	str	r6, [sp, #4]
	mov	r2, r3
	str	r9, [sp]
	mov	r7, r0
	bl	aijn
	mov	r3, r9
	mov	r0, r7
	mov	r1, r5
	mov	r2, r8
	str	r6, [sp]
	fcpyd	d8, d0
	bl	bin
	mov	r2, r8
	mov	r0, r7
	mov	r1, r5
	mov	r3, r4
	str	r9, [sp]
	str	r6, [sp, #4]
	fmuld	d8, d8, d0
	bl	aijn
	mov	r3, r9
	str	r6, [sp]
	mov	r0, r7
	mov	r1, r5
	mov	r2, r4
	fcpyd	d9, d0
	bl	bin
	fnmacd	d8, d9, d0
	fcpyd	d0, d8
	add	sp, sp, #12
	@ sp needed
	fldmfdd	sp!, {d8-d9}
	pop	{r4, r5, r6, r7, r8, r9, pc}
.L11:
	add	r5, r1, r2, lsl #3
	fldd	d0, [r5]
	add	sp, sp, #12
	@ sp needed
	fldmfdd	sp!, {d8-d9}
	pop	{r4, r5, r6, r7, r8, r9, pc}
	.size	bin, .-bin
	.align	2
	.global	solve_xi
	.thumb
	.thumb_func
	.type	solve_xi, %function
solve_xi:
	@ args = 4, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, r5, r6, r7, r8, r9, r10, fp, lr}
	add	r8, r3, #1
	fstmfdd	sp!, {d8}
	mov	r5, r3
	mov	fp, r2
	mov	r2, r3
	mov	r3, r8
	mov	r10, r0
	mov	r9, r1
	sub	sp, sp, #12
	ldr	r7, [sp, #56]
	str	r7, [sp]
	bl	bin
	cmp	r5, #0
	fcpyd	d8, d0
	ble	.L13
	mov	r6, fp
	movs	r4, #0
.L14:
	mov	r3, r4
	str	r8, [sp]
	mov	r0, r10
	str	r7, [sp, #4]
	mov	r1, r9
	mov	r2, r5
	bl	aijn
	fldmiad	r6!, {d7}
	adds	r4, r4, #1
	cmp	r4, r5
	fnmacd	d8, d0, d7
	bne	.L14
.L13:
	mov	r2, r5
	mov	r3, r5
	str	r8, [sp]
	mov	r0, r10
	str	r7, [sp, #4]
	mov	r1, r9
	bl	aijn
	add	r5, fp, r5, lsl #3
	fdivd	d0, d8, d0
	fstd	d0, [r5]
	add	sp, sp, #12
	@ sp needed
	fldmfdd	sp!, {d8}
	pop	{r4, r5, r6, r7, r8, r9, r10, fp, pc}
	.size	solve_xi, .-solve_xi
	.align	2
	.global	runtime_solve
	.thumb
	.thumb_func
	.type	runtime_solve, %function
runtime_solve:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	cmp	r3, #0
	ble	.L23
	push	{r4, r5, r6, r7, r8, lr}
	sub	sp, sp, #8
	mov	r5, r3
	mov	r8, r2
	mov	r7, r1
	mov	r6, r0
	movs	r4, #0
.L18:
	mov	r3, r4
	str	r5, [sp]
	mov	r0, r6
	mov	r1, r7
	mov	r2, r8
	adds	r4, r4, #1
	bl	solve_xi
	cmp	r4, r5
	bne	.L18
	add	sp, sp, #8
	@ sp needed
	pop	{r4, r5, r6, r7, r8, pc}
.L23:
	bx	lr
	.size	runtime_solve, .-runtime_solve
	.section	.text.startup,"ax",%progbits
	.align	2
	.global	main
	.thumb
	.thumb_func
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 280
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, r5, r6, r7, r8, r9, r10, fp, lr}
	movw	r1, #:lower16:.LANCHOR0
	ldr	r6, .L28
	sub	sp, sp, #316
	movt	r1, #:upper16:.LANCHOR0
	movs	r2, #200
	add	r0, sp, #112
	add	r5, sp, #32
	bl	memcpy
	ldmia	r6!, {r0, r1, r2, r3}
	movs	r4, #0
	movs	r7, #5
	stmia	r5!, {r0, r1, r2, r3}
	ldmia	r6!, {r0, r1, r2, r3}
	stmia	r5!, {r0, r1, r2, r3}
	ldmia	r6, {r0, r1}
	stmia	r5, {r0, r1}
.L25:
	mov	r3, r4
	str	r7, [sp]
	add	r0, sp, #112
	add	r1, sp, #32
	add	r2, sp, #72
	adds	r4, r4, #1
	bl	solve_xi
	cmp	r4, #5
	bne	.L25
	ldrd	r10, [sp, #80]
	movw	r0, #:lower16:.LC2
	ldrd	r8, [sp, #88]
	movt	r0, #:upper16:.LC2
	ldrd	r6, [sp, #96]
	ldrd	r4, [sp, #104]
	ldrd	r2, [sp, #72]
	strd	r10, [sp]
	strd	r8, [sp, #8]
	strd	r6, [sp, #16]
	strd	r4, [sp, #24]
	bl	printf
	movs	r0, #0
	add	sp, sp, #316
	@ sp needed
	pop	{r4, r5, r6, r7, r8, r9, r10, fp, pc}
.L29:
	.align	2
.L28:
	.word	.LANCHOR0+200
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
