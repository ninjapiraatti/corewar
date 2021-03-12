#include "../includes/asm.h"

/*
** parses NAME_CMD_STRING from the champion file.
*/

int		loop_name(char **file, t_asm *assm)
{
	char		*name;

	name = ft_strdup(ft_strchr(file[assm->index], '"') + 1);
	assm->index++;
	while (!ft_strchr(name, '"') && file[assm->index])
	{
		name = free_strjoin(name, ft_strdup("\n"));
		name = free_strjoin(name, ft_strdup(file[assm->index]));
		assm->index++;
		if (ft_strchr(name, '"'))
			break ;
	}
	*ft_strrchr(name, '"') = '\0';
	ft_strdel(&name);
	return (1);
}

/*
** parses COMMENT_CMD_STRING from the champion file.
*/

int		loop_comment(char **file, t_asm *assm)
{
	char		*comment;

	comment = ft_strdup(ft_strchr(file[assm->index], '"') + 1);
	assm->index++;
	while (!ft_strchr(comment, '"') && file[assm->index])
	{
		comment = free_strjoin(comment, ft_strdup("\n"));
		comment = free_strjoin(comment, ft_strdup(file[assm->index]));
		assm->index++;
		if (ft_strchr(comment, '"'))
			break ;
	}
	*ft_strrchr(comment, '"') = '\0';
	ft_strdel(&comment);
	return (1);
}

/*
** searches for NAME_CMD_STRING and COMMENT_CMD_STRING from the champion file.
*/

int		loop_index(t_asm *assm, int name, int comment, int check)
{
	int		i;

	assm->index = 0;
	while (assm->file[assm->index])
	{
		i = 0;
		if (name && comment)
			break ;
		while (ft_isspace(assm->file[assm->index][i]))
			i++;
		if (ft_strnequ(assm->file[assm->index] + i, NAME_CMD_STRING,
		ft_strlen(NAME_CMD_STRING)))
		{
			name = loop_name(assm->file, assm);
			if (comment == 0)
				check = 0;
		}
		else if (ft_strnequ(assm->file[assm->index] + i, COMMENT_CMD_STRING,
		ft_strlen(COMMENT_CMD_STRING)))
		{
			comment = loop_comment(assm->file, assm);
			if (name == 0)
				check = 1;
		}
		else
			assm->index++;
	}
	return (check);
}

void	get_name_and_comment(t_asm *assm, int i, int check)
{
	char	*str;
	char	*first;

	check = loop_index(assm, 0, 0, 2);
	if (check == 0)
		first = ".name";
	else
		first = ".comment";
	str = ft_strchr(ft_strstr(assm->file1d, first), '"') + 1;
	while(str[i] && str[i] != '"')
		i++;
	if (check == 0)
		assm->name = ft_strsub(str, 0, i);
	else
		assm->comment = ft_strsub(str, 0, i);
	str = ft_strchr(str, '"') + 1;
	i = 0;
	first = check == 0 ? ".comment" : ".name";
	str = ft_strchr(ft_strstr(str, first), '"') + 1;
	while(str[i] && str[i] != '"')
		i++;
	if (check == 0)
		assm->comment = ft_strsub(str, 0, i);
	else
		assm->name = ft_strsub(str, 0, i);
}
