/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_aff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:00:08 by pkuussaa          #+#    #+#             */
/*   Updated: 2021/03/18 12:00:11 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	manage_aff(t_carriage *carr, t_arena *arena, t_flag *flags)
{
	int		arg;

	arg = arena[modpc(carr->pc + 2)].ar;
	if (flags->aff == 1)
		ft_printf("AFF: %c\n", (char)carr->regs[arg - 1]);
}
