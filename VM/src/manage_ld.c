# include "vm.h"

void    write_to_memory(t_arena *arena, unsigned int pos, int arg, int size)
{
    int i;
    i = size - 1;
    while (i >= 0)
    {
        if (pos >= MEM_SIZE)
            pos = pos % MEM_SIZE;
        arena[pos].ar = arg >> (8 * i) & 0xff;
        i--;
        pos++;
    }
}

/*
** Reads size bytes from arena address
** Converts bytes to int and returns int.
** Currently only allows sizes 1, 2 and 4
*/

int		read_bytes(t_arena *arena, int index, int size)
{
	unsigned char	buf[size]; // is it ok to define string size like this?
	int				i;

	i = 0;
	if (size != 1 && size != 2 && size != 4)
		return (0);
	if (size == 1)
		return ((int)arena[index].ar);
	ft_memset(buf, 0, size);
	while (i < size)
	{
		index = index % MEM_SIZE;
		buf[i] = arena[index].ar;
		i++;
		index++;
	}
	if (size == 4)
		return ((buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | buf[3]);
	if (size == 2)
		return (buf[0] << 8 | buf[1]);
	return (0);
}

void	manage_ld(t_carriage *carr, t_arena *arena)
{
	int	arg1;
	int	arg2;

	arg2 = arena[carr->pc + 2 + carr->arg_size[0]].ar; // registry where we will write the number to
	if (carr->args[0] == DIR_CODE)
		arg1 = read_bytes(arena, carr->pc + 2, carr->arg_size[0]);
	else
		arg1 = read_bytes(arena, carr->pc + 2, carr->arg_size[0]);
		arg1 = read_bytes(arena, carr->pc + arg1 % IDX_MOD, 4);
		ft_printf("read indirect %d\n", arg1);
	carr->regs[arg2 - 1] = arg1;
	ft_printf("reg[%d]: %d arg1: %d\n", arg2, carr->regs[arg2 - 1], arg1);
	if (arg1 == 0)
		carr->carry = 1;
	else
		carr->carry = 0;
}

/*
** arg1 reg / dir / ind
** arg2 reg / dir
** arg3 reg
** 4 bytes from pc + (arg1 value + arg2 value) % IDX_MOD is written to arg3
** check if original corewar sets carry also in ldi
*/

void	manage_ldi(t_carriage *carr, t_arena *arena)
{
	int	arg1;
	int	arg2;
	int	arg3;

	arg1 = read_bytes(arena, carr->pc + 2, carr->arg_size[0]);
	arg2 = read_bytes(arena, carr->pc + 2 + carr->arg_size[0], carr->arg_size[1]);
	arg3 = read_bytes(arena, carr->pc + 2 + carr->arg_size[0] + carr->arg_size[1], carr->arg_size[2]);
	if (carr->args[0] == REG_CODE)
		arg1 = carr->regs[arg1 - 1];
	else if (carr->args[0] == IND_CODE)
		arg1 = read_bytes(arena, carr->pc + arg1 % IDX_MOD, carr->arg_size[0]);
	if (carr->args[1] == REG_CODE)
		arg2 = carr->regs[arg2 - 1];
	ft_printf("arg1 %d arg2: %d\n", arg1, arg2);
	ft_printf("reg[%d]: %d\n", arg3, carr->regs[arg3 - 1]);
	carr->regs[arg3 - 1] = read_bytes(arena, carr->pc + (arg1 + arg2) % IDX_MOD, 4);
	ft_printf("reg[%d]: %d from %d\n", arg3, carr->regs[arg3 - 1], carr->pc + (arg1 + arg2) % IDX_MOD);
}

void	manage_lld(t_carriage *carr, t_arena *arena)
{
	int	arg1;
	int	arg2;

	arg2 = arena[carr->pc + 2 + carr->arg_size[0]].ar;
	if (carr->args[0] == DIR_CODE)
		arg1 = read_bytes(arena, carr->pc + 2, carr->arg_size[0]);
	else
	{
		arg1 = read_bytes(arena, carr->pc + 2, carr->arg_size[0]);
		arg1 = read_bytes(arena, carr->pc + arg1, 4);
	}
	carr->regs[arg2 - 1] = arg1;
	ft_printf("reg[%d]: %d arg1: %d\n", arg2, carr->regs[arg2 - 1], arg1);
	if (arg1 == 0)
		carr->carry = 1;
	else
		carr->carry = 0;
}

void	manage_lldi(t_carriage *carr, t_arena *arena)
{
	int	arg1;
	int	arg2;
	int	arg3;

	arg1 = read_bytes(arena, carr->pc + 2, carr->arg_size[0]);
	arg2 = read_bytes(arena, carr->pc + 2 + carr->arg_size[0], carr->arg_size[1]);
	arg3 = read_bytes(arena, carr->pc + 2 + carr->arg_size[0] + carr->arg_size[1], carr->arg_size[2]);
	if (carr->args[0] == REG_CODE)
		arg1 = carr->regs[arg1 - 1];
	else if (carr->args[0] == IND_CODE)
		arg1 = read_bytes(arena, carr->pc + arg1 % IDX_MOD, carr->arg_size[0]);
	if (carr->args[1] == REG_CODE)
		arg2 = carr->regs[arg2 - 1];
	ft_printf("arg1 %d arg2: %d\n", arg1, arg2);
	ft_printf("reg[%d]: %d\n", arg3, carr->regs[arg3 - 1]);
	carr->regs[arg3 - 1] = read_bytes(arena, carr->pc + (arg1 + arg2), 4);
	ft_printf("reg[%d]: %d from %d\n", arg3, carr->regs[arg3 - 1], carr->pc + (arg1 + arg2));
}

/*
** Orded of actions inside the cycle
** 1. set statement code
** 2. reduce the number of cycles before execution
** 3. perform statement if cycles_to_wait is 0 and everything is valid
** 4. move carriage to the next position if cycles_to_wait is 0.
*/

void    run_carriage(t_arena *arena, t_carriage *carr)
{
    char    inst;
    char    arg_code;

    inst = arena[carr->pc].ar;
    arg_code = arena[carr->pc + 1].ar;
	arg_code = 10;
	carr->cycles_to_wait = 0; // move this to initialising carr
    if (carr->cycles_to_wait == 0 && inst > 0 && inst < 17) // 1. set statement code
        carr->cycles_to_wait = 1; // op_table[inst - 1].cycles_to_wait;
    if (carr->cycles_to_wait > 0) // 2. reduce number of cycles before execution
        carr->cycles_to_wait--;
    if (carr->cycles_to_wait == 0)
    {
        if (inst > 0 && inst < 17)
        {
            if (check_arg_type_code(inst, arg_code, carr)) // 3. perform statement
			{
				if (check_regs(inst, carr, arena)) // possibly move to check_arg_type_code but then need to add arena as parameter
				{
					ft_printf("ready to perform statement!\n");
					// ft_printf("reg6: %s\n", carr->regs[5]);
					// manage_ldi(carr, arena);
					// ft_printf("reg6: %s\n", carr->regs[5]);
                	// perform_statement(inst, arena, carr);
				}
			}
        }
        else
            carr->next_state = 1;
        carr->pc += carr->next_state; // 4. move carriage
        if (carr->pc >= MEM_SIZE)
            carr->pc = carr->pc % MEM_SIZE;
    }
}