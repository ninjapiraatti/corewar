#include "vm.h"

/*
** Kills certain carriages from list and updates ctd when needed.
*/

void	run_check(t_game *game)
{
	if (game->ctd <= 0)
		game->head = kill_all_carriages(game->head, game);
	else
		game->head = kill_carriages(game->head, game);
	if (game->lives_num >= NBR_LIVE || game->checks == MAX_CHECKS)
	{
		game->ctd -= CYCLE_DELTA;
		game->checks = 0;
		if (game->flags->show_cycles)
			ft_printf("Cycle to die is now %d\n", game->ctd);
	}
	else
	{
		game->checks++;
		if (game->lives_num >= NBR_LIVE || game->checks == MAX_CHECKS)
		{
			game->ctd -= CYCLE_DELTA;
			game->checks = 0;
			if (game->flags->show_cycles)
				ft_printf("Cycle to die is now %d\n", game->ctd);
		}
	}
	game->lives_num = 0;
}

void	set_new_pc_and_color(t_game *game, t_carriage *carr)
{
	int	i;

	i = 0;
	if (carr->next_state != JUMPED)
	{
		if (game->flags->pc_move && carr->next_state != 1)
		{
			ft_printf("ADV %d (0x%04x -> 0x%04x) ",
				carr->next_state, carr->pc, carr->pc + carr->next_state);
			while (i < carr->next_state)
			{
				ft_printf("%02x ", game->arena[carr->pc + i].ar);
				i++;
			}
			ft_printf("\n");
		}
		game->arena[carr->pc].color_carr = 0;
		carr->pc = (unsigned int)(carr->pc + carr->next_state) % MEM_SIZE;
		game->arena[carr->pc].color_carr = carr->color_id;
	}
}

/*
** Orded of actions inside the cycle
** 1. set statement code
** 2. reduce the number of cycles before execution
** 3. perform statement if cycles_to_wait is 0 and everything is valid
** 4. move carriage to the next position if cycles_to_wait is 0.
*/

void	run_carriage(t_game *game, t_carriage *carr)
{
	char	arg_code;
	t_arena	*arena;

	arena = game->arena;
	arg_code = arena[(unsigned int)(carr->pc + 1) % MEM_SIZE].ar;
	if (carr->cycles_to_wait == 0)
	{
		carr->inst = arena[carr->pc].ar;
		if (carr->inst > 0 && carr->inst < 17)
			carr->cycles_to_wait = op_table[carr->inst - 1].cycles_to_wait;
	}
	if (carr->cycles_to_wait > 0)
		carr->cycles_to_wait--;
	if (carr->cycles_to_wait == 0)
	{
		if (carr->inst > 0 && carr->inst < 17)
		{
			if (check_inst(carr->inst, arg_code, carr, arena))
			{
				if (game->flags->moves)
					ft_printf("P %4d | %s", carr->carr_id, op_table[carr->inst - 1].op_name);
				perform_statement(carr, game, carr->inst);
			}
		}
		else
			carr->next_state = 1;
		set_new_pc_and_color(game, carr);
	}
}

void	prepare_game_variables(t_game *game)
{
	game->checks = 0;
	game->game_state = 1;
	game->lives_num = 0;
	game->ctd = CYCLE_TO_DIE;
	game->cycles = 0;
	game->id_last_live = 0;
	game->lives_num = 0;
	game->time_to_check = CYCLE_TO_DIE;
}

void	vm_loop(t_game *game)
{
	t_carriage *cur;

	prepare_game_variables(game);
	while (game->game_state == 1)
	{
		cur = game->head;
		game->cycles++;
		if (game->flags->show_cycles)
			ft_printf("It is now cycle %d\n", game->cycles);
		game->time_to_check--;
		while (cur)
		{
			run_carriage(game, cur);
			cur = cur->next;
		}
		if (game->flags->viz)
			perform_visualization(game);
		if (game->time_to_check == 0 || game->ctd <= 0)
		{
			run_check(game);
			game->time_to_check = game->ctd;
		}
		if (!game->head)
			break ;
		if (game->flags->dump != INIT_FLAG && game->flags->dump == game->cycles)
			dump_memory(game->arena);
	}
}
