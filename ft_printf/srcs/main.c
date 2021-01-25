#include "ft_printf.h"
#include <stdio.h>
int main(void)
{
    char *str = "test";
    char *str2 = "second test";
    int test = 42;
    // ft_printf("%d\n",10);
    // printf("%d\n",10);
    // ft_printf("%c %-x %-X\n", 2, 65, 5);
    // printf("%c %-x %-X\n", 2, 65, 5);
    ft_printf("%d %d %d %d %o %o %x %x\n", 65, 41, 65, 5, 42, 3, 100, 120);
    printf("%d %d %d %d %o %o %x %x\n", 65, 41, 65, 5, 42, 3, 100, 120);
    ft_printf("%#0x %X %#x\n", 42, 42, 42);
	printf("%#0x %X %#x\n", 42, 42, 42);
    // ft_printf("%s %s %d %d %d %d %d %-X\n", str, str2, test, 65, 41, 65, 5, 3);
    // printf("%s %s %d %d %d %d %d %-X\n", str, str2, test, 65, 41, 65, 5, 3);
    // ft_printf("%x\n",10);
    // printf("%x\n",10);
    // ft_printf("%f\n", -0.001675);
    // printf("%f\n", -0.001675);
   // while (1);
    return (0);
}