#include "vm.h"

/*
** Adds new carriage to the beginning of the list and updates the
** new carriages carr_id.
*/

void				ft_add_carriage(t_carriage **alst, t_carriage *new)
{
	if (new)
	{
		if (!*alst)
			*alst = new;
		else
		{
			new->carr_id = (*alst)->carr_id + 1;
			new->next = *alst;
			*alst = new;
		}
	}
}

t_carriage			*create_carriage(int player_id, int position)
{
	t_carriage	*new;

	if (!(new = (t_carriage*)malloc(sizeof(t_carriage))))
		vm_error(strerror(errno));
	new->carry = 0;
	new->color_id = player_id;
	new->next = NULL;
	new->pc = position;
	new->cycles_to_wait = 0;
	new->last_live = 0;
	new->args[0] = 0;
	new->args[1] = 0;
	new->args[2] = 0;
	new->carr_id = 1;
	new->inst = -1;
	return (new);
}

/*
** This function kills all carriages in the event that ctd
** is <= 0.
*/

t_carriage			*kill_all_carriages(t_carriage *head, t_game *game)
{
	t_carriage	*cur;

	while (head)
	{
		cur = head->next;
		if (game->flags->kill)
			ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
				head->carr_id, game->cycles - head->last_live, game->ctd);
		free(head);
		head = cur;
	}
	return (head);
}

/*
** kills carriages from beginning of list
*/

static t_carriage	*kill_first_carrs(t_carriage *head, t_game *game)
{
	t_carriage	*tmp;
	int			limit;

	limit = game->cycles - game->ctd;
	while (head && head->last_live <= limit)
	{
		tmp = head->next;
		game->arena[head->pc].color_carr = 0;
		if (game->flags->kill)
			ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
				head->carr_id, game->cycles - head->last_live, game->ctd);
		free(head);
		head = tmp;
	}
	return (head);
}

/*
** Function removes carriages from the list that have not performed a live
** statement in the required period. Returns the updated head of the list.
*/

t_carriage			*kill_carriages(t_carriage *head, t_game *game)
{
	t_carriage	*cur;
	t_carriage	*tmp;

	head = kill_first_carrs(head, game);
	cur = head;
	if (cur)
	{
		while (cur->next)
		{
			tmp = cur->next;
			if (tmp->last_live <= (game->cycles - game->ctd))
			{
				if (game->flags->kill)
					ft_printf("Process %d hasn't lived for %d cycles \
						(CTD %d)\n", tmp->carr_id, game->cycles -
							tmp->last_live, game->ctd);
				game->arena[tmp->pc].color_carr = 0;
				cur->next = tmp->next ? tmp->next : NULL;
				free(tmp);
			}
			else
				cur = cur->next;
		}
	}
	return (head);
}
