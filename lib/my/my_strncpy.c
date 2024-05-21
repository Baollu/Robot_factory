/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n){
        dest[i] = src[i];
        i++;
    }
    for (int j = i; j < n; j++){
        dest[j] = '\0';
    }
    return dest;
}
