/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_add_sub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:00:26 by pkuussaa          #+#    #+#             */
/*   Updated: 2021/03/18 12:00:27 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	manage_add(t_carriage *carr, t_game *game)
{
	int		arg1;
	int		arg2;
	int		arg3;

	arg1 = carr->regs[game->arena[modpc(carr->pc + 2)].ar - 1];
	arg2 = carr->regs[game->arena[modpc(carr->pc + 3)].ar - 1];
	arg3 = arg1 + arg2;
	if (arg3 == 0)
		carr->carry = 1;
	else
		carr->carry = 0;
	carr->regs[game->arena[modpc(carr->pc + 4)].ar - 1] = arg3;
	if (game->flags->moves)
	{
		ft_printf(" r%d r%d r%d\n",
		game->arena[modpc(carr->pc + 2)].ar,
		game->arena[modpc(carr->pc + 3)].ar,
		game->arena[modpc(carr->pc + 4)].ar);
	}
}

void	manage_sub(t_carriage *carr, t_game *game)
{
	int		arg1;
	int		arg2;
	int		arg3;

	arg1 = game->arena[modpc(carr->pc + 2)].ar;
	arg2 = game->arena[modpc(carr->pc + 3)].ar;
	arg3 = game->arena[modpc(carr->pc + 4)].ar;
	carr->regs[arg3 - 1] = carr->regs[arg1 - 1] - carr->regs[arg2 - 1];
	if (carr->regs[arg3 - 1] == 0)
		carr->carry = true;
	else
		carr->carry = false;
	if (game->flags->moves)
	{
		ft_printf(" r%d r%d r%d\n",
			game->arena[modpc(carr->pc + 2)].ar,
			game->arena[modpc(carr->pc + 3)].ar,
			game->arena[modpc(carr->pc + 4)].ar);
	}
}
