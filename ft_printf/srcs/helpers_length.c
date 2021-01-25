/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:37:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/07/08 16:42:55 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_stars(t_printf *data, va_list args)
{
	int			temp;

	temp = 0;
	if (data->starlen == 1)
	{
		temp = va_arg(args, intmax_t);
		if (temp < 0)
		{
			data->minus = 1;
			temp *= -1;
		}
		data->fieldwidth = temp;
	}
	temp = 0;
	if (data->starprc == 1)
	{
		temp = va_arg(args, intmax_t);
		if (temp < 0)
			temp *= -1;
		data->prc = temp;
	}
}

void		handle_length(t_printf *data, va_list args)
{
	if (data->l == 1)
		data->val = (long)va_arg(args, long);
	else if (data->ll == 1)
		data->val = (long long)va_arg(args, long long);
	else if (data->h == 1)
		data->val = (short)va_arg(args, int);
	else if (data->hh == 1)
		data->val = (char)va_arg(args, int);
	else
		data->val = (int)va_arg(args, int);
}

void		handle_length_unsigned(t_printf *data, va_list args)
{
	if (data->l == 1)
		data->val = (unsigned long)va_arg(args, unsigned long);
	else if (data->ll == 1)
		data->val = (uintmax_t)va_arg(args, uintmax_t);
	else if (data->h == 1)
		data->val = (unsigned short)va_arg(args, unsigned int);
	else if (data->hh == 1)
		data->val = (unsigned char)va_arg(args, unsigned int);
	else
		data->val = (unsigned int)va_arg(args, unsigned int);
}

void		helper_length_flags(char *str, t_printf *data)
{
	if (*str == 'L')
		data->lod = 1;
	else if (*str == 'l' && data->ll == 0)
	{
		if (*++str == 'l')
			data->ll = 1;
		else
		{
			str--;
			data->l = 1;
		}
	}
	else if (*str == 'h' && data->hh == 0)
	{
		if (*++str == 'h')
			data->hh = 1;
		else
		{
			str--;
			data->h = 1;
		}
	}
}

char		*helper_itoa_base_u(uintmax_t value, int base, t_printf *data)
{
	char		*s;
	uintmax_t	n;
	int			i;
	int			caps;

	caps = 10;
	if (data->bx == 1)
		caps = 42;
	n = (value < 0) ? -value : value;
	i = 1;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = (value < 0) ? -value : value;
	while (i--)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - caps;
		n /= base;
	}
	return (s);
}
