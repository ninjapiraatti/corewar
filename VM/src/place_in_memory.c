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
** Puts the player's executable code into the arena (into the 'ar'-byte of the
** struct) and sends the corresponding 'color'-string and the player's index
** number to add_color(). Returns the amount of bytes written.
*/

int     player_to_arena(t_arena *start, unsigned char *code, int len, int index)
{
    int k;

    k = 0;
    while (k < len)
    {
        start[k].ar = code[k];
        add_color(start[k].color, index);
        k++;
    }
    return (k);
}

/*
** Divides the memory of the arena by the number of players
** and sends sends each player's executable code and the appropriate
** 'arena' -area to 'player_to_arena()'. Sets the empty memory
** in between players to 0 (the 'ar'-byte) and sets each corresponding
** 'color' -string to zero also.
*/

void    place_players_in_mem(t_game *game, t_pl *pl)
{
    int     per_pl;
    int     i;
    int     k;
    t_arena *arena;
    t_carriage  *head;
    t_carriage  *new;

    head = NULL;
    arena = game->arena;
    per_pl = MEM_SIZE / pl->pl_num;
    i = 0;
    while (i < pl->pl_num)
    {
        k = i * per_pl;
        new = create_carriage(i, (i + 1), k);
        ft_add_carriage(&head, new);
        k += player_to_arena(&arena[k], pl->exec[i + 1], pl->h_info[i + 1]->prog_size, i);
        i++;
        while (k < i * per_pl)
        {
            game->arena[k].ar = 0;
            ft_bzero(game->arena[k].color, 11);
            k++;
        }
    }
    game->head = head;
    game->car_num = i;
    game->players = pl;
}