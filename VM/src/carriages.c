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

t_carriage  *create_carriage(int player_id, int position)
{
    t_carriage  *new;

    if (!(new = (t_carriage*)malloc(sizeof(t_carriage))))
            vm_error(strerror(errno));
    new->carry = 0;
    new->color_id = player_id;
    new->next = NULL;
    new->pc = position;
    new->cycles_to_wait = 0; //might have to put back to -1
    new->args[0] = 0;
    new->args[1] = 0;
    new->args[2] = 0;
    return (new);
}


/*
** This function kills all carriages in the event that cycles_to_die
** is <= 0.
*/

t_carriage  *kill_all_carriages(t_carriage *head)
{
    t_carriage  *cur;

    while (head)
    {
        cur = head->next;
        free(head);
        head = cur;
    }
    return (head);
}

/*
** Function removes carriages from the list that have not performed a live
** statement in the required period. Returns the updated head of the list.
*/

t_carriage    *kill_carriages(t_carriage *head, t_game *game)
{
    t_carriage  *cur;
    t_carriage  *tmp;

    if (game->cycles_to_die <= 0)
        return(kill_all_carriages(head));
    while (head && head->last_live <= (game->cycles - game->cycles_to_die))
    {
        tmp = head->next;
        game->arena[head->pc].color_carr = 0;
        free(head);
        head = tmp;
    }
    cur = head;
    while (cur && cur->next)
    {
        tmp = cur->next;
        if (tmp->last_live <= (game->cycles - game->cycles_to_die))
        {
            if (tmp->next)
                cur->next = tmp->next;
            game->arena[tmp->pc].color_carr = 0;
            free(tmp);
        }
        else
            cur = cur->next;
    }
    return (head);
}