# include "vm.h"

// void	perform_statement2(t_carriage *carr, t_arena *arena, int inst)
// {
	// if (inst == 10)
	// 	manage_ldi(carr, arena);
	// else if (inst == 11)
	// 	manage_sti(carr, arena);
	// else if (inst == 12)
	// 	manage_fork(carr, arena);
	// else if (inst == 13)
	// 	manage_lld(carr, arena);
	// else if (inst == 14)
	// 	manage_lldi(carr, arena);
	// else if (inst == 15)
	// 	manage_lfork(carr, arena);
	// else if (inst == 16)
	// 	manage_aff(carr, arena);
// }

void	perform_statement(t_carriage *carr, t_game *game, int inst)
{
	// if (inst == 1) // should we compare to op_table op_code?
	// 	manage_live(carr, arena);
	// else if (inst == 2)
	// 	manage_ld(carr, arena);
	// else if (inst == 3)
	// 	manage_st(carr, arena);
	// else if (inst == 4)
	// 	manage_add(carr, arena);
	// else if (inst == 5)
	// 	manage_sub(carr, arena);
	// else if (inst == 6)
	// 	manage_and(carr, arena);
	// else if (inst == 7)
	// 	manage_or(carr, arena);
	// else if (inst == 8)
	// 	manage_xor(carr, arena);
	// else if (inst == 9)
	// 	manage_zjmp(carr, arena);
	// else
	// 	perform_statement2(carr, arena, inst);
		
	(void)carr;

	if (inst == 1) // should we compare to op_table op_code?
		manage_live(carr, game);
	else if (inst == 2)
		manage_ld(carr, game->arena);
	else if (inst == 3)
		manage_st(carr, game->arena);

	else if (inst == 10)
		manage_ldi(carr, game->arena);
	else if (inst == 11)
		manage_sti(carr, game->arena);

}
