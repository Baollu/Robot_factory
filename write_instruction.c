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

int get_op_index(char *op)
{
    for (int i = 0; i < NBR_OP; i++)
        if (my_strcmp(op, op_tab[i].mnemonique) == 0)
            return i;
    return -1;
}

void write_instruction(char *op, int fd)
{
    int op_code = get_op_index(op) + 1;

    write(fd, &op_code, 1);
}
