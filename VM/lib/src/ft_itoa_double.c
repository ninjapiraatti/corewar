/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:33:47 by ksalmi            #+#    #+#             */
/*   Updated: 2020/03/03 18:34:07 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*put_ints(char *s, long double n, long long int len)
{
	long long int tmp;

	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
		len += 1;
	}
	tmp = (long long int)n;
	s[len] = '.';
	len--;
	while (tmp > 9)
	{
		s[len] = tmp % 10 + 48;
		tmp /= 10;
		len--;
	}
	s[len] = tmp + 48;
	return (s);
}

static char		*round_up(char *s, long long int len)
{
	char			*ints;
	long long int	num;
	long long int	final;
	char			*new;
	long long int	len_final;

	ints = ft_strsub(s, 0, ft_strlen(s) - ft_strlen(ft_strchr(s, '.')));
	num = ft_atoi(ints);
	free(ints);
	final = num + 1;
	if (num < 0)
		final = num - 1;
	if ((len_final = intlength_double(final)) > intlength_double(num))
		new = ft_strnew(len + 1);
	else
		new = ft_strnew(len);
	put_ints(new, (double)final, len_final);
	if (final >= 0)
		ft_strcpy(&new[(int)intlength_double(final)], ft_strchr(s, '.'));
	else
		ft_strcpy(&new[(int)intlength_double(final) + 1], ft_strchr(s, '.'));
	free(s);
	s = new;
	return (s);
}

char			*put_floats(char *s, long double n, int prec, long long int len)
{
	long double		tmp_d;

	tmp_d = (long double)(long long int)n;
	tmp_d = n - tmp_d;
	while (--prec > -2)
		tmp_d *= 10;
	if ((long long int)tmp_d % 10 >= 5)
		tmp_d = tmp_d / 10 + 1;
	else
		tmp_d = tmp_d / 10;
	len--;
	while (tmp_d >= 10)
	{
		s[len] = (long long int)tmp_d % 10 + 48;
		tmp_d /= 10;
		len--;
	}
	if (s[len] != '.')
		s[len] = (long long int)tmp_d + 48;
	else
		return (round_up(s, len));
	while (s[--len] != '.')
		s[len] = '0';
	return (s);
}

static char		*zero_precision(long double n)
{
	long long int	num;
	int				sign;

	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n = n * -1;
	}
	n = n * 10;
	num = (long long int)n;
	if (num % 10 >= 5)
		num = num / 10 + 1;
	else
		num = num / 10;
	if (sign == 1)
		num = num * -1;
	return (ft_itoa_ll(num));
}

char			*ft_itoa_double(long double n, int precision)
{
	long long int	i;
	char			*s;
	long long int	len;
	int				sign;

	sign = 0;
	i = intlength_double(n);
	if (precision == 0)
		return (zero_precision(n));
	if (n < 0)
		sign = 1;
	len = i + precision + sign + 1;
	s = ft_strnew((size_t)len);
	put_ints(s, n, i);
	if (sign == 1)
		n = n * -1;
	s = put_floats(s, n, precision, len);
	if (s[0] == '-')
		s = all_zeroes_check(s);
	return (s);
}
