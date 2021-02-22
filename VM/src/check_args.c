# include "vm.h"

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

	i = carr->pc + 2;
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
		arg++;
	}
	return (1);
}

int     check_args(char arg, int i, int inst)
{
    int     j;
    int     count;

    j = -1;
    count = 0;
    while (++j < 3)
        if (op_table[inst].arguments[i][j] == 0)
            count++;
    if (count < 3 && arg == 0)
        return (0);
    j = 0;
    while (j < 3)
    {
        if (op_table[inst].arguments[i][j] == arg)
            return (1);
        j++;
    }
    ft_printf("returned 0\n");
    return (0);
}

int     check_arg_type_code(int inst, unsigned char arg_code, t_carriage *carr, t_arena *arena)
{
    int     i;

    i = 0;

    carr->args[0] = arg_code >> 6;
    carr->args[1] = (arg_code >> 4) & 3;
    carr->args[2] = (arg_code >> 2) & 3;
    carr->arg_size[0] = get_arg_size(carr->args[0], inst);
	carr->arg_size[1] = get_arg_size(carr->args[1], inst);
	carr->arg_size[2] = get_arg_size(carr->args[2], inst);
    carr->next_state = carr->pc + 2 + carr->arg_size[0] + carr->arg_size[1] + carr->arg_size[2];
    while(i < 3)
    {
        if (!check_args(carr->args[i], i, inst - 1))
            return (0);
        i++;
    }
    // ft_printf("arg type code valid!\n");
    return (check_regs(carr, arena));
}

int     check_instruction(int inst, unsigned char arg_code, t_carriage *carr, t_arena *arena)
{
    if (op_table[inst - 1].arg_type_code == 1)
        return (check_arg_type_code(inst, arg_code, carr, arena));
    else
        carr->next_state = carr->pc + 1 + op_table[inst - 1].t_dir_size;
    return (1);
}
