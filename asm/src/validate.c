#include "../includes/asm.h"

int		count_rows(char *file, int end)
{
	int	rows;
	int	i;

	i = 0;
	rows = 0;
	while (i <= end)
	{
		if (file[i] == '\n' && file[i + 1] != '\n')
			rows++;
		i++;
	}
	return (rows);
}

/*
** Validates name and comment length and syntax, ignores whitespace
** and removes comments from the ends of the lines.
** Change 2d array to 1d to be able to count empty lines
*/

int		validate_st(char *file, int i, int max_length)
{
	int		len;

	i += skip_spaces(&file[i]);
	if (file[i] != '"')
		error_management("error in champion statement");
	i++;
	len = 0;
	while (file[i] != '\0' && file[i] != '"')
	{
		len++;
		i++;
	}
	if (len > max_length)
		error_management("champion statement length exceeded");
	if (file[i] == '\0' || file[i] != '"')
		error_management("missing double quote on statement");
	i++;
	i += skip_spaces(&file[i]);
	if (ft_str2chr(&file[i], COMMENT_CHAR, ALT_COMMENT_CHAR) != NULL)
		i += skip_comment(ft_str2chr(&file[i], COMMENT_CHAR, ALT_COMMENT_CHAR));
	else if (file[i] != '\n')
		error_management("syntax error in statement");
	return (i + 1);
}

/*
** Validates header (champion name and comment)
** Checks that there is one and only one name and comment given
** at the start of the file. Comments, extra whitespace and empty
** lines are allowed, everything else leads to an error.
*/

int		validate_header(char *file)
{
	int	i;
	int	name;
	int comment;

	i = 0;
	name = 0;
	comment = 0;
	while (file[i] != '\0' && (name == 0 || comment == 0))
	{
		// ft_printf("at %.10s ", &file[i]);
		i += skip_spaces(&file[i]);
		if (!ft_strncmp(&file[i], NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
		{
			i += ft_strlen(NAME_CMD_STRING);
			i = validate_st(file, i, PROG_NAME_LENGTH);
			// ft_printf("found name\n");
			name++;
		}
		else if (!ft_strncmp(&file[i], COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
		{
			i += ft_strlen(COMMENT_CMD_STRING);
			i = validate_st(file, i, COMMENT_LENGTH);
			// ft_printf("found player comment\n");
			comment++;
		}
		else if (file[i] == COMMENT_CHAR || file[i] == ALT_COMMENT_CHAR)
		{
			i += skip_comment(ft_str2chr(&file[i], COMMENT_CHAR, ALT_COMMENT_CHAR));
			// ft_printf("found comment\n");
		}
		else if (file[i] == '\n')
			i++;
		else
		{
			// ft_printf("found nothing\n");
			error_management("error in header");
		}
	}
	if (name != 1 || comment != 1)
		error_management("statement duplicate or missing");
	return (count_rows(file, i));
}

void	validate_file(t_asm *assm)
{
	int		i;

	i = validate_header(assm->file1d);
	validate_instructions(assm->file, i);
	ft_putstr("		~ validation successful ~\n");
}
