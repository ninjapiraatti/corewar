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

int     check_args(char arg, int i, int inst)
{
    int     j;
    int     count;

    j = -1;
    count = 0;
    while (++j < 3)
        if (op_table[inst].arguments[i][j] == 0)
            count++;
    if (count < 3 && arg == 0)
        return (0);
    j = 0;
    while (j < 3)
    {
        if (op_table[inst].arguments[i][j] == arg)
            return (1);
        j++;
    }
    ft_printf("returned 0\n");
    return (0);
}

int     check_arg_type_code(int inst, unsigned char arg_code, t_carriage *carr)
{
    char arg_type1;
    char arg_type2;
    char arg_type3;
    int     i;

    i = 0;
    arg_type1 = arg_code >> 6;
    arg_type2 = (arg_code >> 4) & 3;
    arg_type3 = (arg_code >> 2) & 3;

    carr->args[0] = arg_type1;
    carr->args[1] = arg_type2;
    carr->args[2] = arg_type3;
    while(i < 3)
    {
        if (!check_args(carr->args[i], i, inst - 1))
            return (0);
        i++;
    }
    ft_printf("arg type code valid!\n");
    return (1);
}

void    update_pc(t_carriage *carr, int error)
{
    if (error)
        carr->pc++;
    else
        carr->pc = carr->pc + carr->next_state;
    if (carr->pc >= MEM_SIZE)
        carr->pc = carr->pc % MEM_SIZE;
}

int     check_instruction(int inst, unsigned char arg_code, t_carriage *carr)
{
    if (op_table[inst - 1].arg_type_code == 1)
        return (check_arg_type_code(inst, arg_code, carr));
    return (1);
}

void    run_carriage(t_arena *arena, t_carriage *carr)
{
    char    inst;
    char    arg_code;
    int     error;

    inst = arena[carr->pc].ar;
    arg_code = arena[carr->pc + 1].ar;
    check_arg_type_code(inst, arg_code, carr);
    carr->regs[2] = 154;
    error = manage_sti(carr, arena); //this will be something like perform statement
    update_pc(carr, error);
    print_hex(arena);
    exit(0);
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