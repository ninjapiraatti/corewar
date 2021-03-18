/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_zjmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:54:07 by ksalmi            #+#    #+#             */
/*   Updated: 2021/03/18 10:54:08 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	manage_zjmp(t_game *game, t_carriage *carr)
{
	int		arg;
	int		address;

	arg = read_bytes(game->arena, carr->pc + 1, 2);
	address = modpc(carr->pc + (arg % IDX_MOD));
	if (carr->carry)
	{
		game->arena[carr->pc].color_carr = 0;
		carr->pc = address;
		game->arena[carr->pc].color_carr = carr->color_id;
		carr->next_state = JUMPED;
	}
	if (game->flags->moves)
	{
		ft_printf(" %d", arg);
		if (carr->carry)
			ft_printf(" OK\n");
		else
			ft_printf(" FAILED\n");
	}
}
