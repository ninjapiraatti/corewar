#include "../includes/asm.h"

char    *get_file_name(char *file_name)
{
    char    *new_name;

    if (ft_strchr(file_name, '/'))
        new_name = ft_strrchr(file_name, '/') + 1;
    else
        new_name = file_name;
    *ft_strrchr(new_name, '.') = '\0';
	return (ft_strjoin(new_name, ".cor"));
}

void    write_instructions(t_statement *statement, int fd)
{
    unsigned char   buffer;

    while (statement)
    {
        buffer = statement->code + 1;
        write(fd, &buffer, 1);
        if (op_table[statement->code].arg_type_code)
            write(fd, &statement->arg_type_code, 1);
        write_arguments(statement, fd);
        statement = statement->next;
    }
}

void    write_hexa(t_asm *assm, char *file_name)
{
    int     fd;
    char    *output_file;

    ft_printf("file: %s\n", file_name);
    output_file = get_file_name(file_name);
    ft_printf("new file: %s\n", output_file);
    fd = open(output_file, O_WRONLY | O_CREAT, 0666);
    //write_header(fd);
    //write_champion_name(assm, fd);
    //write_champ_exec_code_size(assm, fd);
    //write_champion_comment(assm, fd);
    write_instructions(assm->statements, fd);
}