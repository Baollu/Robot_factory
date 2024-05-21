/*
** EPITECH PROJECT, 2023
** temp
** File description:
** temp file
*/

int is_num(char c)
{
    if (c >= 48 && c <= 57)
        return 1;
    return 0;
}

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (is_num(str[i]) == 0)
            return 0;
    return 1;
}
