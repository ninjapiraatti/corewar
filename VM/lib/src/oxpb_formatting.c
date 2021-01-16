/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_formatting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:49:02 by ksalmi            #+#    #+#             */
/*   Updated: 2020/03/05 15:45:36 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*o_formatting(t_data *data)
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
	data->formatted_area = ft_itoa_base_ll_low(d, 8);
	data->formatted_len = (int)ft_strlen(data->formatted_area);
	handle_precision(data);
	if (data->flag_precis)
		data->flag_zero = 0;
	return (data);
}

t_data	*x_formatting(t_data *data)
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
	if (data->form_specifier == 'x')
		data->formatted_area = ft_itoa_base_ll_low(d, 16);
	else if (data->form_specifier == 'X')
		data->formatted_area = ft_itoa_base_ll_up(d, 16);
	data->formatted_len = (int)ft_strlen(data->formatted_area);
	handle_precision(data);
	if (data->flag_precis)
		data->flag_zero = 0;
	return (data);
}

t_data	*p_formatting(t_data *data)
{
	unsigned long long	num;
	char				*beginning;
	char				*temp;

	beginning = "0x";
	num = va_arg(data->args, unsigned long long);
	temp = ft_itoa_base_ll_low(num, 16);
	data->formatted_area = ft_strjoin(beginning, temp);
	data->formatted_len = (int)ft_strlen(data->formatted_area);
	free(temp);
	return (data);
}

t_data	*b_formatting(t_data *data)
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
	data->formatted_area = ft_itoa_base_ll_up(d, 2);
	data->formatted_len = (int)ft_strlen(data->formatted_area);
	handle_precision(data);
	if (data->flag_precis)
		data->flag_zero = 0;
	return (data);
}
