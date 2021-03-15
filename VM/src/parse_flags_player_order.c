#include "vm.h"

/*
** Assigns the player order for every champion found. If 'pos' is not
** zero, meaning that the assignment happens after -n flag is triggered,
** and the position where the new champion should be placed is not empty,
** the function moves all the existing champions a step forward in the array.
** If 'pos' is zero, the champion is placed in the first free slot.
*/

static void	assign_player_order(t_pl *ps, char *champion, int pos)
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

static void	double_check_player_order(char **order, int player_num)
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

/*
** Checks for valid flags and checks the input of the flag (the
** following argument) to make sure it is a number and
** saves it into the struct. If -n flag is found, sends the
** champion whose order position is being indicated to
** 'assign_player_order'.
** Returns the current index i.
*/

static int	parse_flags(int i, t_flag *fl, t_pl *ps, t_avac *avac)
{
	int		pos;
	char	**av;

	pos = 0;
	av = avac->av;
	if (!ft_strcmp(av[i], "-dump"))
	{
		if (fl->dump != INIT_FLAG)
			vm_error("Error, too many -dump flags");
		if (++i >= avac->ac ||
			ft_strcmp(ft_itoa(fl->dump = ft_atoi(av[i])), av[i]))
			vm_error("Error, -dump flag must be followed by a number");
	}
	else if (!ft_strcmp(av[i], "-n"))
	{
		fl->n[0] = 1;
		if (++i + 1 >= avac->ac || ft_strcmp(ft_itoa((pos = ft_atoi(av[i]))),
			av[i]) || pos < 1 || fl->n[pos] != INIT_FLAG || pos > MAX_PLAYERS)
			vm_error("Error, invalid usage of -n flag");
		i++;
		assign_player_order(ps, av[i], pos);
	}
	else
		vm_error("Error, invalid flag option");
	return (i);
}

/*
** Goes through argument list saving champion files and
** sending anything looking like a flag option to
** 'parse_flags'.
*/

void		parse_flags_player_order(t_pl *players, t_flag *flags, t_avac *avac)
{
	int		i;

	i = 1;
	while (i < avac->ac)
	{
		if (ft_strstr(avac->av[i], ".cor\0"))
		{
			if (players->pl_num + 1 > MAX_PLAYERS)
				vm_error("Error, too many players");
			players->pl_num++;
			assign_player_order(players, avac->av[i], 0);
		}
		else if (!ft_strcmp(avac->av[i], "-v"))
			flags->viz = 1;
		else if (!ft_strcmp(avac->av[i], "-a"))
			flags->aff = 1;
		else if (!ft_strcmp(avac->av[i], "-k"))
			flags->kill = 1;
		else if (!ft_strcmp(avac->av[i], "-l"))
			flags->live = 1;
		else if (!ft_strcmp(avac->av[i], "-m"))
			flags->moves = 1;
		else if (!ft_strcmp(avac->av[i], "-p"))
			flags->pc_move = 1;
		else if (!ft_strcmp(avac->av[i], "-c"))
			flags->show_cycles = 1;
		else if (avac->av[i][0] == '-')
			i = parse_flags(i, flags, players, avac);
		else
			vm_error("Error, files must be .cor -files");
		i++;
	}
	double_check_player_order(players->pl_order, players->pl_num);
}
