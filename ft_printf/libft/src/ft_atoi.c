/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 11:28:48 by tlouekar          #+#    #+#             */
/*   Updated: 2020/07/14 15:40:05 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	long i;
	long result;
	long sign;

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
