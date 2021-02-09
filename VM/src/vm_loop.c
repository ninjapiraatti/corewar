# include "vm.h"

// init wait time to -1

int     check_arg_type_code(char inst, char arg_code)
{
    
}

void    run_carriage(t_arena *arena, t_carriage *carr)
{
    char    inst;
    char    arg_code;

    inst = arena[carr->pc].ar;
    arg_code = arena[carr->pc + 1].ar;
    if (carr->cycles_to_wait == -1 || carr->cycles_to_wait == 0)
    {
        if (inst > 0 && inst < 17 && check_arg_type_code(inst, arg_code))
        {
            // do statement;
        }
        else
        {
            carr->cycles_to_wait = 0;
            carr->pc++;
            if (carr->pc == MEM_SIZE)
                carr->pc = 0;
        }
    }
    else
    {
        carr->cycles_to_wait--;
    }
    


}



void    vm_loop(t_game *game, t_pl *players)
{
    t_carriage *cur;

    game->game_state = 1;
    while (game->game_state == 1)// will be a variable in game
    {
        cur = game->head;
        while (cur)
        {
            go_through(cur);
            cur = cur->next;
            //go throug each carriage
             /* carriages read info, save next_state; */
             // wait ajat
        }
        
       
        
        // kattoo, et onko cycles_to_die aika
    //if cycles_to_die
        //    check
            //update carriage number
    }
    
}