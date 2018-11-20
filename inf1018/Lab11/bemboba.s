.text
.globl bemboba
bemboba:
	push %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	movl $0, %esi /*i=0*/
	leaq -16(%rbp), %rcx

	J1:
		cmpl $4, %esi
		je J2
		movl %edi, (%rcx)
		addq $4, %rcx
		addl $1, %esi
		jmp J1 

	J2:
		leaq -16(%rbp), %rdi
		movl $4, %esi
		call addl
		leave
		ret

/*int bemboba (int num) {
  int local[4];
  int *a;
  int i;

  for (i=0,a=local;i<4;i++) {
    *a = num;
    a++;
  }
  return addl (local, 4);
}*/