/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_zero_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:04:34 by ksalmi            #+#    #+#             */
/*   Updated: 2020/02/25 17:12:27 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	negative_values(t_data *data)
{
	char	*ptr;

	if (data->is_neg == 1)
	{
		if (data->formatted_area[0] != '-')
		{
			ptr = ft_strchr(data->formatted_area, '-');
			ptr[0] = '0';
			data->formatted_area[0] = '-';
		}
	}
}

static void	add_zeroes(t_data *data)
{
	int		zero_len;
	char	*zeroes;
	char	*tmp;

	zero_len = data->width_num - data->formatted_len;
	zeroes = ft_strnew((size_t)zero_len);
	ft_memset(zeroes, '0', (size_t)zero_len);
	tmp = ft_strdup(data->formatted_area);
	free(data->formatted_area);
	data->formatted_area = ft_strjoin(zeroes, tmp);
	data->formatted_len = data->formatted_len + zero_len;
	free(tmp);
	free(zeroes);
	if (data->form_specifier == 'x' &&
			data->flag_hash && ft_strchr(data->formatted_area, 'x'))
	{
		*ft_strchr(data->formatted_area, 'x') = '0';
		data->formatted_area[1] = 'x';
	}
	if (data->form_specifier == 'X' &&
			data->flag_hash && ft_strchr(data->formatted_area, 'X'))
	{
		*ft_strchr(data->formatted_area, 'X') = '0';
		data->formatted_area[1] = 'X';
	}
}

t_data		*put_zero_flag(t_data *data)
{
	if (data->flag_justify == 0 && data->form_specifier != 's' &&
			data->form_specifier != 'p' && data->form_specifier != 'c')
	{
		if (data->width_num > data->formatted_len)
			add_zeroes(data);
		if (data->flag_plus_space == 1 && (data->form_specifier == 'd' ||
					data->form_specifier == 'i' || data->form_specifier == 'f'))
			data->formatted_area[0] = ' ';
		if (data->flag_plus_space == 2 && (data->form_specifier == 'd' ||
					data->form_specifier == 'i' || data->form_specifier == 'f'))
			data->formatted_area[0] = '+';
		negative_values(data);
	}
	return (data);
}
