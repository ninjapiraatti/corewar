#include "includes/op.h"

int	main(int argc, char **argv)
{
    char *file;

    if (argc > 1)
    {
        file = argv[argc - 1];
        if (file[ft_strlen(file) - 1] == 's' && file[ft_strlen(file) - 2] == '.')
        {
            ft_printf("Lollotiloo");
        }
    }
	return (0);
}

