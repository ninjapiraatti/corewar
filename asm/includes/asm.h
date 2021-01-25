#ifndef ASM_H
#define ASM_H
#include <fcntl.h>
#include "op.h"
#include "op_table.h"
#include "../../ft_printf/includes/ft_printf.h"
#include "../../get_next_line/get_next_line.h"

typedef struct			s_statement
{
	char				**label;
	int					code;
	char				*instruction;
	int					arg_count;
	char				**args;
	int				size;
	struct s_statement	*next;
}						t_statement;

typedef struct			s_asm
{
	char				*name;
	char				*comment;
	char				**file;
	t_statement			*statements;
	int					index;
}						t_asm;

void					get_name_and_comment(t_asm *assm);
void					lexical_analysis(t_asm *assm);
void					error_management(char *str);
void					get_statement_arguments(t_statement *statement, char *line, int i);
void					print_2d_array(char **arr);

char					**resize_2d_array(char **arr, char *str);
char					**get_label(t_asm *assm);
char					*free_strjoin(char *s1, char *s2);
char					*get_instruction(t_asm *assm);
char					*free_strtrim(char *s);

int						get_arg_type(char *arg);
int						get_2d_array_size(char **arr);
int						loop_label(char *line);
int						get_instruction_code(char *instruction);
int						get_statement_size(t_statement *statement);
#endif
