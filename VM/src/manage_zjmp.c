#include "vm.h"

void    manage_zjmp(t_arena *arena, t_carriage *carr)
{
    int arg;
    int address;

    if (carr->carry)
    {
        arg = read_bytes(arena, carr->pc + 1, 2);
        // ft_printf("from jump |%d|\n", arg);
        address = (carr->pc + (arg % IDX_MOD)) % MEM_SIZE;
        arena[carr->pc].color_carr = 0;
        carr->pc = address;
        arena[carr->pc].color_carr = carr->color_id;
        carr->next_state = JUMPED;
    }
}
