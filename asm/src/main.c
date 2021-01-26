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

t_asm	*init_asm()
{
	t_asm	*assm;

	if (!(assm = (t_asm*)malloc(sizeof(t_asm))))
		error_management("Malloc error");
	return (assm);
}

/*
** reads champion file into 2d array
*/

char	**read_file(char *file)
{
	int	 fd;
	char	*line;
	char	*str[3];

	fd = open(file, O_RDONLY);
	str[0] = ft_strnew(0);
	while (get_next_line(fd, &line) > 0)
	{
		str[1] = ft_strjoin(line, "\n");
		str[2] = free_strjoin(str[0], str[1]);;
		str[0] = ft_strdup(str[2]);
		free(str[2]);
		free(line);
	}
	return (ft_strsplit(str[0], '\n'));
}

int	main(int argc, char **argv)
{
	t_asm		*assm;

	if (argc < 2)
		error_management("Error, no file arguments.");
	if (argv[argc - 1][ft_strlen(argv[argc - 1]) - 1] != 's' &&
		argv[argc - 1][ft_strlen(argv[argc - 1]) - 2] != '.')
		error_management("Error, wrong file type.");
	assm = init_asm();
	assm->file = read_file(argv[argc - 1]);
	validate_file(assm);
	get_name_and_comment(assm);
	lexical_analysis(assm);
	outputbin(assm);
	return (0);
}
