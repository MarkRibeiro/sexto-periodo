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
movl $0xffffffff, %edx   /*ba ff ff ff ff*/

movl %edx,  -4(%rbp)   /*89 55 fc*/
movl %edx,  -8(%rbp)   /*89 55 f8*/
movl %edx,  -12(%rbp)  /*89 55 f4*/
movl %edx,  -16(%rbp)  /*89 55 f0*/
movl %edx,  -20(%rbp)  /*89 55 ec*/
movl %edx,  -24(%rbp)  /*89 55 e8*/

movl -4(%rbp),    %eax   /*8b 45 fc*/
movl -8(%rbp),    %eax   /*8b 45 f8*/
movl -12(%rbp),   %eax   /*8b 45 f4*/
movl -16(%rbp),   %eax   /*8b 45 f0*/
movl -20(%rbp),   %eax   /*8b 45 ec*/
movl -24(%rbp),   %eax   /*8b 45 e8*/
movl $0xffffffff, %eax   /*b8 ff ff ff ff*/

addl -4(%rbp),    %edx   /*03 55 fc*/
addl -8(%rbp),    %edx   /*03 55 f8*/
addl -12(%rbp),   %edx   /*03 55 f4*/
addl -16(%rbp),   %edx   /*03 55 f0*/
addl -20(%rbp),   %edx   /*03 55 ec*/
addl -24(%rbp),   %edx   /*03 55 e8*/
addl $0x1000, %edx   /*83 c2 ff*/

subl -4(%rbp),    %edx   /*2b 55 fc*/
subl -8(%rbp),    %edx   /*2b 55 f8*/
subl -12(%rbp),   %edx   /*2b 55 f4*/
subl -16(%rbp),   %edx   /*2b 55 f0*/
subl -20(%rbp),   %edx   /*2b 55 ec*/
subl -24(%rbp),   %edx   /*2b 55 e8*/
subl $0x1000, %edx   /*83 ea ff*/

imull -4(%rbp),   %edx   /*0f af 55 fc*/
imull -8(%rbp),   %edx   /*0f af 55 f8*/
imull -12(%rbp),  %edx   /*0f af 55 f4*/
imull -16(%rbp),  %edx   /*0f af 55 f0*/
imull -20(%rbp),  %edx   /*0f af 55 ec*/
imull -24(%rbp),  %edx   /*0f af 55 e8*/
imull $0x1000,%edx   /*6b d2 ff*/

cmpl $0, -4(%rbp)        /*83 7d fc 00*/
cmpl $0, -8(%rbp)        /*83 7d f8 00*/
cmpl $0, -12(%rbp)       /*83 7d f4 00*/  
cmpl $0, -16(%rbp)       /*83 7d f0 00*/
cmpl $0, -20(%rbp)       /*83 7d ec 00*/
cmpl $0, -24(%rbp)       /*83 7d e8 00*/
