#include "vm.h"

void	manage_aff(t_carriage *carr, t_arena *arena, t_flag *flags)
{
	int		arg;

	arg = arena[(unsigned int)(carr->pc + 2) % MEM_SIZE].ar; //there is an arg_type_code
	if (flags->aff == 1)
		ft_printf("AFF: %c\n", (char)carr->regs[arg - 1]);
}
