//#include "includes/op.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
    char    *file;
    int     fd;
    //int     fdr;
    int     i;
    char    buf[9];

    if (argc > 1)
    {
        FILE *fp;
        //file = argv[argc - 1];
        fd = open(argv[1], O_RDONLY);
        fp = fopen ("output.cor","w");
        printf("fd is %d", fd);
        while ((i = read(fd, buf, 8)) > 0)
        {
            /*
            buf[i] = '\0';
            if (lem->input == NULL)
                lem->input = ft_strnew(0);
            tmp = ft_strjoin(lem->input, buf);
            ft_strdel(&lem->input);
            lem->input = tmp;
            */
            write(fp, 0x24, 1);
            printf(buf);
        }
        /*
        if (file[ft_strlen(file) - 1] == 's' && file[ft_strlen(file) - 2] == '.')
        {
            printf("Lollotiloo");
        }
        */
    }
	return (0);
}

