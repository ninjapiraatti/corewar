/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:36:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/07/08 16:15:19 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			con_d(t_printf *data, va_list args)
{
	char		*str;

	handle_stars(data, args);
	handle_length(data, args);
	str = helper_itoa_base(data->val, 10, data);
	data->len = ft_strlen(str);
	if (data->minus == 0)
		helper_print_padding(data);
	helper_plusminus(data);
	helper_spaces(data);
	helper_prc_zeros(data);
	if (!(data->dot == 1 && data->val == 0 && data->prc == 0))
	{
		ft_putstr(str);
		data->cc += ft_strlen(str);
	}
	free(str);
}
