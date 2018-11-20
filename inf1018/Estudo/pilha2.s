.data
nums:  .int 3, -5, 7, 8, -2, 10, 11, 12, 13, 14, 15 
s1:  .string "%d\n"

.text
.globl main
main:

	pushq 	%rbp
	movq 	%rsp, %rbp
	subq 	$16, %rsp
	movq 	%rbx, -8(%rbp)
	movq 	%r12, -16(%rbp)

	movq 	$nums, %rbx
	

	PRINT:
	movq 	$s1, %rdi		/*passa "%d" como primeiro parametro da printf*/
	movl	(%rbx), %edi	/*passa *nums como o segundo parametro da printf*/
	movl	$0, %eax 		/*zera o eax*/
	call 	printf			/*chama a printf*/
	addq 	$4, %rbx
	movq	%rbx, %rax
	cmpq	0, %rax
	jne PRINT
	leave
	ret
