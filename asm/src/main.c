//#include "includes/op.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*file;
	int		fd;
	int		fdr;
	int		i;
	char	buf[9];

	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		fdr = open("output.cor", O_RDWR);
		while ((i = read(fd, buf, 8)) > 0)
		{
			write(fdr, &buf, 9);
			write(1, &buf, 9);
		}
	}
	return (0);
}
