/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:28:33 by ksalmi            #+#    #+#             */
/*   Updated: 2019/11/06 17:48:39 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[j] && j < len)
	{
		i = 0;
		while (big[j + i] == little[i] && (j + i) < len)
		{
			i++;
			if (little[i] == '\0')
				return ((char *)big + j);
		}
		j++;
	}
	return (NULL);
}
