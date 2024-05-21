/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"
#include <stdarg.h>

struct option_s *option_init(void)
{
    struct option_s *Option;

    Option = malloc(sizeof(struct option_s));
    Option->plus = 0;
    Option->space = 0;
    Option->zero = 0;
    Option->minus = 0;
    Option->pre = -1;
    Option->width = -1;
    Option->hash = 0;
    Option->h = 0;
    Option->l = 0;
    Option->L = 0;
    return Option;
}

void basic_condition(char c, struct option_s *option)
{
    char array[] = {'+', '-', ' ', '#', 'h', 'l', 'L'};
    int *option_array[] = {&option->plus, &option->minus, &option->space,
        &option->hash, &option->h, &option->l, &option->L};

    for (int j = 0; j < 7; j++){
        if (c == array[j])
            *option_array[j] = 1;
    }
}

int stockage(char *str, int i, int *is_first_width)
{
    int stored = 0;

    for (; str[i] >= 48 && str[i] <= 57; i++){
        stored = stored * 10;
        stored = stored + str[i] - 48;
    }
    *is_first_width = 0;
    return (stored);
}

void convert_str(char *str, struct option_s *option, va_list list)
{
    int i;
    int is_first_width = 1;
    int is_nbr = 0;

    for (i = 0; str[i] != '\0'; i++){
        is_nbr = str[i] >= 48 && str[i] <= 57;
        if (is_nbr && is_first_width == 1 && str[i - 1] != '.')
            option->width = stockage(str, i, &is_first_width);
        if (str[i] == '.')
            option->pre = stockage(str, i + 1, &is_first_width);
        if (str[i] == '0' && (i == 0 || is_in_str(str[i - 1], "+- #%")))
            option->zero = 1;
        if (str[i] == '*' && str[i - 1] == '.')
            option->pre = va_arg(list, int);
        if (str[i] == '*' && str[i - 1] != '.')
            option->width = va_arg(list, int);
        basic_condition(str[i], option);
    }
    option->letter = str[i - 1];
}
