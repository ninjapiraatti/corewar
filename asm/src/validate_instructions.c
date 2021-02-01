#include "../includes/asm.h"

/*
** Checks that argument is the correct type and checks
** the validity of separator character.
*/

int		validate_arg(char *file, int op, int args)
{
	int	i;

	i = 0;
	if (file[i] == '\0')
		error_management("file ended");
	if (op_table[op].arguments[args][0] == T_REG)
		i = is_t_reg(&file[i]);
	if (i == 0 && op_table[op].arguments[args][1] == T_DIR)
		i = is_t_dir(&file[i]);
	if (i == 0 && op_table[op].arguments[args][2] == T_IND)
		i = is_t_ind(&file[i]);
	if (i == 0)
	{
		// ft_printf("at %s ", file);
		error_management("didnt find correct argument");
	}
	while (file[i] != '\0' && ft_isspace(file[i]))
		i++;
	if (op_table[op].arg_amount > 1 && args < op_table[op].arg_amount - 1 && file[i] != SEPARATOR_CHAR)
		error_management("no separator char");
	if (file[i] == SEPARATOR_CHAR)
		i++;
	return (i);
}

/*
** Goes through arguments for the instruction.
*/

void	validate_arguments(char *file, int op)
{
	int	i;
	int	args;

	i = 0;
	args = 0;
	while (args < op_table[op].arg_amount)
	{
		while (file[i] != '\0' && ft_isspace(file[i]))
			i++;
		i += validate_arg(&file[i], op, args);
		if (i == 0)
			error_management("invalid arguments");
		args++;
	}
	while (file[i] != '\0')
	{
		if (!ft_isspace(file[i]))
			error_management("syntax error");
		i++;
	}
}

/*
** Finds matching instruction from op_table.
*/

int		validate_instruction(char *file)
{
	int	i;
	int	code;

	code = -1;
	i = 0;
	while (file[i] != '\0' && ft_isspace(file[i]))
		i++;
	if (file[i] != '\0')
	{
		file = &file[i];
		i = OP_CODE_COUNT - 1;
		while (i >= 0)
		{
			if (ft_strncmp(op_table[i].op_name, file, ft_strlen(op_table[i].op_name)) == 0)
			{
				code = i;
				validate_arguments(file + ft_strlen(op_table[i].op_name), code);
				break ;
			}
			i--;
		}
	}
	return (code);
}

void	validate_label(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '\0' && ft_strchr(LABEL_CHARS, file[i]))
		i++;
	if (file[i] != LABEL_CHAR)
		error_management("syntax error in label");
	i++;
	if (validate_instruction(&file[i]) == -1)
	{
		while (file[i] != '\0')
		{
			if (!ft_isspace(file[i]))
				error_management("syntax error");
			i++;
		}
	}
}

/*
** Removes comments and validates labels.
*/

void	validate_instructions(t_asm *assm, int i)
{
	int	j;

	while (assm->file[i] != NULL)
	{
		j = 0;
		if (ft_str2chr(assm->file[i], COMMENT_CHAR, ALT_COMMENT_CHAR) != NULL)
			remove_comment(ft_str2chr(assm->file[i], COMMENT_CHAR, ALT_COMMENT_CHAR));
		while (assm->file[i][j] != '\0' && ft_isspace(assm->file[i][j]))
			j++;
		if (assm->file[i][j] != '\0' && validate_instruction(&assm->file[i][j]) == -1)
		{
			if (ft_strchr(LABEL_CHARS, assm->file[i][j]))
				validate_label(&assm->file[i][j]);
			else
			{
				// ft_printf("at %s ", &assm->file[i][j]);
				error_management("syntax error in instructions");
			}
		}
		i++;
	}
}
