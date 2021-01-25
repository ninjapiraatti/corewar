#include "../includes/asm.h"
#include <stdio.h>

void		outputbin(t_asm *assm)
{
	unsigned char	a;
	unsigned char	argh[3];
	int				fd;
	int				i;
	int				namei;
	int				magic;
	char			*examplename;

	a = 0x00; // Why can't this be directly written like write(fd, 0x0, 1)? It must be possible.
	i = 3;
	examplename = "kylpynalle";
	namei = ft_strlen(examplename);
	magic = COREWAR_EXEC_MAGIC;
	fd = open("test.cor", O_WRONLY);
	ft_printf("\nCorewar magic header: ");
	while (i >= 0)
	{
		argh[i] = *(((unsigned char *)&magic) + i);
		ft_printf("%x", argh[i]);
		write(fd, &argh[i], 1);
		i--;
	}
	i = 0;
	while (i < namei)
	{
		ft_printf("%c", examplename[i]);
		write(fd, &examplename[i], 1);
		i++;
	}
	i = 0;
	while (i < 128 - namei)
	{
		write(fd, &a, 1);
		i++;
	}
	ft_printf("\nSupposedly wrote something to a file.\n\n");
}