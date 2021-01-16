/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hash_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:54:32 by ksalmi            #+#    #+#             */
/*   Updated: 2020/02/28 20:42:12 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	o_hash(t_data *data)
{
	char	*add;
	char	*tmp;

	if (data->formatted_area[0] != '0')
	{
		add = ft_strdup("0");
		tmp = ft_strdup(data->formatted_area);
		free(data->formatted_area);
		data->formatted_area = ft_strjoin(add, tmp);
		data->formatted_len += 1;
		free(add);
		free(tmp);
	}
}

static void	x_hash(t_data *data)
{
	char	*tmp;

	tmp = ft_strdup(data->formatted_area);
	free(data->formatted_area);
	if (data->form_specifier == 'x')
		data->formatted_area = ft_strjoin("0x", tmp);
	else if (data->form_specifier == 'X')
		data->formatted_area = ft_strjoin("0X", tmp);
	data->formatted_len += 2;
	free(tmp);
}

t_data		*put_hash_flag(t_data *data)
{
	char	*tmp;

	if (data->flag_hash && data->formatted_area &&
			ft_strcmp(data->formatted_area, "0"))
	{
		if (data->form_specifier == 'o')
			o_hash(data);
		if (data->form_specifier == 'x' || data->form_specifier == 'X')
			x_hash(data);
		if (data->form_specifier == 'f')
		{
			if (!ft_strchr(data->formatted_area, '.'))
			{
				tmp = ft_strdup(data->formatted_area);
				free(data->formatted_area);
				data->formatted_area = ft_strjoin(tmp, ".");
				data->formatted_len += 1;
				free(tmp);
			}
		}
	}
	if (data->form_specifier == 'o' && data->flag_hash && !data->formatted_area)
		data->formatted_area = ft_strdup("0");
	return (data);
}
