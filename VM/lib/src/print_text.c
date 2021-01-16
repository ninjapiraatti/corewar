/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:52:04 by ksalmi            #+#    #+#             */
/*   Updated: 2020/03/03 19:49:29 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_text(t_data *data)
{
	long long int	i;

	i = 0;
	if (data->null_char)
	{
		while (data->last[i])
		{
			if (data->last[i] == -1)
				data->last[i] = 0;
			ft_putchar(data->last[i]);
			i++;
		}
	}
	else
		ft_putstr(data->last);
}
