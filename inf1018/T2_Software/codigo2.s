/*legenda*/
/*p0=edi*/
/*v0=-4(%rbp)*/
/*v1=-8(%rbp)*/
/*v2=-12(%rbp)*/
/*v3=-16(%rbp)*/
/*v4=-20(%rbp)*/

/*v0 = p0 + $1000*/
movl -24(%rbp), %edx/*8b 55 e8*/
movl -4(%rbp), %edx
addl -24(%rbp), %edx/*03 55 e8*/
addl -4(%rbp), %edx /*03 55 f8*/
addl -8(%rbp), %edx /**/
addl -12(%rbp), %edx /**/
addl -16(%rbp), %edx /**/
addl -20(%rbp), %edx /**/
addl $1000, %edx   /*81 c2 e8 03 00 00*/

subl -24(%rbp), %edx/*2b 55 e8*/
subl -4(%rbp), %edx /*2b 55 f8*/
subl -8(%rbp), %edx /**/
subl -12(%rbp), %edx /**/
subl -16(%rbp), %edx /**/
subl -20(%rbp), %edx /**/
subl $1000, %edx   /*81 ea e8 03 00 00*/


imull -24(%rbp), %edx/*0f af 55 e8*/
imull -4(%rbp), %edx/*0f af 55 f8*/
imull -8(%rbp), %edx /**/
imull -12(%rbp), %edx /**/
imull -16(%rbp), %edx /**/
imull -20(%rbp), %edx /**/
imull $1000, %edx  /*69 d2 e8 03 00 00*/


movl %edx, -4(%rbp)
movl %edx, -8(%rbp)
movl %edx, -12(%rbp)
movl %edx, -16(%rbp)
movl %edx, -20(%rbp)
