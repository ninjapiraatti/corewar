#include "vm.h"

/*
** Reads the first 4 bytes from the file, reverses the bytes, and
** turns the bytes into an integer. If the int matches the magic
** number in the op.h file, it returns the number.
*/

unsigned int    check_magic_number(int fd)
{
    char            bytes[4];
    int             ret;
    unsigned int    magic_num;

    if ((ret = read(fd, bytes, 4)) == -1)
    {
        close(fd);
        vm_error(strerror(errno));
    }
    else if (ret < 4)
    {
        close(fd);
        vm_error("Error! Invalid file type");
    }
    ft_revbytes(bytes, 4);
    magic_num = *(int*)bytes;
    if (magic_num != COREWAR_EXEC_MAGIC)
    {
        close(fd);
        vm_error("Error! Invalid file type");
    }
    return (magic_num);
}

/*
** Reads the PROG_NAME_LENGTH amount of bytes from file into prog_name
** array and checks that the following 4 bytes are empty.
*/

void            read_champ_name(int fd, char *prog_name)
{
    char    empty[4];
    int     ret;

    if ((ret = read(fd, prog_name, PROG_NAME_LENGTH)) == -1)
    {
        close(fd);
        vm_error(strerror(errno));
    }
    else if (ret < PROG_NAME_LENGTH)
    {
        close(fd);
        vm_error("Error! File does not meet requirements");
    }
    prog_name[PROG_NAME_LENGTH] = '\0';
    if (((ret = read(fd, empty, 4)) == -1) || ret < 4)
    {
        close(fd);
        vm_error(strerror(errno));
    }
    if (!ft_str_is_empty(empty, 4))
        vm_error("Error! File does not meet requirements");
}

/*
** Reads the next 4 bytes from the file and after reversing the bytes,
** turns them into an int. Checks that the stated executable size isn't
** too big.
*/

unsigned int    check_champ_size(int fd)
{
    char    bytes[4];
    int     ret;
    unsigned int     champ_size;

    if (((ret = read(fd, bytes, 4)) == -1) || ret < 4)
    {
        close(fd);
        vm_error(strerror(errno));
    }
    ft_revbytes(bytes, 4);
    champ_size = *(int*)bytes;
    if ( champ_size > CHAMP_MAX_SIZE)
    {
        close(fd);
        vm_error("Error! Champion size too big");
    }
    return (champ_size);
}

/*
** Reads COMMENT_LENGTH amount of bytes and saves them into *comment.
** Checks that the following 4 bytes are empty.
*/

void            read_champ_comment(int fd, char *comment)
{
    char    empty[4];
    int     ret;

    if (((ret = read(fd, comment, COMMENT_LENGTH)) == -1) ||
        ret < COMMENT_LENGTH)
    {
        close(fd);
        vm_error(strerror(errno));
    }
    comment[COMMENT_LENGTH] = '\0';
    if ((ret = read(fd, empty, 4)) == -1)
    {
        close(fd);
        vm_error(strerror(errno));
    }
    if (ret < 4 || !ft_str_is_empty(empty, 4))
        vm_error("ERROR! Invalid file");
}

/*
** Reads the remaining bytes from file and check that the amount matches
** the prog_size indicated earlier. Copies the read executable code bytes
** from buf to *executable and returns it.
*/

char            *read_champ_executable(int fd, unsigned int prog_size)
{
    char            *executable;
    char            buf[CHAMP_MAX_SIZE + 1];
    int             ret;
    unsigned int     count;

    count = 0;
    while ((ret = read(fd, buf, 1)))
    {
        count++;
        if (ret == -1 || count > CHAMP_MAX_SIZE)
        {
            close(fd);
            vm_error("Error! Problem reading champ executable code");
        }
    }
    buf[count] = '\0';
    if (count != prog_size)
    {
        close(fd);
        vm_error("Error! Stated program size does not match executable code");
    }
    if (!(executable = (char*)malloc(sizeof(char) * (prog_size + 1))))
        vm_error(strerror(errno));
    ft_strcpy(executable, buf);
    return (executable);
}