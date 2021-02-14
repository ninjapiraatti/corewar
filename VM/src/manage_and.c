# include "vm.h"

/*
** Reads REG_SIZE 4 bytes from arena address
** Should it return int, char *, or should it straight copy it to reg?
** If copying to reg then how? how can you move one byte at a time in int
*/

int		read_address(t_arena *arena, int pc)
{
	unsigned char	*nb; // or int? but if int then how?
	int	i;

	pc = pc % MEM_SIZE;
	i = 0;
	while (i < REG_SIZE)
	{
		nb[i] = arena[pc].ar;
		i++;
		pc++;
		if (pc == MEM_SIZE)
		pc = pc % MEM_SIZE;
	}
}

void	manage_and(t_carriage *carr, t_arena *arena)
{
	int	arg1;
	int	arg2;
	int	arg3;
	int	nb;

	arg1 = arena[carr->pc + 2].ar; // either number or address to number
	arg2 = arena[carr->pc + 3].ar; // we can't really read arguments like this because they are of different sizes, not 
	arg3 = arena[carr->pc + 4].ar; // registry where we will write the number to
	if (carr->args[0] == REG_CODE)
		arg1 = carr->regs[arg1 - 1];
	else if (carr->args[0] == IND_CODE)
		arg1 = read_address(arena, carr->pc + arg1 % IDX_MOD);
	else
		ft_printf("argument error.");
	if (carr->args[1] == REG_CODE)
		arg2 = carr->regs[arg2 - 1];
	else if (carr->args[1] == IND_CODE)
		arg2 = read_address(arena, carr->pc + arg2 % IDX_MOD);
	else
		ft_printf("argument error.");
	if (carr->args[2] == DIR_CODE)
		arg3 = carr->regs[arg3 - 1];
	else
		ft_printf("argument error.");
	if (arg1 & arg2 == 1)
		arg3 = 1;
	else
		arg3 = 0;
}