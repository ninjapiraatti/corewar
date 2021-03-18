/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 09:14:02 by tlouekar          #+#    #+#             */
/*   Updated: 2020/07/14 15:39:33 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		*trimstart(char *s, char *newstr)
{
	int			i;
	int			spaces;

	i = 0;
	spaces = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && (s[i]))
	{
		spaces++;
		i++;
	}
	while (s[i] != '\0')
	{
		newstr[i - spaces] = s[i];
		i++;
	}
	newstr[i - spaces] = '\0';
	return (newstr);
}

static char		*trimend(char *ns, int n)
{
	ns[n + 1] = '\0';
	while ((ns[n] == ' ' || ns[n] == '\n' || ns[n] == '\t') && (ns[n]))
	{
		ns[n] = '\0';
		n--;
	}
	return (ns);
}

char			*ft_strtrim(char const *s)
{
	int			len;
	char		*newstr;

	if (!s)
		return (NULL);
	len = ft_strlen((char *)s);
	if ((newstr = (char *)malloc(len * sizeof(char) + 1)))
	{
		newstr = trimstart((char *)s, newstr);
		len = ft_strlen(newstr);
		newstr = trimend(newstr, (len - 1));
		return (newstr);
	}
	else
		return (NULL);
}
