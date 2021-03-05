#include "vm.h"

/*
** manage_st() writes a value from the registry that was passed as the first argument
** to the second, which is either a registry or an address, which has to be defined
** with the help of IDX_MOD.
*/

void	manage_st(t_carriage *carr, t_arena *arena)
{
	int		reg;
	int		arg1;
	int		arg2;

	reg = arena[carr->pc + 2].ar;
	arg1 = carr->regs[reg - 1];
	if (carr->args[1] == REG_CODE)
	{
		reg = arena[carr->pc + 2 + carr->arg_size[0]].ar;
		carr->regs[reg - 1] = arg1;
	}
	else //arg2 is T_IND 2
	{
		arg2 = read_bytes(arena, carr->pc + 2 + carr->arg_size[0],
			carr->arg_size[1]);
		arg2 = carr->pc + arg2 % IDX_MOD;
		write_to_memory(arena, arg2, arg1, REG_SIZE);
		update_color(carr, arena, arg2, REG_SIZE);
	}
}

/*
** manage_sti() writes the value of the registry of the first argument
** to the following address: current position +
** (<SECOND_ARGUMENT_VALUE> + <THIRD_ARGUMENT_VALUE>) % IDX_MOD.
** The variable k helps move the correct amount of bytes to the
** last argument.
*/

void	manage_sti(t_carriage *carr, t_arena *arena)
{
	int		arg1;
	int		arg2;
	int		arg3;
	int		pos;
	int		k; //makes it easier to keep track of what byte we are reading at the moment

	arg1 = carr->regs[arena[carr->pc + 2].ar - 1];
	k = 2 + carr->arg_size[0];
	if (carr->args[1] == REG_CODE)
		arg2 = carr->regs[arena[carr->pc + k].ar - 1];
	else
	{
		arg2 = read_bytes(arena, carr->pc + k, carr->arg_size[1]);
		if (carr->args[1] == IND_CODE)
		{
			arg2 = carr->pc + arg2 % IDX_MOD;
			arg2 = read_bytes(arena, arg2, REG_SIZE);
		}
	}
	k += carr->arg_size[1];
	if (carr->args[2] == REG_CODE)
		arg3 = carr->regs[arena[carr->pc + k].ar - 1];
	else
		arg3 = read_bytes(arena, carr->pc + k, carr->arg_size[2]);
	pos = carr->pc + (arg2 + arg3) % IDX_MOD;
	write_to_memory(arena, pos, arg1, REG_SIZE);
	update_color(carr, arena, pos, REG_SIZE);
}
