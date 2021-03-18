/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:21:34 by pkuussaa          #+#    #+#             */
/*   Updated: 2021/03/18 11:25:47 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	get_statement_arguments(t_statement *statement, char *line, int i)
{
	char	**args;

	i = loop_label(line);
	while (ft_isspace(line[i]) && line[i])
		i++;
	i += ft_strlen(statement->instruction);
	while (ft_isspace(line[i]) && line[i])
		i++;
	args = ft_strsplit(line + i, SEPARATOR_CHAR);
	i = 0;
	while (args[i])
	{
		args[i] = free_strtrim(args[i]);
		i++;
	}
	statement->args = args;
	statement->arg_count = get_2d_size(args);
}
