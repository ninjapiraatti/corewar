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
		{T_DIR}
	},
	{
		"ld",
		0x02,
		4,
		1,
		{T_DIR | T_IND, T_REG}
	},
	{
		"st",
		0x03,
		4,
		1,
		{T_REG, T_IND | T_REG}
	},
	{
		"add",
		0x04,
		4,
		1,
		{T_REG, T_REG, T_REG}
	},
	{
		"sub",
		0x05,
		4,
		1,
		{T_REG, T_REG, T_REG}
	},
	{
		"and",
		0x06,
		4,
		1,
		{T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}
	},
	{
		"or",
		0x07,
		4,
		1,
		{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}
	},
	{
		"xor",
		0x08,
		4,
		1,
		{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}
	},
	{
		"zjmp",
		0x09,
		2,
		0,
		{T_DIR}
	},
	{
		"ldi",
		0x0a,
		2,
		1,
		{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}
	},
	{
		"sti",
		0x0b,
		2,
		1,
		{T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}
	},
	{
		"fork",
		0x0c,
		2,
		0,
		{T_DIR}
	},
	{
		"lld",
		0x0d,
		4,
		1,
		{T_DIR | T_IND, T_REG}
	},
	{
		"lldi",
		0x0e,
		2,
		1,
		{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}
	},
	{
		"lfork",
		0x0f,
		2,
		0,
		{T_DIR}
	},
	{
		"aff",
		0x10,
		4,
		1,
		{T_REG}
	}
};

#endif
