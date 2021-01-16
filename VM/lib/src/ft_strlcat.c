/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:19:58 by ksalmi            #+#    #+#             */
/*   Updated: 2019/11/01 19:30:33 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	ret;

	k = 0;
	i = ft_strlen(dst);
	j = ft_strlen(src);
	if (i >= dstsize)
		ret = dstsize + j;
	else
		ret = i + j;
	while (src[k] && i < dstsize - 1 && dstsize != 0)
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (ret);
}
