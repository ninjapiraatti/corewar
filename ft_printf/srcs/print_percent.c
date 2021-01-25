/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:55:18 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/03/13 14:42:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "Libft\libft.h"

t_lst	*print_percent(t_lst *arr)
{
	if (arr->flag_arr[0] == '\0' && arr->flag_arr[4] == '\0')
		print_min_width(arr, 1, 1);
	else if (arr->flag_arr[0] == '\0' && arr->flag_arr[4] == '0')
		print_zeros(arr, 1, 1);
	write(1, "%", 1);
	arr->len++;
	if (arr->flag_arr[0] == '-')
		print_min_width(arr, 1, 1);
	return (arr);
}
