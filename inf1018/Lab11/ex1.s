.data

s1: .string "numero: "
s2: .string "%d"

.text
.globl novonum

novonum:

	push %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	movq $s1, %rdi
	call printf
	movq $s2, %rdi
	leaq -16(%rbp), %rsi
	call scanf 
	movl -16(%rbp), %eax
	leave
	ret


/*int novonum(void) {
  int minhalocal;
  printf("numero: ");
  scanf("%d",&minhalocal);
  return minhalocal;
}*/