# include "vm.h"

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

t_carriage    *kill_carriages(t_carriage *head, int cycles, int to_die)
{
    t_carriage  *cur;
    t_carriage  *tmp;

    if (to_die <= 0)
        return(kill_all_carriages(head));
    while (head && head->last_live <= (cycles - to_die))
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }
    cur = head;
    while (cur && cur->next)
    {
        tmp = cur->next;
        if (tmp->last_live <= (cycles - to_die))
        {
            if (tmp->next)
                cur->next = tmp->next;
            free(tmp);
        }
        else
            cur = cur->next;
    }
    return (head);
}

/*
** Kills certain carriages from list and updates cycles_to_die when needed.
*/

void     run_check(t_game *game)
{
    game->head = kill_carriages(game->head, game->cycles, game->cycles_to_die);
    if (game->lives_num >= NBR_LIVE || game->checks == MAX_CHECKS)
    {
        game->cycles_to_die -= CYCLE_DELTA;
        game->checks = 0;
    }
    else
        game->checks++;
    game->lives_num = 0;
}


/*
** Orded of actions inside the cycle
** 1. set statement code
** 2. reduce the number of cycles before execution
** 3. perform statement if cycles_to_wait is 0 and everything is valid
** 4. move carriage to the next position if cycles_to_wait is 0.
*/

void    run_carriage(t_game *game, t_carriage *carr)
{
    char    inst;
    char    arg_code;
    t_arena *arena;

    arena = game->arena;
    inst = arena[carr->pc].ar;
    arg_code = arena[carr->pc + 1].ar;
	carr->cycles_to_wait = 0; // move this to initialising carr
    if (carr->cycles_to_wait == 0 && inst > 0 && inst < 17) // 1. set statement code
        carr->cycles_to_wait = op_table[inst - 1].cycles_to_wait;
    if (carr->cycles_to_wait > 0) // 2. reduce number of cycles before execution
        carr->cycles_to_wait--;
    if (carr->cycles_to_wait == 0)
    {
        if (inst > 0 && inst < 17)
        {
            if (check_instruction(inst, arg_code, carr)) // 3. perform statement
			{
				if (check_regs(inst, carr, arena)) // possibly move to check_arg_type_code but then need to add arena as parameter
				{
					// ft_printf("ready to perform statement!\n");
                	perform_statement(carr, game, inst);
                    // print_hex(arena);
				}
                perform_statement(carr, game, inst); //only for testing live
			}
        }
        else
            carr->next_state = 1;
        carr->pc += carr->next_state; // 4. move carriage
        if (carr->pc >= MEM_SIZE)
            carr->pc = carr->pc % MEM_SIZE;
    }
}

void    vm_loop(t_game *game)
{
    t_carriage *cur;

    game->checks = 0;
    game->game_state = 1;
    game->lives_num = 0;
    game->cycles_to_die = CYCLE_TO_DIE;
    game->cycles = 0;
    while (game->game_state == 1)// will be a variable in game
    {
		cur = game->head;
		while (cur)
        {
            game->cycles++;
            run_carriage(game, cur);
            cur = cur->next;
        }
        if (game->cycles % game->cycles_to_die == 0 || game->cycles_to_die <= 0)
        {
            run_check(game);
            ft_printf("performed check!\n");
        }
        if (game->head == NULL)
		    game->game_state = 0;
    }
}