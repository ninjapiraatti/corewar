/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:15:35 by pkuussaa          #+#    #+#             */
/*   Updated: 2021/03/16 20:26:56 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <fcntl.h>
# include "op.h"
# include "op_table.h"
# include "../../ft_printf/includes/ft_printf.h"

# define BUF_SIZE	4194305

typedef struct			s_statement
{
	char				**label;
	int					code;
	char				*instruction;
	int					arg_count;
	char				**args;
	int					size;
	unsigned char		arg_type_code;
	struct s_statement	*next;
}						t_statement;

typedef struct			s_asm
{
	char				*name;
	char				*comment;
	char				**file;
	char				*file1d;
	int					champion_size;
	int					file_size;
	t_statement			*statements;
	int					index;
}						t_asm;

void					lexical_analysis(t_asm *assm);

/*
** get_*.c
*/

void					get_name_and_comment(t_asm *assm, int i, int check);
void					get_statement_arguments(t_statement *statement,
						char *line, int i);
char					*get_instruction(t_asm *assm);
int						get_arg_type(char *arg);
int						get_instruction_code(char *instruction);
int						get_statement_size(t_statement *statement);
unsigned char			get_arg_type_code(t_statement *statement);
char					**get_label(t_asm *assm);
int						loop_label(char *line);

/*
** validate*.c files
*/

void					validate_file(t_asm *assm);
void					validate_instructions(char **file, int i);
int						is_t_ind(char *file);
int						is_t_dir(char *file);
int						is_t_reg(char *file);
int						is_label(char *str, int mode);
int						skip_spaces(char *file);
int						skip_comment(char *file);
void					remove_comment(char *file);
char					*ft_str2chr(const char *s, int c, int h);

/*
** write*.c files
*/

void					write_header(t_asm *assm, int fd);
void					write_arguments(t_statement *statement, int fd);
void					write_hexa(t_asm *assm, char *file_name);
void					convert_labels(t_statement *tmp, int i, int count);

/*
** help_functions.c
*/

void					error_management(char *str);
int						get_2d_array_size(char **arr);
char					**resize_2d_array(char **arr, char *str);
char					*free_strjoin(char *s1, char *s2);
char					*free_strtrim(char *s);

#endif
