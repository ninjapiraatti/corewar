/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_field_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:37:29 by ksalmi            #+#    #+#             */
/*   Updated: 2020/02/28 21:23:39 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*put_field_width(t_data *data)
{
	char	*tmp;
	char	*add;
	int		added_len;

	if (data->width_num > data->formatted_len)
	{
		added_len = data->width_num - data->formatted_len;
		add = ft_strnew((size_t)added_len);
		ft_memset(add, ' ', (size_t)added_len);
		tmp = ft_strdup(data->formatted_area);
		free(data->formatted_area);
		data->formatted_area = ft_strjoin(add, tmp);
		free(tmp);
		free(add);
		data->formatted_len = data->formatted_len + added_len;
	}
	return (data);
}
