#include "vm.h"

/*
** Adds color to the arena-byte's 'color'-string according
** to the player's index number.
*/

void    add_color(char *color, int player_number)
{
    enum e_color colors;

    colors = player_number;
    if (colors == yellow)
        ft_strcpy(color, YELLOW);
    else if (colors == cyan)
        ft_strcpy(color, CYAN);
    else if (colors == magenta)
        ft_strcpy(color, MAGENTA);
    else
        ft_strcpy(color, GREEN);
}

/*
** Divides the memory of the arena by the number of players
** and places the executable code of each player in the
** appropriate arena.ar bytes.
*/

void    place_players_in_mem(t_game *game, t_pl *pl)
{
    int per_pl;
    int i;
    int j;
    unsigned int k;

    per_pl = MEM_SIZE / pl->pl_num;
    i = 0;
    while (i < pl->pl_num)
    {
        j = i * per_pl;
        k = -1;
        while (++k < pl->h_info[i + 1]->prog_size)
        {
            game->arena[j].ar = pl->exec[i + 1][k];
            add_color(game->arena[j].color, i);
            j++;
        }
        i++;
        while (j < i * per_pl)
        {
            game->arena[j].ar = 0;
            ft_bzero(game->arena[j].color, 11);
            j++;
        }
    }
}