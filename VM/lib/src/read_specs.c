/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_specs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:26:08 by ksalmi            #+#    #+#             */
/*   Updated: 2020/03/05 16:02:48 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		read_field_width(t_data *data)
{
	size_t	field_w_len;
	int		start;
	char	*field_width;

	data->flag_width = 1;
	start = (int)data->spec_i;
	field_w_len = 0;
	while (ft_isdigit(data->specif_area[data->spec_i]))
	{
		field_w_len++;
		data->spec_i++;
	}
	field_width = ft_strsub(data->specif_area, start, field_w_len);
	data->width_num = ft_atoi(field_width);
	free(field_width);
}

static void		read_precision(t_data *data)
{
	size_t	precis_len;
	int		start;
	char	*str_precision;

	precis_len = 0;
	data->flag_precis = 1;
	data->spec_i++;
	start = (int)data->spec_i;
	if (ft_isdigit(data->specif_area[data->spec_i]))
	{
		while (ft_isdigit(data->specif_area[data->spec_i]))
		{
			precis_len++;
			data->spec_i++;
		}
		str_precision = ft_strsub(data->specif_area, start, precis_len);
		data->precision = ft_atoi(str_precision);
		free(str_precision);
	}
	else if (data->specif_area[data->spec_i] == '*')
		data->flag_asterisk_prec = 1;
	else
		data->precision = 0;
}

static void		read_length_flags(t_data *data)
{
	size_t	len;
	int		start;

	len = 0;
	start = (int)data->spec_i;
	data->length_flags = 1;
	while (ft_strchr(FORM_SPECIFIERS, data->specif_area[data->spec_i]) == 0)
	{
		len++;
		data->spec_i++;
	}
	data->len_flag = ft_strsub(data->specif_area, start, len);
	if (ft_strcmp(data->len_flag, "h") && ft_strcmp(data->len_flag, "hh") &&
			ft_strcmp(data->len_flag, "l") && ft_strcmp(data->len_flag, "ll")
			&& ft_strcmp(data->len_flag, "L"))
		error_handling(-1);
}

static void		read_basic_flags(t_data *data)
{
	if (data->specif_area[data->spec_i] == ' '
			&& data->flag_plus_space == 0)
		data->flag_plus_space = 1;
	if (data->specif_area[data->spec_i] == '+')
		data->flag_plus_space = 2;
	if (data->specif_area[data->spec_i] == '-')
		data->flag_justify = 1;
	if (data->specif_area[data->spec_i] == '#')
		data->flag_hash = 1;
	if (data->specif_area[data->spec_i] == '0' && data->flag_width == 0)
		data->flag_zero = 1;
}

t_data			*read_specs(t_data *data)
{
	data->form_specifier = data->specif_area[data->spec_len - 1];
	while (data->spec_i < data->spec_len - 1)
	{
		read_basic_flags(data);
		if (data->specif_area[data->spec_i] == '*' \
			&& data->specif_area[data->spec_i - 1] != '.')
			data->flag_asterisk_width = 1;
		if (ft_isdigit(data->specif_area[data->spec_i])
				&& data->specif_area[data->spec_i] != '0')
			read_field_width(data);
		if (data->specif_area[data->spec_i] == '.')
			read_precision(data);
		if (ft_isalpha(data->specif_area[data->spec_i])
				&& data->spec_i < data->spec_len - 1)
			read_length_flags(data);
		data->spec_i++;
	}
	return (data);
}
