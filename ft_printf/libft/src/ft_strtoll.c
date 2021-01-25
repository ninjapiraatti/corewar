/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 15:08:42 by tlouekar          #+#    #+#             */
/*   Updated: 2020/07/14 15:39:33 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long long		ft_strtoll(const char *str, const char **endptr, int base)
{
	long long	i;
	long long	result;
	int			sign;

	i = 0;
	result = 0;
	sign = 0;
	while ((str[i] == ' ') || (str[i] == '\t') ||
	(str[i] == '\n') || (str[i] == '\v') ||
	(str[i] == '\r') || (str[i] == '\f'))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] > '/' && str[i] < ':')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (sign == -1)
		return (-result);
	else
		return (result);
}
