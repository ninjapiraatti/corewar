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

int		validate_st(char **file, int i, char *cmd_string, int length)
{
	int		j;
	char	*str;

	j = ft_strlen(cmd_string);
	while (file[i][j] != '\0' && ft_isspace(file[i][j]))
		j++;
	if (file[i][j] != '"')
		error_management("error in champion statement");
	j++;
	str = ft_strcdup_2d(file, i, j, '"');
	if ((int)ft_strlen(str) > length)
		error_management("champion statement length exceeded");
	ft_printf("statement: '%s'\n", str);
	return (i);
}

void	remove_comment(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '\0')
	{
		file[i] = ' ';
		i++;
	}
}

void	validate_file(t_asm *assm)
{
	char	**file;
	int		i;

	file = assm->file;
	i = 0;
	while (file[i] != NULL)
	{
		ft_printf("%s\n", file[i]);
		i++;
	}
	i = 0;
	ft_printf("\n\n");
	while (file[i] != NULL)
	{
		if (ft_strchr(file[i], '#') != NULL)
			remove_comment(ft_strchr(file[i], '#'));
		if (ft_strncmp(file[i], NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0)
			i = validate_st(file, i, NAME_CMD_STRING, PROG_NAME_LENGTH);
		else if (ft_strncmp(file[i], COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)) == 0)
			i = validate_st(file, i, COMMENT_CMD_STRING, COMMENT_LENGTH);
		i++;
	}
	i = 0;
	ft_printf("\n\n");
	while (file[i] != NULL)
	{
		ft_printf("%s\n", file[i]);
		i++;
	}
}