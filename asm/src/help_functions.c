/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:22:02 by pkuussaa          #+#    #+#             */
/*   Updated: 2021/03/18 10:41:44 by spentti          ###   ########.fr       */
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

int		get_2d_array_size(char **arr)
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

char	**resize_2d_array(char **arr, char *str)
{
	char	**new_arr;
	int		i;

	if (!arr)
	{
		new_arr = (char**)ft_memalloc(sizeof(char*) * 2);
		new_arr[0] = str;
		new_arr[1] = NULL;
	}
	else
	{
		new_arr = (char**)ft_memalloc(sizeof(char*) * (get_2d_array_size(arr)
			+ 2));
		i = 0;
		while (i < get_2d_array_size(arr))
		{
			new_arr[i] = ft_strdup(arr[i]);
			i++;
		}
		new_arr[i] = str;
		new_arr[i + 1] = NULL;
		free(arr);
	}
	return (new_arr);
}

/*
** same as regular ft_strjoin, but frees strings given as parameters.
*/

char	*free_strjoin(char *s1, char *s2)
{
	char *str;

	if (!(str = (char*)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
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
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' ||
	s[i] == '\r' || s[i] == '\v')
		i++;
	start = i;
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n'
	|| s[len - 1] == '\r' || s[len - 1] == '\v')
		len--;
	if (len < start)
	{
		trimmed = (char *)malloc(sizeof(char) * 1);
		trimmed[0] = '\0';
	}
	else
		trimmed = ft_strsub(s, start, len - start);
	free(s);
	return (trimmed);
}
