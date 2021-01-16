/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pprecision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:48:13 by ksalmi            #+#    #+#             */
/*   Updated: 2020/02/28 20:23:07 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_data	*handle_dioux_precision(t_data *data)
{
	char	*zero;
	char	*tmp;
	int		len;

	len = data->formatted_len;
	if (data->is_neg)
		len = data->formatted_len - 1;
	if (len < data->precision)
	{
		zero = ft_strnew(data->precision - len);
		ft_memset(zero, '0', (size_t)(data->precision - len));
		tmp = ft_strdup(data->formatted_area);
		free(data->formatted_area);
		data->formatted_area = ft_strjoin(zero, tmp);
		if (data->is_neg)
		{
			*ft_strchr(data->formatted_area, '-') = '0';
			data->formatted_area[0] = '-';
		}
		data->formatted_len = (int)ft_strlen(data->formatted_area);
		free(zero);
		free(tmp);
	}
	return (data);
}

t_data			*handle_precision(t_data *data)
{
	char	*tmp;

	if (data->flag_precis == 1)
	{
		if (data->form_specifier == 's')
		{
			tmp = ft_strdup(data->formatted_area);
			free(data->formatted_area);
			data->formatted_area = ft_strsub(tmp, 0, (size_t)data->precision);
			data->formatted_len = (int)ft_strlen(data->formatted_area);
			free(tmp);
		}
		else
		{
			if (data->precision >= data->formatted_len)
				return (handle_dioux_precision(data));
			if (!(ft_strcmp(data->formatted_area, "0")) && data->precision == 0)
			{
				free(data->formatted_area);
				data->formatted_area = NULL;
				data->formatted_len = 0;
			}
		}
	}
	return (data);
}
