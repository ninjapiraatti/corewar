#include "vm.h"

int	change_player_order(int i, t_flag *fl, t_pl *ps, t_avac *avac)
{
	char	*pos_string;
	int		pos;
	char	**av;

	av = avac->av;
	fl->n[0] = 1;
	i++;
	if (i + 1 >= avac->ac)
		vm_error("Error, invalid usage of -n flag");
	pos = ft_atoi(av[i]);
	pos_string = ft_itoa(pos);
	if (ft_strcmp(pos_string, av[i]) || pos < 1 ||
		fl->n[pos] != INIT_FLAG || pos > MAX_PLAYERS)
		vm_error("Error, invalid usage of -n flag");
	i++;
	ft_strdel(&pos_string);
	assign_player_order(ps, av[i], pos);
	return (i);
}

/*
** Assigns the player order for every champion found. If 'pos' is not
** zero, meaning that the assignment happens after -n flag is triggered,
** and the position where the new champion should be placed is not empty,
** the function moves all the existing champions a step forward in the array.
** If 'pos' is zero, the champion is placed in the first free slot.
*/

void	assign_player_order(t_pl *ps, char *champion, int pos)
{
	int		i;

	i = 1;
	while (ps->pl_order[i])
		i++;
	if (!pos)
		ps->pl_order[i] = champion;
	else
	{
		ps->pl_num++;
		if (ps->pl_order[pos] != NULL)
		{
			while (i > pos)
			{
				ft_strswap(&ps->pl_order[i], &ps->pl_order[i - 1]);
				i--;
			}
		}
		if (!(ps->pl_order[pos]))
			ps->pl_order[pos] = champion;
	}
}

void	double_check_player_order(char **order, int player_num)
{
	int		i;

	i = 1;
	while (i < MAX_PLAYERS)
	{
		if (order[i])
		{
			if (i > player_num)
				vm_error("Error, invalid -n flag implementation!");
		}
		i++;
	}
}
