#include "vm.h"

void	dump_memory(t_arena *arena)
{
	int	i;
	int	j;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("0x%04x : ", i);
		j = 0;
		while (j < 32)
		{
			ft_printf("%02x ", arena[i].ar);
			j++;
			i++;
		}
		ft_putchar('\n');
	}
	exit(0);
}

void	print_sti_info(int reg, int arg2, int arg3, int pos)
{
	ft_printf(" r%d %d %d\n", reg, arg2, arg3);
	ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
		arg2, arg3, arg2 + arg3, pos);
}
