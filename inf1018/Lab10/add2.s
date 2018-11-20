.text
.globl add2
add2:
	push %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	movq %rdi, -8(%rbp)
	cmpq $0, %rdi
	je J1
	movq 8(%rdi), %rdi
	call add2
	movq -8(%rbp), %rdi
	addl (%rdi), %eax 
	leave
	ret 
	
	J1:
	movl $0, %eax
	leave
	ret



/*
int add2 (struct X *x) 
{
	if (x == NULL) 
		return 0;

  	else 
		return x->val + add2(x->next);
}
*/
