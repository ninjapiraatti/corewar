#include "vm.h"

/*in subject, it is stated that every time a valid live is performed, it should be printed. example corewar does not do it.*/

void	manage_live(t_carriage *carr, t_game *game)
{
	int	arg;

	arg = read_bytes(game->arena, carr->pc + 1, DIR_SIZE);
	if (game->flags->moves)
		ft_printf(" %d\n", arg);
	carr->last_live = game->cycles;
	game->lives_num++;
	arg *= -1;
	if (arg > 0 && arg <= game->players->pl_num)
	{
		game->id_last_live = arg;
		if (game->flags->live)
			ft_printf("Player %d (%s) is said to be alive\n", 
				arg, game->players->h_info[arg]->prog_name);
		game->players->last_life[arg] = game->cycles;
	}
}
