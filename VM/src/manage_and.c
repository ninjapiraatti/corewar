#include "vm.h"

int		do_operation(int arg1, int arg2, int op)
{
	int	res;

	res = 0;
	if (op == OP_AND)
		res = arg1 & arg2;
	else if (op == OP_OR)
		res = arg1 | arg2;
	else if (op == OP_XOR)
		res = arg1 ^ arg2;
	return (res);
}

void	manage_and_or_xor(t_carriage *carr, t_game *game, int op)
{
	int		arg1;
	int		arg2;
	int		arg3;
	int		res;

	res = 0;
	arg1 = read_bytes(game->arena, carr->pc + 2, carr->arg_size[0]);
	arg2 = read_bytes(game->arena, carr->pc + 2 +
		carr->arg_size[0], carr->arg_size[1]);
	arg3 = game->arena[modpc(carr->pc + 2 + carr->arg_size[0] +
		carr->arg_size[1])].ar;
	if (carr->args[0] == REG_CODE)
		arg1 = carr->regs[arg1 - 1];
	else if (carr->args[0] == IND_CODE)
		arg1 = read_bytes(game->arena, carr->pc + arg1 % IDX_MOD, REG_SIZE);
	if (carr->args[1] == REG_CODE)
		arg2 = carr->regs[arg2 - 1];
	else if (carr->args[1] == IND_CODE)
		arg2 = read_bytes(game->arena, carr->pc + arg2 % IDX_MOD, REG_SIZE);
	res = do_operation(arg1, arg2, op);
	carr->carry = res == 0 ? 1 : 0;
	carr->regs[arg3 - 1] = res;
	if (game->flags->moves)
		ft_printf(" %d %d r%d\n", arg1, arg2, arg3);
}

void	manage_and(t_carriage *carr, t_game *game)
{
	manage_and_or_xor(carr, game, OP_AND);
}

void	manage_or(t_carriage *carr, t_game *game)
{
	manage_and_or_xor(carr, game, OP_OR);
}

void	manage_xor(t_carriage *carr, t_game *game)
{
	manage_and_or_xor(carr, game, OP_XOR);
}
