.text
.globl myotherwrite
myotherwrite
	movq $1, %rax
	movq %rsi, %r9
	movl $0, %r8d

	loop:
		cmpl $0, (%r9)
		je end
		inc %r8d
		add $1, %r9
		jmp loop

	end:
		movl %r8d, %edx
		syscall
		ret