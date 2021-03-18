/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:00:06 by ksalmi            #+#    #+#             */
/*   Updated: 2021/03/18 12:00:08 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Gets the content of a registry. Pc is assumed to be in position,
** meaning on the statement it will execute. The '2' is for skipping over
** the argument_type_code byte and 'extra' is to skip over possible arguments.
*/

int	get_reg(t_arena *arena, t_carriage *c, int extra)
{
	int reg;

	reg = c->regs[arena[modpc(c->pc + 2 + extra)].ar - 1];
	return (reg);
}

/*
** Tiny function to save space and apply mod MEM_SIZE
*/

int	modpc(unsigned int address)
{
	return (address % MEM_SIZE);
}
