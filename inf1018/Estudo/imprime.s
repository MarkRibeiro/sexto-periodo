.data
s1: .string "oi\n"

.text
.globl imprime
imprime:

	movq $s1, %rdi
	call printf
	ret
	