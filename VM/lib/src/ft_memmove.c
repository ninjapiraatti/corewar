/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:07:21 by ksalmi            #+#    #+#             */
/*   Updated: 2019/11/07 11:37:10 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*sour;

	dest = (unsigned char *)dst;
	sour = (unsigned char *)src;
	if (!dest && !sour)
		return (0);
	if (dst > src)
	{
		while (len > 0)
		{
			dest[len - 1] = sour[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(dest, sour, len);
	return (dest);
}
