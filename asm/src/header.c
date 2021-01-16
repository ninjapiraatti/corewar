#include "../includes/asm.h"

/*
** parses NAME_CMD_STRING from the champion file.
*/

void		get_name(char **file, t_asm *assm)
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
	assm->name = name;
}

/*
** parses COMMENT_CMD_STRING from the champion file.
*/

void		get_comment(char **file, t_asm *assm)
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
	assm->comment = comment;
}

/*
** searches for NAME_CMD_STRING and COMMENT_CMD_STRING from the champion file.
*/

void			get_name_and_comment(t_asm *assm)
{
	assm->index = 0;
	while (assm->file[assm->index])
	{
		if (assm->name && assm->comment)
			break ;
		if (ft_strnequ(assm->file[assm->index], NAME_CMD_STRING,
		ft_strlen(NAME_CMD_STRING)))
			get_name(assm->file, assm);
		else if (ft_strnequ(assm->file[assm->index], COMMENT_CMD_STRING,
		ft_strlen(COMMENT_CMD_STRING)))
			get_comment(assm->file, assm);
		else
			assm->index++;
	}
}
