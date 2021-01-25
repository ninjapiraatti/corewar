/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:09:08 by tlouekar          #+#    #+#             */
/*   Updated: 2020/07/14 15:39:33 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		linejoiner(int fd, char **strs_joiner, char **line, int bytes)
{
	int		i;
	char	*temp;

	i = 0;
	if (bytes < 0)
		return (-1);
	while ((strs_joiner[fd][i] != '\0') && (strs_joiner[fd][i] != '\n'))
		i++;
	if (strs_joiner[fd][i] == '\n')
	{
		*line = ft_strsub(strs_joiner[fd], 0, i);
		temp = ft_strdup(strs_joiner[fd] + i + 1);
		ft_strdel(&strs_joiner[fd]);
		strs_joiner[fd] = temp;
		return (1);
	}
	else if (strs_joiner[fd][i] == '\0')
	{
		if (bytes == BUFF_SIZE)
			return (0);
		*line = ft_strdup(strs_joiner[fd]);
		ft_strdel(&strs_joiner[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char *sv[FD_MAX];
	int			bt;
	char		*temp;
	int			i;

	i = 0;
	bt = 0;
	if ((fd < 0) || (!line) || (read(fd, buf, 0) < 0))
		return (-1);
	while (!(ft_strchr(sv[fd], '\n')) && ((bt = read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[bt] = '\0';
		if (sv[fd] == NULL)
			sv[fd] = ft_strnew(1);
		temp = ft_strjoin(sv[fd], buf);
		free(sv[fd]);
		sv[fd] = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if ((bt == 0 && sv[fd] == NULL) || sv[fd][0] == '\0')
		return (0);
	return (linejoiner(fd, sv, line, bt));
}
