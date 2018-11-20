.text
.globl foo1
foo1:
	pushq %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	movq %xmm1, -8(%rbp)

	cvtss2sd %xmm0, %xmm0
	call sin
	cvtsd2ss %xmm0, %xmm0

	addss -8(%rbp), %xmm0
	movq -8(%rbp), %xmm1
	leave
	ret
	