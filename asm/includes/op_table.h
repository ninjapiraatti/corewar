#ifndef OP_TABLE_H
# define OP_TABLE_H

# include "op.h"


# define OP_CODE_COUNT 16

typedef struct		s_op_table
{
	char			*op_name;
	unsigned int	op_code;
	int				t_dir_size;
	int				arg_type_code;
}					t_op_table;

static const	t_op_table op_table[OP_CODE_COUNT] =
{
	{
		"live",
		0x01,
		4,
		0,
	},
	{
		"ld",
		0x02,
		4,
		1,
	},
	{
		"st",
		0x03,
		4,
		1,
	},
	{
		"add",
		0x04,
		4,
		1,
	},
	{
		"sub",
		0x05,
		4,
		1,
	},
	{
		"and",
		0x06,
		4,
		1,
	},
	{
		"or",
		0x07,
		4,
		1,
	},
	{
		"xor",
		0x08,
		4,
		1,
	},
	{
		"zjmp",
		0x09,
		2,
		0,
	},
	{
		"ldi",
		0x0a,
		2,
		1,
	},
	{
		"sti",
		0x0b,
		2,
		1,
	},
	{
		"fork",
		0x0c,
		2,
		0,
	},
	{
		"lld",
		0x0d,
		4,
		1,
	},
	{
		"lldi",
		0x0e,
		2,
		1,
	},
	{
		"lfork",
		0x0f,
		2,
		0,
	},
	{
		"aff",
		0x10,
		4,
		1,
	}
};

#endif
