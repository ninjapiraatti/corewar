/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:39:54 by ksalmi            #+#    #+#             */
/*   Updated: 2019/10/25 14:42:29 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*sour;
	unsigned char	ch;

	dest = (unsigned char *)dst;
	sour = (unsigned char *)src;
	ch = (unsigned char)c;
	i = 0;
	while (i < n && sour[i] != ch)
	{
		*dest = sour[i];
		i++;
		dest++;
	}
	if (sour[i] == ch)
	{
		*dest = sour[i];
		dest++;
		return (dest);
	}
	return (NULL);
}
