/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:54:01 by spentti           #+#    #+#             */
/*   Updated: 2021/03/18 11:54:03 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static size_t	get_arg_size(int arg_type, int inst)
{
	if (arg_type == REG_CODE)
		return (1);
	if (arg_type == DIR_CODE && g_op_table[inst - 1].t_dir_size == 4)
		return (4);
	else if (arg_type == IND_CODE || arg_type == DIR_CODE)
		return (2);
	return (0);
}

static int		check_regs(t_carriage *carr, t_arena *arena)
{
	int		arg;
	int		reg;
	int		i;

	i = modpc(carr->pc + 2);
	arg = 0;
	while (arg < 3)
	{
		if (carr->args[arg] == REG_CODE)
		{
			reg = arena[i].ar;
			if (reg < 1 || reg > 16)
				return (0);
		}
		i += carr->as[arg];
		i = (unsigned int)i % MEM_SIZE;
		arg++;
	}
	return (1);
}

static int		check_args(char arg, int i, int inst)
{
	int		j;
	int		count;

	j = -1;
	count = 0;
	while (++j < 3)
	{
		if (g_op_table[inst].arguments[i][j] == 0)
			count++;
	}
	if (count < 3 && arg == 0)
		return (0);
	j = 0;
	while (j < 3)
	{
		if (g_op_table[inst].arguments[i][j] == arg)
			return (1);
		j++;
	}
	return (0);
}

static int		check_code(unsigned char atc, t_carriage *c, t_arena *a)
{
	int		i;
	int		prob;

	i = 0;
	prob = 0;
	c->args[0] = atc >> 6;
	c->args[1] = (atc >> 4) & 3;
	c->args[2] = (atc >> 2) & 3;
	c->as[0] = get_arg_size(c->args[0], c->inst);
	c->as[1] = get_arg_size(c->args[1], c->inst);
	c->as[2] = get_arg_size(c->args[2], c->inst);
	c->next_state = 2;
	while (i < g_op_table[c->inst - 1].arg_amount)
	{
		c->next_state += c->as[i];
		if (!check_args(c->args[i], i, c->inst - 1))
			prob = 1;
		i++;
	}
	if (prob)
		return (0);
	return (check_regs(c, a));
}

int				check_inst(unsigned char atc, t_carriage *c, t_arena *a)
{
	if (c->inst > 0 && c->inst < 17)
	{
		if (g_op_table[c->inst - 1].arg_type_code == 1)
			return (check_code(atc, c, a));
		else
			c->next_state = 1 + g_op_table[c->inst - 1].t_dir_size;
		return (1);
	}
	return (0);
}
