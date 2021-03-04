#include "vm.h"

// init wait time to -1

void	manage_add(t_carriage *carr, t_arena *arena)
{
	int		arg1;
	int		arg2;
	int		arg3;

	arg1 = carr->regs[arena[carr->pc + 2].ar - 1];
	arg2 = carr->regs[arena[carr->pc + 3].ar - 1];
	arg3 = arg1 + arg2;
	if (arg3 == 0)
		carr->carry = 1;
	else
		carr->carry = 0;
	carr->regs[arena[carr->pc + 4].ar - 1] = arg3;
}
