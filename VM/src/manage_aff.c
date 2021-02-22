#include "vm.h"

void    manage_aff(t_carriage *carr, t_arena *arena)
{
    int arg;

    arg = arena[carr->pc + 1].ar;
    if (AFF_DISPLAY == 1)
        ft_printf("AFF: %c\n", (char)carr->regs[arg]);
}