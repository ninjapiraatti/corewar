/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:22:50 by pkuussaa          #+#    #+#             */
/*   Updated: 2021/03/12 12:43:44 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		count_rows(char *file, int end)
{
	int	rows;
	int	i;

	i = 0;
	rows = 0;
	while (ft_isspace(file[end]))
		end++;
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

int		validate_st(char *file, int i, int max_length, char *cmd_string)
{
	int		len;

	i += ft_strlen(cmd_string);
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

int		validate_header(char *file, int name, int comment, int i)
{
	while (file[i] != '\0' && (name == 0 || comment == 0))
	{
		i += skip_spaces(&file[i]);
		if (!ft_strncmp(&file[i], NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
		{
			i = validate_st(file, i, PROG_NAME_LENGTH, NAME_CMD_STRING);
			name++;
		}
		else if (!ft_strncmp(&file[i], COMMENT_CMD_STRING,
		ft_strlen(COMMENT_CMD_STRING)))
		{
			i = validate_st(file, i, COMMENT_LENGTH, COMMENT_CMD_STRING);
			comment++;
		}
		else if (file[i] == COMMENT_CHAR || file[i] == ALT_COMMENT_CHAR)
			i += skip_comment(&file[i]);
		else if (file[i] == '\n')
			i++;
		else
			error_management("error in header");
	}
	if (name != 1 || comment != 1)
		error_management("statement duplicate or missing");
	return (count_rows(file, i));
}

void	validate_file(t_asm *assm)
{
	int		i;

	i = validate_header(assm->file1d, 0, 0, 0);
	validate_instructions(assm->file, i);
	ft_putstr("		~ validation successful ~\n");
}
