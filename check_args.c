/*
** EPITECH PROJECT, 2023
** main
** File description:
** main template
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "my_macro.h"
#include "op.h"

static int check_header(char **file)
{
    have_headers(file[0]);
    return have_headers(file[1]);
}

int get_arrlen(char **arr)
{
    int len = 0;

    for (len = 0; arr[len] != NULL && arr[len][0] != '#'; len++);
    return len;
}

static int get_theoric_nbr_args(char *param)
{
    for (int i = 0; i < NBR_OP; i++)
        if (my_strcmp(param, op_tab[i].mnemonique) == 0)
            return op_tab[i].nbr_args;
    return -10;
}

static int check_line(char *Line)
{
    char **line = my_split_str(Line, " \t,");

    if (get_op_index(line[0]) == -1)
        line++;
    if (get_arrlen(line) == 0)
        return 0;
    if (get_arrlen(line) != get_theoric_nbr_args(line[0]) + 1)
        return 84;
    return 0;
}

static int check_body(char **file)
{
    for (int i = 0; file[i] != NULL; i++)
        if (check_line(file[i]) == 84)
            return 84;
    return 0;
}

int check_args(char **av)
{
    int fd = open(av[1], O_RDONLY);
    char **file = NULL;

    if (fd == -1)
        return 84;
    close(fd);
    file = read_file(av[1]);
    if (check_header(file) == 84)
        return 84;
    if (check_body(file + 2))
        return 84;
    return 0;
}
