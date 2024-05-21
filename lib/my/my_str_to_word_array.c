/*
** EPITECH PROJECT, 2024
** test
** File description:
** test
*/

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int is_alphanum(char c)
{
    if (c >= 48 && c <= 57)
        return 1;
    if (c >= 65 && c <= 90)
        return 1;
    if (c >= 97 && c <= 122)
        return 1;
    return 0;
}

int get_nbr_word(char const *str)
{
    int nbr_word = 0;
    int i;

    for (i = 1; str[i]; i++){
        if (is_alphanum(str[i - 1]) && is_alphanum(str[i]) == 0)
            nbr_word ++;
    }
    if (is_alphanum(str[i - 1]))
        nbr_word ++;
    return nbr_word;
}

int get_word_len(char const *str)
{
    int len;

    for (len = 0; is_alphanum(str[len]); len++);
    return len;
}

char *get_word(char const *str, int *counter)
{
    char *cut_str = malloc(sizeof(char) * get_word_len(str));
    int i;

    for (i = 0; is_alphanum(str[i]); i++){
        cut_str[i] = str[i];
    }
    *counter += i - 1;
    return cut_str;
}

char **my_str_to_word_array(char const *str)
{
    int nbr_word = get_nbr_word(str);
    char **str_split = malloc(sizeof(char *) * (nbr_word + 1));
    int j = 0;

    for (int i = 0; str[i]; i++){
        if (is_alphanum(str[i])){
            str_split[j] = get_word(str + i, &i);
            j++;
        }
    }
    str_split[nbr_word] = NULL;
    return str_split;
}
