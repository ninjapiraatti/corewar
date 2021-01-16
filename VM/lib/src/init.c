/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:37:36 by ksalmi            #+#    #+#             */
/*   Updated: 2020/03/05 14:28:59 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*init(t_data *data)
{
	data->len_flag = NULL;
	data->spec_i = 0;
	data->spec_len = 1;
	data->width_num = 0;
	data->precision = 6;
	data->formatted_len = 0;
	data->spec_field_len = 0;
	data->spec_start = 0;
	data->flag_justify = 0;
	data->flag_hash = 0;
	data->flag_plus_space = 0;
	data->flag_zero = 0;
	data->flag_precis = 0;
	data->flag_width = 0;
	data->flag_asterisk_width = 0;
	data->flag_asterisk_prec = 0;
	data->length_flags = 0;
	data->after_specs = 0;
	data->is_neg = 0;
	data->null_char = 0;
	return (data);
}
