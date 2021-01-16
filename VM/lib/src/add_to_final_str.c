/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_final_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:34:16 by ksalmi            #+#    #+#             */
/*   Updated: 2020/03/02 12:11:14 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*add_to_final_str(t_data *data)
{
	char	*temp;

	temp = ft_strdup(data->last);
	free(data->last);
	data->last = ft_strjoin(temp, data->formatted_area);
	data->final_len = data->final_len + data->formatted_len;
	free(data->formatted_area);
	free(data->specif_area);
	free(temp);
	if (data->length_flags == 1)
		free(data->len_flag);
	return (data);
}
