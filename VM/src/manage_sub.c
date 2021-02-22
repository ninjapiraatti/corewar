#include "vm.h"

void    manage_sub(t_carriage *carr, t_arena *arena)
{
    int     arg1;
    int     arg2;
    int     arg3;

    arg1 = arena[carr->pc + 2].ar;
    arg2 = arena[carr->pc + 3].ar;
    arg3 = arena[carr->pc + 4].ar;
    carr->regs[arg3 - 1] = carr->regs[arg1 - 1] - carr->regs[arg2 - 1];
    if (carr->regs[arg3 - 1] == 0)
        carr->carry = true;
    else
        carr->carry = false;
}