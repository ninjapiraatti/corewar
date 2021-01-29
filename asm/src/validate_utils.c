#include "../includes/asm.h"

int	ft_strclen(char const *s, int i, char c)
{
	int len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char	*ft_strcdup(const char *str, char c)
{
	char	*dup;
	size_t	i;

	i = 0;
	if (!(dup = ft_strnew(ft_strclen(str, i, c))))
		return (NULL);
	while (str[i] && str[i] != c)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strcdup_2d(char **file, int i, int j, char c)
{
	char	*dup;
	char	*new;

	dup = ft_strcdup(&file[i][j], c);
	j += ft_strlen(dup);
	while (file[i][j] == '\0')
	{
		i++;
		dup = free_strjoin(dup, ft_strdup("\n"));
		new = ft_strcdup(file[i], '"');
		dup = free_strjoin(dup, new);
		j = ft_strlen(new);
	}
	return (dup);
}

char	*ft_str2chr(const char *s, int c, int h)
{
	char	*p;

	if (!s)
		return (NULL);
	p = (char *)s;
	while (*p != c && *p != h)
	{
		if (*p == '\0')
			return (NULL);
		p++;
	}
	return (p);
}

void	remove_comment(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ' ';
		i++;
	}
}

void	print_file(char **file)
{
	int	i;

	i = 0;
	while (file[i] != NULL)
	{
		ft_printf("%s\n", file[i]);
		i++;
	}
}


int		is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i] != '\0' && str[i] != SEPARATOR_CHAR)
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
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
** T_REG 1 - r + two digits r87
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
** T_DIR 2 - DIRECT_CHAR + number / label
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
** T_IND 4 - number / label
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
