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

void     check_arg(int inst, int arg, int i)
{
    int     j;

    j = 0;
    while (j < 3)
    {
        if (op_table[inst].arguments[i][j] == arg)
            return ;
        j++;
    }
    vm_error("wrong arg type");
}

int     validate_binary(char *binary, int inst)
{
    int     i;
    char    *sub;
    int     check;

    ft_printf("%s, %s\n", op_table[inst].op_name, binary);
    i = 0;
    check = 0;
    while (i < 8)
    {
        sub = ft_strsub(binary, i, 2);
        if (ft_strequ(sub, "01"))
            check_arg(inst, T_REG, i / 2);
        else if (ft_strequ(sub, "11"))
            check_arg(inst, T_IND, i / 2);
        else if (ft_strequ(sub, "10"))
            check_arg(inst, T_DIR, i / 2);
        else if (ft_strequ(sub, "00") && i == 6)
            check = 1;
        else
            vm_error("wrong arg type");
        ft_printf("sub: %s\n", sub);
        i += 2;
    }
    if (check == 1)
        return (1);
    return (0);
}

int     check_arg_type_code(int inst, char arg_code, int i, int j)
{
    char    *str_arg;
    char    binary[16][5] = {"0000", "0001", "0010", "0011", "0100", "0101","0110", "0111", "1000",
    "1001", "1010", "1011", "1100", "1101", "1110","1111"};
    char    digits [] = "0123456789abcdef";
    char    binary_str[9];

    (void)inst;
    str_arg = itoa_base(arg_code, 16);
    i = -1;
    ft_bzero(binary_str, 9);
    while (str_arg[++i])
    {
        j = -1;
        while (digits[++j])
            if (digits[j] == str_arg[i])
                break ;
        ft_strcat(binary_str, binary[j]);
    }
    ft_printf("binary: %s\n", binary_str);
    return (validate_binary(binary_str, inst - 1));
}

void    run_carriage(t_arena *arena, t_carriage *carr)
{
    char    inst;
    char    arg_code;

    inst = arena[carr->pc].ar;
    arg_code = arena[carr->pc + 1].ar;
    carr->regs[7] = 5;
    carr->regs[12] = 30;
    //manage_add(carr, arena);
    if (carr->cycles_to_wait == -1 || carr->cycles_to_wait == 0)
    {
        if (inst > 0 && inst < 17 && check_arg_type_code(inst, arg_code, -1, -1))
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
    //while (game->game_state == 1)// will be a variable in game
    //{
        cur = game->head;
        while (cur)
        {
            (void)players;
            run_carriage(game->arena, cur);
            cur = cur->next;
            //go throug each carriage
             /* carriages read info, save next_state; */
             // wait ajat
        }
        
       
        
        // kattoo, et onko cycles_to_die aika
    //if cycles_to_die
        //    check
            //update carriage number
    //}
    
}