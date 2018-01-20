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
	.file	"exp_static_a_b.c"
	.section	.text.startup,"ax",%progbits
	.align	2
	.global	main
	.thumb
	.thumb_func
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, r5, r6, r7, r8, r9, r10, fp, lr}
	sub	sp, sp, #36
	adr	fp, .L3
	ldrd	r10, [fp]
	movw	r0, #:lower16:.LC2
	adr	r9, .L3+8
	ldrd	r8, [r9]
	movt	r0, #:upper16:.LC2
	adr	r7, .L3+16
	ldrd	r6, [r7]
	adr	r5, .L3+24
	ldrd	r4, [r5]
	adr	r3, .L3+32
	ldrd	r2, [r3]
	strd	r10, [sp]
	strd	r8, [sp, #8]
	strd	r6, [sp, #16]
	strd	r4, [sp, #24]
	bl	printf
	movs	r0, #0
	add	sp, sp, #36
	@ sp needed
	pop	{r4, r5, r6, r7, r8, r9, r10, fp, pc}
.L4:
	.align	3
.L3:
	.word	232640199
	.word	-1075429521
	.word	83248120
	.word	1071841626
	.word	-1063973261
	.word	1073030601
	.word	-1120311528
	.word	1071782572
	.word	87906252
	.word	-1075208333
	.size	main, .-main
	.section	.rodata.str1.4,"aMS",%progbits,1
	.align	2
.LC2:
	.ascii	"%f, %f, %f, %f, %f\012\000"
	.ident	"GCC: (Debian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",%progbits
