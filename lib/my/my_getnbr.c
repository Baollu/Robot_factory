/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

int check(char c)
{
    if (c >= 48 && c < 58){
        return 1;
    }
    return 0;
}

int transform_into_nbr(char const *str, int start, int length, int neg)
{
    long nbr = 0;

    if (length > 10){
        return 0;
    }
    for (int i = 0; i < length; i++){
        nbr = (nbr * 10) + (str[start + i] - 48);
    }
    if (neg == 1){
        if (nbr > 2147483647){
            return 0;
        }
    } else {
        if (nbr > 2147483648){
            return 0;
        }
    }
    return nbr;
}

int my_findnbr(char const *str, int i, int neg)
{
    int length = 0;
    int start = i;

    while (0 == (str[i] == '\0' || (0 == (check(str[i]))))){
            length++;
            i++;
    }
    return transform_into_nbr(str, start, i - start, neg);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int neg = 1;

    while (str[i] != '\0'){
        if (i > 0 && str[i - 1] == '-'){
            neg = -1;
        } else {
            neg = 1;
        }
        if (check(str[i])){
            return my_findnbr(str, i, neg) * neg;
        }
        i++;
    }
    return 0;
}
