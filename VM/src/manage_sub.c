#include "vm.h"

void	manage_sub(t_carriage *carr, t_game *game)
{
	int		arg1;
	int		arg2;
	int		arg3;

	arg1 = game->arena[carr->pc + 2].ar;
	arg2 = game->arena[carr->pc + 3].ar;
	arg3 = game->arena[carr->pc + 4].ar;
	carr->regs[arg3 - 1] = carr->regs[arg1 - 1] - carr->regs[arg2 - 1];
	if (carr->regs[arg3 - 1] == 0)
		carr->carry = true;
	else
		carr->carry = false;
	if (game->flags->moves)
	{
		ft_printf(" r%d r%d r%d\n",
		game->arena[carr->pc + 2].ar, game->arena[carr->pc + 3].ar,
		game->arena[carr->pc + 4].ar);
	}
}
