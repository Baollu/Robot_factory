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

void write_header(int fd, char *prog_name, int prog_size, char *comment)
{
    header_t header = {0, "", 0, ""};
    int i = 0;

    for (i = 0; prog_name[i]; i++)
        header.prog_name[i] = prog_name[i];
    header.prog_name[i] = '\0';
    for (i = 0; comment[i]; i++)
        header.comment[i] = comment[i];
    header.comment[i] = '\0';
    header.magic = rev_int(COREWAR_EXEC_MAGIC);
    header.prog_size = rev_int(prog_size);
    write(fd, &header, sizeof(header_t));
}
