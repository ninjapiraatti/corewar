/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_formatting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:02:31 by ksalmi            #+#    #+#             */
/*   Updated: 2020/03/02 15:32:53 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*s_formatting(t_data *data)
{
	data->formatted_area = ft_strdup(va_arg(data->args, char *));
	if (data->formatted_area == NULL)
		data->formatted_area = ft_strdup("(null)");
	data->formatted_len = (int)ft_strlen(data->formatted_area);
	handle_precision(data);
	return (data);
}

t_data	*c_formatting(t_data *data)
{
	unsigned char c;

	c = (unsigned char)va_arg(data->args, int);
	if (c == 0)
	{
		c = -1;
		data->null_char = 1;
	}
	data->formatted_area = ft_strnew(1);
	data->formatted_area[0] = c;
	data->formatted_len = 1;
	return (data);
}
