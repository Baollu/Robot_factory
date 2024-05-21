/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include "include/my.h"

char *my_strcapitalize(char *str)
{
    int start_of_a_word = 1;

    my_strlowcase(str);
    for (int i = 0; str[i] != '\0'; i++){
        if (start_of_a_word == 1 && str[i] <= 122 && 97 <= str[i]){
            str[i] -= 32;
        }
        if (str[i] == ' '){
            start_of_a_word = 1;
        } else {
            start_of_a_word = 0;
        }
    }
    return str;
}
