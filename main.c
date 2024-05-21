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

int rev_int(int nbr)
{
    int byte1 = (nbr >> 0) % 256;
    int byte2 = (nbr >> 8) % 256;
    int byte3 = (nbr >> 16) % 256;
    int byte4 = (nbr >> 24) % 256;

    return (byte1 << 24) + (byte2 << 16) + (byte3 << 8) + (byte4 << 0);
}

char *get_name(char *base_name)
{
    char *name = malloc(sizeof(char) * (my_strlen(base_name) + 3));
    int i = 0;

    for (i = 0; base_name[i] != '\0'; i++)
        name[i] = base_name[i];
    name[i - 1] = 'c';
    name[i] = 'o';
    name[i + 1] = 'r';
    name[i + 2] = '\0';
    return name;
}

char *skip_label(char *line)
{
    while (*line != ' ' && *line != '\t' && *line != '\0')
        line++;
    while (*line == ' ' || *line == '\t')
        line++;
    return line;
}

static void write_op(char *line, int fd, label_t *label_list)
{
    char **splited_line = my_split_str(line, " ,\t");
    char *op = splited_line[0];

    if (get_op_index(op) == -1){
        splited_line += 1;
        op = splited_line[0];
        line = skip_label(line);
    }
    if (get_arrlen(splited_line) == 0)
        return;
    write_instruction(op, fd);
    if (need_params_type(op))
        write_params_type(op, fd, splited_line);
    for (int i = 1; splited_line[i] != NULL && splited_line[i][0] != '#'; i++){
        write_params(fd, line, i, label_list);
    }
}

int main(int ac, char **av)
{
    label_t *label_list = NULL;
    char **file;
    int fd;

    if (ac != 2)
        return 84;
    if (check_args(av) == 84)
        return 84;
    fd = open(get_name(av[1]), O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
    file = read_file(av[1]);
    name_headers(file);
    write_header(fd, file[0], count_octet(file, &label_list), file[1]);
    for (int i = 2; file[i] != NULL; i++)
        write_op(file[i], fd, label_list);
    close(fd);
    free(file);
    return 0;
}
