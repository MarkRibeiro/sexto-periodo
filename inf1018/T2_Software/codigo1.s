/******Function******/
  pushq %rbp			/*55*//*OK*/
  movq %rsp, %rbp		/*48 89 e5*//*OK*/
  subq $32, %rsp		/*48 83 ec 20*//*OK*/
  movl %edi, -24(%rbp) 	/*89 7d e8*/
/********************/

  movl  -24(%rbp), %edx	/*8b 55 e8*//*OK*/
  addl  $1000, %edx		/*81 c2 e8 03 00 00 */
  movl  %edx, -4(%rbp)	/*89 55 fc*//*OK*/
  movl	-4(%rbp), %eax	/*8b 45 fc*//*OK*/

 /********end********/
  leave					/*c9*//*OK*/
  ret					/*c3*//*OK*/
/********************/

cmpl $0, -4(%rbp)   /*83 7d fc 00*/
cmpl $0, -8(%rbp)   /*83 7d f8 00*/
cmpl $0, -12(%rbp)  /*83 7d f4 00*/  
cmpl $0, -16(%rbp)  /*83 7d f0 00*/
cmpl $0, -20(%rbp)  /*83 7d ec 00*/
cmpl $0, -24(%rbp)  /*83 7d e8 00*/


pushq %rbp        /*55*/
movq %rsp, %rbp     /*48 89 e5*/
subq $32, %rsp      /*48 83 ec 20*/
movl %edi, -24(%rbp)  /*89 7d e8*/

movl $0, %edx
cmpl $0, %edx
je WERTYUIOP

movl  -24(%rbp), %edx /*8b 55 e8*/
addl  $1000, %edx   /*81 c2 e8 03 00 00*/
movl  %edx, -4(%rbp)  /*89 55 fc*/
movl  -4(%rbp), %eax  /*8b 45 fc*/

  WERTYUIOP:
   leave
   ret    
