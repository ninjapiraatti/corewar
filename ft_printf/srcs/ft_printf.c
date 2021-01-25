/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 12:35:19 by tlouekar          #+#    #+#             */
/*   Updated: 2020/07/01 17:03:42 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*preparse(char *str, va_list args, t_printf *data)
{
	if (*str == '\\')
	{
		str++;
		write(1, (char *)str, 1);
		str++;
		data->cc++;
	}
	if (*(str + 1) == '%')
	{
		ft_putchar('%');
		str += 2;
		data->cc++;
		return (str);
	}
	str = parse(str + 1, data);
	if (str != NULL)
	{
		output(data, args, 0);
		str++;
	}
	return (str);
}

char			*loopidiloop(char *traverse, va_list args, t_printf *data)
{
	if (*traverse == '%')
		traverse = preparse(traverse, args, data);
	else
	{
		ft_putchar((char)*traverse);
		traverse++;
		data->cc++;
	}
	if (traverse == NULL)
	{
		free(data);
		return (NULL);
	}
	return (traverse);
}

int				ft_printf(const char *format, ...)
{
	va_list		args;
	char		*traverse;
	t_printf	*data;
	int			count;

	count = 0;
	va_start(args, format);
	traverse = (char *)format;
	while (*traverse != '\0')
	{
		data = initialize(traverse);
		traverse = loopidiloop(traverse, args, data);
		if (traverse == NULL)
			return (0);
		count += data->cc;
		free(data);
	}
	va_end(args);
	return (count);
}
