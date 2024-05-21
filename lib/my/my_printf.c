/*
** EPITECH PROJECT, 2023
** main
** File description:
** main template
*/

#include <stdio.h>
#include "include/my.h"
#include <stdarg.h>
#include <stdlib.h>
#include "include/my_macro.h"

int get_nbr_letter(int add)
{
    static int nbr_letter = 0;

    nbr_letter += add;
    return nbr_letter;
}

int launch_function(va_list list, struct option_s *option, char *str)
{
    int(*FUNCS[NBR_FUNCTION])(va_list, struct option_s *) = {
        &format_d, &format_c, &format_i, &format_percent, &format_s,
        &format_u, &format_n, &format_x, &format_x2, &format_o,
        &format_p
    };
    int sum = 0;

    option = option_init();
    convert_str(str, option, list);
    if (option->letter == 'p')
        option->hash = 1;
    for (int i = 0; i < NBR_FUNCTION; i++){
        sum += (*FUNCS[i])(list, option);
    }
    free(option);
    return sum;
}

char *extract_str(const char *format, int last_percent)
{
    char letter[] = "icopdsneu%ExgfXG";
    int j;
    char *extracted_str;

    for (j = 1; is_in_str(format[last_percent + j], letter) == 0; j++);
    extracted_str = malloc(sizeof(char) * (j + 1));
    for (int i = 1; i < j + 1; i++){
        extracted_str[i - 1] = format[last_percent + i];
    }
    extracted_str[j] = '\0';
    return extracted_str;
}

int my_printf(const char *format, ...)
{
    struct option_s *option;
    va_list list;
    int i;
    char *str;

    va_start(list, format);
    for (i = 0; i < my_strlen(format); i++){
        if (format[i] != '%'){
            my_putchar(format[i]);
            get_nbr_letter(1);
            continue;
        }
        str = extract_str(format, i);
        get_nbr_letter(launch_function(list, option, str));
        i += my_strlen(str);
        free(str);
    }
    return get_nbr_letter(0);
}
