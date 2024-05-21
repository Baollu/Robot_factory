/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

int my_is_prime(int nb)
{
    int i = 3;

    if (nb < 2){
        return 0;
    }
    if (nb % 2 == 0){
        return 0;
    }
    while (i < nb / 2){
        if (nb % i == 0){
            return 0;
        }
        i = i + 2;
    }
    return 1;
}
