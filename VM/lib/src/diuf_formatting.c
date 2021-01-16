/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_formatting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:06:14 by ksalmi            #+#    #+#             */
/*   Updated: 2020/03/02 14:57:57 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*di_formatting(t_data *data)
{
	long long int	d;

	if (data->length_flags == 0)
		d = (int)va_arg(data->args, int);
	else
	{
		if (!ft_strcmp("hh", data->len_flag))
			d = (signed char)va_arg(data->args, int);
		if (!ft_strcmp("h", data->len_flag))
			d = (short int)va_arg(data->args, int);
		if (!ft_strcmp("l", data->len_flag))
			d = (long int)va_arg(data->args, long int);
		if (!ft_strcmp("ll", data->len_flag))
			d = (long long int)va_arg(data->args, long long int);
	}
	if (d < 0)
		data->is_neg = 1;
	data->formatted_area = ft_itoa_ll(d);
	data->formatted_len = (int)ft_strlen(data->formatted_area);
	handle_precision(data);
	if (data->flag_precis)
		data->flag_zero = 0;
	return (data);
}

t_data	*u_formatting(t_data *data)
{
	unsigned long long int	d;

	if (data->length_flags == 0)
		d = (unsigned int)va_arg(data->args, unsigned int);
	else
	{
		if (!ft_strcmp("hh", data->len_flag))
			d = (unsigned char)va_arg(data->args, unsigned int);
		if (!ft_strcmp("h", data->len_flag))
			d = (unsigned short int)va_arg(data->args, unsigned int);
		if (!ft_strcmp("l", data->len_flag))
			d = (unsigned long int)va_arg(data->args, unsigned long int);
		if (!ft_strcmp("ll", data->len_flag))
			d = (unsigned long long int)va_arg(data->args,
					unsigned long long int);
	}
	data->formatted_area = ft_itoa_ll(d);
	data->formatted_len = (int)ft_strlen(data->formatted_area);
	handle_precision(data);
	if (data->flag_precis)
		data->flag_zero = 0;
	return (data);
}

t_data	*f_formatting(t_data *data)
{
	long double	f;

	if (data->length_flags == 0)
		f = (double)va_arg(data->args, double);
	else
	{
		if (!ft_strcmp("l", data->len_flag))
			f = (double)va_arg(data->args, double);
		if (!ft_strcmp("L", data->len_flag))
			f = (long double)va_arg(data->args, long double);
	}
	if (f < 0)
		data->is_neg = 1;
	data->formatted_area = ft_itoa_double(f, data->precision);
	data->formatted_len = (int)ft_strlen(data->formatted_area);
	return (data);
}
