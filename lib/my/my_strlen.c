/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        i++;
    }
    return i;
}

int my_nbrlen(int nbr)
{
    int i = 1;

    if (nbr < 0)
        nbr = nbr * -1;
    while (nbr >= 10){
        nbr = nbr / 10;
        i++;
    }
    return i;
}
