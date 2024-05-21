/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include <stdio.h>
#include "include/my.h"
#include "include/my_macro.h"
#include <stdarg.h>
#include <stdlib.h>

long long int convert_nbr(struct option_s *op, va_list list)
{
    if (op->h == 1)
        return (short) va_arg(list, int);
    if (op->letter == 'p')
        return va_arg(list, long long int);
    return va_arg(list, int);
}

void check_option(struct option_s *op, int is_neg)
{
    if (is_neg == 1)
        my_putchar('-');
    if (op->plus == 1)
        my_putchar('+');
    if (op->space == 1)
        my_putchar(' ');
}

int print_space(int nbr_space, struct option_s *op, int no_space, int is_neg)
{
    if (no_space == 1)
        return 0;
    if (op->zero == 0){
        for (int i = 0; i < nbr_space - h_diff(op, op->letter); i++){
            my_putchar(' ');
        }
        check_option(op, is_neg);
    } else {
        check_option(op, is_neg);
        for (int i = 0; i < nbr_space - h_diff(op, op->letter); i++){
            my_putchar('0');
        }
    }
    return 1;
}

void convert_base(long long int nbr, int base, int act, int *Nbr)
{
    if (nbr < base){
        Nbr[act] = nbr;
        Nbr[act + 1] = -101;
    } else {
        Nbr[act] = (nbr % base);
        convert_base(nbr / base, base, act + 1, Nbr);
    }
}

int *convert_base_start(long long int nbr, int base)
{
    int length;
    int Nbr[65];
    int *Nbr2 = malloc(sizeof(int) * 65);

    nbr = ABS(nbr);
    convert_base(nbr, base, 0, Nbr);
    for (length = 0; Nbr[length] != -101; length++);
    for (int i = 0; i < length; i++){
        Nbr2[length - i - 1] = Nbr[i];
    }
    Nbr2[length] = -101;
    return Nbr2;
}
