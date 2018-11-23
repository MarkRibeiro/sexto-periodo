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



/*55 48 89 e5 48 83 ec 20 89 7d e8 8b 55 e8 81 c2 01 00 00 00 89 55 fc 8b 45 fc c9 c3*/
