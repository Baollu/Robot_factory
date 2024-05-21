/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include "include/my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        my_putchar(str[i]);
        i++;
    }
    return 0;
}

int is_in_str(char letter, char *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == letter){
            return 1;
        }
    }
    return 0;
}

int my_arrlen(char **arr)
{
    int len;

    for (len = 0; arr[len]; len++);
    return len;
}

void print_arr(char **arr)
{
    for (int i = 0; arr[i]; i++)
        my_printf("{%s}\n", arr[i]);
}
