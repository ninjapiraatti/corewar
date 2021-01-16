/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_field_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:00:50 by ksalmi            #+#    #+#             */
/*   Updated: 2020/03/05 14:21:31 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*implement_flags(t_data *data)
{
	if (data->flag_hash)
		put_hash_flag(data);
	if (data->flag_zero)
		put_zero_flag(data);
	if (data->flag_plus_space && !data->flag_zero)
		put_plus_space_flag(data);
	if (data->flag_justify)
		put_justify_flag(data);
	if ((data->flag_width || data->flag_asterisk_width) && !data->flag_justify \
		&& !data->flag_zero)
		put_field_width(data);
	data->formatted_len = (int)ft_strlen(data->formatted_area);
	return (data);
}
