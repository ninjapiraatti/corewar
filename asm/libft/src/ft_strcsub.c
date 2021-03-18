/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 10:31:03 by tlouekar          #+#    #+#             */
/*   Updated: 2020/07/14 15:39:33 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcsub(const char *s)
{
	char	*temp;
	int		i;
	int		len;
	int		nlfound;

	i = 0;
	nlfound = 0;
	len = 0;
	while (s[len++] != '\0')
	{
		if (s[len] == '\n')
		{
			nlfound = 1;
			break ;
		}
	}
	if (nlfound == 1)
	{
		if (!(temp = (char *)malloc(len * sizeof(char) + 1)))
			return (0);
		while (i++ < len)
			temp[i] = s[i];
		return (temp);
	}
	return ((char *)s);
}
