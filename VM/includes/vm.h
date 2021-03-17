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
# include <ncurses.h>

# define INIT_FLAG -10000
# define SIZE_MAGIC_NUM 4
# define JUMPED 20000
# define VISUAL 1
# define OP_AND 1
# define OP_OR	2
# define OP_XOR 3

/*
** Simple struct for storing command line argc and **argv
*/

typedef struct			s_avac
{
	int					ac;
	char				**av;
}						t_avac;

/*
** Struct for all information concerning players and
** command-line arguments.
** 'pl_order' will list the champion files in their
** indicated order (Player 1 is in pl_order[1]).
*/

typedef struct			s_pl
{
	char				*pl_order[MAX_PLAYERS + 1];
	int					pl_num;
	header_t			**h_info;
	unsigned char		**exec;
	int					last_life[MAX_PLAYERS + 1];
}						t_pl;

/*
** Struct for option flag information. 'n' is an array,
** because '-n' can be among the command-line arguments
** several times.
*/

typedef struct			s_flag
{
	int					n[MAX_PLAYERS + 1];
	int					dump;
	int					viz;
	int					aff;
	int					live;
	int					moves;
	int					kill;
	int					pc_move;
	int					show_cycles;
}						t_flag;

/*
** Mini struct for storing arena memory byte
** and the possible corresponding color.
*/

typedef struct			s_arena
{
	unsigned char		ar;
	int					color;
	int					color_carr;
	int					color_bold;
}						t_arena;

typedef struct			s_carriage
{
	int					carry; //changed to int from enum
	int					pc;
	int					cycles_to_wait;// time to wait
	int					last_live;// when live was (index of cycle)
	int					regs[REG_NUMBER]; //should we specify REG_SIZE, or is int enough??
	int					color_id;   //maybe color of carriage
	int					carr_id;
	int					next_state;
	struct s_carriage	*next;
	int					args[3];
	int					as[3];
	int					inst;
}						t_carriage;

/*
** Struct for storing fighting arena related data.
*/

typedef struct			s_game
{
	t_arena				arena[MEM_SIZE];
	t_pl				*players;
	t_flag				*flags;
	t_carriage			*head; //linked list with list front add
	int					id_last_live;//player last told he was alive
	int					cycles;//cycles passed
	unsigned int		lives_num;
	int					ctd;
	unsigned int		checks;
	int					car_num; //num of carriages
	int					game_state;
	int					time_to_check;
}						t_game;

/*
** main.c
*/

void					declare_winner(t_game *game);
int						parse_champ_files(t_pl *players);
void					introduce_players(t_pl *players);

/*
** vm_error.c
*/

int						vm_error(char *str);

/*
** vm_tools.c
*/

void					init_structs(t_pl *players, t_flag *flags);
header_t				**prepare_header_info_array(int pl_num);
void					ft_revbytes(char *bytes, size_t size);
int						ft_str_is_empty(char *str, int size);
void					init_registries(int *new_regs, int id, int *copy_regs);

/*
** parse_flags_player_order.c
*/

int	parse_flags(int i, t_flag *fl, t_pl *ps, t_avac *avac);
void					parse_flags_player_order(t_pl *players,
						t_flag *flags, t_avac *avac);

/*
** player_order.c
*/

int	change_player_order(int i, t_flag *fl, t_pl *ps, t_avac *avac);
void	assign_player_order(t_pl *ps, char *champion, int pos);
void	double_check_player_order(char **order, int player_num);

/*
** read_from_champ_files.c
*/

unsigned int			check_magic_number(int fd);
void					read_champ_name(int fd, char *prog_name);
unsigned int			check_champ_size(int fd);
void					read_champ_comment(int fd, char *comment);
unsigned char			*read_champ_executable(int fd, int prog_size);

/*
** place_in_memory.c
*/

void					place_players_in_mem(t_game *game, t_pl *pl,
						t_flag *flags);
int						player_to_arena(t_arena *start, unsigned char *code,
						int len, int index);
void					add_color(char *color, int player_number);
void					init_mem_area_to_zero(t_arena *arena);

/*
**  print_dump.c
*/

void    dump_memory(t_arena *arena);
void	print_sti_info(int reg, int arg2, int arg3, int pos);

/*
** carriages.c
*/

void					ft_add_carriage(t_carriage **alst, t_carriage *new);
t_carriage				*create_carriage(int player_id, int position);
t_carriage				*kill_first_carrs(t_carriage *head, t_game *g);
t_carriage				*kill_carriages(t_carriage *head, t_game *game);
t_carriage				*kill_all_carriages(t_carriage *head, t_game *game);

/*
** vm_loop.c
*/

void					vm_loop(t_game *game);
void					run_carriage(t_game *game, t_carriage *carr);
void					set_new_pc_and_color(t_game *game, t_carriage *carr);
void					run_check(t_game *game);
void					prepare_game_variables(t_game *game);

/*
** op_tools.c
*/

char					*copy_mem_area(t_arena *arena, int start, int size);
int						read_bytes_convert(t_arena *arena, int pos, int size);
void					write_to_memory(t_arena *arena, unsigned int pos,
						int arg, int size);
int						read_bytes(t_arena *arena, unsigned int i, int size);
void					update_color(t_carriage *carr, t_arena *arena,
						unsigned int pos, int size);

/*
** op_tools2.c
*/

int						get_reg(t_arena *arena, t_carriage *c, int extra);
int						modpc(unsigned int address);

/*
** check_args.c
*/

int     check_inst(int inst, unsigned char arg_code, t_carriage *c, t_arena *a);
int     check_(int inst, unsigned char arg_code, t_carriage *carr, t_arena *arena);
int     check_args(char arg, int i, int inst);
int		check_regs(t_carriage *carr, t_arena *arena);

/*
** perform_statement.c
*/

void	perform_statement(t_carriage *carr, t_game *game, int inst);

/*
** manage_live.c
*/

void    manage_live(t_carriage *carr, t_game *game);

/*
** manage_ld_ldi_lld_lldi.c
*/

void	manage_ld(t_carriage *carr, t_game *game);
void	manage_ldi(t_carriage *carr, t_game *game);
void	manage_lld(t_carriage *carr, t_game *game);
void	manage_lldi(t_carriage *carr, t_game *game);

/*
** manage_st_sti.c
*/

void    manage_st(t_carriage *carr, t_game *game);
void    manage_sti(t_carriage *c, t_game *game);

/*
** manage_and_or_xor
*/

void	manage_and(t_carriage *carr, t_game *game);
void	manage_or(t_carriage *carr, t_game *game);
void	manage_xor(t_carriage *carr, t_game *game);
void    manage_aff(t_carriage *carr, t_arena *arena, t_flag *flags);

/*
** manage_add_sub.c
*/

void    manage_sub(t_carriage *carr, t_game *game);
void    manage_add(t_carriage *carr, t_game *game);

/*
** manage_fork_lfork.c
*/

void    manage_fork(t_game *game, t_carriage *carr);
void    manage_lfork(t_game *game, t_carriage *carr);

/*
** manage_zjmp.c
*/

void    manage_zjmp(t_game *game, t_carriage *carr);

/*
** visualizer_ncurses1.c
*/
int    start_visualizer(void);
int    ncurses_print_arena(t_arena *arena);
void    perform_visualization(t_game *game);
void    ncurses_declare_winner(int winner_number, char *winner_name);

/*
** visualizer_ncurses2.c
*/

t_arena    print_hex_color(t_arena arena);
void	ncurses_print_players(t_game *game, int y, int x);
void    ncurses_print_game_info(t_game *game, int x);

# endif
