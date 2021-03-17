#include "vm.h"

/*
** manage_st() writes a value from the registry that was passed as the first
** argument to the second, which is either a registry or an address, which has
** to be defined with the help of IDX_MOD.
*/

void	manage_st(t_carriage *carr, t_game *game)
{
	int	reg;
	int	arg1;
	int	pos;
	int	arg2;

	reg = game->arena[modpc(carr->pc + 2)].ar;
	arg1 = carr->regs[reg - 1];
	if (carr->args[1] == REG_CODE)
	{
		pos = modpc(carr->pc + 2 + carr->arg_size[0]);
		carr->regs[game->arena[pos].ar - 1] = arg1;
	}
	else
	{
		pos = read_bytes(game->arena, carr->pc + 2 + carr->arg_size[0],
			carr->arg_size[1]);
		arg2 = carr->pc + pos % IDX_MOD;
		write_to_memory(game->arena, arg2, arg1, REG_SIZE);
		update_color(carr, game->arena, arg2, REG_SIZE);
	}
	if (game->flags->moves)
		ft_printf(" r%d %d\n", reg, pos);
}

/*
** manage_sti() writes the value of the registry of the first argument
** to the following address: current position +
** (<SECOND_ARGUMENT_VALUE> + <THIRD_ARGUMENT_VALUE>) % IDX_MOD.
** The variable k helps move the correct amount of bytes to the
** last argument.
*/

void	manage_sti(t_carriage *c, t_game *game)
{
	int	arg1;
	int	arg2;
	int	arg3;
	int	pos;

	arg1 = c->regs[game->arena[modpc(c->pc + 2)].ar - 1];
	if (c->args[1] == REG_CODE)
		arg2 = get_registry_content(game->arena, c, c->arg_size[0]);
	else
	{
		arg2 = read_bytes(game->arena, c->pc + 2 + c->arg_size[0], c->arg_size[1]);
		if (c->args[1] == IND_CODE)
			arg2 = read_bytes(game->arena, c->pc + arg2 % IDX_MOD, REG_SIZE);
	}
	if (c->args[2] == REG_CODE)
		arg3 = get_registry_content(game->arena, c, c->arg_size[0] + c->arg_size[1]);
	else
		arg3 = read_bytes(game->arena, c->pc + 2 + c->arg_size[0] + c->arg_size[1],
			c->arg_size[2]);
	pos = c->pc + (arg2 + arg3) % IDX_MOD;
	write_to_memory(game->arena, pos, arg1, REG_SIZE);
	update_color(c, game->arena, pos, REG_SIZE);
	if (game->flags->moves)
		print_sti_info(game->arena[modpc(c->pc + 2)].ar, arg2, arg3, pos);
}
