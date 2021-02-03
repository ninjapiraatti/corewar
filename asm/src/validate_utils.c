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
		ft_printf("'%s'\n", file[i]);
		i++;
	}
}
