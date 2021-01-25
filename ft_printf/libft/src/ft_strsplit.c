/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 09:34:01 by tlouekar          #+#    #+#             */
/*   Updated: 2020/07/14 15:39:33 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		len;
	char	**splits;
	int		count;

	i = 0;
	count = ft_wordcnt((char *)s, c);
	if (!(splits = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	j = 0;
	while (i < count)
	{
		while (s[j] == c)
			j++;
		len = ft_wordlen((char *)s, c, j);
		if (!(splits[i] = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		splits[i] = ft_strncpy(splits[i], &s[j], len);
		splits[i][len] = '\0';
		i++;
		j = j + len;
	}
	splits[count] = NULL;
	return (splits);
}
