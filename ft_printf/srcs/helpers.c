/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:37:41 by tlouekar          #+#    #+#             */
/*   Updated: 2020/07/07 15:40:54 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		helper_print_padding(t_printf *data)
{
	int		i;

	i = data->fieldwidth - data->len;
	if ((data->x != 1 && data->bx != 1 && data->u != 1) &&
	((data->pl == 1) || (data->spc == 1) || (data->val < 0) || (data->flo < 0)))
		i--;
	if ((data->prc > data->len) && data->s != 1)
		i -= data->prc - data->len;
	if (data->minus == 0 && data->fieldwidth > 0 && data->zero == 1
	&& data->dot == 0 && data->loose == 0)
		i = 0;
	if (data->minus == 0 && data->fieldwidth > 0 && data->zero == 1
	&& (data->f == 1 || data->l == 1))
		i = 0;
	if ((data->x == 1 || data->bx == 1) && data->hash == 1 && data->val != 0)
		i -= 2;
	if ((data->prc == 0 && data->val == 0 && data->dot == 1) && (data->i == 1
	|| data->d == 1 || data->u == 1 || (data->o == 1 && data->hash == 0)))
		i++;
	while (i > 0)
	{
		ft_putchar(' ');
		data->cc++;
		i--;
	}
}

void		helper_spaces(t_printf *data)
{
	if (data->spc == 1 && data->pl == 0 && data->val >= 0
	&& data->flo >= 0 && data->loose == 0)
	{
		ft_putchar(' ');
		data->cc++;
	}
}

void		helper_plusminus(t_printf *data)
{
	if (data->pl == 1 && data->val >= 0 && data->flo >= 0
	&& data->o != 1)
	{
		ft_putchar('+');
		data->cc++;
	}
	if (data->val < 0 || data->flo < 0)
	{
		ft_putchar('-');
		data->cc++;
	}
}

void		helper_prc_zeros(t_printf *data)
{
	int		i;

	i = 0;
	if (data->prc > data->len)
		i = data->prc - data->len;
	else if ((data->dot == 0 || data->l == 1 || data->f == 1)
	&& data->zero == 1 && data->minus == 0)
	{
		i = data->fieldwidth - data->len;
		if (data->val < 0 || data->pl == 1 || data->flo < 0
		|| data->spc == 1)
			i--;
	}
	if ((data->x == 1 || data->bx == 1) && data->hash == 1
	&& data->val != 0 && data->minus == 0 && data->dot == 0)
		i -= 2;
	if (data->o == 1 && data->hash == 1 && data->val != 0)
		i++;
	while (i > 0)
	{
		ft_putchar('0');
		data->cc++;
		i--;
	}
}

char		*helper_itoa_base(intmax_t value, int base, t_printf *data)
{
	char		*s;
	intmax_t	n;
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
