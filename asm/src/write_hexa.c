/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:47:33 by pkuussaa          #+#    #+#             */
/*   Updated: 2021/03/18 11:12:33 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	*get_file_name(char *file_name)
{
	char	*new_name;

	new_name = file_name;
	*ft_strrchr(new_name, '.') = '\0';
	ft_printf("Writing output to: %s.cor\n", file_name);
	return (ft_strjoin(new_name, ".cor"));
}

void	write_champ_exec_code_size(t_asm *assm, int fd)
{
	write(fd, "\0\0\0\0", 4);
	write(fd, &((unsigned char*)&assm->champion_size)[3], 1);
	write(fd, &((unsigned char*)&assm->champion_size)[2], 1);
	write(fd, &((unsigned char*)&assm->champion_size)[1], 1);
	write(fd, &((unsigned char*)&assm->champion_size)[0], 1);
}

void	write_champion_comment(t_asm *assm, int fd)
{
	char	comment[COMMENT_LENGTH];
	int		i;

	ft_bzero(comment, COMMENT_LENGTH);
	i = -1;
	while (assm->comment[++i])
		comment[i] = assm->comment[i];
	write(fd, comment, COMMENT_LENGTH);
	write(fd, "\0\0\0\0", 4);
}

void	write_instructions(t_statement *statement, int fd)
{
	unsigned char	buffer;

	while (statement)
	{
		if (statement->instruction)
		{
			buffer = statement->code + 1;
			write(fd, &buffer, 1);
			if (g_op_table[statement->code].arg_type_code)
				write(fd, &statement->arg_type_code, 1);
			write_arguments(statement, fd);
		}
		statement = statement->next;
	}
}

void	write_hexa(t_asm *assm, char *file_name)
{
	int		fd;
	char	*output_file;

	output_file = get_file_name(file_name);
	fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	free(output_file);
	write_header(assm, fd);
	write_champ_exec_code_size(assm, fd);
	write_champion_comment(assm, fd);
	write_instructions(assm->statements, fd);
}
