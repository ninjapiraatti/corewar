/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:36:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/07/08 16:15:31 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			con_f(t_printf *data, va_list args)
{
	char		*str;

	handle_stars(data, args);
	if (data->lod == 1)
		data->flo = va_arg(args, long double);
	else
		data->flo = va_arg(args, double);
	if (data->dot == 0)
		data->prc = 6;
	str = ftoa(data->flo, data);
	data->len = ft_strlen(str);
	if (data->minus == 0)
		helper_print_padding(data);
	helper_plusminus(data);
	helper_spaces(data);
	helper_prc_zeros(data);
	ft_putstr(str);
	data->cc += ft_strlen(str);
	free(str);
}
