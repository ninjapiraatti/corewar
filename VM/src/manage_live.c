/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_live.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:53:49 by ksalmi            #+#    #+#             */
/*   Updated: 2021/03/18 12:02:50 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Performs live statement saving the cycle into the carriage which performed
** the live. If the live corresponds to a player number, it is saved to
** 'game->id_last_live' and printed if the live flag is active.
*/

void	manage_live(t_carriage *carr, t_game *game)
{
	int	arg;

	arg = read_bytes(game->arena, carr->pc + 1, DIR_SIZE);
	if (game->flags->moves)
		ft_printf(" %d\n", arg);
	carr->last_live = game->cycles;
	game->lives_num++;
	arg *= -1;
	if (arg > 0 && arg <= game->players->pl_num)
	{
		game->id_last_live = arg;
		if (game->flags->live)
			ft_printf("Player %d (%s) is said to be alive\n",
				arg, game->players->h_info[arg]->prog_name);
		game->players->last_life[arg] = game->cycles;
	}
}
