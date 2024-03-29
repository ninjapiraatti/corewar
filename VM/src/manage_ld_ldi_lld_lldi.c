/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ld_ldi_lld_lldi.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:54:27 by spentti           #+#    #+#             */
/*   Updated: 2021/03/18 11:54:29 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	manage_ld(t_carriage *c, t_game *game)
{
	int	arg1;
	int	arg2;

	arg2 = game->arena[modpc(c->pc + 2 + c->as[0])].ar;
	arg1 = read_bytes(game->arena, c->pc + 2, c->as[0]);
	if (c->args[0] == IND_CODE)
		arg1 = read_bytes(game->arena, c->pc + arg1 % IDX_MOD, REG_SIZE);
	c->regs[arg2 - 1] = arg1;
	if (arg1 == 0)
		c->carry = 1;
	else
		c->carry = 0;
	if (game->flags->moves == 1)
		ft_printf(" %d r%d\n", arg1, arg2);
}

/*
** arg1 reg / dir / ind
** arg2 reg / dir
** arg3 reg
** 4 bytes from pc + (arg1 value + arg2 value) % IDX_MOD is written to arg3
** check if original corewar sets carry also in ldi
*/

void	manage_ldi(t_carriage *c, t_game *game)
{
	int	arg1;
	int	arg2;
	int	arg3;
	int	pos;

	arg1 = read_bytes(game->arena, c->pc + 2, c->as[0]);
	arg2 = read_bytes(game->arena, c->pc + 2 + c->as[0], c->as[1]);
	arg3 = read_bytes(game->arena, c->pc + 2 + c->as[0] + c->as[1],
	c->as[2]);
	if (c->args[0] == REG_CODE)
		arg1 = c->regs[arg1 - 1];
	else if (c->args[0] == IND_CODE)
		arg1 = read_bytes(game->arena, c->pc + arg1 % IDX_MOD, REG_SIZE);
	if (c->args[1] == REG_CODE)
		arg2 = c->regs[arg2 - 1];
	pos = read_bytes(game->arena, c->pc + (arg1 + arg2) % IDX_MOD, REG_SIZE);
	c->regs[arg3 - 1] = pos;
	if (game->flags->moves == 1)
	{
		ft_printf(" %d %d r%d\n", arg1, arg2, arg3);
		ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
			arg1, arg2, arg1 + arg2, c->pc + (arg1 + arg2) % IDX_MOD);
	}
}

/*
** At line 68, original corewar reads 2 bytes but it's more logical
** to read 4 bytes
*/

void	manage_lld(t_carriage *c, t_game *game)
{
	int	arg1;
	int	arg2;

	arg2 = game->arena[c->pc + 2 + c->as[0]].ar;
	arg1 = read_bytes(game->arena, c->pc + 2, c->as[0]);
	if (c->args[0] == IND_CODE)
		arg1 = read_bytes(game->arena, c->pc + arg1, 2);
	c->regs[arg2 - 1] = arg1;
	if (arg1 == 0)
		c->carry = 1;
	else
		c->carry = 0;
	if (game->flags->moves == 1)
		ft_printf(" %d %d\n", arg1, arg2);
}

void	manage_lldi(t_carriage *c, t_game *game)
{
	int	arg1;
	int	arg2;
	int	arg3;

	arg1 = read_bytes(game->arena, c->pc + 2, c->as[0]);
	arg2 = read_bytes(game->arena, c->pc + 2 + c->as[0], c->as[1]);
	arg3 = read_bytes(game->arena, c->pc + 2 + c->as[0] + c->as[1],
	c->as[2]);
	if (c->args[0] == REG_CODE)
		arg1 = c->regs[arg1 - 1];
	else if (c->args[0] == IND_CODE)
		arg1 = read_bytes(game->arena, c->pc + arg1 % IDX_MOD, REG_SIZE);
	if (c->args[1] == REG_CODE)
		arg2 = c->regs[arg2 - 1];
	c->regs[arg3 - 1] = read_bytes(game->arena, c->pc +
	(arg1 + arg2), REG_SIZE);
	if (c->regs[arg3 - 1] == 0)
		c->carry = 1;
	else
		c->carry = 0;
	if (game->flags->moves == 1)
		ft_printf(" %d %d %d\n", arg1, arg2, arg3);
}
