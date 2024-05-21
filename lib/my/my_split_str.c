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
#include "include/my.h"

int get_nbr_word_split_str(char const *str, char *c)
{
    int nbr_word = 0;
    int i;

    for (i = 1; str[i]; i++){
        if (!is_in_str(str[i - 1], c) && is_in_str(str[i], c))
            nbr_word ++;
    }
    if (!is_in_str(str[i - 1], c))
        nbr_word ++;
    return nbr_word;
}

int get_word_len_split_str(char const *str, char *c)
{
    int len;

    for (len = 0; str[len] && !is_in_str(str[len], c); len++);
    return len;
}

char *get_word_split_str(char const *str, int *counter, char *c)
{
    char *cutstr = malloc(sizeof(char) * (get_word_len_split_str(str, c) + 1));
    int i;

    for (i = 0; !is_in_str(str[i], c) && str[i]; i++){
        cutstr[i] = str[i];
    }
    cutstr[i] = '\0';
    *counter += i - 1;
    return cutstr;
}

char **my_split_str(char *str, char *c)
{
    int nbr_word = get_nbr_word_split_str(str, c);
    char **str_split = malloc(sizeof(char *) * (nbr_word + 1));
    int j = 0;
    int i = 0;

    for (i = 0; str[i]; i++){
        if (!is_in_str(str[i], c)){
            str_split[j] = get_word_split_str(str + i, &i, c);
            j++;
        }
    }
    str_split[nbr_word] = NULL;
    return str_split;
}
