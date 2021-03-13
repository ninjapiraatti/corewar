#include "vm.h"

/*
** manage_st() writes a value from the registry that was passed as the first
** argument to the second, which is either a registry or an address, which has
** to be defined with the help of IDX_MOD.
*/

void	manage_st(t_carriage *carr, t_arena *arena)
{
	int	reg;
	int	arg1;
	int	arg2;
	int	pos;

	arg1 = get_registry_content(arena, carr, 0);
	if (carr->args[1] == REG_CODE)
	{
		pos = (unsigned int)(carr->pc + 2 + carr->arg_size[0]) % MEM_SIZE;
		reg = arena[pos].ar;
		carr->regs[reg - 1] = arg1;
	}
	else
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

void	manage_sti(t_carriage *c, t_arena *arena)
{
	int	arg1;
	int	arg2;
	int	arg3;
	int	pos;

	if (c->carr_id == 1268)
		ft_printf("im in sti\n");
	arg1 = get_registry_content(arena, c, 0);
	if (c->args[1] == REG_CODE)
		arg2 = get_registry_content(arena, c, c->arg_size[0]);
	else
	{
		arg2 = read_bytes(arena, c->pc + 2 + c->arg_size[0], c->arg_size[1]);
		if (c->args[1] == IND_CODE)
		{
			arg2 = c->pc + arg2 % IDX_MOD;
			arg2 = read_bytes(arena, arg2, REG_SIZE);
		}
	}
	if (c->args[2] == REG_CODE)
		arg3 = get_registry_content(arena, c, c->arg_size[0] + c->arg_size[1]);
	else
		arg3 = read_bytes(arena, c->pc + 2 + c->arg_size[0] + c->arg_size[1],
			c->arg_size[2]);
	pos = c->pc + (arg2 + arg3) % IDX_MOD;
	write_to_memory(arena, pos, arg1, REG_SIZE);
	update_color(c, arena, pos, REG_SIZE);
	// ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
	// 	arg2, arg3, arg2 + arg3, pos);
}
