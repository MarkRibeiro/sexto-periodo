.text
.globl foo3
foo3:
	pushq %rbp
	movq %rsp, %rbp
	subq $32, %rsp

	movl $0, %r12d /*i(r12d)=0*/
	movsd $0.0, %xmm7 /*r(xmm7)=0.0*/

	movq %r12, -8(%rbp) /*coloca i(r12) na pilha*/
	movq %xmm7, -16(%rbp) /*coloca r(xmm7) na pilha*/
	movq %rsi, -24(%rbp) /*coloca n(rsi) na pilha*/
	movq %rdi, -32(%rbp) /*coloca a(rdi) na pilha*/

	J1:
		movsd (%rdi), %xmm0
		call sin
		addq %xmm0, -16(%rbp)
		addl $1, -8(%rbp)
		addq $1, -32(%rbp)
		compl -24(%rbp), -8(%rbp)
		jl J1

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