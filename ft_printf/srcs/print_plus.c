/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:18:49 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/03/13 14:42:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "Libft\libft.h"

t_lst	*print_plus(t_lst *arr, intmax_t i)
{
	if (arr->flag_arr[2] == '+' && i >= 0 && arr->negative == 1)
	{
		if (arr->period == 0 && i == 0)
			arr->period = 0;
		else
		{
			write(1, "+", 1);
			arr->len++;
		}
	}
	else if (arr->flag_arr[1] == ' ' && arr->negative == 1)
	{
		write(1, " ", 1);
		arr->len++;
	}
	else if (i < 0 || arr->negative == -1)
	{
		arr->negative = -1;
		write(1, "-", 1);
		arr->len++;
	}
	return (arr);
}
