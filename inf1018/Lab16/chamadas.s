/*
int myopen (const char *pathname, int flags, int buffersize) {
  tamBufferAberto = buffersize;
  return open(pathname, flags);
}
*/
.text

.globl myread
myread:
	movq $0, %rax
	movl tamBufferAberto, %edx
	syscall
	ret

.globl mywrite
mywrite:
	movq $1, %rax
	syscall
	ret	

.globl myopen
myopen:
	movq $2, %rax
	movl %edx, tamBufferAberto
	syscall
	ret

.globl myclose
myclose:	
	movq $3, %rax
	syscall
	ret
	