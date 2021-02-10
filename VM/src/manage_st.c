#include "vm.h"

void    manage_st(t_carriage *carr, t_arena *arena)
{
    int arg1;
    int pos2;
    int arg2;

    arg1 = carr->regs[arena[carr->pc + 2].ar - 1];
    if (carr->args[1] == REG_CODE)
    {
        arg2 = carr->regs[arena[carr->pc + 3].ar - 1];
        arg2 = arg1;
    }
    else
    {
        pos2 = carr->pc + arena[carr->pc + 3].ar % IDX_MOD;
        if (pos2 >= MEM_SIZE)
            pos2 = pos2 % MEM_SIZE;
        arg2 = arena[pos2].ar;
        ft_memcpy(arg2, arg1, REG_SIZE);
        //what happens if REG_SIZE memory area starting from arg2
        //streches beyond MEM_SIZE?
    }
    //should we set new pc in these functions or after the statement is perfomed?
    //missing arg validation, maybe should return something in case of error
}

void    manage_sti(t_carriage *carr, t_arena *arena)
{
    int arg1;
    int pos2;
    int arg2;
    int arg3;
    int end_address;

    arg1 = carr->regs[arena[carr->pc + 2].ar - 1];
    if (carr->args[1] == REG_CODE)
        arg2 = carr->regs[arena[carr->pc + 3].ar - 1];
    else if (carr->args[1] == DIR_CODE)
        arg2 = arena[carr->pc + 3].ar;
    else
    {
        pos2 = carr->pc + arena[carr->pc + 3].ar % IDX_MOD;
        ft_memcpy(arg2, arena[pos2].ar, 4);
    }
    if (carr->args[2] == REG_SIZE)
        arg3 = carr->regs[arena[carr->pc + 4].ar - 1];
    else
        arg3 = arena[carr->pc + 4].ar;

    end_address = arena[carr->pc + ((arg2 + arg3) % IDX_MOD)].ar;
    //how much to write? 4 bytes? 1 byte?? 

    ft_memcpy(end_address, arg1, REG_SIZE);
    //should we set new pc in these functions or after the statement is perfomed?
    //missing arg validation, maybe should return something in case of error
}