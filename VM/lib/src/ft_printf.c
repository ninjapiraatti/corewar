/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:04:53 by ksalmi            #+#    #+#             */
/*   Updated: 2020/03/03 19:38:09 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_data	data;

	init_first_time(&data, format);
	va_start(data.args, format);
	while (data.f_arg[data.i])
	{
		if (data.f_arg[data.i] == '%')
		{
			init(&data);
			save_area(&data);
			cut_specs(&data);
			read_specs(&data);
			make_formatting(&data);
			implement_flags(&data);
			add_to_final_str(&data);
		}
		if (data.f_arg[data.i])
			data.i++;
	}
	save_area(&data);
	va_end(data.args);
	print_text(&data);
	free(data.f_arg);
	free(data.last);
	return (data.final_len);
}
