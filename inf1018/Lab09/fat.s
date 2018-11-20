.text
.globl fat
fat:
	
	cmpl $0, %edi
	je J1
	
	push %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	movq %r12, -8(%rbp)
	movl %edi, %r12d

	subl $1, %edi
	call fat
	imull %r12d ,%eax
	movq -8(%rbp), %r12
	leave
	ret 


	J1:
		movl $1, %eax
		movq -8(%rbp), %r12
		leave
		ret




/*
int fat (int n) 
{
  if (n==0) 
	return 1;
  else 
	return n*fat(n-1);
}
*/
