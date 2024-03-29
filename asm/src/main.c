/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:22:11 by pkuussaa          #+#    #+#             */
/*   Updated: 2021/03/18 11:31:08 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	print_2d_array(char **arr)
{
	int		i;

	i = -1;
	if (!arr)
		return ;
	while (arr[++i])
		ft_printf("%s\n", arr[i]);
}

t_asm	*init_asm(void)
{
	t_asm	*assm;

	if (!(assm = (t_asm*)malloc(sizeof(t_asm))))
		error_management(strerror(errno));
	assm->statements = NULL;
	assm->name = NULL;
	assm->comment = NULL;
	assm->file = NULL;
	assm->file1d = NULL;
	assm->champion_size = 0;
	assm->file_size = 0;
	assm->index = 0;
	return (assm);
}

void	check_last_row(char *str)
{
	int	nl;
	int	i;

	i = 0;
	nl = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			nl = i;
		i++;
	}
	i = nl + 1;
	while (str[i] != '\0' && ft_isspace(str[i]))
		i++;
	if (str[i] != '\0' && str[i] != COMMENT_CHAR && str[i] != ALT_COMMENT_CHAR)
		error_management("error in end of file");
}

/*
** reads champion file into 2d array
*/

char	**read_file(char *file, int i, t_asm *assm)
{
	int		fd;
	char	buf[BUF_SIZE + 1];
	char	*input;
	char	*tmp;
	char	**arr;

	fd = open(file, O_RDONLY);
	input = ft_strnew(0);
	while ((i = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[i] = '\0';
		tmp = ft_strjoin(input, buf);
		ft_strdel(&input);
		input = tmp;
	}
	if (i == -1)
		error_management(strerror(errno));
	if (input == NULL)
		error_management("empty input file");
	check_last_row(input);
	arr = ft_strsplit(input, '\n');
	assm->file1d = input;
	return (arr);
}

int		main(int argc, char **argv)
{
	t_asm		*assm;

	if (argc < 2)
		error_management("Error, no file arguments.");
	if (argv[argc - 1][ft_strlen(argv[argc - 1]) - 1] != 's' &&
		argv[argc - 1][ft_strlen(argv[argc - 1]) - 2] != '.')
		error_management("Error, wrong file type.");
	assm = init_asm();
	assm->file = read_file(argv[argc - 1], 0, assm);
	validate_file(assm);
	get_name_and_comment(assm, 0, 0);
	lexical_analysis(assm);
	write_hexa(assm, argv[argc - 1]);
	return (0);
}
