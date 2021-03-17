#include "vm.h"

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
	initscr();
	noecho();
	curs_set(0);
	if (has_colors())
	{
		if (start_color() == OK)
		{
			init_pair(1, COLOR_BLACK, COLOR_YELLOW);
			init_pair(2, COLOR_BLACK, COLOR_CYAN);
			init_pair(3, COLOR_BLACK, COLOR_MAGENTA);
			init_pair(4, COLOR_BLACK, COLOR_GREEN);
			init_pair(11, COLOR_YELLOW, COLOR_BLACK);
			init_pair(12, COLOR_CYAN, COLOR_BLACK);
			init_pair(13, COLOR_MAGENTA, COLOR_BLACK);
			init_pair(14, COLOR_GREEN, COLOR_BLACK);
			init_pair(20, COLOR_WHITE, COLOR_BLACK);
		}
		else
			vm_error("Cannot start colors, \
			visualizer won't work in this terminal");
	}
	else
		vm_error("Cannot start colors, visualizer won't work in this terminal");
	return (0);
}

/*
** Performs the visualization. Erases the previous screen, prints the
** current state of the arena and game related information and
** refreshes the screen.
*/

void	perform_visualization(t_game *game)
{
	int y;

	napms(1);
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
	attrset(COLOR_PAIR(winner_number + 10));
	move(y += 2, x -= 5);
	printw("Player %d (%s) won\n", winner_number, winner_name);
	attroff(COLOR_PAIR(winner_number + 10));
	attroff(A_BOLD);
	refresh();
	getch();
	endwin();
}
