/*
** EPITECH PROJECT, 2024
** parsing
** File description:
** parsing
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/my_macro.h"

int my_count(char *str, char c)
{
    int res = 0;

    for (int i = 0; str[i]; i++)
        res += str[i] == c;
    return res;
}

int my_len(char *str)
{
    int res;

    for (res = 0; str[res]; res++);
    return res;
}

char *my_strip_base(char *str, int free_)
{
    char *res;
    int start = 0;
    int end = 0;

    for (start = 0; str[start] == ' ' || str[start] == '\t'; start++);
    for (end = my_len(str); end > 0 && is_in_str(str[end - 1], " \t"); end--);
    res = malloc(sizeof(char) * (end - start + 1));
    for (int i = start; i < end; i++)
        res[i - start] = str[i];
    res[end - start] = '\0';
    if (free_)
        free(str);
    return res;
}

char *my_strip(char *str)
{
    return my_strip_base(str, 0);
}

char *my_stripf(char *str)
{
    return my_strip_base(str, 1);
}
