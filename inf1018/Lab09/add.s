.text
.globl add
add:

	addl %esi, %edi
	addl %edx, %edi
	movl %edi, %eax
	ret
