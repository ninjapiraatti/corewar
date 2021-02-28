# include "vm.h"

void	manage_and_or_xor(t_carriage *carr, t_arena *arena, int op)
{
	int	arg1;
	int	arg2;
	int	arg3;
	int res;

	res = 0;
	op--;
	arg1 = read_bytes(arena, carr->pc + 2, carr->arg_size[0]);
	arg2 = read_bytes(arena, carr->pc + 2 + carr->arg_size[0], carr->arg_size[1]);
	arg3 = read_bytes(arena, carr->pc + 2 + carr->arg_size[0] + carr->arg_size[1], carr->arg_size[2]);
	ft_putstr_fd("Arg1 and size: ", 2);
	ft_putnbr_fd(arg1, 2);
	ft_putstr_fd("|", 2);
	ft_putnbr_fd(carr->arg_size[0], 2);
	ft_putstr_fd("  Arg2 and size: ", 2);
	ft_putnbr_fd(arg2, 2);
	ft_putstr_fd("|", 2);
	ft_putnbr_fd(carr->arg_size[1], 2);
	ft_putstr_fd("  Arg3 and size: ", 2);
	ft_putnbr_fd(arg3, 2);
	ft_putstr_fd("|", 2);
	ft_putnbr_fd(carr->arg_size[2], 2);
	if (carr->args[0] == REG_CODE) {
		arg1 = carr->regs[arg1 - 1];
		//ft_putnbr_fd(carr->args[2], 2);
		//ft_putstr_fd("\n", 2);
	}
	else if (carr->args[0] == IND_CODE)
		arg1 = read_bytes(arena, carr->pc + arg1 % IDX_MOD, carr->arg_size[0]);
	else
		arg1 = carr->args[0];
	if (carr->args[1] == REG_CODE)
		arg2 = carr->regs[arg2 - 1];
	else if (carr->args[1] == IND_CODE)
		arg2 = read_bytes(arena, carr->pc + arg2 % IDX_MOD, carr->arg_size[1]);
	else
		arg2 = carr->args[1];
	carr->regs[arg3 - 1] = read_bytes(arena, carr->pc + (arg1 + arg2) % IDX_MOD, 4);
	/*
	if (carr->args[2] == REG_CODE) {
		//ft_putnbr_fd(carr->regs[0], 2);
		arg3 = carr->regs[arg3 - 1];
	}
	else
		ft_printf("argument error in arg3.\n");
	*/
	if (arg1 & arg2) {
		carr->carry = 1;
		res = 1;
	}
	else {
		carr->carry = 0;
		res = 0;
	}
	carr->regs[arg3 - 1] = res;
	ft_putstr_fd(" res of OP:", 2);
	ft_putnbr_fd(carr->regs[arg3 - 1], 2);
	ft_putstr_fd("\n", 2);
	/*
	ft_putstr_fd("Value in reg ", 2);
	ft_putnbr_fd(arg3, 2);
	ft_putstr_fd(":", 2);
	ft_putnbr_fd(carr->regs[arg3 - 1], 2);
	ft_putstr_fd("\n", 2);
	*/
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