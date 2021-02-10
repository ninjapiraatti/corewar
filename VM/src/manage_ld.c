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

void	manage_ld(t_carriage *carr, t_arena *arena)
{
	int	arg1;
	int	arg2;
	int	nb;

	arg1 = arena[carr->pc + 2].ar; // either number or address to number
	arg2 = arena[carr->pc + 3].ar; // registry where we will write the number to
	if (carr->args[0] == DIR_CODE)
		nb = arg1;
	else if (carr->args[0] == IND_CODE)
		nb = read_address(arena, carr->pc + arg1 % IDX_MOD);
	carr->regs[arg2] = nb;
	if (nb == 0)
		carr->carry = 1;
	else
		carr->carry = 0;
}

void	manage_ldi(t_carriage *carr, t_arena *arena)
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
		arg1 = read_address(arena, carr->pc + arg1 % IDX_MOD)
	if (carr->args[1] == REG_CODE)
		arg2 = carr->regs[arg1 - 1];
	nb = read_address(arena, carr->pc + (arg1 + arg2) % IDX_MOD);
	carr->regs[arg2] = nb;
}


int     check_args(int inst, int arg_code, t_arena *arena, t_carriage *carr)
{
    if (check_arg_type_code(inst, arg_code))
    {
        // save arg types somewhere in check_arg_type_code
        // check validity of arg types for statement from op_table
        // if there are registries check that they are valid
        return (1);
    }
    return (0);
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
    ft_printf("pc: %d\n", carr->pc + 1);
    if (carr->cycles_to_wait == 0 && inst > 0 && inst < 17) // 1. set statement code
        carr->cycles_to_wait = op_table[inst - 1].cycles_to_wait;
    if (carr->cycles_to_wait > 0) // 2. reduce number of cycles before execution
        carr->cycles_to_wait--;
    if (carr->cycles_to_wait == 0)
    {
        if (inst > 0 && inst < 17)
        {
            if (check_args(inst, arg_code, arena, carr)) // 3. perform statement if everything is ok
                perform_statement(inst, arena, carr);
        }
        else
            carr->next_state = 1;
        carr->pc += carr->next_state; // 4. move carriage
        if (carr->pc >= MEM_SIZE)
            carr->pc = carr->pc % MEM_SIZE;
    }
}