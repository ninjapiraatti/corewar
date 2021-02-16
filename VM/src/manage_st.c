#include "vm.h"

/*
** Copies spedified memory area into buf(no trailing '\0')
*/

char     *copy_mem_area(t_arena *arena, int start, int size)
{
    int     i;
    char    *buf;

    if (!(buf = (char*)malloc(sizeof(char) * size)))
        vm_error(strerror(errno));
    i = 0;
    while (i < size)
    {
        buf[i] = arena[start + i].ar;
        i++;
    }
    return(buf);
}

/*
** After receiving buf, which is a copy of the specified memory area,
** the function turns the bytes around and casts it to an int.
*/

int      read_bytes_convert(t_arena *arena, int pos, int size)
{
    char    *buf;
    int     res;
    
    buf = copy_mem_area(arena, pos, size);
    ft_revbytes(buf, size);
    res =  *(int*)buf;
    return(res);
}

/*
** Writes 'arg' divided into memory arena one byte at a time (until 'size').
** Because the VM is big-endian, the most significant bytes are written first.
*/

void    write_to_memory(t_arena *arena, unsigned int pos, int arg, int size)
{
    int i;

    i = size - 1;
    while (i >= 0)
    {
        if (pos >= MEM_SIZE)
            pos = pos % MEM_SIZE;      
        arena[pos].ar = arg >> (8 * i) & 0xff;
        i--;
        pos++;
    }
}

int     check_ind_pc(int pc, int arg)
{
    int pos;

    pos = pc + (arg % IDX_MOD);
    if (pos >= MEM_SIZE)
        pos = pos % MEM_SIZE;
    return (pos);
}

/*
** manage_st() writes a value from the registry that was passed as the first argument
** to the second, which is either a registry or an address, which has to be defined
** with the help of IDX_MOD.
*/

int   manage_st(t_carriage *carr, t_arena *arena)
{
    int reg;
    int arg1;
    int arg2;

    if ((reg = arena[carr->pc + 2].ar) < 1 || reg > 16)
        return (1);
    arg1 = carr->regs[reg - 1];
    if (carr->args[1] == REG_CODE)
    {
        if ((reg = arena[carr->pc + 3].ar) < 1 || reg > 16)
            return (1);
        arg2 = carr->regs[reg - 1];
        arg2 = arg1;
    }
    else //arg2 is T_IND 2
    {
        arg2 = read_bytes_convert(arena, carr->pc + 3, IND_SIZE);
        arg2 = check_ind_pc(carr->pc, arg2);
        write_to_memory(arena, arg2, arg1, REG_SIZE);
    }
    carr->cycles_to_wait = 5;
    return (0);
}

/*
** manage_sti() writes the value of the registry of the first argument
** to the following address: current position +
** (<SECOND_ARGUMENT_VALUE> + <THIRD_ARGUMENT_VALUE>) % IDX_MOD.
** The variable k helps move the correct amount of bytes to the
** last argument.
*/

int    manage_sti(t_carriage *carr, t_arena *arena)
{
    int reg;
    int arg1;
    int arg2;
    int arg3;
    int k;

    if ((reg = arena[carr->pc + 2].ar) < 1 || reg > 16)
        return (1);
    arg1 = carr->regs[reg - 1];
    ft_printf("%d\n", arg1);
    if (carr->args[1] == REG_CODE)
    {
        if ((reg = arena[carr->pc + 3].ar) < 1 || reg > 16)
            return (1);
        arg2 = carr->regs[reg - 1];
    }
    else
    {
        arg2 = read_bytes_convert(arena, carr->pc + 3, 2);
        if (carr->args[1] == IND_CODE)
        {
            arg2 = check_ind_pc(carr->pc, arg2);
            arg2 = read_bytes_convert(arena, arg2, REG_SIZE);
        }
    }
    k = (carr->args[1] == REG_SIZE) ? 4 : 5;
    if (carr->args[2] == REG_CODE)
    {
        if ((reg = arena[carr->pc + k].ar) < 1 || reg > 16)
            return (1);
        arg3 = carr->regs[reg - 1];
    }
    else
        arg3 = read_bytes_convert(arena, carr->pc + k, 2); //read 2 or 4 bytes??
    write_to_memory(arena, carr->pc + (arg2 + arg3) % IDX_MOD, arg1, REG_SIZE);
    carr->cycles_to_wait = 25;
    return (0);
}
