.data
S2:    .int 10, -21, -30, 45
Sf2: .string "%d "    /* segunda string de formato para printf */

.text
.globl  main
main:

/********************************************************/
/* mantenha este trecho aqui e nao mexa - prologo !!!   */
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)  /* guarda rbx */
  movq    %r12, -16(%rbp)  /* guarda r12 */
/********************************************************/
  movq $S2, %r12
  movl $0, %ebx 
L1:
  cmpl $4, %ebx
  je L3 
  movl (%r12), %r11d
  and $0x00000001, %r11d
  jnz L2
  cmpl $0, (%r12)
  jle L2
  movl (%r12), %eax

  


/*************************************************************/
/* este trecho imprime o valor de %eax (estraga %eax)  */
  movq    $Sf2, %rdi    /* primeiro parametro (ponteiro)*/
  movl    %eax, %esi   /* segundo parametro  (inteiro) */
  movl  $0, %eax
  call  printf       /* chama a funcao da biblioteca */
/*************************************************************/
  L2:

  addl $1, %ebx
  addq $4, %r12
  jmp L1

  L3:
/***************************************************************/
/* mantenha este trecho aqui e nao mexa - finalizacao!!!!      */
  movq  $0, %rax  /* rax = 0  (valor de retorno) */
  movq    -16(%rbp), %r12 /* recupera r12 */
  movq    -8(%rbp), %rbx  /* recupera rbx */
  leave
  ret      
/***************************************************************/

