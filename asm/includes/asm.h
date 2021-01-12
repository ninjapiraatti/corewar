#ifndef ASM_H
#define ASM_H
#include "op.h"
#include "libft.h"

typedef struct		    s_statement
{
	char				*label;
	int					code;
	int					cycles;
	char				*arg[3];
    int             	type[3];
	struct s_statement	*next;

}                       t_statement;





#endif