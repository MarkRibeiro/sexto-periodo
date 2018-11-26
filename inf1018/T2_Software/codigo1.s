/*legenda*/
/*p0=edi*/
/*v0=-4(%rbp)*/
/*v1=-8(%rbp)*/
/*v2=-12(%rbp)*/
/*v3=-16(%rbp)*/
/*v4=-20(%rbp)*/

/*Function*/
pushq %rbp			         /*55*//*OK*/
movq %rsp, %rbp		       /*48 89 e5*//*OK*/
subq $32, %rsp		       /*48 83 ec 20*//*OK*/
movl %edi, -24(%rbp) 	   /*89 7d e8*/

 /*end*/
leave					           /*c9*//*OK*/
ret					             /*c3*//*OK*/

movl %edi,        %edx   /*8b 55 fc*/
movl -4(%rbp),    %edx   /*8b 55 fc*/
movl -8(%rbp),    %edx   /*8b 55 f8*/
movl -12(%rbp),   %edx   /*8b 55 f4*/
movl -16(%rbp),   %edx   /*8b 55 f0*/
movl -20(%rbp),   %edx   /*8b 55 ec*/
movl -24(%rbp),   %edx   /*8b 55 e8*/
movl $0x7fffffff, %edx   /*ba ff ff ff ff*/

movl %edx,  -4(%rbp)   /*89 55 fc*/
movl %edx,  -8(%rbp)   /*89 55 f8*/
movl %edx,  -12(%rbp)  /*89 55 f4*/
movl %edx,  -16(%rbp)  /*89 55 f0*/
movl %edx,  -20(%rbp)  /*89 55 ec*/
movl %edx,  -24(%rbp)  /*89 55 e8*/

movl -4(%rbp),    %eax   /*8b 55 fc*/
movl -8(%rbp),    %eax   /*8b 55 f8*/
movl -12(%rbp),   %eax   /*8b 55 f4*/
movl -16(%rbp),   %eax   /*8b 55 f0*/
movl -20(%rbp),   %eax   /*8b 55 ec*/
movl -24(%rbp),   %eax   /*8b 55 e8*/
movl $0xffffffff, %eax   /*b8 ff ff ff ff*/

movl -4(%rbp),    %edx   /*03 55 fc*/
movl -8(%rbp),    %edx   /*03 55 f8*/
movl -12(%rbp),   %edx   /*03 55 f4*/
movl -16(%rbp),   %edx   /*03 55 f0*/
movl -20(%rbp),   %edx   /*03 55 ec*/
movl -24(%rbp),   %edx   /*03 55 e8*/
movl $0xffffffff, %edx   /*83 c2 ff*/ 

cmpl $0, %edx
je 0x7fffffff
