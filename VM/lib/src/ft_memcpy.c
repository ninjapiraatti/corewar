/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ft_memcpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:11:48 by ksalmi            #+#    #+#             */
/*   Updated: 2019/11/06 16:43:09 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*sour;

	i = 0;
	dest = (unsigned char *)dst;
	sour = (unsigned char *)src;
	if (!dest && !sour)
		return (0);
	while (i < n)
	{
		dest[i] = sour[i];
		i++;
	}
	return (dest);
}
