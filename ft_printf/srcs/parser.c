/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 09:43:42 by tlouekar          #+#    #+#             */
/*   Updated: 2020/07/07 14:14:25 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		inject_int(char *str, t_printf *data, int *flag)
{
	int		i;

	i = 0;
	*flag = ft_atoi((char *)str);
	while (ft_isdigit(*(str)) == 1)
	{
		str++;
		i++;
	}
	return (i);
}

int		basic_flags(char *str, t_printf *data)
{
	if (*str == '+')
		data->pl = 1;
	else if (*str == '-')
		data->minus = 1;
	else if (*str == '#')
		data->hash = 1;
	else if (*str == ' ')
		data->spc = 1;
	else if (*str == '*')
	{
		str--;
		if (*str == '.')
			data->starprc = 1;
		else
			data->starlen = 1;
		str++;
	}
	return (1);
}

int		flag_to_data(char *str, t_printf *data)
{
	helper_length_flags(str, data);
	basic_flags(str, data);
	if (*str == '.')
	{
		data->dot = 1;
		str++;
		return (inject_int(str, data, &(data->prc)) + 1);
	}
	else if (*str == '0')
	{
		str--;
		if (ft_isdigit(*(str)) == 0)
			data->zero = 1;
		str++;
	}
	else if (ft_isdigit(*(str)) == 1)
		return (inject_int(str, data, &(data->fieldwidth)));
	return (1);
}

int		parse_numerals(char *str, t_printf *data)
{
	if (*str == 'd')
		data->d = 1;
	else if (*str == 'i')
		data->i = 1;
	else if (*str == 'o')
		data->o = 1;
	else if (*str == 'u')
		data->u = 1;
	else if (*str == 'f')
		data->f = 1;
	else
		return (0);
	return (1);
}

char	*parse(char *str, t_printf *data)
{
	while (ft_strchr(g_flags, *str) != NULL)
		str += flag_to_data(str, data);
	if (parse_numerals(str, data) == 1)
		return (str);
	else if (*str == 'c')
		data->c = 1;
	else if (*str == 's')
		data->s = 1;
	else if (*str == 'x')
		data->x = 1;
	else if (*str == 'X')
		data->bx = 1;
	else if (*str == 'p')
		data->p = 1;
	else if (*str == '%')
		data->loose = 1;
	else
		return (NULL);
	return (str);
}
