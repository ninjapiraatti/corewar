/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_specs_and_convert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:45:07 by ksalmi            #+#    #+#             */
/*   Updated: 2020/03/03 18:57:40 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data		*cut_specs(t_data *data)
{
	while (data->f_arg[data->i] && (ft_isalpha(data->f_arg[data->i]) == 0 ||
				data->f_arg[data->i] == 'h' || data->f_arg[data->i] == 'l' ||
				data->f_arg[data->i] == 'L'))
	{
		data->spec_len++;
		data->i++;
		if (data->f_arg[data->i] == '%')
			break ;
	}
	if (data->f_arg[data->i] && (ft_strchr(FORM_SPECIFIERS,
					data->f_arg[data->i]) || data->f_arg[data->i] == '%'))
	{
		data->specif_area = ft_strsub(data->f_arg,
				data->spec_start, data->spec_len);
		data->str_save_start = data->i + 1;
	}
	else
		error_handling(-1);
	return (data);
}

t_data		*save_area(t_data *data)
{
	char *temp;

	data->str_save_len = (size_t)(data->i - data->str_save_start);
	data->str_to_save = ft_strsub(data->f_arg,
				data->str_save_start, data->str_save_len);
	data->final_len = data->final_len + (int)data->str_save_len;
	data->spec_start = data->i;
	temp = ft_strdup(data->last);
	free(data->last);
	data->last = ft_strjoin(temp, data->str_to_save);
	free(data->str_to_save);
	free(temp);
	return (data);
}
