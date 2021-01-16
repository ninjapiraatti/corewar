/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:12:02 by ksalmi            #+#    #+#             */
/*   Updated: 2019/11/18 15:54:06 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *ret;

	ret = NULL;
	if (!s)
		return (NULL);
	while (*s && *s != c)
		s++;
	if (*s == c)
		ret = (char *)s;
	return (ret);
}
