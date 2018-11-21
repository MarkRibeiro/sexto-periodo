/******Function******/
.text
.globl foo
foo:
  pushq %rbp
  movq %rsp, %rbp
  subq $32, %rsp
  movl %edi, -4(%rbp)	
/*
  movl %edi, %esi
  movl %edi, %eax

  addl %edi, %esi 
  addl %edi, %eax

  subl %edi, %esi 
  subl %edi, %eax

  imull %edi, %esi 
  imull %edi, %eax
*/

  movl $1, %eax
  ret



  leave
  ret

