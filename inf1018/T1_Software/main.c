#include<stdio.h>
#include"grava_struct.h"
struct s 
{
    int i1;
    short s1;
    char c1;
};
struct s exemplo[2] = {{0x01020304, 0xaabb, 0xcc}, {0x05060708, 0xddee, 0xff}};
/*
struct s 
{
    long l1;
    char c1;
    short s1;
    int i1;
    long l2;
    long l3;
    char c2;
    short s2;
    int i2;
    long l4;
};
struct s exemplo[2] = {{0x0102030405060708, 0x0a}, {0x0807060504030201, 0x0b}};

struct s {
    int i1;
    long l1;
    short s1;
    char c1;
    short s2;
  };
struct s exemplo[10];*/

int main (void)
{ 
	char *arquivo = "saida1";

	grava_structs(2, (void*)exemplo, "isc", 'B', arquivo);
    dump_structs(arquivo);
    //dump_structs("kalil");
}
