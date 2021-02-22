# include "vm.h"

void	manage_ld(t_carriage *carr, t_arena *arena)
{
	int	arg1;
	int	arg2;

	arg2 = arena[carr->pc + 2 + carr->arg_size[0]].ar; // registry where we will write the number to
	arg1 = read_bytes(arena, carr->pc + 2, carr->arg_size[0]);
	if (carr->args[0] == IND_CODE)
	{
		arg1 = read_bytes(arena, carr->pc + arg1 % IDX_MOD, REG_SIZE);
		// ft_printf("read indirect %d\n", arg1);
	}
	carr->regs[arg2 - 1] = arg1;
	// ft_printf("reg[%d]: %d arg1: %d\n", arg2, carr->regs[arg2 - 1], arg1);
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
	// ft_printf("arg1 %d arg2: %d\n", arg1, arg2);
	// ft_printf("reg[%d]: %d\n", arg3, carr->regs[arg3 - 1]);
	carr->regs[arg3 - 1] = read_bytes(arena, carr->pc + (arg1 + arg2) % IDX_MOD, 4);
	// ft_printf("reg[%d]: %d from %d\n", arg3, carr->regs[arg3 - 1], carr->pc + (arg1 + arg2) % IDX_MOD);
}

void	manage_lld(t_carriage *carr, t_arena *arena)
{
	int	arg1;
	int	arg2;

	arg2 = arena[carr->pc + 2 + carr->arg_size[0]].ar;
	arg1 = read_bytes(arena, carr->pc + 2, carr->arg_size[0]);
	if (carr->args[0] == IND_CODE)
		arg1 = read_bytes(arena, carr->pc + arg1, 4);
	carr->regs[arg2 - 1] = arg1;
	// ft_printf("reg[%d]: %d arg1: %d\n", arg2, carr->regs[arg2 - 1], arg1);
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
	// ft_printf("arg1 %d arg2: %d\n", arg1, arg2);
	// ft_printf("reg[%d]: %d\n", arg3, carr->regs[arg3 - 1]);
	carr->regs[arg3 - 1] = read_bytes(arena, carr->pc + (arg1 + arg2), 4);
	// ft_printf("reg[%d]: %d from %d\n", arg3, carr->regs[arg3 - 1], carr->pc + (arg1 + arg2));
}
