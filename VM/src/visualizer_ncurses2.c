#include "vm.h"

/*
** Prints the individual hex with color. If there is currently
** a carriage on top, the color will be in the background,
** otherwise the hex itself will have color.
*/

t_arena	print_hex_color(t_arena arena)
{
	int	color;

	color = (arena.color_carr != 0) ? arena.color_carr : arena.color;
	attrset(COLOR_PAIR(color));
	if (arena.color_bold)
	{
		attron(A_BOLD);
		printw("%02x", arena.ar);
		attroff(A_BOLD);
		arena.color_bold--;
	}
	else
		printw("%02x", arena.ar);
	attroff(COLOR_PAIR(color));
	addch(' ');
	return (arena);
}

void	ncurses_print_players(t_game *game, int y, int x)
{
	int	i;

	i = 0;
	while (++i <= game->players->pl_num)
	{
		move(++y, x);
		attrset(COLOR_PAIR(i + 10));
		if (game->players->last_life[i] &&
			game->players->last_life[i] > (game->cycles - game->ctd))
		{
			attron(A_BOLD);
			printw("Player no %d (%s) is alive!",
				i, game->players->h_info[i]->prog_name);
			attroff(A_BOLD);
		}
		else
			printw("Player no %d (%s)", i, game->players->h_info[i]->prog_name);
		attroff(COLOR_PAIR(i + 10));
	}
}

void	ncurses_print_game_info(t_game *game, int y)
{
	int	x;

	attron(A_BOLD);
	mvprintw(y += 2, x = 5, "Cycle: %d", game->cycles);
	mvprintw(y += 2, x, "Cycles to die: %d", game->ctd);
	mvprintw(y += 2, x, "Number of cycles before check: %d",
		game->ctd - game->cycles % game->ctd);
	mvprintw(y += 2, x, "Lives performed in current period: %d",
		game->lives_num);
	mvprintw(y += 2, x, "Players:");
	attroff(A_BOLD);
	ncurses_print_players(game, y, x);
}
