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
	int				arguments[3][3];
	int				arg_amount;

}					t_op_table;

static const	t_op_table op_table[OP_CODE_COUNT] =
{
	{
		"live",
		0x01,
		4,
		0,
		{
			{0, T_DIR, 0},
			{0, 0, 0},
			{0, 0, 0}
		},
		1
	},
	{
		"ld",
		0x02,
		4,
		1,
		{
			{0, T_DIR, T_IND},
			{T_REG, 0, 0},
			{0, 0, 0}
		},
		2
	},
	{
		"st",
		0x03,
		4,
		1,
		{
			{T_REG, 0, 0},
			{T_REG, 0, T_IND},
			{0, 0, 0}
		},
		2
	},
	{
		"add",
		0x04,
		4,
		1,
		{
			{T_REG, 0, 0},
			{T_REG, 0, 0},
			{T_REG, 0, 0}
		},
		3
	},
	{
		"sub",
		0x05,
		4,
		1,
		{
			{T_REG, 0, 0},
			{T_REG, 0, 0},
			{T_REG, 0, 0}
		},
		3
	},
	{
		"and",
		0x06,
		4,
		1,
		{
			{T_REG, T_DIR, T_IND},
			{T_REG, T_DIR, T_IND},
			{T_REG, 0, 0}
		},
		3
	},
	{
		"or",
		0x07,
		4,
		1,
		{
			{T_REG, T_DIR, T_IND},
			{T_REG, T_DIR, T_IND},
			{T_REG, 0, 0}
		},
		3
	},
	{
		"xor",
		0x08,
		4,
		1,
		{
			{T_REG, T_DIR, T_IND},
			{T_REG, T_DIR, T_IND},
			{T_REG, 0, 0}
		},
		3
	},
	{
		"zjmp",
		0x09,
		2,
		0,
		{
			{0, T_DIR, 0},
			{0, 0, 0},
			{0, 0, 0}
		},
		1
	},
	{
		"ldi",
		0x0a,
		2,
		1,
		{
			{T_REG, T_DIR, T_IND},
			{T_REG, T_DIR, 0},
			{T_REG, 0, 0}
		},
		3
	},
	{
		"sti",
		0x0b,
		2,
		1,
		{
			{T_REG, 0, 0},
			{T_REG, T_DIR, T_IND},
			{T_REG, T_DIR, 0}
		},
		3
	},
	{
		"fork",
		0x0c,
		2,
		0,
		{
			{0, T_DIR, 0},
			{0, 0, 0},
			{0, 0, 0}
		},
		1
	},
	{
		"lld",
		0x0d,
		4,
		1,
		{
			{0, T_DIR, T_IND},
			{T_REG, 0, 0},
			{0, 0, 0}
		},
		2
	},
	{
		"lldi",
		0x0e,
		2,
		1,
		{
			{T_REG, T_DIR, T_IND},
			{T_REG, T_DIR, 0},
			{T_REG, 0, 0}
		},
		3
	},
	{
		"lfork",
		0x0f,
		2,
		0,
		{
			{0, T_DIR, 0},
			{0, 0, 0},
			{0, 0, 0}
		},
		1
	},
	{
		"aff",
		0x10,
		4,
		1,
		{
			{T_REG, 0, 0},
			{0, 0, 0},
			{0, 0, 0}
		},
		1
	}
};

#endif
