/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include "include/my.h"

int my_find_prime_sup(int nb)
{
    if (nb <= 2){
        return 2;
    }
    while (my_is_prime(nb) == 0){
        nb++;
    }
    return nb;
}
