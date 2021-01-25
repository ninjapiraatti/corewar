#ifndef ASM_H
#define ASM_H
#include <fcntl.h>
#include "op.h"
#include "../../ft_printf/includes/ft_printf.h"

typedef struct			s_statement
{
	char				**label;
	int					code;
	int					cycles;
	char				*arg[3];
	int					type[3];
	struct s_statement	*next;
}						t_statement;

typedef struct			s_asm
{
	char				*name;
	char				*comment;
	char				**file;
	char				*file1d;
	t_statement			*statements;
	int					index;
}						t_asm;

void					get_name_and_comment(t_asm *assm);
void					lexical_analysis(t_asm *assm);
void					error_management(char *str);
void					validate_file(t_asm *assm);

char					**resize_2d_array(char **arr, char *str);
char					**get_label(t_asm *assm);
char					*free_strjoin(char *s1, char *s2);
void					outputbin(t_asm *assm);

void					remove_comment(char *file);
void					print_file(char **file);

#endif
