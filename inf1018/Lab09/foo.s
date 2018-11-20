.text
.globl foo
foo:
	pushq %rbp
	movq %rsp, %rbp
	
	movl $0, %edx /*edx=i*/
	movl $0, %ecx /*ecx=s*/
	
	J1:
		cmpl %esi, %edx 
		jge J3
	
		movslq %edx, %r8
		addl  (%rdi, %r8, 4), %ecx
		cmpl  $0, (%rdi, %r8, 4)
		je J2
	
		addl $1, %edx
		jmp J1
		

		J2:
			addl %ecx, (%rdi, %rdx, 4)
			movl $0, %ecx
			addl $1, %edx
			jmp J1

		J3:
			leave
			ret
		
/*
void foo (int a[], int n) 
{
	int i;
  	int s = 0;
  	
  	for (i=0; i<n; i++) 
	{
    	s += a[i];
    	if (a[i] == 0) 
		{
			a[i] = s;
    		s = 0;
    	}
  	}
} */
