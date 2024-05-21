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
#include <stdlib.h>

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

int format_x(va_list list, struct option_s *op)
{
    int *nbr;
    int nbr_space;
    int option;
    int option2;

    if (op->letter != 'x')
        return 0;
    nbr = convert_base_start(convert_nbr(op, list), 16);
    nbr_space = op->width - MAX(my_base_len(nbr), op->pre);
    option = op->plus + op->space;
    option2 = option + h_diff(op, 'x');
    print_space(nbr_space - option, op, op->minus, 0);
    if (op->hash == 1)
        print_hash(op->letter);
    for (int i = 0; i < op->pre - my_base_len(nbr); i++){
        my_putchar('0');
    }
    my_put_base(nbr, 16, 0);
    print_space(nbr_space - option, op, 1 - op->minus, 0);
    return MAX(op->width, MAX(my_base_len(nbr), op->pre) + option2);
}

int format_x2(va_list list, struct option_s *op)
{
    int *nbr;
    int nbr_space;
    int option;
    int option2;

    if (op->letter != 'X')
        return 0;
    nbr = convert_base_start(convert_nbr(op, list), 16);
    nbr_space = op->width - MAX(my_base_len(nbr), op->pre);
    option = op->plus + op->space;
    option2 = option + h_diff(op, 'X');
    print_space(nbr_space - option, op, op->minus, 0);
    if (op->hash == 1)
        print_hash(op->letter);
    for (int i = 0; i < op->pre - my_base_len(nbr); i++){
        my_putchar('0');
    }
    my_put_base(nbr, 16, 0);
    print_space(nbr_space - option, op, 1 - op->minus, 0);
    return MAX(op->width, MAX(my_base_len(nbr), op->pre) + option2);
}

int format_o(va_list list, struct option_s *op)
{
    int *nbr;
    int nbr_space;
    int option;
    int option2;

    if (op->letter != 'o')
        return 0;
    nbr = convert_base_start(convert_nbr(op, list), 8);
    nbr_space = op->width - MAX(my_base_len(nbr), op->pre);
    option = op->plus + op->space;
    option2 = option - h_diff(op, 'o');
    print_space(nbr_space - option, op, op->minus, 0);
    if (op->hash == 1)
        print_hash(op->letter);
    for (int i = 0; i < op->pre - my_base_len(nbr) - op->hash; i++){
        my_putchar('0');
    }
    my_put_base(nbr, 8, 0);
    print_space(nbr_space - option, op, 1 - op->minus, 0);
    return MAX(op->width, MAX(my_base_len(nbr) + op->hash, op->pre) + option);
}
