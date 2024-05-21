/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include <stdio.h>
#include "include/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int len = my_strlen(dest);

    my_strncpy(dest + len, src, nb);
    *(dest + len + nb) = '\0';
    return dest;
}
