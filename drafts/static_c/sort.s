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
	.file	"sort.c"
	.section	.text.startup,"ax",%progbits
	.align	2
	.global	main
	.thumb
	.thumb_func
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 32
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, r5, r6, lr}
	movw	r5, #:lower16:.LANCHOR0
	movt	r5, #:upper16:.LANCHOR0
	sub	sp, sp, #32
	ldmia	r5!, {r0, r1, r2, r3}
	mov	r6, sp
	movs	r4, #7
	stmia	r6!, {r0, r1, r2, r3}
	ldmia	r5, {r0, r1, r2, r3}
	stmia	r6, {r0, r1, r2, r3}
.L3:
	cmp	r4, #0
	it	gt
	movgt	r1, #0
	ble	.L5
.L2:
	lsls	r5, r1, #2
	ldr	r0, [sp, r1, lsl #2]
	adds	r5, r5, #4
	ldr	r2, [sp, r5]
	subs	r3, r0, r2
	add	r2, r2, r0
	cmp	r3, #0
	it	lt
	rsblt	r3, r3, #0
	subs	r0, r2, r3
	add	r3, r3, r2
	add	r0, r0, r0, lsr #31
	add	r3, r3, r3, lsr #31
	asrs	r0, r0, #1
	str	r0, [sp, r1, lsl #2]
	cmp	r1, r4
	it	lt
	addlt	r1, r1, #1
	asrs	r3, r3, #1
	cmp	r1, r4
	str	r3, [sp, r5]
	blt	.L2
.L5:
	subs	r4, r4, #1
	bne	.L3
	sub	r4, sp, #4
	add	r5, sp, #28
.L6:
	ldr	r1, [r4, #4]!
	movw	r0, #:lower16:.LC1
	movt	r0, #:upper16:.LC1
	bl	printf
	cmp	r4, r5
	bne	.L6
	movs	r0, #0
	add	sp, sp, #32
	@ sp needed
	pop	{r4, r5, r6, pc}
	.size	main, .-main
	.section	.rodata
	.align	2
.LANCHOR0 = . + 0
.LC0:
	.word	1
	.word	5
	.word	2
	.word	9
	.word	6
	.word	7
	.word	8
	.word	5
	.section	.rodata.str1.4,"aMS",%progbits,1
	.align	2
.LC1:
	.ascii	"%d\000"
	.ident	"GCC: (Debian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",%progbits
