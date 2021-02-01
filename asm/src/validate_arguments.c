#include "../includes/asm.h"

int		is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0' && str[i] != SEPARATOR_CHAR && !ft_isspace(str[i]))
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i == 0 || (str[0] == '-' && i == 1))
		return (0);
	return (i);
}

int		is_label(char *str, int mode)
{
	int	i;

	i = 0;
	if (mode == 1 && str[i] != LABEL_CHAR)
		return (0);
	if (mode == 1)
		i++;
	while (str[i] != '\0' && ft_strchr(LABEL_CHARS, str[i]))
		i++;
	if (mode == 0 && str[i] != LABEL_CHAR)
		return (0);
	if (mode == 0)
		i++;
	return (i);
}

/*
** T_REG - r + two digits r87
*/

int		is_t_reg(char *file)
{
	if (file[0] == 'r')
	{
		if (ft_isdigit(file[1]) && ft_isdigit(file[2]))
			return (3);
		if (ft_isdigit(file[1]))
			return (2);
	}
	return (0);
}

/*
** T_DIR - DIRECT_CHAR + number / label
*/

int		is_t_dir(char *file)
{
	int	i;

	i = 0;
	if (file[i] == DIRECT_CHAR)
	{
		if ((i = is_number(&file[i + 1])) != 0)
			return (i + 1);
		if ((i = is_label(&file[i + 1], 1)) != 0)
			return (i + 1);
	}
	return (0);
}

/*
** T_IND - number / label, no prefix
*/

int		is_t_ind(char *file)
{
	int	i;

	i = 0;
	if ((i = is_number(&file[i])) != 0)
		return (i);
	if ((i = is_label(&file[i], 1)) != 0)
		return (i);
	return (0);
}
