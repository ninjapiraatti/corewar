/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:28:49 by ksalmi            #+#    #+#             */
/*   Updated: 2019/10/29 13:53:57 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_length(const char *str, int i, char c)
{
	int len;

	len = 0;
	while (str[i] && str[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static int	ft_count_words(const char *str, char c)
{
	int i;
	int count;
	int is_word;

	i = 0;
	count = 0;
	is_word = 0;
	while (str[i])
	{
		if (str[i] == c)
			is_word = 0;
		if (str[i] && str[i] != c && is_word == 0)
		{
			is_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = -1;
	arr = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	while (++j < ft_count_words(s, c))
	{
		k = 0;
		while (s[i] == c)
			i++;
		arr[j] = ft_strnew(ft_word_length(s, i, c) + 1);
		while (s[i] && s[i] != c)
		{
			arr[j][k] = s[i];
			i++;
			k++;
		}
	}
	arr[j] = NULL;
	return (arr);
}
