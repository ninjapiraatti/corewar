#include "vm.h"

// init wait time to -1

void	manage_add(t_carriage *carr, t_game *game)
{
	int		arg1;
	int		arg2;
	int		arg3;

	arg1 = carr->regs[game->arena[carr->pc + 2].ar - 1];
	arg2 = carr->regs[game->arena[carr->pc + 3].ar - 1];
	arg3 = arg1 + arg2;
	if (arg3 == 0)
		carr->carry = 1;
	else
		carr->carry = 0;
	carr->regs[game->arena[carr->pc + 4].ar - 1] = arg3;
	if (game->flags->moves)
	{
		ft_printf(" r%d r%d r%d\n",
		game->arena[carr->pc + 2].ar, game->arena[carr->pc + 3].ar,
		game->arena[carr->pc + 4].ar);
	}
}
