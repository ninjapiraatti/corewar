# include "vm.h"

/*
** Kills certain carriages from list and updates cycles_to_die when needed.
*/

void     run_check(t_game *game)
{
    if (game->cycles_to_die <= 0)
        game->head = kill_all_carriages(game->head);
    else
        game->head = kill_carriages(game->head, game);
    if (game->lives_num >= NBR_LIVE || game->checks == MAX_CHECKS)
    {
        game->cycles_to_die -= CYCLE_DELTA;
        game->checks = 0;
    }
    else
        game->checks++;
    game->lives_num = 0;
}

void    set_new_pc_and_color(t_arena *arena, t_carriage *carr)
{
    if (carr->next_state != JUMPED)
    {
        arena[carr->pc].color_carr = 0;
        carr->pc = (carr->pc + carr->next_state) % MEM_SIZE; // 4. move carriage
        arena[carr->pc].color_carr = carr->color_id;
    }
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
    // if (carr->cycles_to_wait == -1)
	//     carr->cycles_to_wait = 0; // move this to initialising carr
    if (carr->cycles_to_wait == 0 && inst > 0 && inst < 17) // 1. set statement code
        carr->cycles_to_wait = op_table[inst - 1].cycles_to_wait;
    if (carr->cycles_to_wait > 0) // 2. reduce number of cycles before execution
        carr->cycles_to_wait--;
    if (carr->cycles_to_wait == 0)
    {
        if (inst > 0 && inst < 17)
        {
            if (check_instruction(inst, arg_code, carr, arena)) // 3. perform statement
                perform_statement(carr, game, inst);
        }
        else
            carr->next_state = 1;
        set_new_pc_and_color(game->arena, carr);
    }
}

void    prepare_game_variables(t_game *game)
{
    game->checks = 0;
    game->game_state = 1;
    game->lives_num = 0;
    game->cycles_to_die = CYCLE_TO_DIE;
    game->cycles = 0;
    game->id_last_live = 0;
}

void    vm_loop(t_game *game)
{
    t_carriage *cur;

    prepare_game_variables(game);
    while (game->game_state == 1)// will be a variable in game
    {
		cur = game->head;
        game->cycles++;
		while (cur)
        {
            run_carriage(game, cur);
            cur = cur->next;
        }
        if (game->flags->viz == 1)
                perform_visualization(game);
        if (game->flags->dump != INIT_FLAG && game->flags->dump == game->cycles)
            dump_memory(game->arena);
        if (game->cycles % game->cycles_to_die == 0 || game->cycles_to_die <= 0)
            run_check(game);
        if (!game->head)
		    game->game_state = 0;
    }
}