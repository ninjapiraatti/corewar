#include "vm.h"

void	manage_zjmp(t_game *game, t_carriage *carr)
{
	int		arg;
	int		address;

	arg = read_bytes(game->arena, carr->pc + 1, 2);
	address = (unsigned int)(carr->pc + (arg % IDX_MOD)) % MEM_SIZE;
	if (carr->carry)
	{
		game->arena[carr->pc].color_carr = 0;
		carr->pc = address;
		game->arena[carr->pc].color_carr = carr->color_id;
		carr->next_state = JUMPED;
	}
	if (game->flags->moves)
	{
		ft_printf(" %d", arg);
		if (carr->carry)
			ft_printf(" OK\n");
		else
			ft_printf(" FAILED\n");
	}
}
