#include "vm.h"
//in subject, it is stated that every time a valid live is performed,
//it should be printed. example corewar does not do it.
void    manage_live(t_carriage *carr, t_game *game)
{
    int arg;

    arg = read_bytes(game->arena, carr->pc + 1, DIR_SIZE);
    carr->last_live = game->cycles;
    game->lives_num++;
    arg *= -1;
    if (arg > 0 && arg <= game->players->pl_num)
    {
        game->id_last_live = arg;
        // ft_printf("A process shows that player %d (%s) is alive\n", 
        //     arg, game->players->pl_order[arg]);
    }
    carr->next_state = 1 + DIR_SIZE;
}