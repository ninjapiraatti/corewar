#include "vm.h"

/*
** Function creates a new carriage and copies the necessary
** variables and initializes the registries to the same
** as those in the original carriage and sets the new pc to
** the address calculated from the statement argument.
*/

void	manage_fork(t_game *game, t_carriage *carr)
{
	int			arg;
	int			address;
	t_carriage	*new;

	arg = read_bytes(game->arena, carr->pc + 1, 2);
	address = (unsigned int)(carr->pc + (arg % IDX_MOD)) % MEM_SIZE;
	new = create_carriage(carr->color_id, address);
	new->carry = carr->carry;
	new->last_live = carr->last_live;
	initialize_registries(new->regs, carr->color_id, carr->regs);
	new->next_state = 0;
	ft_add_carriage(&(game->head), new);
	game->arena[new->pc].color_carr = new->color_id;
}

/*
** Does the same as manage_fork() except the address calculated from
** the argument isn't truncated by IDX_MOD.
*/

void	manage_lfork(t_game *game, t_carriage *carr)
{
	int			arg;
	int			address;
	t_carriage	*new;

	arg = read_bytes(game->arena, carr->pc + 1, 2);
	address = (unsigned int)(carr->pc + arg) % MEM_SIZE;
	new = create_carriage(carr->color_id, address);
	new->carry = carr->carry;
	new->last_live = carr->last_live;
	initialize_registries(new->regs, carr->color_id, carr->regs);
	new->next_state = 0;
	ft_add_carriage(&(game->head), new);
	game->arena[new->pc].color_carr = new->color_id;
	if (carr->carr_id == 1268)
		ft_printf("made new carr!");
}
