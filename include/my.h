/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#ifndef MY_PROTOTYPE
    #define MY_PROTOTYPE
    #define NBR_FUNCTION 11

typedef struct label_s {
    char *name;
    int label_pos;
    struct label_s *next;
} label_t;

int get_arrlen(char **arr);
int check_args(char **av);
char *get_name(char *base_name);
int need_params_type(char *inst);
int find_str(char *line);
int count_octet(char **tab, label_t **label_list);
int get_params_type(char **line, int index);
int is_index(char *inst);
int get_params_len(char **line, int index);
void write_header(int fd, char *prog_name, int prog_size, char *comment);
void write_instruction(char *op, int fd);
void write_params_type(char *op, int fd, char **splited_line);
void write_params(int fd, char *line, int index, label_t *label_list);
int get_op_index(char *op);
int rev_int(int nbr);
char **read_file(const char *file_name);
char *find_name(char *line, int j);
int nbr_word(char **tab);
char **name_headers(char **tab);
int have_headers(char *line);

char *my_strip(char *str);
void print_arr(char **arr);
int my_arrlen(char **arr);
char **my_split(char *str, char c);
char **my_split_str(char *str, char *c);
char **my_str_to_word_array(char const *str);
int my_nbrlen(int nbr);
int is_in_str(char letter, char *str);
void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr_u(unsigned nb);
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
