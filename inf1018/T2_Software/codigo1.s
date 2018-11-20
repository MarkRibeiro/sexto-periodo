/******Function******/
.text
.globl foo
foo:
  pushq %rbp
  movq %rsp, %rbp
  subq $32, %rsp
/********************/

/******ret $100******/
  movl $100, -8(%rbp)
  movl -8(%rbp), %eax
/********************/

 /********end********/
  leave
  ret
/********************/
