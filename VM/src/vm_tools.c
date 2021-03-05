#include "vm.h"

void		init_structs(t_pl *players, t_flag *flags)
{
	int			i;

	i = -1;
	while (++i < MAX_PLAYERS + 1)
		players->pl_order[i] = NULL;
	players->pl_num = 0;
	i = -1;
	while (++i < MAX_PLAYERS + 1)
	{
		flags->n[i] = INIT_FLAG;
		players->last_life[i] = 0;
	}
	flags->dump = INIT_FLAG;
	flags->viz = INIT_FLAG;
	flags->aff = 0;
}

/*
** Allocates the right amount of memory for the header_t* array
*/

header_t	**prepare_header_info_array(int pl_num)
{
	header_t	**h_info;
	int			i;

	if (!(h_info = (header_t**)malloc(sizeof(header_t*) *
		pl_num + 1)))
		vm_error(strerror(errno));
	h_info[0] = NULL;
	i = 1;
	while (i <= pl_num)
	{
		if (!(h_info[i] = (header_t*)malloc(sizeof(header_t))))
			vm_error(strerror(errno));
		i++;
	}
	return (h_info);
}

/*
** Reverses the order of the bytes in *bytes array
*/

void		ft_revbytes(char *bytes, size_t size)
{
	size_t		i;
	size_t		j;
	char		temp;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		temp = bytes[i];
		bytes[i] = bytes[j];
		bytes[j] = temp;
		i++;
		j--;
	}
}

int			ft_str_is_empty(char *str, int size)
{
	int			i;
	int			ret;

	ret = 1;
	i = 0;
	while (i < size)
	{
		if (str[i])
		{
			ret = 0;
			break ;
		}
		i++;
	}
	return (ret);
}

/*
** Sets registries for the new carriage. If carriage will be a copy,
** copy registries from *copy_regs, otherwise set them to 0.
** Place players 'id' in the first registry with a '-' sign.
*/

void		initialize_registries(int *new_regs, int id, int *copy_regs)
{
	int			i;

	i = 0;
	while (i < REG_NUMBER)
	{
		if (i == 0)
		{
			if (copy_regs)
				new_regs[i] = copy_regs[i];
			else
				new_regs[i] = (id * -1);
		}
		else if (!copy_regs)
			new_regs[i] = 0;
		else
			new_regs[i] = copy_regs[i];
		i++;
	}
}
