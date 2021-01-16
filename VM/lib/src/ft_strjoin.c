/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:49:55 by ksalmi            #+#    #+#             */
/*   Updated: 2019/11/24 14:44:45 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*new;

	if (s1)
		i = ft_strlen(s1);
	if (s2)
		j = ft_strlen(s2);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!(new = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	ft_strcpy(new, s1);
	ft_strcpy((new + i), s2);
	return (new);
}
