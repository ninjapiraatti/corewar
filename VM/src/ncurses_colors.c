#include "vm.h"
#include <ncurses.h>

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

/*
** Calculates the max width of the screen and prints the current
** state of the game arena.
*/

int		ncurses_print_arena(t_arena *arena)
{
	int	i;
	int	y;
	int	x;
	int	max_x;

	max_x = getmaxx(stdscr);
	i = 0;
	y = 0;
	x = 0;
	while (i < MEM_SIZE)
	{
		move(y, x);
		arena[i] = print_hex_color(arena[i]);
		i++;
		x += 3;
		if (x >= max_x)
		{
			y++;
			x = 0;
			addch('\n');
		}
	}
	addch('\n');
	return (y);
}

/*
** Starts the visualizer, sets the color pairs that will be used later.
*/

int		start_visualizer(void)
{
	initscr(); //what does this return, if ncurses lib is not installed??
	noecho();
	curs_set(0);
	if (has_colors())
	{
		if (start_color() == OK)
		{
			init_pair(1, COLOR_BLACK, COLOR_YELLOW);//these 4 will be carriage colors (colorful background)
			init_pair(2, COLOR_BLACK, COLOR_CYAN);
			init_pair(3, COLOR_BLACK, COLOR_MAGENTA);
			init_pair(4, COLOR_BLACK, COLOR_GREEN);
			init_pair(11, COLOR_YELLOW, COLOR_BLACK);// these will be basic colors
			init_pair(12, COLOR_CYAN, COLOR_BLACK);
			init_pair(13, COLOR_MAGENTA, COLOR_BLACK);
			init_pair(14, COLOR_GREEN, COLOR_BLACK);
			init_pair(20, COLOR_WHITE, COLOR_BLACK); //the 00 hex
		}
		else
			vm_error("Cannot start colors, visualizer won't work in this terminal");
	}
	else
		vm_error("Cannot start colors, visualizer won't work in this terminal");
	return (0);
}

void	ncurses_print_game_info(t_game *game, int y)
{
	int	x;
	int	i;

	attron(A_BOLD);
	mvprintw(y += 2, x = 5, "Cycle: %d", game->cycles);
	mvprintw(y += 2, x, "Cycles to die: %d", game->cycles_to_die);
	mvprintw(y += 2, x, "Number of cycles before check: %d",
		game->cycles_to_die - game->cycles % game->cycles_to_die);
	mvprintw(y += 2, x, "Max checks: %d", MAX_CHECKS);
	mvprintw(y += 2, x, "Checks in current period: %d", game->checks);
	mvprintw(y += 2, x, "Lives performed in current period: %d", game->lives_num);
	mvprintw(y += 2, x, "Players:");
	attroff(A_BOLD);
	i = 0;
	while (++i <= game->players->pl_num)
	{
		move(++y, x);
		attrset(COLOR_PAIR(i + 10));
		if (game->players->last_life[i] &&
			game->players->last_life[i] > (game->cycles - game->cycles_to_die))
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

/*
** Performs the visualization. Erases the previous screen, prints the
** current state of the arena and game related information and
** refreshes the screen.
*/

void	perform_visualization(t_game *game)
{
	int y;

	napms(1000);
	erase();
	y = ncurses_print_arena(game->arena);
	ncurses_print_game_info(game, y);
	refresh();
}

void	ncurses_declare_winner(int winner_number, char *winner_name)
{
	int	max_x;
	int	max_y;
	int	x;
	int	y;

	erase();
	getmaxyx(stdscr, max_y, max_x);
	x = max_x / 2 - 5;
	y = max_y / 2 - 1;
	move(y, x);
	attron(A_BOLD);
	printw("BATTLE OVER!");
	if (winner_number > 0)
	{
		attrset(COLOR_PAIR(winner_number + 10));
		move(y += 2, x -= 5);
		printw("Player %d (%s) won\n", winner_number, winner_name);
		attroff(COLOR_PAIR(winner_number + 10));
	}
	else
		mvprintw(y += 3, x -= 1, "EVERYONE LOSES!");
	attroff(A_BOLD);
	refresh();
	getch();
	endwin();
}
