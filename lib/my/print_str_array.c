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

void print_str_array(char **str)
{
    for (int i = 0; str[i] != NULL; i++){
        for (int j = 0; str[i][j] != '\0'; j++)
            write(1, &(str[i][j]), 1);
        write(1, "\n", 1);
    }
}
