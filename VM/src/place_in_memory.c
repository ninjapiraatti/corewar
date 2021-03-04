#include "vm.h"

/*
** Puts the player's executable code into the arena (into the 'ar'-byte of the
** struct) and sends the corresponding 'color'-string and the player's index
** number to add_color(). Returns the amount of bytes written.
*/

int		player_to_arena(t_arena *start, unsigned char *code, int len, int index)
{
	int			k;

	k = 0;
	while (k < len)
	{
		start[k].ar = code[k];
		start[k].color = index + 11;
		start[k].color_carr = 0;
		k++;
	}
	return (k);
}

/*
** Set remaining bytes in a player's area to 0 and color to neutral.
*/

void	init_mem_area_to_zero(t_arena *arena)
{
	int			i;

	i = 0;
	while (i < MEM_SIZE)
	{
		arena[i].ar = 0;
		arena[i].color = 20;
		arena[i].color_carr = 0;
		arena[i].color_bold = 0;
		i++;
	}
}

/*
** Divides the memory of the arena by the number of players
** and sends sends each player's executable code and the appropriate
** 'arena' -area to 'player_to_arena()'. Sets the empty memory
** in between players to 0 (the 'ar'-byte) and sets each corresponding
** 'color' -string to zero also.
*/

void	place_players_in_mem(t_game *game, t_pl *pl, t_flag *flags)
{
	int			per_pl;
	int			i;
	int			k;
	t_arena		*arena;
	t_carriage	*new;

	game->head = NULL;
	arena = game->arena;
	init_mem_area_to_zero(arena);
	per_pl = MEM_SIZE / pl->pl_num;
	i = 0;
	while (i < pl->pl_num)
	{
		k = i * per_pl;
		new = create_carriage((i + 1), k);
		initialize_registries(new->regs, (i + 1), NULL);
		ft_add_carriage(&(game->head), new);
		k += player_to_arena(&arena[k], pl->exec[i + 1], pl->h_info[i + 1]->prog_size, i);
		arena[new->pc].color_carr = new->color_id;
		i++;
	}
	game->car_num = i;
	game->players = pl;
	game->flags = flags;
}
