/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:13:06 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/03/13 14:42:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "Libft\libft.h"

int		get_nbr_count(intmax_t len)
{
	int count;

	count = 0;
	if (len == -9223372036854775807 - 1)
		return (21);
	if (len == 0)
		return (1);
	if (len < 0)
	{
		len = len * -1;
		count++;
	}
	while (len > 0)
	{
		len = len / 10;
		count++;
	}
	return (count);
}
