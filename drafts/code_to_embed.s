-- andand.s

  movq  %rax, %r14
  .align  16, 0x90
.LBB0_6:
  # =>This Inner Loop Header: Depth=1
  cmpl  $1, -12(%r12,%rbx,4)
  jne  .LBB0_11
# BB#7:    #   in Loop: Header=BB0_6 Depth=1
  cmpl  $1, -8(%r12,%rbx,4)
  jne  .LBB0_11
# BB#8:    #   in Loop: Header=BB0_6 Depth=1
  cmpl  $1, -4(%r12,%rbx,4)
  jne  .LBB0_11
# BB#9:    #   in Loop: Header=BB0_6 Depth=1
  cmpl  $1, (%r12,%rbx,4)
  jne  .LBB0_11
# BB#10:   #   in Loop: Header=BB0_6 Depth=1
  incl  4(%rsp)
  .align  16, 0x90
.LBB0_11:  # %._crit_edge
           #   in Loop: Header=BB0_6 Depth=1
  addq  $1, %rbx
  cmpq  $160000000, %rbx
  jne  .LBB0_6


-- and.s

  movq  %rax, %r14
  .align  16, 0x90
.LBB0_6: 
  # =>This Inner Loop Header: Depth=1
  cmpl  $1, -12(%r12,%rbx,4)
  jne  .LBB0_10
# BB#7:    #   in Loop: Header=BB0_6 Depth=1
  cmpl  $1, -8(%r12,%rbx,4)
  jne  .LBB0_10
# BB#8:    #   in Loop: Header=BB0_6 Depth=1
  cmpl  $1, -4(%r12,%rbx,4)
  jne  .LBB0_10
# BB#9:    #   in Loop: Header=BB0_6 Depth=1
  cmpl  $1, (%r12,%rbx,4)
  jne  .LBB0_10
# BB#20:   #   in Loop: Header=BB0_6 Depth=1
  incl  4(%rsp)
.LBB0_10:  # %.backedge
           #   in Loop: Header=BB0_6 Depth=1
  addq  $1, %rbx
  cmpq  $160000000, %rbx
  jne  .LBB0_6
  

-- andand_double.s

  movq  %rax, %r14
  .align  16, 0x90
.LBB0_6:
  # =>This Inner Loop Header: Depth=1
  vmovsd  -24(%r15,%rbx,8), %xmm0
  vucomisd  .LCPI0_0(%rip), %xmm0
  jne  .LBB0_11
  jp  .LBB0_11
# BB#7:    #   in Loop: Header=BB0_6 Depth=1
  vmovsd  -16(%r15,%rbx,8), %xmm0
  vucomisd  .LCPI0_0(%rip), %xmm0
  jne  .LBB0_11
  jp  .LBB0_11
# BB#8:    #   in Loop: Header=BB0_6 Depth=1
  vmovsd  -8(%r15,%rbx,8), %xmm0
  vucomisd  .LCPI0_0(%rip), %xmm0
  jne  .LBB0_11
  jp  .LBB0_11
# BB#9:    #   in Loop: Header=BB0_6 Depth=1
  vmovsd  (%r15,%rbx,8), %xmm0
  vucomisd  .LCPI0_0(%rip), %xmm0
  jne  .LBB0_11
  jp  .LBB0_11
# BB#10:   #   in Loop: Header=BB0_6 Depth=1
  incl  4(%rsp)
  .align  16, 0x90
.LBB0_11:  # %._crit_edge
           #   in Loop: Header=BB0_6 Depth=1
  addq  $1, %rbx
  cmpq  $160000000, %rbx
  jne  .LBB0_6
  
  
-- andand_float.s

  movq  %rax, %r14
  .align  16, 0x90
.LBB0_6:  
  # =>This Inner Loop Header: Depth=1
  vmovss  -12(%r15,%rbx,4), %xmm0
  vucomiss  .LCPI0_0(%rip), %xmm0
  jne  .LBB0_11
  jp  .LBB0_11
# BB#7:    #   in Loop: Header=BB0_6 Depth=1
  vmovss  -8(%r15,%rbx,4), %xmm0
  vucomiss  .LCPI0_0(%rip), %xmm0
  jne  .LBB0_11
  jp  .LBB0_11
# BB#8:    #   in Loop: Header=BB0_6 Depth=1
  vmovss  -4(%r15,%rbx,4), %xmm0
  vucomiss  .LCPI0_0(%rip), %xmm0
  jne  .LBB0_11
  jp  .LBB0_11
# BB#9:    #   in Loop: Header=BB0_6 Depth=1
  vmovss  (%r15,%rbx,4), %xmm0
  vucomiss  .LCPI0_0(%rip), %xmm0
  jne  .LBB0_11
  jp  .LBB0_11
# BB#10:   #   in Loop: Header=BB0_6 Depth=1
  incl  4(%rsp)
  .align  16, 0x90
.LBB0_11:  # %._crit_edge
           #   in Loop: Header=BB0_6 Depth=1
  addq  $1, %rbx
  cmpq  $160000000, %rbx
  jne  .LBB0_6
  
  
-- compare_zero.s

  movq  %rax, %r14
  .align  16, 0x90
.LBB0_6:
  # =>This Inner Loop Header: Depth=1
  cmpl  $0, -12(%r12,%rbx,4)
  jne  .LBB0_11
# BB#7:    #   in Loop: Header=BB0_6 Depth=1
  cmpl  $0, -8(%r12,%rbx,4)
  jne  .LBB0_11
# BB#8:    #   in Loop: Header=BB0_6 Depth=1
  cmpl  $0, -4(%r12,%rbx,4)
  jne  .LBB0_11
# BB#9:    #   in Loop: Header=BB0_6 Depth=1
  cmpl  $0, (%r12,%rbx,4)
  jne  .LBB0_11
# BB#10:   #   in Loop: Header=BB0_6 Depth=1
  incl  4(%rsp)
  .align  16, 0x90
.LBB0_11:  # %._crit_edge
           #   in Loop: Header=BB0_6 Depth=1
  addq  $1, %rbx
  cmpq  $160000000, %rbx
  jne  .LBB0_6
  
  
-- minus_abs_plus.s

  movq  %rax, %r14
  .align  16, 0x90
.LBB0_6:   
  # =>This Inner Loop Header: Depth=1
  movl  -12(%r12,%rbx,4), %eax
  leal  -1(%rax), %ecx
  movl  $1, %edx
  subl  %eax, %edx
  testl  %eax, %eax
  cmovgl  %ecx, %edx
  movl  -8(%r12,%rbx,4), %eax
  leal  -1(%rax), %ecx
  movl  $1, %esi
  subl  %eax, %esi
  testl  %eax, %eax
  cmovgl  %ecx, %esi
  addl  %edx, %esi
  movl  -4(%r12,%rbx,4), %eax
  leal  -1(%rax), %ecx
  movl  $1, %edx
  subl  %eax, %edx
  testl  %eax, %eax
  cmovgl  %ecx, %edx
  addl  %esi, %edx
  movl  (%r12,%rbx,4), %eax
  leal  -1(%rax), %ecx
  movl  $1, %esi
  subl  %eax, %esi
  testl  %eax, %eax
  cmovgl  %ecx, %esi
  addl  %edx, %esi
  jne  .LBB0_7
# BB#17:   #   in Loop: Header=BB0_6 Depth=1
  incl  4(%rsp)
.LBB0_7:   # %.backedge
           #   in Loop: Header=BB0_6 Depth=1
  addq  $1, %rbx
  cmpq  $160000000, %rbx
  jne  .LBB0_6
  

-- minus_mul_plus.s

  movq  %rax, %r14
  .align  16, 0x90
.LBB0_6:
  # =>This Inner Loop Header: Depth=1
  movl  -12(%r12,%rbx,4), %eax
  addl  $-1, %eax
  imull  %eax, %eax
  movl  -8(%r12,%rbx,4), %ecx
  addl  $-1, %ecx
  imull  %ecx, %ecx
  addl  %eax, %ecx
  movl  -4(%r12,%rbx,4), %eax
  addl  $-1, %eax
  imull  %eax, %eax
  addl  %ecx, %eax
  movl  (%r12,%rbx,4), %ecx
  movl  $1, %edx
  subl  %ecx, %edx
  addl  $-1, %ecx
  imull  %edx, %ecx
  cmpl  %ecx, %eax
  jne  .LBB0_7
# BB#17:   #   in Loop: Header=BB0_6 Depth=1
  incl  4(%rsp)
.LBB0_7:   # %.backedge
           #   in Loop: Header=BB0_6 Depth=1
  addq  $1, %rbx
  cmpq  $160000000, %rbx
  jne  .LBB0_6
  
  
-- minus_mul_double.s

  movq  %rax, %r14
  vmovsd  .LCPI1_0(%rip), %xmm0
  vxorps  %xmm1, %xmm1, %xmm1
  .align  16, 0x90
.LBB1_6:
  # =>This Inner Loop Header: Depth=1
  vaddsd  -24(%r12,%rbx,8), %xmm0, %xmm2
  vmulsd  %xmm2, %xmm2, %xmm2
  vaddsd  -16(%r12,%rbx,8), %xmm0, %xmm3
  vmulsd  %xmm3, %xmm3, %xmm3
  vaddsd  %xmm3, %xmm2, %xmm2
  vaddsd  -8(%r12,%rbx,8), %xmm0, %xmm3
  vmulsd  %xmm3, %xmm3, %xmm3
  vaddsd  %xmm3, %xmm2, %xmm2
  vaddsd  (%r12,%rbx,8), %xmm0, %xmm3
  vmulsd  %xmm3, %xmm3, %xmm3
  vaddsd  %xmm3, %xmm2, %xmm2
  vucomisd  %xmm1, %xmm2
  jne  .LBB1_9
  jnp  .LBB1_8
  jmp  .LBB1_9
.LBB1_8:   #   in Loop: Header=BB1_6 Depth=1
  incl  4(%rsp)
.LBB1_9:   # %.backedge
           #   in Loop: Header=BB1_6 Depth=1
  addq  $1, %rbx
  cmpq  $160000000, %rbx
  jne  .LBB1_6
  
  
-- mul.s

  movq  %rax, %r14
  movl  $-1, %eax
  .align  16, 0x90
.LBB0_6:
  # =>This Inner Loop Header: Depth=1
  cmpl  $1, -4(%r12,%rbx,4)
  sete  %cl
  cmpl  $1, -8(%r12,%rbx,4)
  movl  $0, %edx
  cmovel  %eax, %edx
  cmpl  $1, -12(%r12,%rbx,4)
  movzbl  %cl, %ecx
  je  .LBB0_8
# BB#7:    # %select.false
           #   in Loop: Header=BB0_6 Depth=1
  xorl  %edx, %edx
.LBB0_8:   # %select.end
           #   in Loop: Header=BB0_6 Depth=1
  andl  %edx, %ecx
  cmpl  $1, (%r12,%rbx,4)
  sete  %dl
  movzbl  %dl, %edx
  negl  %ecx
  testl  %ecx, %edx
  je  .LBB0_9
# BB#19:   #   in Loop: Header=BB0_6 Depth=1
  incl  4(%rsp)
.LBB0_9:   # %.backedge
           #   in Loop: Header=BB0_6 Depth=1
  addq  $1, %rbx
  cmpq  $160000000, %rbx
  jne  .LBB0_6
  

