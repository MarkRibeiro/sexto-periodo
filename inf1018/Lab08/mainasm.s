  .data
  nums: .int 3, -5, 7, 8, -2
  s1:   .string "%d\n"

  .text
  .globl main
  main:
  /* prologo */
	pushq %rbp
    movq  %rsp, %rbp
    subq  $16, %rsp
    movq  %rbx, -8(%rbp)
    movq  %r12, -16(%rbp)

  /* coloque seu codigo aqui */
		movl  $0, %r12d
		movq  $nums, %rbx
	
		J1:
		cmpl  $5, %r12d
		je J2

		movl (%rbx), %edi
		movl $1, %esi
		call filtro
		
		movq $s1, %rdi
		movl %eax, %esi
		call printf 

		addl $1, %r12d
		addq $4, %rbx
		jmp J1

		J2:
  /* finalizacao */
    movq -8(%rbp), %rbx
    movq -16(%rbp), %r12
    leave
    ret
