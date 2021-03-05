#include "../includes/asm.h"

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

int		skip_spaces(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '\0' && file[i] != '\n' && ft_isspace(file[i]))
		i++;
	return (i);
}

int		skip_comment(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '\0' && file[i] != '\n')
		i++;
	return (i + 1);
}