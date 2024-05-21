/*
** EPITECH PROJECT, 2023
** temp
** File description:
** temp file
*/

int is_upper(char c)
{
    if (c >= 65 && c <= 90)
        return 1;
    return 0;
}

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (is_upper(str[i]) == 0)
            return 0;
    return 1;
}
