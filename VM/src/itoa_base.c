#include "vm.h"

static	uintmax_t	negative(uintmax_t i)
{
	if (i < 0)
		i *= -1;
	return (i);
}

char				*itoa_base(uintmax_t i, int base)
{
	char		*str;
	char		*tab;
	int			size;
	int			flag;
	uintmax_t	tmp;

	flag = 0;
	size = 0;
	tab = "0123456789abcdef";
	if (i < 0 && base == 10)
		flag = 1;
	tmp = i;
	while ((tmp = tmp / base))
		size++;
	size = size + flag + 1;
	str = ft_strnew(size);
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = tab[negative(i % base)];
		size--;
		i = i / base;
	}
	return (str);
}