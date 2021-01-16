/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_justify_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:13:50 by ksalmi            #+#    #+#             */
/*   Updated: 2020/02/25 19:09:48 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*put_plus_space_flag(t_data *data)
{
	char	*add;
	char	*tmp;

	if ((data->form_specifier == 'd' || data->form_specifier == 'i' ||
			data->form_specifier == 'f') && data->is_neg == 0)
	{
		add = ft_strnew(1);
		if (data->flag_plus_space == 1)
			add[0] = ' ';
		if (data->flag_plus_space == 2)
			add[0] = '+';
		tmp = ft_strdup(data->formatted_area);
		free(data->formatted_area);
		data->formatted_area = ft_strjoin(add, tmp);
		data->formatted_len += 1;
		free(tmp);
		free(add);
	}
	return (data);
}
