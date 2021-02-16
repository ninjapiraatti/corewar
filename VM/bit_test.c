#include "vm.h"
#include <stdio.h>
# define REG_CODE				1 //-> 01
# define DIR_CODE				2 //-> 10
# define IND_CODE				3 //-> 11
/*
Argument # 1    Argument # 2    Argument # 3	-       Result Code
T_REG           T_DIR	        T_DIR	        -	    - 
01	            10	            10	            00	    0x68  or 104 in decimal*/

int main()
{
	unsigned char a = 0xa4;
    char arg1;
    char arg2;
    char arg3;

    arg1 = a >> 6;
    arg2 = (a >> 4) & 3;
    arg3 = (a >> 2) & 3;
    if (arg1 == REG_CODE)
        printf("arg1 is reg\n");
    if (arg2 == DIR_CODE)
        printf("arg2 is dir\n");
    if (arg3 == REG_CODE)
        printf("arg3 is reg\n");


    int mystery = 0xfffb;
    unsigned pos = (unsigned int)mystery;
    signed neg = (short)mystery;

    printf("pos: %d\n", pos);
    printf("neg: %d\n", neg);
    return (0);
}                            
