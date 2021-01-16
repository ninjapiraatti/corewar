/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:31:53 by ksalmi            #+#    #+#             */
/*   Updated: 2020/02/24 13:32:19 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	intlength(int n)
{
	int len;

	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*superint(char *s)
{
	if (!(s = (char *)malloc(12)))
		return (NULL);
	ft_strcpy(s, "-2147483648");
	return (s);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*s;

	s = NULL;
	if (n == -2147483648)
		return (superint(s));
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
