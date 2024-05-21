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

int format_p(va_list list, struct option_s *op)
{
    int *nbr;
    int nbr_space;
    int option;
    int option2;

    if (op->letter != 'p')
        return 0;
    nbr = convert_base_start(convert_nbr(op, list), 16);
    nbr_space = op->width - MAX(my_base_len(nbr), op->pre);
    option = op->plus + op->space;
    option2 = option + h_diff(op, 'p');
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

int my_base_len(int *Nbr)
{
    int i;

    for (i = 0; Nbr[i] != -101; i++);
    return i;
}

void my_put_base(int *Nbr, int base, int uppercase)
{
    char Base[16];

    if (base == 8)
        my_strcpy(Base, "01234567");
    if (base == 16 && uppercase == 0)
        my_strcpy(Base, "0123456789abcdef");
    if (base == 16 && uppercase == 1)
        my_strcpy(Base, "0123456789ABCDEF");
    for (int i = 0; Nbr[i] != -101; i++){
        my_putchar(Base[Nbr[i]]);
    }
}

void print_hash(char letter)
{
    if (letter == 'x' || letter == 'p')
        my_putstr("0x");
    if (letter == 'X')
        my_putstr("0X");
    if (letter == 'o')
        my_putchar('0');
}

int h_diff(struct option_s *op, char c)
{
    if (op->hash == 0)
        return 0;
    if (c == 'x' || c == 'X' || c == 'p')
        return 2;
    if (c == 'o')
        return 1;
}
