/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_length_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:39:19 by ksalmi            #+#    #+#             */
/*   Updated: 2020/03/03 18:21:42 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int	intlength_double(long double n)
{
	long long int	len;
	long long int	tmp;

	if (n < 0)
		n *= -1;
	tmp = (long long int)n;
	len = 1;
	while (tmp > 9)
	{
		tmp = tmp / 10;
		len++;
	}
	return (len);
}

char			*all_zeroes_check(char *s)
{
	long long int	i;
	char			*tmp;

	i = 1;
	while (s[i] == '0' || s[i] == '.')
		i++;
	if (s[i] == '\0')
	{
		tmp = ft_strsub(s, 1, ft_strlen(s) - 1);
		free(s);
		s = tmp;
	}
	return (s);
}
