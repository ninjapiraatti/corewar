/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 09:01:35 by tlouekar          #+#    #+#             */
/*   Updated: 2020/07/14 15:39:33 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_wordcnt(char *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	count = 0;
	while (i < len)
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && i < len)
				i++;
		}
		i++;
	}
	return ((int)count);
}
