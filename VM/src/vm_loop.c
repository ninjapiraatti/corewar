# include "vm.h"

// init wait time to -1

void    manage_add(t_carriage *carr, t_arena *arena)
{
    int     arg1;
    int     arg2;
    int     arg3;

    arg1 = carr->regs[arena[carr->pc + 2].ar - 1];
    arg2 = carr->regs[arena[carr->pc + 3].ar - 1];
    arg3 = arg1 + arg2;
    if (arg3 == 0)
        carr->carry = true;
    else
        carr->carry = false;
    carr->regs[arena[carr->pc + 4].ar - 1] = arg3;
}

int     check_arg_type_code(char inst, char arg_code)
{
    //char digist[] = "0123456789abcdef";

    //converts arg_type_code
    //checks if arguments match to statement
    ft_printf("%d , %d\n", arg_code, inst);
    return (0);
}

void    run_carriage(t_arena *arena, t_carriage *carr)
{
    char    inst;
    char    arg_code;

    inst = arena[carr->pc].ar;
    arg_code = arena[carr->pc + 1].ar;
    ft_printf("pc: %d\n", carr->pc + 1);
    carr->regs[7] = 5;
    carr->regs[12] = 30;
    manage_add(carr, arena);
    /*if (carr->cycles_to_wait == -1 || carr->cycles_to_wait == 0)
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
    }*/
    


}



void    vm_loop(t_game *game, t_pl *players)
{
    t_carriage *cur;

    game->game_state = 1;
    //while (game->game_state == 1)// will be a variable in game
    //{
        cur = game->head;
        //while (cur)
        //{
            (void)players;
            run_carriage(game->arena, cur);
            cur = cur->next;
            //go throug each carriage
             /* carriages read info, save next_state; */
             // wait ajat
        //}
        
       
        
        // kattoo, et onko cycles_to_die aika
    //if cycles_to_die
        //    check
            //update carriage number
    //}
    
}