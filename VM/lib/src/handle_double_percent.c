/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_double_percent.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 20:12:51 by ksalmi            #+#    #+#             */
/*   Updated: 2020/02/23 20:21:14 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*handle_double_percent(t_data *data)
{
	data->i++;
	save_area(data);
	data->str_save_start = data->i + 1;
	return (data);
}
