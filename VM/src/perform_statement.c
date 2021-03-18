/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_statement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:54:57 by spentti           #+#    #+#             */
/*   Updated: 2021/03/18 11:54:58 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	perform_statement2(t_carriage *carr, t_game *game, int inst)
{
	if (inst == 10)
		manage_ldi(carr, game);
	else if (inst == 11)
		manage_sti(carr, game);
	else if (inst == 12)
		manage_fork(game, carr);
	else if (inst == 13)
		manage_lld(carr, game);
	else if (inst == 14)
		manage_lldi(carr, game);
	else if (inst == 15)
		manage_lfork(game, carr);
	else if (inst == 16)
		manage_aff(carr, game->arena, game->flags);
}

void	perform_statement(t_carriage *carr, t_game *game, int inst)
{
	if (inst == 1)
		manage_live(carr, game);
	else if (inst == 2)
		manage_ld(carr, game);
	else if (inst == 3)
		manage_st(carr, game);
	else if (inst == 4)
		manage_add(carr, game);
	else if (inst == 5)
		manage_sub(carr, game);
	else if (inst == 6)
		manage_and(carr, game);
	else if (inst == 7)
		manage_or(carr, game);
	else if (inst == 8)
		manage_xor(carr, game);
	else if (inst == 9)
		manage_zjmp(game, carr);
	else
		perform_statement2(carr, game, inst);
}
