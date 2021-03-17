#include "vm.h"

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

static int	parse_bonus_flags2(t_flag *flags, char *arg)
{
	int	ret;

	ret = 0;
	if (!ft_strcmp(arg, "-l"))
	{
		ret = 1;
		flags->live = 1;
	}
	else if (!ft_strcmp(arg, "-m"))
	{
		ret = 1;
		flags->moves = 1;
	}
	else if (!ft_strcmp(arg, "-p"))
	{
		ret = 1;
		flags->pc_move = 1;
	}
	else if (!ft_strcmp(arg, "-c"))
	{
		ret = 1;
		flags->show_cycles = 1;
	}
	return (ret);
}

static int	parse_bonus_flags(t_flag *flags, char *arg)
{
	int	ret;

	ret = 0;
	if (parse_bonus_flags2(flags, arg))
		return (1);
	if (!ft_strcmp(arg, "-v"))
	{
		ret = 1;
		flags->viz = 1;
	}
	else if (!ft_strcmp(arg, "-a"))
	{
		ret = 1;
		flags->aff = 1;
	}
	else if (!ft_strcmp(arg, "-k"))
	{
		ret = 1;
		flags->kill = 1;
	}
	return (ret);
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
		else if (parse_bonus_flags(flags, avac->av[i]))
			;
		else if (avac->av[i][0] == '-')
			i = parse_flags(i, flags, players, avac);
		else
			vm_error("Error, files must be .cor -files");
		i++;
	}
	double_check_player_order(players->pl_order, players->pl_num);
}
