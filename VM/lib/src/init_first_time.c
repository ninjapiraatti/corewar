/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_first_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:10:13 by ksalmi            #+#    #+#             */
/*   Updated: 2020/03/03 19:30:36 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*init_first_time(t_data *data, const char *format)
{
	data->f_arg = ft_strdup(format);
	data->i = 0;
	data->last = ft_strnew(1);
	data->str_save_start = 0;
	data->final_len = 0;
	data->str_save_start = 0;
	data->length_flags = 0;
	return (data);
}
