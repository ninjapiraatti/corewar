#ifndef VM_H
# define VM_H
# include "op.h"
# include "libft.h"
# define INIT_FLAGS -10000

/*
** Struct for all information concerning players and
** command-line arguments.
** 'pl_order' will list the champion files in their
** indicated order (Player 1 is in pl_order[1]).
*/

typedef struct  s_pl
{
    int     ac;
    char    **av;
    char    *pl_order[MAX_PLAYERS + 1];
    int     pl_num;
    char    **pl_names;
    char    **pl_comments;
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

void    init_structs(t_pl *players, t_flag *flags, int ac, char **av);
void     parse_flags_players(t_pl *players, t_flag *flags);
int     vm_error(char *str);

# endif