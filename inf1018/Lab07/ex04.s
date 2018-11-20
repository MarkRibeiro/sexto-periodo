.data
S2: .int 65, -105, 111, 34
Sf2: .string "%d\n" /* segunda string de formato para printf */

.text
.globl main
main:

/********************************************************/
/* mantenha este trecho aqui e nao mexa - prologo !!! */
pushq %rbp
movq %rsp, %rbp
subq $16, %rsp
movq %rbx, -8(%rbp) /* guarda rbx */
movq %r12, -16(%rbp) /* guarda r12 */
/********************************************************/


movl $0, %ebx
movl $0, %esi
movq $S2, %r12
movl $0, %eax
L1:
cmpl $4,%esi
je L2
movl %esi,%ebx
imull $4,%ebx
movslq %ebx,%rbx
addq %r12,%rbx
addl (%rbx),%eax
addl $1,%esi

jmp L1

L2:
/*************************************************************/
/* este trecho imprime */
movq $Sf2, %rdi /* primeiro parametro (ponteiro)*/
movl %eax,%esi
movl $0, %eax
call printf /* chama a funcao da biblioteca */
/*************************************************************/


/***************************************************************/
/* mantenha este trecho aqui e nao mexa - finalizacao!!!! */
movq $0, %rax /* rax = 0 (valor de retorno) */
movq -16(%rbp), %r12 /* recupera r12 */
movq -8(%rbp), %rbx /* recupera rbx */
leave
ret
/***************************************************************/
