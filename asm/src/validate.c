#include "../includes/asm.h"

int		check_st(char **file, int i, int j)
{
	if (file[i] == NULL || file[i][j] != '"')
		error_management("missing double quote on statement");
	j++;
	j += skip_spaces(&file[i][j]);
	if (ft_str2chr(file[i], COMMENT_CHAR, ALT_COMMENT_CHAR) != NULL)
		remove_comment(ft_str2chr(file[i], COMMENT_CHAR, ALT_COMMENT_CHAR));
	else if (file[i][j] != '\0')
		error_management("syntax error in statement");
	return (i);
}

/*
** Validates name and comment length and syntax, ignores whitespace
** and removes comments from the ends of the lines.
*/

int		validate_st(char **file, int i, int j, int max_length)
{
	int		len;

	j += skip_spaces(&file[i][j]);
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
	return (check_st(file, i, j));
}

/*
** Validates header (champion name and comment)
** Checks that there is one and only one name and comment given
** at the start of the file. Comments, extra whitespace and empty
** lines are allowed, everything else leads to an error.
*/

int		validate_header(char **file)
{
	int	i;
	int	j;
	int	name;
	int comment;

	i = 0;
	name = 0;
	comment = 0;
	j = 0;
	while (file[i] != NULL && (name == 0 || comment == 0))
	{
		j = skip_spaces(&file[i][j]);
		if (!ft_strncmp(&file[i][j], NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
		{
			j += ft_strlen(NAME_CMD_STRING);
			i = validate_st(file, i, j, PROG_NAME_LENGTH);
			name++;
		}
		else if (!ft_strncmp(&file[i][j], COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
		{
			j += ft_strlen(COMMENT_CMD_STRING);
			i = validate_st(file, i, j, COMMENT_LENGTH);
			comment++;
		}
		else if (file[i][j] == COMMENT_CHAR || file[i][j] == ALT_COMMENT_CHAR)
			remove_comment(ft_str2chr(&file[i][j], COMMENT_CHAR, ALT_COMMENT_CHAR));
		else
			error_management("error in header");
		i++;
	}
	if (name != 1 || comment != 1)
		error_management("statement duplicate or missing");
	return (i);
}

void	validate_file(t_asm *assm)
{
	int		i;

	i = validate_header(assm->file);
	validate_instructions(assm->file, i);
	ft_putstr("		~ validation successful ~\n");
}
