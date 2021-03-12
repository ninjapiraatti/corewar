/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:22:45 by pkuussaa          #+#    #+#             */
/*   Updated: 2021/03/12 12:22:46 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	*ft_str2chr(const char *s, int c, int h)
{
	char	*p;

	if (!s)
		return (NULL);
	p = (char *)s;
	while (*p != c && *p != h)
	{
		if (*p == '\0' || *p == '\n')
			return (NULL);
		p++;
	}
	return (p);
}

void	remove_comment(char *str)
{
	int	i;

	i = 0;
	if (str[i] == COMMENT_CHAR || str[i] == ALT_COMMENT_CHAR)
	{
		while (str[i] != '\0')
		{
			str[i] = ' ';
			i++;
		}
	}
}

int		skip_spaces(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '\0' && file[i] != '\n' && ft_isspace(file[i]))
		i++;
	return (i);
}

int		skip_comment(char *file)
{
	int	i;

	i = 0;
	if (file[i] != COMMENT_CHAR && file[i] != ALT_COMMENT_CHAR)
		return (0);
	while (file[i] != '\0' && file[i] != '\n')
		i++;
	return (i + 1);
}
