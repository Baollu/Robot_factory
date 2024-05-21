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

int format_f(va_list list, struct option_s *op)
{
    double nbr;
    int nbr_space;
    int option;
    int option2;

    if (op->letter != 'f')
        return 0;
    if (op->pre == -1)
        op->pre = 6;
    nbr = va_arg(list, double);
    nbr_space = op->width - MAX(my_nbrlen(nbr), op->pre) - IS_NEG(nbr);
    option = op->plus + op->space;
    option2 = option + IS_NEG(nbr);
    print_space(nbr_space - option, op, op->minus, IS_NEG(nbr));
    my_put_nbr(ABS(nbr));
    for (int i = 0; i < op->pre - my_nbrlen(nbr); i++){
        my_putchar('0');
    }
    print_space(nbr_space - option, op, 1 - op->minus, IS_NEG(nbr));
    return MAX(op->width, MAX(my_nbrlen(nbr), op->pre) + option2);
}

int format_n(va_list list, struct option_s *op)
{
    if (op->letter != 'n')
        return 0;
    *(va_arg(list, int *)) = get_nbr_letter(0);
    return 0;
}

int format_u(va_list list, struct option_s *op)
{
    unsigned nbr;
    int nbr_space;
    int option;

    if (op->letter != 'u')
        return 0;
    nbr = (unsigned)convert_nbr(op, list);
    nbr_space = op->width - MAX(my_nbrlen(nbr), op->pre);
    option = op->plus + op->space;
    print_space(nbr_space - option, op, op->minus, 0);
    for (int i = 0; i < op->pre - my_nbrlen(nbr); i++){
        my_putchar('0');
    }
    my_put_nbr_u(nbr);
    print_space(nbr_space - option, op, 1 - op->minus, 0);
    return MAX(op->width, MAX(my_nbrlen(nbr), op->pre) + option);
}
