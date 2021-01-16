#include "vm.h"

int     main(int argc, char **argv)
{
    t_pl    players;
    t_flag  flags;

    if (argc == 1)
        vm_error("usage");
    init_structs(&players, &flags, argc, argv);
    parse_flags_players(&players, &flags);


    return (0);
}

/*
**  to-do list
** -parse flags and players (assign player numbers etc)
** -check file sizes (x has too large a code (993 bytes > 682 bytes)) CHAMP_MAX_SIZE
** -introduce players and their comments on stdout
** -create memory area
** -create regstries??
** -place players in memory area
** etc.
*/