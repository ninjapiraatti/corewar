#include "../includes/asm.h"

void    write_reg(char *arg, int fd)
{
    unsigned char   reg;

    reg = ft_atoi(arg + 1);
    write(fd, &reg, 1);
}

void    write_dir(char *arg, int index, int fd)
{
    int     dir;

    dir = ft_atoi(arg + 1);
    if (op_table[index].t_dir_size == 4)
    {
        write(fd, &((unsigned char*)&dir)[3], 1);
        write(fd, &((unsigned char*)&dir)[2], 1);
    }
    write(fd, &((unsigned char*)&dir)[1], 1);
    write(fd, &((unsigned char*)&dir)[0], 1);
}

void    write_ind(char *arg, int fd)
{
    int     ind;

    ind = ft_atoi(arg);
    write(fd, &((unsigned char*)&ind)[1], 1);
    write(fd, &((unsigned char*)&ind)[0], 1);
}

void    write_arguments(t_statement *statement, int fd)
{
    int     type;
    int     i;

    i = 0;
    while (statement->args[i])
    {
        type = get_arg_type(statement->args[i]);
        if (type == REG_CODE)
            write_reg(statement->args[i], fd);
        else if (type == DIR_CODE)
            write_dir(statement->args[i], statement->code, fd);
        else if (type == IND_CODE)
            write_ind(statement->args[i], fd);
        i++;
    }
}
