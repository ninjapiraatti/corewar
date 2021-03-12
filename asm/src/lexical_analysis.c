/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analysis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:22:07 by pkuussaa          #+#    #+#             */
/*   Updated: 2021/03/12 12:41:12 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
** checks if row in champion file is a statement.
*/

int			contains_statement(char *line)
{
	int		i;

	i = 0;
	if (line[0] == '\0')
		return (0);
	while (line[i])
	{
		if (line[i] == '.' || line[i] == COMMENT_CHAR ||
		line[i] == ALT_COMMENT_CHAR)
			return (0);
		if (!ft_isspace(line[i]))
			return (1);
		i++;
	}
	return (0);
}

/*
** creates a new statement struct.
*/

t_statement	*new_statement(t_asm *assm)
{
	t_statement	*statement;

	if (!(statement = (t_statement*)malloc(sizeof(t_statement))))
		error_management("Malloc error");
	statement->label = get_label(assm);
	statement->instruction = get_instruction(assm);
	if (!statement->instruction)
		return (statement);
	statement->code = get_instruction_code(statement->instruction);
	get_statement_arguments(statement, assm->file[assm->index], 0);
	statement->size = get_statement_size(statement);
	statement->arg_type_code = get_arg_type_code(statement);
	assm->champion_size += statement->size;
	return (statement);
}

/*
** parses the champion file into t_asm struct and ignores all unnecessary rows.
*/

void		lexical_analysis(t_asm *assm)
{
	t_statement *statements;

	assm->file_size = get_2d_array_size(assm->file);
	while (assm->file[assm->index])
	{
		if (contains_statement(assm->file[assm->index]))
		{
			if (assm->statements == NULL)
			{
				statements = new_statement(assm);
				assm->statements = statements;
				statements->next = NULL;
			}
			else
			{
				statements->next = new_statement(assm);
				statements = statements->next;
				statements->next = NULL;
			}
		}
		assm->index++;
		if (assm->file_size <= assm->index)
			break ;
	}
	convert_labels(assm->statements, 0, 0);
}
