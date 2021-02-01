#include "vm.h"

void    print_hex(t_arena *arena)
{
    int i;
    int j;

    i = 0;
    while (i < MEM_SIZE)
    {
        ft_printf("0x%04x   ", i);
        j = 0;
        while (j < 32)
        {
            if (arena[i].color[0])
                ft_printf("%s%02x%s ", arena[i].color, arena[i].ar, EOC);
            else
                ft_printf("%02x ", arena[i].ar);
            j++;
            i++;
        }
        ft_putchar('\n');
    }
}



