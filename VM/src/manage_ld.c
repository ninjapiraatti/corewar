#include "vm.h"

void	manage_ld(t_carriage *c, t_arena *arena)
{
	int	arg1;
	int	arg2;

	arg2 = arena[c->pc + 2 + c->arg_size[0]].ar;
	arg1 = read_bytes(arena, c->pc + 2, c->arg_size[0]);
	if (c->args[0] == IND_CODE)
		arg1 = read_bytes(arena, c->pc + arg1 % IDX_MOD, REG_SIZE);
	c->regs[arg2 - 1] = arg1;
	if (arg1 == 0)
		c->carry = 1;
	else
		c->carry = 0;
}

/*
** arg1 reg / dir / ind
** arg2 reg / dir
** arg3 reg
** 4 bytes from pc + (arg1 value + arg2 value) % IDX_MOD is written to arg3
** check if original corewar sets carry also in ldi
*/

void	manage_ldi(t_carriage *c, t_arena *arena)
{
	int	arg1;
	int	arg2;
	int	arg3;
	int	pos;

	arg1 = read_bytes(arena, c->pc + 2, c->arg_size[0]);
	arg2 = read_bytes(arena, c->pc + 2 + c->arg_size[0], c->arg_size[1]);
	arg3 = read_bytes(arena, c->pc + 2 + c->arg_size[0] + c->arg_size[1], \
	c->arg_size[2]);
	if (c->args[0] == REG_CODE)
		arg1 = c->regs[arg1 - 1];
	else if (c->args[0] == IND_CODE)
		arg1 = read_bytes(arena, c->pc + arg1 % IDX_MOD, REG_SIZE);
	if (c->args[1] == REG_CODE)
		arg2 = c->regs[arg2 - 1];
	pos = read_bytes(arena, c->pc + (arg1 + arg2) % IDX_MOD, REG_SIZE);
	c->regs[arg3 - 1] = pos;
	// ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
	// 	arg1, arg2, arg1 + arg2,  c->pc + (arg1 + arg2) % IDX_MOD);
}

void	manage_lld(t_carriage *c, t_arena *arena)
{
	int	arg1;
	int	arg2;

	if (c->carr_id == 1268)
		ft_printf("im in lld\n");
	arg2 = arena[c->pc + 2 + c->arg_size[0]].ar;
	arg1 = read_bytes(arena, c->pc + 2, c->arg_size[0]);
	if (c->args[0] == IND_CODE)
		arg1 = read_bytes(arena, c->pc + arg1, 2); // should apparently read 4 bytes but original corewar reads 2
	c->regs[arg2 - 1] = arg1;
	if (arg1 == 0)
		c->carry = 1;
	else
		c->carry = 0;
}

void	manage_lldi(t_carriage *c, t_arena *arena)
{
	int	arg1;
	int	arg2;
	int	arg3;

	arg1 = read_bytes(arena, c->pc + 2, c->arg_size[0]);
	arg2 = read_bytes(arena, c->pc + 2 + c->arg_size[0], c->arg_size[1]);
	arg3 = read_bytes(arena, c->pc + 2 + c->arg_size[0] + c->arg_size[1], \
	c->arg_size[2]);
	if (c->args[0] == REG_CODE)
		arg1 = c->regs[arg1 - 1];
	else if (c->args[0] == IND_CODE)
		arg1 = read_bytes(arena, c->pc + arg1 % IDX_MOD, REG_SIZE);
	if (c->args[1] == REG_CODE)
		arg2 = c->regs[arg2 - 1];
	c->regs[arg3 - 1] = read_bytes(arena, c->pc + (arg1 + arg2), REG_SIZE);
	if (c->regs[arg3 - 1] == 0)
		c->carry = 1;
	else
		c->carry = 0;
}
