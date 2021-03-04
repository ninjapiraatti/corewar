#include "vm.h"

/*
** Displays the error message sent into the function and exits
** the program. If str is "usage", displays a longer 'usage
** message'.
*/

int	vm_error(char *str)
{
	if (!ft_strcmp(str, "usage"))
	{
		ft_putendl("Usage: ./corewar [-dump nbr_cycles] [-n number] \
			file1.cor [... file4.cor]");
		ft_putendl("-dump: at the end of nbr_cycles of \
			executions, dump the memory on the standard output and quit");
		ft_putendl("-n: assign player number for the following player");
	}
	else
		ft_putendl(str);
	exit(0);
}
