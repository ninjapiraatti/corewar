/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:39:52 by tlouekar          #+#    #+#             */
/*   Updated: 2020/07/14 15:39:33 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	result;

	i = 0;
	while (dst[i] != '\0')
		i++;
	result = 0;
	while (src[result] != '\0')
		result++;
	if (dstsize < i)
		result += dstsize;
	else
		result += i;
	j = 0;
	while (src[j] != '\0' && i + 1 < dstsize && dst != src)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (result);
}
