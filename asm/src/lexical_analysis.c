#include "../includes/asm.h"

/*
** checks if row in champion file is a statement.
*/

int			contains_statement(char *line)
{
	int		i;

	i = 0;
	if (line[0] == '\0')
		return (0);
	while (line[i])
	{
		if (line[i] == '.' || line[i] == COMMENT_CHAR ||
		line[i] == ALT_COMMENT_CHAR)
			return  (0);
		if (!ft_isspace(line[i]))
			return (1);
		i++;
	}
	return (0);
}

/*
** creates a new statement struct.
*/

t_statement	*new_statement(t_asm *assm)
{
	t_statement	*statement;

	if (!(statement = (t_statement*)malloc(sizeof(t_statement))))
		error_management("Malloc error");
	statement->label = get_label(assm);
	if (statement->label)
		for (int i = 0;statement->label[i];i++)
			ft_printf("LABEL: %s\n", statement->label[i]);
	//statement->code = get_statement_code(assm);
	if (statement->code == 0)
		return (statement);
	//get_statement_arguments(assm, statement);
	return (statement);
}

/*
** parses the champion file into t_asm struct and ignores all unnecessary rows.
*/

void		lexical_analysis(t_asm *assm)
{
	t_statement *statements;

	ft_printf("name: %s\n", assm->name);
	ft_printf("comment: %s\n", assm->comment);
	while (assm->file[assm->index])
	{
		if (contains_statement(assm->file[assm->index]))
		{
			ft_printf("statement: %s\n", assm->file[assm->index]);
			if (!assm->statements)
			{
				statements = new_statement(assm);
				assm->statements = statements;
			}
			else
			{
				statements->next = new_statement(assm);
				statements = statements->next;
			}
		}
		assm->index++;
	}
}
