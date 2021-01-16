/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:15:44 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/03/13 14:42:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "Libft\libft.h"

t_lst	*check_width(t_lst *arr)
{
	while (arr->copy[arr->i] >= '0' && arr->copy[arr->i] <= '9')
	{
		arr->field_width *= 10;
		arr->field_width += arr->copy[arr->i] - 48;
		arr->i++;
	}
	return (check_period(arr));
}
