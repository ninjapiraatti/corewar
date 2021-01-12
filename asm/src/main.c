#include "includes/op.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
    char    *file;
    int     fd;

    if (argc > 1)
    {
        file = argv[argc - 1];
        fd = open(argv[1], O_RDONLY);
        if (file[ft_strlen(file) - 1] == 's' && file[ft_strlen(file) - 2] == '.')
        {
            ft_printf("Lollotiloo");
        }
    }
	return (0);
}

