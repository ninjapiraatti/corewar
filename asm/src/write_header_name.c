#include "../includes/asm.h"

void		write_name(int fd, char a, t_asm *assm)
{
	int				i;
	int				namei;
	int				magic;
	char			*name;

	name = assm->name;
	namei = ft_strlen(name);
	i = 0;
	while (i < namei)
	{
		write(fd, &name[i], 1);
		i++;
	}
	i = 0;
	while (i < 128 - namei)
	{
		write(fd, &a, 1);
		i++;
	}
}

void		write_header(t_asm *assm, int fd)
{
	unsigned char	a;
	unsigned char	argh[3];
	int				i;
	int				magic;

	a = 0x00; // Why can't this be directly written like write(fd, 0x0, 1)? It must be possible.
	i = 3;
	magic = COREWAR_EXEC_MAGIC;
	while (i >= 0)
	{
		argh[i] = *(((unsigned char *)&magic) + i);
		write(fd, &argh[i], 1);
		i--;
	}
	write_name(fd, a, assm);
}