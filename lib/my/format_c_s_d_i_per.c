/*
** EPITECH PROJECT, 2023
** main
** File description:
** main template
*/

#include <stdio.h>
#include "include/my.h"
#include "include/my_macro.h"
#include <stdarg.h>

int format_c(va_list list, struct option_s *op)
{
    if (op->letter != 'c'){
        return 0;
    }
    print_space(op->width - 1, op, op->minus, 0);
    my_putchar(va_arg(list, int));
    print_space(op->width - 1, op, 1 - op->minus, 0);
    return MAX(1, op->width);
}

int format_i(va_list list, struct option_s *op)
{
    long nbr;
    int nbr_space;
    int option;
    int option2;

    if (op->letter != 'd')
        return 0;
    nbr = convert_nbr(op, list);
    nbr_space = op->width - MAX(my_nbrlen(nbr), op->pre) - IS_NEG(nbr);
    option = op->plus + op->space;
    option2 = option + IS_NEG(nbr);
    print_space(nbr_space - option, op, op->minus, IS_NEG(nbr));
    for (int i = 0; i < op->pre - my_nbrlen(nbr); i++){
        my_putchar('0');
    }
    my_put_nbr(ABS(nbr));
    print_space(nbr_space - option, op, 1 - op->minus, IS_NEG(nbr));
    return MAX(op->width, MAX(my_nbrlen(nbr), op->pre) + option2);
}

int format_d(va_list list, struct option_s *op)
{
    int nbr;
    int nbr_space;
    int option;
    int option2;

    if (op->letter != 'i')
        return 0;
    nbr = convert_nbr(op, list);
    nbr_space = op->width - MAX(my_nbrlen(nbr), op->pre) - IS_NEG(nbr);
    option = op->plus + op->space;
    option2 = option + IS_NEG(nbr);
    print_space(nbr_space - option, op, op->minus, IS_NEG(nbr));
    for (int i = 0; i < op->pre - my_nbrlen(nbr); i++){
        my_putchar('0');
    }
    my_put_nbr(ABS(nbr));
    print_space(nbr_space - option, op, 1 - op->minus, IS_NEG(nbr));
    return MAX(op->width, MAX(my_nbrlen(nbr), op->pre) + option2);
}

int format_percent(va_list list, struct option_s *option)
{
    if (option->letter != '%')
        return 0;
    my_putchar('%');
    return 1;
}

int format_s(va_list list, struct option_s *op)
{
    char *str;
    int nbr_space;

    if (op->letter != 's')
        return 0;
    str = va_arg(list, char *);
    if (op->pre != -1){
        nbr_space = op->width - MIN(my_strlen(str), op->pre);
        print_space(nbr_space, op, op->minus, 0);
        for (int i = 0; i < op->pre && str[i] != '\0'; i++){
            my_putchar(str[i]);
        }
        print_space(nbr_space, op, 1 - op->minus, 0);
        return MAX(MIN(my_strlen(str), op->pre), op->width);
    } else {
        print_space(op->width - my_strlen(str), op, op->minus, 0);
        my_putstr(str);
        print_space(op->width - my_strlen(str), op, 1 - op->minus, 0);
        return MAX(my_strlen(str), op->width);
    }
}
