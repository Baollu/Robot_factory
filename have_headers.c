/*
** EPITECH PROJECT, 2024
** header
** File description:
** header
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "my_macro.h"
#include "op.h"

int same_name(char *line)
{
    static int name = 0;
    static int comment = 0;
    char **tab = my_split_str(line, "\t ");

    for (int i = 0; tab[i] != NULL; i++){
        if (my_strcmp(tab[i], ".name") == 0)
            name++;
        if (my_strcmp(tab[i], ".comment") == 0)
            comment++;
    }
    if (name != 1 && comment != 1)
        return 84;
    return 0;
}

int have_name(char *line)
{
    for (int i = 0; line[i] != '\0'; i++){
        if (line[i] == '"')
            return 1;
    }
    return 0;
}

int have_headers(char *line)
{
    int error = same_name(line);

    if (error == 84)
        return 84;
    if (have_name(line) == 0)
        return 84;
    return 0;
}
