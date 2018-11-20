/******Function******/
.text
.globl foo
foo:

  movl %edi, %esi
  movl %edi, %eax

  addl %edi, %esi 
  addl %edi, %eax

  subl %edi, %esi 
  subl %edi, %eax

  imull %edi, %esi 
  imull %edi, %eax




  ret
