#ifndef VM_H
# define VM_H
# include "op_table.h"
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
** Simple struct for storing command line argc and **argv
*/

typedef struct  s_avac
{
    int     ac;
    char    **av;
}               t_avac;

/*
** Struct for all information concerning players and
** command-line arguments.
** 'pl_order' will list the champion files in their
** indicated order (Player 1 is in pl_order[1]).
*/

typedef struct  s_pl
{
    char        *pl_order[MAX_PLAYERS + 1];
    int         pl_num;
    header_t    **h_info;
    unsigned char   **exec;
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

/*
** Mini struct for storing arena memory byte
** and the possible corresponding color.
*/

typedef struct      s_arena
{
    unsigned char ar;
    char          color[11];
}                   t_arena;

/*
** Enum with a color for each player according to
** the player's index number.
*/

enum    e_color 
{ 
    yellow, 
    cyan, 
    magenta, 
    green 
};

enum e_carry {
    false,
    true
}; // carry-flag


typedef struct          s_carriage
{
    int                 id; // unique carriage number
    enum e_carry        carry;
    int                 pc;
    int                 cycles_to_wait;// time to wait
    unsigned int        last_live;// when live was (index of cycle)
    int                 regs[REG_NUMBER]; //should we specify REG_SIZE, or is int enough??
    int                 color_id;   //maybe color of carriage
    int                 next_state;
    struct s_carriage   *next;
    int                 args[3];
    int                 arg_size[3];
}                       t_carriage;


/*
** Struct for storing fighting arena related data.
*/

typedef struct      s_game
{
    t_arena         arena[MEM_SIZE];
    t_pl            *players;
    enum e_color    colors;
    t_carriage      *head; //linked list with list front add
    int             id_last_live;//player last told he was alive
    unsigned int    cycles;//cycles passed
    //number of completed live statements for the last period
    //cycles_to_die[CYCLES_TO_DIE]
    //number of checks performed
    int             car_num; //num of carriages
    int             game_state;
}                   t_game;


int             parse_champ_files(t_pl *players);
void            introduce_players(t_pl *players);


void    place_players_in_mem(t_game *game, t_pl *pl);
/*
** vm_error.c
*/

int             vm_error(char *str);

/*
** vm_tools.c
*/

void            init_structs(t_pl *players, t_flag *flags);
header_t        **prepare_header_info_array(int pl_num);
void            ft_revbytes(char *bytes, size_t size);
int             ft_str_is_empty(char *str, int size);

/*
** parse_flags_player_order.c
*/

void            parse_flags_player_order(t_pl *players, t_flag *flags, t_avac *avac);

/*
** read_from_champ_files.c
*/

unsigned int    check_magic_number(int fd);
void            read_champ_name(int fd, char *prog_name);
unsigned int    check_champ_size(int fd);
void            read_champ_comment(int fd, char *comment);
unsigned char   *read_champ_executable(int fd, int prog_size);

/*
** place_in_memory.c
*/

void    place_players_in_mem(t_game *game, t_pl *pl);
int     player_to_arena(t_arena *start, unsigned char *code, int len, int index);
void    add_color(char *color, int player_number);

/*
**  print_hex.c
*/

void    print_hex(t_arena *arena);

/*
** carriages.c
*/

void        initialize_registries(int *new_regs, int id, int *copy_regs);
void	ft_add_carriage(t_carriage **alst, t_carriage *new);
t_carriage  *create_carriage(int car_id, int player_id, int position);

// void    create_first_carriages(t_game *game, t_pl *players);
void    vm_loop(t_game *game, t_pl *players);

/*
** manage_st.c
*/
int    manage_st(t_carriage *carr, t_arena *arena);
int    manage_sti(t_carriage *carr, t_arena *arena);
void    write_to_memory(t_arena *arena, unsigned int pos, int arg, int size);
int      read_bytes_convert(t_arena *arena, int pos, int size);
char    *copy_mem_area(t_arena *arena, int start, int size);
int     check_ind_pc(int pc, int arg);
/*
** Manage statements
*/

void	manage_and(t_carriage *carr, t_arena *arena);
int     check_arg_type_code(int inst, unsigned char arg_code, t_carriage *carr);
void    run_carriage(t_arena *arena, t_carriage *carr);
int		check_regs(int inst, t_carriage *carr, t_arena *arena);

# endif