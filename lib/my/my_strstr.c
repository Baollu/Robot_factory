/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include <stddef.h>

int search(char *str, char const *to_find, int n)
{
    for (int i = 0; str[n + i] != '\0'; i++){
        if (to_find[i] == '\0'){
            return 1;
        }
        if (to_find[i] != str[i + n]){
            break;
        }
    }
    return 0;
}

char *my_strstr(char *str, char const *to_find)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == to_find[0] && search(str, to_find, i) == 1){
            return str + i;
        }
    }
    return NULL;
}
