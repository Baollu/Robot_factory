/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] <= 90 && 65 <= str[i]){
            str[i] += 32;
        }
    }
    return str;
}
