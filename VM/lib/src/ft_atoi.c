/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:57:30 by ksalmi            #+#    #+#             */
/*   Updated: 2019/11/09 14:51:43 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*maxmin(char *str)
{
	int i;

	if (ft_strlen(str) > 18 && str[0] != '-')
	{
		i = 0;
		while (i <= 19)
		{
			if (ft_isdigit(str[i]) == 0)
				return (str);
			i++;
		}
		ft_strcpy(str, "-1");
	}
	if (ft_strlen(str) > 19 && str[0] == '-')
	{
		i = 1;
		while (i <= 20)
		{
			if (ft_isdigit(str[i]) == 0)
				return (str);
			i++;
		}
		ft_strcpy(str, "0");
	}
	return (str);
}

int			ft_atoi(const char *str)
{
	int i;
	int	ret;
	int sign;

	maxmin((char *)str);
	ret = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13) || \
			(str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9'))
		i++;
	if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			ret = ret * 10 + (str[i] - 48);
		if (str[i] < '0' || str[i] > '9')
			break ;
		i++;
	}
	return (sign * ret);
}
