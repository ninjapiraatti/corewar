/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:02:33 by tlouekar          #+#    #+#             */
/*   Updated: 2020/07/14 15:39:33 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *hstck, const char *ndl, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*ndl == '\0')
	{
		return ((char *)hstck);
	}
	while (i < len && hstck[i] != '\0')
	{
		j = 0;
		if (hstck[i] == ndl[0])
		{
			while ((ndl[j] == hstck[i + j]) && ndl[j] != '\0' && (i + j < len))
			{
				j++;
			}
			if (ndl[j] == '\0')
				return ((char *)&hstck[i]);
		}
		i++;
	}
	return (NULL);
}
