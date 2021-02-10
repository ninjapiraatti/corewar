#include "vm.h"

/*
** Sets registries for the new carriage. If carriage will be a copy,
** copy registries from *copy_regs, otherwise set them to 0.
** Place players 'id' in the first registry with a '-' sign.
*/

void        initialize_registries(int *new_regs, int id, int *copy_regs)
{
    int i;

    i = 0;
    while (i < REG_NUMBER)
    {
        if (i == 0)
            new_regs[i] = (id * -1);
        else if (!copy_regs)
            new_regs[i] = 0;
        else
            new_regs[i] = copy_regs[i];
        i++;
    }
}

/*
** Adds new carriage to the beginning of the list.
*/

void	ft_add_carriage(t_carriage **alst, t_carriage *new)
{
	if (new)
	{
		if (!*alst)
			*alst = new;
		else
		{
			new->next = *alst;
			*alst = new;
		}
	}
}

t_carriage  *create_carriage(int car_id, int player_id, int position)
{
    t_carriage  *new;

    if (!(new = (t_carriage*)malloc(sizeof(t_carriage))))
            vm_error(strerror(errno));
    initialize_registries(new->regs, player_id, NULL);
    new->carry = false;
    new->color_id = player_id - 1;
    new->id = car_id;
    new->next = NULL;
    new->pc = position;
    new->cycles_to_wait = -1;
    new->args[0] = 0;
    new->args[1] = 0;
    new->args[2] = 0;
    return (new);
}

/*
** Create initial carriages for each player.
*/

// void    create_first_carriages(t_game *game, t_pl *players)
// {
//     int         i;
//     int         car_num;
//     t_carriage  *head;
//     t_carriage  *new;

//     i = 1;
//     car_num = 0;
//     head = NULL;
//     while (i <= players->pl_num)
//     {
//         new = create_carriage(car_num, i);
//         ft_add_carriage(&head, new);
//         car_num++;
//         i++;
//     }
//     game->car_num = car_num;
// }