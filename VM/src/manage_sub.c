#include "vm.h"

void	manage_sub(t_carriage *carr, t_game *game)
{
	int		arg1;
	int		arg2;
	int		arg3;

	arg1 = game->arena[(unsigned int)(carr->pc + 2) % MEM_SIZE].ar;
	arg2 = game->arena[(unsigned int)(carr->pc + 3) % MEM_SIZE].ar;
	arg3 = game->arena[(unsigned int)(carr->pc + 4) % MEM_SIZE].ar;
	carr->regs[arg3 - 1] = carr->regs[arg1 - 1] - carr->regs[arg2 - 1];
	if (carr->regs[arg3 - 1] == 0)
		carr->carry = true;
	else
		carr->carry = false;
	if (game->flags->moves)
	{
		ft_printf(" r%d r%d r%d\n",
		game->arena[(unsigned int)(carr->pc + 2) % MEM_SIZE].ar,
			game->arena[(unsigned int)(carr->pc + 3) % MEM_SIZE].ar,
			game->arena[(unsigned int)(carr->pc + 4) % MEM_SIZE].ar);
	}
}
