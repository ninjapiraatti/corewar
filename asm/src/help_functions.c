/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:22:02 by pkuussaa          #+#    #+#             */
/*   Updated: 2021/03/18 11:30:04 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
** prints error message given as parameter and a newline,
** then exits the program.
*/

void	error_management(char *str)
{
	ft_putendl(str);
	exit(1);
}

/*
** returns row count of 2d array.
*/

int		get_2d_size(char **arr)
{
	int i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

/*
** reallocates 2d array with size + 1 and adds string given
** as parameter to the 2d array.
*/

char	**resize_2d_array(char **ar, char *str)
{
	char	**new;
	int		i;

	if (!ar)
	{
		if (!(new = (char**)ft_memalloc(sizeof(char*) * 2)))
			error_management(strerror(errno));
		new[0] = str;
		new[1] = NULL;
	}
	else
	{
		if (!(new = (char**)ft_memalloc(sizeof(char*) * (get_2d_size(ar) + 2))))
			error_management(strerror(errno));
		i = 0;
		while (i < get_2d_size(ar))
		{
			new[i] = ft_strdup(ar[i]);
			i++;
		}
		new[i] = str;
		new[i + 1] = NULL;
		free(ar);
	}
	return (new);
}

/*
** same as regular ft_strjoin, but frees strings given as parameters.
*/

char	*free_strjoin(char *s1, char *s2)
{
	char *str;

	if (!(str = (char*)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		error_management(strerror(errno));
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	free(s1);
	free(s2);
	return (str);
}

char	*free_strtrim(char *s)
{
	size_t			len;
	unsigned int	i;
	unsigned int	start;
	char			*trimmed;

	i = 0;
	len = ft_strlen(s);
	if (!s)
		return (NULL);
	while (ft_isspace(s[i]))
		i++;
	start = i;
	while (ft_isspace(s[len - 1]))
		len--;
	if (len < start)
	{
		if (!(trimmed = (char *)malloc(sizeof(char) * 1)))
			error_management(strerror(errno));
		trimmed[0] = '\0';
	}
	else
		trimmed = ft_strsub(s, start, len - start);
	free(s);
	return (trimmed);
}
