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

int get_label_pos(char *name, label_t *label_list)
{
    while (label_list != NULL && my_strcmp(name, label_list->name) != 0){
        label_list = label_list->next;
    }
    if (label_list != NULL)
        return label_list->label_pos;
    return -1;
}

int rev_short(int nbr)
{
    return (nbr >> 8) % 256 + ((nbr % 256) << 8);
}

void write_label(int fd, char *name, label_t *label_list, int actual_octet)
{
    int label_pos = get_label_pos(name + 2, label_list) - actual_octet;

    if (label_pos < 0)
        label_pos++;
    label_pos = rev_short(label_pos);
    write(fd, &label_pos, 2);
}

static void write_type_2(int fd, char *param, char **splited_line, int len)
{
    int nbr = my_getnbr(param + 1);

    nbr = is_index(splited_line[0]) ? rev_short(nbr) : rev_int(nbr);
    write(fd, &nbr, len);
}

static void write_type_3(int fd, char *param, int len)
{
    int nbr = my_getnbr(param);

    nbr = rev_short(nbr);
    write(fd, &nbr, len);
}

void write_params(int fd, char *line, int index, label_t *label_list)
{
    static int actual_octet = 0;
    char **splited_line = my_split_str(line, " ,\t");
    char *param = splited_line[index];
    int params_type = get_params_type(splited_line, index);
    int params_len = get_params_len(splited_line, index);
    int nbr = 0;

    if (index == 1)
        actual_octet += find_str(line);
    if (params_type == 1){
        nbr = my_getnbr(param + 1);
        write(fd, &nbr, params_len);
    }
    if (params_type == 2 && param[1] != ':')
        write_type_2(fd, param, splited_line, params_len);
    if (params_type == 2 && param[1] == ':')
        write_label(fd, param, label_list, actual_octet - find_str(line));
    if (params_type == 3)
        write_type_3(fd, param, params_len);
}
