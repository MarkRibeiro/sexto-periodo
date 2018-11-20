.text
.globl add
add: 
	movl $0, %esi	/*esi=a*/

	J1:
	cmpq $0, %rdi	/*rdi=x*/	
	je J2
	addl (%rdi), %esi
	movq 8(%rdi), %rdi
	jmp J1

	J2:
		movl %esi, %eax
		ret

/*
int add (struct X *x) 
{
  	int a = 0;

  	for (; x != NULL; x = x->next)
    	a += x->val;
  	return a;
}
*/
