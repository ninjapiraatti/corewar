#ifndef OP_TABLE_H
# define OP_TABLE_H
# include "op.h"
# define OP_CODE_COUNT 16

typedef struct		s_op_table
{
	char			*name;
	unsigned int	op_code;
	int				t_dir_size;
	int				arg_type_code;
	int				arguments[3][3];
	int				arg_amount;
	int				cycles_to_wait;

}					t_op_table;

static const	t_op_table	g_op_table[OP_CODE_COUNT] =
{
	{
		"live",
		0x01,
		4,
		0,
		{
			{0, DIR_CODE, 0},
			{0, 0, 0},
			{0, 0, 0}
		},
		1,
		10
	},
	{
		"ld",
		0x02,
		4,
		1,
		{
			{0, DIR_CODE, IND_CODE},
			{REG_CODE, 0, 0},
			{0, 0, 0}
		},
		2,
		5
	},
	{
		"st",
		0x03,
		4,
		1,
		{
			{REG_CODE, 0, 0},
			{REG_CODE, 0, IND_CODE},
			{0, 0, 0}
		},
		2,
		5
	},
	{
		"add",
		0x04,
		4,
		1,
		{
			{REG_CODE, 0, 0},
			{REG_CODE, 0, 0},
			{REG_CODE, 0, 0}
		},
		3,
		10
	},
	{
		"sub",
		0x05,
		4,
		1,
		{
			{REG_CODE, 0, 0},
			{REG_CODE, 0, 0},
			{REG_CODE, 0, 0}
		},
		3,
		10
	},
	{
		"and",
		0x06,
		4,
		1,
		{
			{REG_CODE, DIR_CODE, IND_CODE},
			{REG_CODE, DIR_CODE, IND_CODE},
			{REG_CODE, 0, 0}
		},
		3,
		6
	},
	{
		"or",
		0x07,
		4,
		1,
		{
			{REG_CODE, DIR_CODE, IND_CODE},
			{REG_CODE, DIR_CODE, IND_CODE},
			{REG_CODE, 0, 0}
		},
		3,
		6
	},
	{
		"xor",
		0x08,
		4,
		1,
		{
			{REG_CODE, DIR_CODE, IND_CODE},
			{REG_CODE, DIR_CODE, IND_CODE},
			{REG_CODE, 0, 0}
		},
		3,
		6
	},
	{
		"zjmp",
		0x09,
		2,
		0,
		{
			{0, DIR_CODE, 0},
			{0, 0, 0},
			{0, 0, 0}
		},
		1,
		20
	},
	{
		"ldi",
		0x0a,
		2,
		1,
		{
			{REG_CODE, DIR_CODE, IND_CODE},
			{REG_CODE, DIR_CODE, 0},
			{REG_CODE, 0, 0}
		},
		3,
		25
	},
	{
		"sti",
		0x0b,
		2,
		1,
		{
			{REG_CODE, 0, 0},
			{REG_CODE, DIR_CODE, IND_CODE},
			{REG_CODE, DIR_CODE, 0}
		},
		3,
		25
	},
	{
		"fork",
		0x0c,
		2,
		0,
		{
			{0, DIR_CODE, 0},
			{0, 0, 0},
			{0, 0, 0}
		},
		1,
		800
	},
	{
		"lld",
		0x0d,
		4,
		1,
		{
			{0, DIR_CODE, IND_CODE},
			{REG_CODE, 0, 0},
			{0, 0, 0}
		},
		2,
		10
	},
	{
		"lldi",
		0x0e,
		2,
		1,
		{
			{REG_CODE, DIR_CODE, IND_CODE},
			{REG_CODE, DIR_CODE, 0},
			{REG_CODE, 0, 0}
		},
		3,
		50
	},
	{
		"lfork",
		0x0f,
		2,
		0,
		{
			{0, DIR_CODE, 0},
			{0, 0, 0},
			{0, 0, 0}
		},
		1,
		1000
	},
	{
		"aff",
		0x10,
		4,
		1,
		{
			{REG_CODE, 0, 0},
			{0, 0, 0},
			{0, 0, 0}
		},
		1,
		2
	}
};

#endif
