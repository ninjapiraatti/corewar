/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:07:20 by ksalmi            #+#    #+#             */
/*   Updated: 2020/03/03 16:56:25 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long int	intlength(long long int n)
{
	long long int len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char				*neg_super_long_long(void)
{
	char	*new;

	new = ft_strdup("-9223372036854775808");
	return (new);
}

char					*ft_itoa_ll(long long int n)
{
	long long int	i;
	char			*s;

	s = NULL;
	if (n < -9223372036854775807)
		return (neg_super_long_long());
	i = intlength(n);
	if (!(s = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	s[i] = '\0';
	i--;
	while (n > 9)
	{
		s[i] = n % 10 + 48;
		n /= 10;
		i--;
	}
	s[i] = n + 48;
	return (s);
}
