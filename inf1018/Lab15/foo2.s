.text
.globl foo2
foo2:
	pushq %rbp
	movq %rsp, %rbp
	subq $16, %rsp

	movq %xmm1, -8(%rbp) /*Salva b(xmm1) na pilha em -8(%rbp)*/

	cvtss2sd %xmm0, %xmm0 /*Converte a(xmm0) de float para double*/
	call sin
	cvtsd2ss %xmm0, %xmm0 /*Converte a(xmm0) de double para float*/
	movq %xmm0, -16(%rbp) /*Salva sen(a) na pilha em -16(%rbp)*/

	movq -8(%rbp), %xmm0 /*Passa o valor de -8(%rbp)(b) para %xmm0*/
	cvtss2sd %xmm0, %xmm0 /*Converte b(xmm0) de float para double*/
	call cos
	cvtsd2ss %xmm0, %xmm0 /*Converte b(xmm0) de double para float*/

	addss -16(%rbp), %xmm0 /*Soma -16(%rbp) ao valor de cos(b)*/
	cvtss2sd %xmm0, %xmm0 /*Converte a soma(sen(a) + cos(b)) de float para double*/

	leave
	ret
