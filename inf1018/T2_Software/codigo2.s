/******Function******/
.text
.globl foo
foo:
  pushq %rbp
  movq %rsp, %rbp
  subq $32, %rsp
  movl %edi, -4(%rbp)	

  movl $10, -12(%rbp)
  movl $1, %eax 

  leave
  ret

