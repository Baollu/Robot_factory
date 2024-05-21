/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#ifndef MY_PROTOTYPE
    #define MY_PROTOTYPE

int flag_c(va_list list, char c);
int flag_d(va_list list, char c);
int flag_i(va_list list, char c);
int flag_s(va_list list, char c);
int flag_per(va_list list, char c);
void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
int check(char c);
int transform_into_nbr(char const *str, int start, int length, int neg);
int my_findnbr(char const *str, int i, int neg);
void insert(int *array2, int nbr, int size, int size_max);
int search(char *str, char const *to_find, int n);
int my_char_isalpha(char c);
int my_show_word_array(char const **tab);
int count_space_in_str(char const *str);

#endif
