/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_justify_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:28:47 by ksalmi            #+#    #+#             */
/*   Updated: 2020/03/05 14:53:50 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*put_justify_flag(t_data *data)
{
	char	*add;
	char	*tmp;
	int		added_len;

	if (data->width_num > data->formatted_len)
	{
		added_len = data->width_num - data->formatted_len;
		add = ft_strnew((size_t)added_len);
		ft_memset(add, ' ', (size_t)added_len);
		tmp = ft_strdup(data->formatted_area);
		free(data->formatted_area);
		data->formatted_area = ft_strjoin(tmp, add);
		data->formatted_len = data->formatted_len + added_len;
		free(add);
		free(tmp);
	}
	return (data);
}
