/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include "include/my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int length = my_strlen(str);
    char str_temp[length];

    for (i = 0; i < length; i++){
        str_temp[length - 1 - i] = str[i];
    }
    for (i = 0; i < length; i++){
        str[i] = str_temp[i];
    }
    return str;
}
