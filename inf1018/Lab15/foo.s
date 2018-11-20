.text
.globl foo
foo:
	movsd %xmm0, %xmm2	/*soma(xmm2)=a(xmm0)*/
	cvtss2sd %xmm1, %xmm1
	addsd %xmm1, %xmm2	/*soma(xmm2)=soma(xmm2) + b(xmm1)*/

	movsd %xmm0, %xmm3 /*sub(xmm3)=a(xmm0)*/
	subsd %xmm1, %xmm3 /*sub(xmm3)=sub(xmm3) - b(xmm1)*/

	movsd %xmm2, %xmm0 /*ret=soma(xmm2)*/
	mulsd %xmm3, %xmm0 /*ret soma * sub*/
	cvtsd2ss %xmm0, %xmm0
	ret


