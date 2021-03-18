/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:56:02 by ksalmi            #+#    #+#             */
/*   Updated: 2021/03/18 11:21:12 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	flags->viz = 0;
	flags->live = 0;
	flags->aff = 0;
	flags->moves = 0;
	flags->kill = 0;
	flags->pc_move = 0;
	flags->show_cycles = 0;
}

/*
** Allocates the right amount of memory for the header_t* array
*/

t_header	**prepare_header_info_array(int pl_num)
{
	t_header	**h_info;
	int			i;

	if (!(h_info = (t_header**)malloc(sizeof(t_header*) *
		pl_num + 1)))
		vm_error(strerror(errno));
	h_info[0] = NULL;
	i = 1;
	while (i <= pl_num)
	{
		if (!(h_info[i] = (t_header*)malloc(sizeof(t_header))))
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

void		init_registries(int *new_regs, int id, int *copy_regs)
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
