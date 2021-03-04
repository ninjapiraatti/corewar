#include "vm.h"

void	manage_aff(t_carriage *carr, t_arena *arena, t_flag *flags)
{
	int		arg;

	arg = arena[carr->pc + 1].ar;
	if (flags->aff == 1)
		ft_printf("AFF: %c\n", (char)carr->regs[arg]);
}
