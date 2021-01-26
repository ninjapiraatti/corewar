#include "../includes/asm.h"

/*
** Validates name and comment length and syntax, ignores whitespace
** and removes comments from the ends of the lines.
*/

int		validate_st(char **file, int i, char *cmd_string, int max_length)
{
	int		j;
	int		len;

	j = ft_strlen(cmd_string);
	while (file[i][j] != '\0' && ft_isspace(file[i][j]))
		j++;
	if (file[i][j] != '"')
		error_management("error in champion statement");
	j++;
	len = 0;
	while (file[i] != NULL && file[i][j] != '"')
	{
		len++;
		while (file[i][j++] != '\0' && file[i][j] != '"')
			len++;
		if (file[i][j] == '"')
			break ;
		j = 0;
		i++;
	}
	if (len > max_length)
		error_management("champion statement length exceeded");
	if (file[i] == NULL || file[i][j] != '"')
		error_management("missing double quote on statement");
	j++;
	while (file[i][j] != '\0' && ft_isspace(file[i][j]))
		j++;
	if (ft_str2chr(file[i], COMMENT_CHAR, ALT_COMMENT_CHAR) != NULL)
		remove_comment(ft_str2chr(file[i], COMMENT_CHAR, ALT_COMMENT_CHAR));
	else if (file[i][j] != '\0')
		error_management("syntax error in statement");
	return (i + 1);
}

/*
** Validates header (champion name and comment)
** Checks that there is one and only one name and comment given
** at the start of the file. Comments, extra whitespace and empty
** lines are allowed, everything else leads to an error.
** The order of name and comment doesn't matter and they have to
** prefixed by the string defined in op.h
*/

int		validate_header(t_asm *assm)
{
	int	i;
	int	j;
	int	name;
	int comment;

	i = 0;
	j = 0;
	name = 0;
	comment = 0;
	while (assm->file[i] != NULL && (name == 0 || comment == 0))
	{
		while (assm->file[i][j] != '\0' && ft_isspace(assm->file[i][j]))
			j++;
		if (ft_strncmp(assm->file[i], NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0)
		{
			i = validate_st(assm->file, i, NAME_CMD_STRING, PROG_NAME_LENGTH);
			name++;
		}
		else if (ft_strncmp(assm->file[i], COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)) == 0)
		{
			i = validate_st(assm->file, i, COMMENT_CMD_STRING, COMMENT_LENGTH);
			comment++;
		}
		else if (ft_str2chr(assm->file[i], COMMENT_CHAR, ALT_COMMENT_CHAR) != NULL)
			remove_comment(ft_str2chr(assm->file[i], COMMENT_CHAR, ALT_COMMENT_CHAR));
		else
			error_management("error in header");
	}
	if (name != 1 || comment != 1)
		error_management("duplicate statement");
	return (i);
}

void	validate_instructions(t_asm *assm, int i)
{
	int	j;

	j = 0;
	while (assm->file[i] != NULL)
	{
		if (ft_str2chr(assm->file[i], COMMENT_CHAR, ALT_COMMENT_CHAR) != NULL)
			remove_comment(ft_str2chr(assm->file[i], COMMENT_CHAR, ALT_COMMENT_CHAR));
		i++;
	}
}

/*
** Removes comments from file
*/

void	validate_file(t_asm *assm)
{
	char	**file;
	int		i;

	file = assm->file;
	i = validate_header(assm);
	validate_instructions(assm, i);
}
