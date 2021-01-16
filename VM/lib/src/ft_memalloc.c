/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:38:24 by ksalmi            #+#    #+#             */
/*   Updated: 2019/11/02 23:15:52 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * size);
	if (!new)
		return (NULL);
	ft_bzero(new, size);
	return ((void *)new);
}
