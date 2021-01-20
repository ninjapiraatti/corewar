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

int		validate_name(char **file, int i)
{
	int		j;
	char	*name;

	j = ft_strlen(NAME_CMD_STRING);
	while (file[i][j] != '\0' && ft_isspace(file[i][j]))
		j++;
	if (file[i][j] != '"')
		error_management("error in champion name");
	j++;
	name = ft_strcdup(&file[i][j], '"');
	j += ft_strlen(name);
	while (file[i][j] == '\0')
	{
		i++;
		name = free_strjoin(name, ft_strdup("\n"));
		name = free_strjoin(name, ft_strcdup(file[i], '"'));
		j = ft_strlen(name) - j - 1;
		ft_printf("goes to two lines\n");
	}
	if (ft_strlen(name) > PROG_NAME_LENGTH)
		error_management("champion name length exceeded");
	ft_printf("name: %s\n", name);
	return (i);
}

void	validate_file(t_asm *assm)
{
	char	**file;
	int		i;

	file = assm->file;
	i = 0;
	while (file[i] != NULL)
	{
		if (ft_strncmp(file[i], NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0)
			i = validate_name(file, i);
		// else if (ft_strncmp(file[i], COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)) == 0)
		// 	validate_comment();
		i++;

	}
	// validate_header(assm);

}