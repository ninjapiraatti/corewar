# include "vm.h"

void	manage_and_or_xor(t_carriage *carr, t_arena *arena, int op)
{
	int	arg1;
	int	arg2;
	int	arg3;
	int res;

	res = 0;
	arg1 = read_bytes(arena, carr->pc + 2, carr->arg_size[0]);
	arg2 = read_bytes(arena, carr->pc + 2 + carr->arg_size[0], carr->arg_size[1]);
	arg3 = arena[carr->pc + 2 + carr->arg_size[0] + carr->arg_size[1]].ar;
	// ft_printf("arg1 %d\narg2 %d\narg3 %d\n", arg1, arg2, arg3);
	if (carr->args[0] == REG_CODE)
		arg1 = carr->regs[arg1 - 1];
	else if (carr->args[0] == IND_CODE)
		arg1 = read_bytes(arena, carr->pc + arg1 % IDX_MOD, REG_SIZE);
	if (carr->args[1] == REG_CODE)
		arg2 = carr->regs[arg2 - 1];
	else if (carr->args[1] == IND_CODE)
		arg2 = read_bytes(arena, carr->pc + arg2 % IDX_MOD, REG_SIZE);
	if (op == OP_AND)
		res = arg1 & arg2;
	else if (op ==  OP_OR)
		res = arg1 | arg2;
	else if (op == OP_XOR)
		res =  arg1 ^ arg2;
	if (res ==  0)
		carr->carry = 1;
	else
		carr->carry = 0;
	carr->regs[arg3 - 1] = res;
	// ft_printf("res %d\n", res);
}

void	manage_and(t_carriage *carr, t_arena *arena) {
	manage_and_or_xor(carr, arena, OP_AND);
}

void	manage_or(t_carriage *carr, t_arena *arena) {
	manage_and_or_xor(carr, arena, OP_OR);
}

void	manage_xor(t_carriage *carr, t_arena *arena) {
	manage_and_or_xor(carr, arena, OP_XOR);
}