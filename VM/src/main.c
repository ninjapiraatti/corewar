#include "vm.h"

/*
** Opens each champ file and parses all info from them. Each called
** function can be found in "Read_from_champ_files.c".
*/

int     parse_champ_files(t_pl *players)
{
    int fd;
    int i;

    players->h_info = prepare_header_info_array(players->pl_num);
    if (!(players->exec = malloc(sizeof(char*) * (players->pl_num + 1))))
        vm_error(strerror(errno));
    players->exec[0] = NULL;
    i = 1;
    while (i <= players->pl_num)
    {
        if ((fd = open(players->pl_order[i], O_RDONLY)) == -1)
            vm_error(strerror(errno));
        players->h_info[i]->magic = check_magic_number(fd);
        read_champ_name(fd, players->h_info[i]->prog_name);
        players->h_info[i]->prog_size = check_champ_size(fd);
        read_champ_comment(fd, players->h_info[i]->comment);
        players->exec[i] = read_champ_executable(fd,
            players->h_info[i]->prog_size);
        close(fd);
        i++;
    }
    return (0);
}

void    introduce_players(t_pl *players)
{
    int i;

    ft_putendl("Introducing contestants ...");
    i = 1;
    while (i <= players->pl_num)
    {
        ft_printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\")!\n",
            i, players->h_info[i]->prog_size, players->h_info[i]->prog_name,
            players->h_info[i]->comment);
        i++;
    }
}

int     main(int argc, char **argv)
{
    t_pl    players;
    t_flag  flags;
    t_avac  avac;
    t_game  game;

    if (argc == 1)
        vm_error("usage");
    avac.ac = argc;
    avac.av = argv;
    init_structs(&players, &flags);
    parse_flags_player_order(&players, &flags, &avac);
    parse_champ_files(&players);
    introduce_players(&players);
    place_players_in_mem(&game, &players);
    print_hex(game.arena);
    vm_loop(&game, &players);

    return (0);
}

/*
**  to-do list
** DONE-parse flags and players (assign player numbers etc)
** DONE-check file sizes (x has too large a code (993 bytes > 682 bytes)) CHAMP_MAX_SIZE
** DONE-introduce players and their comments on stdout
** DONE-create memory area
** DONE-create regstries??
** DONE-place players in memory area
** etc.
*/