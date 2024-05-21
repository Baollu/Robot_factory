/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include <stdlib.h>
#include "include/my.h"

char *my_strdup(char const *src)
{
    char *str_cp;

    str_cp = malloc(sizeof(char) * (my_strlen(src) + 1));
    return my_strcpy(str_cp, src);
}
