/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_statement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:21:49 by pkuussaa          #+#    #+#             */
/*   Updated: 2021/03/18 11:12:06 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int				loop_label(char *line)
{
	int		i;

	i = 0;
	while (ft_strchr(LABEL_CHARS, line[i]))
		i++;
	if (line[i] == LABEL_CHAR)
		return (i + 1);
	return (0);
}

int				get_instruction_code(char *instruction)
{
	int		code;
	int		i;

	i = -1;
	while (++i < OP_CODE_COUNT)
		if (ft_strcmp(g_op_table[i].op_name, instruction) == 0)
			code = i;
	return (code);
}

unsigned char	get_arg_type_code(t_statement *statement)
{
	unsigned char	code;
	int				type;
	int				i;
	int				bytes;

	code = 0;
	i = 0;
	bytes = 7;
	while (statement->args[i])
	{
		type = get_arg_type(statement->args[i]);
		if (type == DIR_CODE || type == IND_CODE)
			code += 1 << bytes;
		if (type == REG_CODE || type == IND_CODE)
			code += 1 << (bytes - 1);
		bytes -= 2;
		i++;
	}
	return (code);
}

char			*get_instruction(t_asm *assm)
{
	char	*instruction;
	int		i;
	int		j;

	if (!assm->file[assm->index])
		return (NULL);
	i = loop_label(assm->file[assm->index]);
	while (assm->file[assm->index][i] && ft_isspace(assm->file[assm->index][i]))
		i++;
	j = i;
	while (ft_isalpha(assm->file[assm->index][j]))
		j++;
	if (j > i)
		return (ft_strsub(assm->file[assm->index], i, j - i));
	return (NULL);
}
