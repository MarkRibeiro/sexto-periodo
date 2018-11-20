.text
.globl foo3
foo3:
	push %rbp
	movq %rsp,%rbp
	subq $32, %rsp

	movq %rdi,-8(%rbp)
	movl %esi,-16(%rbp)

	movq $0,-24(%rbp)
	movq %r12,-32(%rbp)
	movl $0,%r12d

	loop:
		cmpl -16(%rbp),%r12d
		jge fim
		movq -8(%rbp),%rdi
		movsd (%rdi),%xmm0
		call sin
		addsd -24(%rbp),%xmm0
		movsd %xmm0,-24(%rbp)
		addq $8,-8(%rbp)
		jmp loop

	fim:
		movsd -24(%rbp),%xmm0
		movq -32(%rbp),%r12
		leave
	ret
/*
double foo3 (double *a, int n) {
  int i;
  double r = 0.0;
  for (i=0; i<n; i++) {
    r += sin(*a);
    a++;
  }
  return r;
}*/