/*
** EPITECH PROJECT, 2023
** temp
** File description:
** temp file
*/

int is_lower(char c)
{
    if (c >= 97 && c <= 122)
        return 1;
    return 0;
}

int my_str_islower(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (is_lower(str[i]) == 0)
            return 0;
    return 1;
}
