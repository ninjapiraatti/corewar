#include "vm.h"

size_t	get_arg_size(int arg_type, int inst)
{
	if (arg_type == REG_CODE)
		return (1);
	if (arg_type == DIR_CODE && op_table[inst - 1].t_dir_size == 4)
		return (4);
	else if (arg_type == IND_CODE || arg_type == DIR_CODE)
		return (2);
	return (0);
}

int		check_regs(t_carriage *carr, t_arena *arena)
{
	int		arg;
	int		reg;
	int		i;

	i = modpc(carr->pc + 2);
	arg = 0;
	while (arg < 3)
	{
		if (carr->args[arg] == REG_CODE)
		{
			reg = arena[i].ar;
			if (reg < 1 || reg > 16)
				return (0);
		}
		i += carr->arg_size[arg];
		i = (unsigned int)i % MEM_SIZE;
		arg++;
	}
	return (1);
}

int		check_args(char arg, int i, int inst)
{
	int		j;
	int		count;

	j = -1;
	count = 0;
	while (++j < 3)
	{
		if (op_table[inst].arguments[i][j] == 0)
			count++;
	}
	if (count < 3 && arg == 0)
		return (0);
	j = 0;
	while (j < 3)
	{
		if (op_table[inst].arguments[i][j] == arg)
			return (1);
		j++;
	}
	return (0);
}

int		check_code(int inst, unsigned char arg_code, t_carriage *c, t_arena *a)
{
	int		i;
	int		prob;

	i = 0;
	prob = 0;
	c->args[0] = arg_code >> 6;
	c->args[1] = (arg_code >> 4) & 3;
	c->args[2] = (arg_code >> 2) & 3;
	c->arg_size[0] = get_arg_size(c->args[0], inst);
	c->arg_size[1] = get_arg_size(c->args[1], inst);
	c->arg_size[2] = get_arg_size(c->args[2], inst);
	c->next_state = 2;
	while (i < op_table[inst - 1].arg_amount)
	{
		c->next_state += c->arg_size[i];
		if (!check_args(c->args[i], i, inst - 1))
			prob = 1;
		i++;
	}
	if (prob)
		return (0);
	return (check_regs(c, a));
}

int		check_inst(int inst, unsigned char arg_code, t_carriage *c, t_arena *a)
{
	if (inst > 0 && inst < 17)
	{
		if (op_table[inst - 1].arg_type_code == 1)
			return (check_code(inst, arg_code, c, a));
		else
			c->next_state = 1 + op_table[inst - 1].t_dir_size;
		return (1);
	}
	return (0);
}
