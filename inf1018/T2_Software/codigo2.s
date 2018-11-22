/*legenda*/
/*edi=p0*/
/*v0=-4(%rbp)*/
/*v1=-8(%rbp)*/
/*v2=-12(%rbp)*/
/*v3=-16(%rbp)*/
/*v4=-20(%rbp)*/

/*v0 = p0 + $1000*/
movl %edi, %edx    /*edx=p0*/
addl $1000, %edx   /*edx=edx+1000*/
movl %edx, -4(%rbp)/*v0=edx*/

/*v0 = p0 + p0*/
movl %edi, %edx    /*edx=p0*/
addl %edi, %edx    /*edx=edx+p0*/
movl %edx, -4(%rbp)/*v0=edx*/

/*v0 = p0 + v1*/
movl %edi, %edx    /*edx=p0*/
addl -8(%rbp), %edx/*edx=edx+v1*/
movl %edx, -4(%rbp)/*v0=edx*/

/*v0 = v1 + $1000*/
movl -8(%rbp), %edx/*edx=v1*/
addl $1000, %edx   /*edx=edx+$1000*/
movl %edx, -4(%rbp)/*v0=edx*/

/*v0 = v1 + p0*/
movl -8(%rbp), %edx/*edx=v1*/
addl %edi, %edx    /*edx=edx+p0*/
movl %edx, -4(%rbp)/*v0=edx*/

/*v0 = v1 + v1*/
movl -8(%rbp), %edx/*edx=v1*/
addl -8(%rbp), %edx/*edx=edx+v1*/
movl %edx, -4(%rbp)/*v0=edx*/

/*v0 = $1000 + $1000*/
movl $1000, %edx   /*edx=$1000*/
addl $1000, %edx   /*edx=edx+$1000*/
movl %edx, -4(%rbp)/*v0=edx*/

/*v0 = $1000 + p0*/
movl $1000, %edx   /*edx=$1000*/
addl %edi, %edx    /*edx=edx+p0*/
movl %edx, -4(%rbp)/*v0=edx*/

/*v0 = $1000 + v1*/
movl $1000, %edx   /*edx=$1000*/
addl -8(%rbp), %edx/*edx=edx+v1*/
movl %edx, -8(%rbp)/*v0=edx*/

movl $1000, %ebx
