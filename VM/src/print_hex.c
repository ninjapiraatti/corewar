#include "vm.h"

void	print_hex(t_arena *arena)
{
	int	i;
	int	j;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("0x%04x   ", i);
		j = 0;
		while (j < 32)
		{
			// if (arena[i].color[0])
				// ft_printf("%s%02x%s ", arena[i].color, arena[i].ar, EOC);
			// else if (arena[i].ar != 0)
				// ft_printf("%s%02x%s ", BLUE, arena[i].ar, EOC);
			// else
				ft_printf("%02x ", arena[i].ar);
			j++;
			i++;
		}
		ft_putchar('\n');
	}
}

void	dump_memory(t_arena *arena)
{
	int	i;
	int	j;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("0x%04x : ", i);
		j = 0;
		while (j < 64) //change back to 32
		{
			ft_printf("%02x ", arena[i].ar);
			j++;
			i++;
		}
		ft_putchar('\n');
	}
	exit(0);
}

void	print_moves(t_carriage *carr, int inst, t_arena *arena)
{
	int	arg;
	int	i;
	int	j;
	int reg;

	ft_printf("P %4d | %s", carr->carr_id, op_table[inst - 1].op_name);
	if (op_table[inst - 1].arg_type_code)
	{
		i = -1;
		j = (unsigned int)(carr->pc + 2) % MEM_SIZE;
		while (++i < 3)
		{
			if (carr->args[i] == REG_CODE)
			{
				reg = arena[j].ar;
				ft_printf(" r%d", reg);
			}
			else if (carr->args[i] != 0)
			{
				arg = read_bytes(arena, j, carr->arg_size[i]);
				if (inst == 2 && carr->args[i] == IND_CODE)
					arg = read_bytes(arena, carr->pc + arg % IDX_MOD, REG_SIZE);
				ft_printf(" %d", arg);
			}
			j = (unsigned int)(j + carr->arg_size[i]) % MEM_SIZE;
		}
	}
	else
	{
		if (inst == 1)
			arg = read_bytes(arena, carr->pc + 1, DIR_SIZE);
		else
		{
			arg = read_bytes(arena, carr->pc + 1, IND_SIZE);
		}
		ft_printf(" %d", arg);
		if (inst == 9)
		{
			if (carr->carry == 1)
				ft_printf(" OK");
			else
				ft_printf(" FAILED");
		}
		if (inst == 12)
			ft_printf(" (%d)", carr->pc + arg);
	}
	ft_putchar('\n');
}