/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:37:28 by ksalmi            #+#    #+#             */
/*   Updated: 2019/11/06 17:52:22 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	i;
	int	j;

	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[j])
	{
		i = 0;
		while (big[j + i] == little[i])
		{
			i++;
			if (little[i] == '\0')
				return ((char *)big + j);
		}
		j++;
	}
	return (NULL);
}
