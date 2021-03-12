/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_statement_size2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:21:45 by pkuussaa          #+#    #+#             */
/*   Updated: 2021/03/12 12:32:19 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		get_arg_type(char *arg)
{
	if (ft_strchr(arg, '%'))
		return (DIR_CODE);
	if (ft_strchr(arg, 'r'))
		return (REG_CODE);
	return (IND_CODE);
}

int		get_arg_size(int code, int type)
{
	if (type == DIR_CODE)
		return (op_table[code].t_dir_size);
	return (type == REG_CODE ? 1 : 2);
}

int		get_statement_size(t_statement *statement)
{
	int		size;
	int		arg_type;
	int		i;

	i = 0;
	size = 1;
	if (op_table[statement->code].arg_type_code)
		size += 1;
	while (statement->args[i])
	{
		arg_type = get_arg_type(statement->args[i]);
		size += get_arg_size(statement->code, arg_type);
		i++;
	}
	return (size);
}
