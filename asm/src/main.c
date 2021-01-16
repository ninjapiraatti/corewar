//#include "includes/op.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	main(int argc, char **argv)
{
	char	*filename;
	int		fd;
	int		fw;
	int		i;
	char	buf[9];

	if (argc > 1)
	{
		filename = argv[argc - 1];
		fd = open(argv[1], O_RDONLY);
		fw = open("output.cor", O_RDWR);
		if (filename[strlen(filename) - 1] == 's' && filename[strlen(filename) - 2] == '.')
		{
			printf("This is a .s file");
		}
		while ((i = read(fd, buf, 8)) > 0)
		{
			write(fw, &buf, 9);
			write(1, &buf, 9);
		}
	}
	return (0);
}
