#include "vm.h"

// init wait time to -1

void	manage_add(t_carriage *carr, t_game *game)
{
	int		arg1;
	int		arg2;
	int		arg3;

	arg1 = carr->regs[game->arena[(unsigned int)(carr->pc + 2) % MEM_SIZE].ar - 1];
	arg2 = carr->regs[game->arena[(unsigned int)(carr->pc + 3) % MEM_SIZE].ar - 1];
	arg3 = arg1 + arg2;
	if (arg3 == 0)
		carr->carry = 1;
	else
		carr->carry = 0;
	carr->regs[game->arena[(unsigned int)(carr->pc + 4) % MEM_SIZE].ar - 1] = arg3;
	if (game->flags->moves)
	{
		ft_printf(" r%d r%d r%d\n",
		game->arena[(unsigned int)(carr->pc + 2) % MEM_SIZE].ar,
			game->arena[(unsigned int)(carr->pc + 3) % MEM_SIZE].ar,
		game->arena[(unsigned int)(carr->pc + 4) % MEM_SIZE].ar);
	}
}
