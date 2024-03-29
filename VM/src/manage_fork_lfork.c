/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_fork_lfork.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:53:38 by ksalmi            #+#    #+#             */
/*   Updated: 2021/03/18 10:53:42 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Function creates a new carriage and copies the necessary
** variables and initializes the registries to the same
** as those in the original carriage and sets the new pc to
** the address calculated from the statement argument.
*/

void	manage_fork(t_game *game, t_carriage *carr)
{
	int			arg;
	int			address;
	t_carriage	*new;

	arg = read_bytes(game->arena, carr->pc + 1, 2);
	address = (unsigned int)(carr->pc + (arg % IDX_MOD)) % MEM_SIZE;
	new = create_carriage(carr->color_id, address);
	new->carry = carr->carry;
	new->last_live = carr->last_live;
	init_registries(new->regs, carr->color_id, carr->regs);
	new->next_state = 0;
	ft_add_carriage(&(game->head), new);
	game->arena[new->pc].color_carr = new->color_id;
	if (game->flags->moves)
		ft_printf(" %d (%d)\n", arg, address);
}

/*
** Does the same as manage_fork() except the address calculated from
** the argument isn't truncated by IDX_MOD.
*/

void	manage_lfork(t_game *game, t_carriage *carr)
{
	int			arg;
	int			address;
	t_carriage	*new;

	arg = read_bytes(game->arena, carr->pc + 1, 2);
	address = (unsigned int)(carr->pc + arg) % MEM_SIZE;
	new = create_carriage(carr->color_id, address);
	new->carry = carr->carry;
	new->last_live = carr->last_live;
	init_registries(new->regs, carr->color_id, carr->regs);
	new->next_state = 0;
	ft_add_carriage(&(game->head), new);
	game->arena[new->pc].color_carr = new->color_id;
	if (game->flags->moves)
		ft_printf(" %d (%d)\n", arg, address);
}
