/*
** EPITECH PROJECT, 2024
** count
** File description:
** count
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int need_params_type(char *inst)
{
    char *list_need_type[] = {"live", "zjmp", "fork", "lfork", NULL};

    for (int i = 0; list_need_type[i] != NULL; i++)
        if (my_strcmp(list_need_type[i], inst) == 0)
            return 0;
    return 1;
}

int find_str(char *line)
{
    int i = 0;
    int octet = 0;
    char **param = my_split_str(line, "\t, ");

    if (param[0][0] == '#')
        return 0;
    if (get_op_index(param[0]) == -1)
        param++;
    if (get_arrlen(param) == 0)
        return 0;
    for (i = 1; param[i] != NULL && param[i][0] != '#'; i++)
        octet = octet + get_params_len(param, i);
    return octet + need_params_type(param[0]) + 1;
}

static void add_label(label_t **label_list, char *name, int label_pos)
{
    label_t *label = malloc(sizeof(label_t));

    label->name = my_strdup(name);
    label->name[my_strlen(label->name) - 1] = '\0';
    label->label_pos = label_pos;
    label->next = *label_list;
    *label_list = label;
}

int count_octet(char **tab, label_t **label_list)
{
    int i = 0;
    int octet = 0;
    char **param = {0};

    for (i = 2; tab[i] != NULL; i++){
        param = my_split_str(tab[i], "\t, ");
        if (get_op_index(param[0]) == -1)
            add_label(label_list, param[0], octet);
        octet = octet + find_str(tab[i]);
    }
    return octet;
}
