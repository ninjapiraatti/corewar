/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:22:37 by pkuussaa          #+#    #+#             */
/*   Updated: 2021/03/18 11:12:24 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
** Checks that argument is the correct type and checks
** the validity of separator character.
*/

int		validate_arg(char *file, int op, int args)
{
	int	i;

	i = 0;
	if (file[i] == '\0')
		error_management("file ended");
	if (g_op_table[op].arguments[args][0] == REG_CODE)
		i = is_t_reg(&file[i]);
	if (i == 0 && g_op_table[op].arguments[args][1] == DIR_CODE)
		i = is_t_dir(&file[i]);
	if (i == 0 && g_op_table[op].arguments[args][2] == IND_CODE)
		i = is_t_ind(&file[i]);
	if (i == 0)
		error_management("didnt find correct argument");
	i += skip_spaces(&file[i]);
	if (g_op_table[op].arg_amount > 1 && args < g_op_table[op].arg_amount - 1 \
	&& file[i] != SEPARATOR_CHAR)
		error_management("no separator char");
	else if (args == g_op_table[op].arg_amount - 1 && file[i] == SEPARATOR_CHAR)
		error_management("separator char after last parameter");
	if (file[i] == SEPARATOR_CHAR)
		i++;
	return (i);
}

/*
** Goes through arguments for the instruction.
*/

void	validate_arguments(char *file, int op)
{
	int	i;
	int	args;

	i = 0;
	args = 0;
	while (args < g_op_table[op].arg_amount)
	{
		i += skip_spaces(&file[i]);
		i += validate_arg(&file[i], op, args);
		if (i == 0)
			error_management("invalid arguments");
		args++;
	}
	while (file[i] != '\0')
	{
		if (!ft_isspace(file[i]))
			error_management("syntax error");
		i++;
	}
}

/*
** Finds matching instruction from g_op_table.
*/

int		validate_instruction(char *file)
{
	int		i;
	int		code;
	char	*op_name;

	code = -1;
	i = 0;
	i += skip_spaces(&file[i]);
	if (file[i] != '\0')
	{
		file = &file[i];
		i = OP_CODE_COUNT - 1;
		while (i >= 0)
		{
			op_name = g_op_table[i].op_name;
			if (ft_strncmp(op_name, file, ft_strlen(op_name)) == 0)
			{
				code = i;
				validate_arguments(file + ft_strlen(op_name), code);
				break ;
			}
			i--;
		}
	}
	return (code);
}

int		validate_label(char *file)
{
	int	i;

	i = is_label(file, 0);
	if (i != 0 && validate_instruction(&file[i]) == -1)
	{
		while (file[i] != '\0')
		{
			if (!ft_isspace(file[i]))
				error_management("syntax error");
			i++;
		}
	}
	return (i);
}

/*
** Removes comments and validates labels.
*/

void	validate_instructions(char **file, int i)
{
	int	j;

	while (file[i] != NULL)
	{
		j = 0;
		if (ft_str2chr(file[i], COMMENT_CHAR, ALT_COMMENT_CHAR) != NULL)
			remove_comment(ft_str2chr(file[i], COMMENT_CHAR, ALT_COMMENT_CHAR));
		j += skip_spaces(&file[i][j]);
		if (file[i][j] != '\0' && validate_label(&file[i][j]) == 0)
		{
			if (validate_instruction(&file[i][j]) == -1)
				error_management("syntax error in instructions");
		}
		i++;
	}
}
