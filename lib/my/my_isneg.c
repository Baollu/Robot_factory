/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include "include/my.h"

int my_isneg(int n)
{
    if (n >= 0){
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return 0;
}
