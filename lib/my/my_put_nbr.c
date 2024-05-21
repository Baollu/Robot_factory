/*
** EPITECH PROJECT, 2023
** task01
** File description:
** test
*/

#include "include/my.h"

int my_put_nbr(int nb)
{
    int temp;

    if (nb < 0){
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb < 10){
        my_putchar(nb + 48);
        return 0;
    }
    temp = nb % 10;
    my_put_nbr(nb / 10);
    my_putchar(temp + 48);
    return 0;
}

int my_put_nbr_u(unsigned nb)
{
    unsigned temp;

    if (nb < 0){
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb < 10){
        my_putchar(nb + 48);
        return 0;
    }
    temp = nb % 10;
    my_put_nbr(nb / 10);
    my_putchar(temp + 48);
    return 0;
}
