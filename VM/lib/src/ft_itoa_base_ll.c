/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:32:26 by ksalmi            #+#    #+#             */
/*   Updated: 2020/02/28 20:47:49 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base_ll_low(unsigned long long value, unsigned int base)
{
	char				*new;
	unsigned long long	temp;
	int					mod;
	int					len;

	temp = value;
	len = 0;
	if (base > 16)
		return (NULL);
	if (value == 0)
		return (ft_strdup("0"));
	while (temp > 0)
	{
		temp = temp / base;
		len++;
	}
	if (!(new = ft_strnew((size_t)len)))
		return (NULL);
	while (--len >= 0)
	{
		mod = value % base;
		new[len] = BASE_STR_LOW[mod];
		value = value / base;
	}
	return (new);
}

char	*ft_itoa_base_ll_up(unsigned long long value, unsigned int base)
{
	char				*new;
	unsigned long long	temp;
	int					mod;
	int					len;

	temp = value;
	len = 0;
	if (base > 16)
		return (NULL);
	if (value == 0)
		return (ft_strdup("0"));
	while (temp > 0)
	{
		temp = temp / base;
		len++;
	}
	new = ft_strnew((size_t)len);
	while (--len >= 0)
	{
		mod = value % base;
		new[len] = BASE_STR_UP[mod];
		value = value / base;
	}
	return (new);
}
