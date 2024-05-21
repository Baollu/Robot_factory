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

int get_params_type(char **line, int index)
{
    if (line[index][0] == 'r')
        return 1;
    if (line[index][0] == '%')
        return 2;
    return 3;
}

int is_index(char *inst)
{
    char *list_have_index[] = {"zjmp", "ldi", "sti", "fork", NULL};

    for (int i = 0; list_have_index[i] != NULL; i++)
        if (my_strcmp(list_have_index[i], inst) == 0)
            return 1;
    return 0;
}

int get_params_len(char **line, int index)
{
    if (line[index][0] == 'r')
        return 1;
    if (line[index][0] == '%' && is_index(line[0]))
        return 2;
    if (line[index][0] == '%')
        return 4;
    return 2;
}

void write_params_type(char *op, int fd, char **splited_line)
{
    int nbr_args = op_tab[get_op_index(op)].nbr_args;
    int params_type = 0;
    int bits_shift = 6;

    for (int i = 0; i < nbr_args; i++){
        params_type += get_params_type(splited_line, i + 1) << bits_shift;
        bits_shift -= 2;
    }
    write(fd, &params_type, 1);
}
