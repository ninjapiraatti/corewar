#include "vm.h"

void    init_structs(t_pl *players, t_flag *flags, int ac, char **av)
{
    int i;

    i = -1;
    while (++i < MAX_PLAYERS + 1)
        players->pl_order[i] = NULL;
    players->ac = ac;
    players->av = av;
    players->pl_num = 0;
    i = -1;
    while (++i < MAX_PLAYERS + 1)
        flags->n[i] = INIT_FLAGS;
    flags->dump = INIT_FLAGS;
}