/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

int my_char_isalpha(char c)
{
    if ((97 <= c && c <= 122) || (64 <= c && c <= 90)){
        return 1;
    }
    return 0;
}

int my_str_isalpha(char *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (my_char_isalpha(str[i] != 1)){
            return 0;
        }
    }
    return 1;
}
