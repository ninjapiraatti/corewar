#include "../includes/asm.h"

/*
** parses label into statement struct.
*/

char	**get_label(t_asm *assm)
{
	char	**label;
	int		j;

	label = NULL;
	j = 0;
	while (assm->file[assm->index])
	{
		if (assm->file[assm->index][0] == '\0')
			return (label);
		while (assm->file[assm->index][j] && assm->file[assm->index][j] != LABEL_CHAR)
			if (!ft_strchr(LABEL_CHARS, assm->file[assm->index][j++]))
				return (label);
		if (assm->file[assm->index][j] == LABEL_CHAR)
			label = resize_2d_array(label, ft_strsub(assm->file[assm->index], 0, j));
		while (assm->file[assm->index][++j])
			if (!ft_isspace(assm->file[assm->index][j]))
				break ;
		if (assm->file[assm->index][j])
			return (label);
		j = 0;
		assm->index++;
	}
}
