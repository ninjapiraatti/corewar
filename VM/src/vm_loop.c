# include "vm.h"

/*
** Orded of actions inside the cycle
** 1. set statement code
** 2. reduce the number of cycles before execution
** 3. perform statement if cycles_to_wait is 0 and everything is valid
** 4. move carriage to the next position if cycles_to_wait is 0.
*/

void    run_carriage(t_arena *arena, t_carriage *carr)
{
    char    inst;
    char    arg_code;

    inst = arena[carr->pc].ar;
    arg_code = arena[carr->pc + 1].ar;
	carr->cycles_to_wait = 0; // move this to initialising carr
    if (carr->cycles_to_wait == 0 && inst > 0 && inst < 17) // 1. set statement code
        carr->cycles_to_wait = 1; // op_table[inst - 1].cycles_to_wait;
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
					ft_printf("ready to perform statement!\n");
                	// perform_statement(inst, arena, carr);
				}
			}
        }
        else
            carr->next_state = 1;
        carr->pc += carr->next_state; // 4. move carriage
        if (carr->pc >= MEM_SIZE)
            carr->pc = carr->pc % MEM_SIZE;
    }
}

void    vm_loop(t_game *game, t_pl *players)
{
    t_carriage *cur;
	int			dumbasstempiterator;

	dumbasstempiterator = 0;
    game->game_state = 1;
    while (game->game_state == 1)// will be a variable in game
    {
		cur = game->head;
		//while (cur)
		while (dumbasstempiterator < 30)
        {
            (void)players;
            run_carriage(game->arena, cur);
            //cur = cur->next;
            //go throug each carriage
             /* carriages read info, save next_state; */
             // wait ajat
			 dumbasstempiterator++;
        }
		game->game_state = 0;
        
       
        
        // kattoo, et onko cycles_to_die aika
    //if cycles_to_die
        //    check
            //update carriage number
    }
}