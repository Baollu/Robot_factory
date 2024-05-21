/*
** EPITECH PROJECT, 2024
** split
** File description:
** split
*/

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int not_same(char c1, char c2)
{
    return c1 != c2;
}

int get_nbr_word_split(char const *str, char c)
{
    int nbr_word = 0;
    int i;

    for (i = 1; str[i]; i++){
        if (not_same(str[i - 1], c) && not_same(str[i], c) == 0)
            nbr_word ++;
    }
    if (not_same(str[i - 1], c))
        nbr_word ++;
    return nbr_word;
}

int get_word_len_split(char const *str, char c)
{
    int len;

    for (len = 0; str[len] && not_same(str[len], c); len++);
    return len;
}

char *get_word_split(char const *str, int *counter, char c)
{
    char *cut_str = malloc(sizeof(char) * (get_word_len_split(str, c) + 1));
    int i;

    for (i = 0; not_same(str[i], c) && str[i]; i++){
        cut_str[i] = str[i];
    }
    cut_str[i] = '\0';
    *counter += i - 1;
    return cut_str;
}

char **my_split(char *str, char c)
{
    int nbr_word = get_nbr_word_split(str, c);
    char **str_split = malloc(sizeof(char *) * (nbr_word + 1));
    int j = 0;
    int i = 0;

    for (i = 0; str[i]; i++){
        if (not_same(str[i], c)){
            str_split[j] = get_word_split(str + i, &i, c);
            j++;
        }
    }
    str_split[nbr_word] = NULL;
    return str_split;
}
