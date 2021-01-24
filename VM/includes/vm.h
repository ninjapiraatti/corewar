#ifndef VM_H
# define VM_H
# include "op.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "colors.h"

# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>

# define INIT_FLAGS -10000
# define SIZE_MAGIC_NUM 4
/*
** Struct for all information concerning players and
** command-line arguments.
** 'pl_order' will list the champion files in their
** indicated order (Player 1 is in pl_order[1]).
*/

typedef struct  s_pl
{
    int         ac;
    char        **av;
    char        *pl_order[MAX_PLAYERS + 1];
    int         pl_num;
    header_t    **h_info;
    char        **exec;
}               t_pl;

/*
** Struct for option flag information. 'n' is an array,
** because '-n' can be among the command-line arguments
** several times.
*/

typedef struct  s_flag
{
    int n[MAX_PLAYERS + 1];
    int dump;
}               t_flag;

int             parse_champ_files(t_pl *players);

/*
** vm_error.c
*/

int             vm_error(char *str);

/*
** vm_tools.c
*/

void            init_structs(t_pl *players, t_flag *flags, int ac, char **av);
header_t        **prepare_header_info_array(int pl_num);
void            ft_revbytes(char *bytes, size_t size);
int             ft_str_is_empty(char *str, int size);

/*
** parse_flags_player_order.c
*/

void            parse_flags_player_order(t_pl *players, t_flag *flags);

/*
** read_from_champ_files.c
*/

unsigned int    check_magic_number(int fd);
void            read_champ_name(int fd, char *prog_name);
unsigned int    check_champ_size(int fd);
void            read_champ_comment(int fd, char *comment);
char            *read_champ_executable(int fd, unsigned int prog_size);

# endif