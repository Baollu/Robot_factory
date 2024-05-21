/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

int my_compute_square_root(int nb)
{
    int i = 1;

    if (nb <= 0){
        return 0;
    }
    while (i * i <= nb){
        if (i * i == nb){
            return i;
        }
        i++;
    }
    return 0;
}
