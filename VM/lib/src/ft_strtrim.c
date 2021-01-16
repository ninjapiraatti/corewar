/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ft_strtrim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:49:02 by ksalmi            #+#    #+#             */
/*   Updated: 2019/11/07 12:49:31 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t			len;
	unsigned int	i;
	unsigned int	start;
	char			*trimmed;

	i = 0;
	len = ft_strlen(s);
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	start = i;
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	if (len < start)
	{
		trimmed = (char *)malloc(sizeof(char) * 1);
		trimmed[0] = '\0';
	}
	else
		trimmed = ft_strsub(s, start, len - start);
	return (trimmed);
}
