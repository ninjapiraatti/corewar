#include "vm.h"

void	manage_aff(t_carriage *carr, t_arena *arena, t_flag *flags)
{
	int		arg;

	arg = arena[modpc(carr->pc + 2)].ar;
	if (flags->aff == 1)
		ft_printf("AFF: %c\n", (char)carr->regs[arg - 1]);
}
