#include "vm.h"

/*
** Copies spedified memory area into buf(no trailing '\0')
*/

char	*copy_mem_area(t_arena *arena, int start, int size)
{
	int		i;
	char	*buf;

	if (!(buf = (char*)malloc(sizeof(char) * size)))
		vm_error(strerror(errno));
	i = 0;
	while (i < size)
	{
		buf[i] = arena[start + i].ar;
		i++;
	}
	return (buf);
}

/*
** After receiving buf, which is a copy of the specified memory area,
** the function turns the bytes around and casts it to an int.
*/

int		read_bytes_convert(t_arena *arena, int pos, int size)
{
	char	*buf;
	int		res;

	buf = copy_mem_area(arena, pos, size);
	ft_revbytes(buf, size);
	res = *(int*)buf;
	return (res);
}

/*
** Writes 'arg' divided into memory arena one byte at a time (until 'size').
** Because the VM is big-endian, the most significant bytes are written first.
*/

void	write_to_memory(t_arena *arena, unsigned int pos, int arg, int size)
{
	int i;

	i = size - 1;
	while (i >= 0)
	{
		pos = pos % MEM_SIZE;
		arena[pos].ar = arg >> (8 * i) & 0xff;
		i--;
		pos++;
	}
}

/*
** Reads size bytes from arena address
** Converts bytes to int and returns int.
** Currently only allows sizes 1, 2 and 4
*/

int		read_bytes(t_arena *arena, unsigned int index, int size)
{
	unsigned char	buf[size];
	int				i;

	i = 0;
	if (size != 1 && size != 2 && size != 4)
		return (0);
	if (size == 1)
		return ((int)arena[index].ar);//if unsigned, whis has to be %MEM_SIZE
	ft_memset(buf, 0, size);
	while (i < size)
	{
		index = index % MEM_SIZE;
		buf[i] = arena[index].ar;
		i++;
		index++;
	}
	if (size == 4)
		return ((buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | buf[3]);
	if (size == 2)
		return ((short)(buf[0] << 8 | buf[1]));
	return (0);
}

void	update_color(t_carriage *c, t_arena *arena, unsigned int pos, int size)
{
	int i;
	int address;

	i = 0;
	while (i < size)
	{
		address = (pos + i) % MEM_SIZE;
		arena[address].color = c->color_id + 10;
		arena[address].color_bold = 100;
		i++;
	}
}
