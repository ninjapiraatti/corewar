/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fucking_hell_get_next.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:49:04 by ksalmi            #+#    #+#             */
/*   Updated: 2019/11/25 19:17:03 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_newlines(char **s, char **line, int fd)
{
	char	*temp;
	char	*found;

	if ((found = ft_strchr(s[fd], '\n')))
	{
		*line = ft_strsub(s[fd], 0, found - s[fd]);
		temp = ft_strdup(found + 1);
		free(s[fd]);
		s[fd] = temp;
		return (1);
	}
	if (s[fd][0] != '\0')
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
		return (1);
	}
	*line = "\0";
	ft_strdel(&s[fd]);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*s[MAX_FD];
	char		*whole_line;
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || !line || fd > MAX_FD)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		whole_line = ft_strjoin(s[fd], buf);
		if (s[fd])
			free(s[fd]);
		s[fd] = whole_line;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret == 0 && !s[fd])
		return (0);
	return (check_newlines(s, line, fd));
}
