##
## EPITECH PROJECT, 2023
## test
## File description:
## test
##

SRC	=	my_compute_power_rec.c		\
		my_compute_square_root.c	\
		my_find_prime_sup.c		\
		my_getnbr.c			\
		my_isneg.c			\
		my_is_prime.c			\
		my_putchar.c			\
		my_put_nbr.c			\
		my_putstr.c			\
		my_revstr.c			\
		my_show_word_array.c		\
		my_sort_int_array.c		\
		my_strcapitalize.c		\
		my_strcat.c			\
		my_strcmp.c			\
		my_strcpy.c			\
		my_strdup.c			\
		my_str_isalpha.c		\
		my_str_isnum.c			\
		my_str_isupper.c		\
		my_str_islower.c		\
		my_strlen.c			\
		my_strlowcase.c			\
		my_strncat.c			\
		my_strncmp.c			\
		my_strncpy.c			\
		my_strstr.c			\
		my_str_to_word_array.c		\
		my_swap.c			\
		my_strip.c			\
		my_read_file.c			\
		my_split.c			\
		my_split_str.c			\
		temp.c				\
		convert_str.c			\
		extra_function.c		\
		format_c_s_d_i_per.c		\
		format_n_u_x_x2_o.c		\
		format_p_extra.c		\
		my_printf.c			\
		print_str_array.c		\

OBJ	=	$(SRC:.c=.o)

all:	compile

compile:	$(OBJ)
	ar rc libmy.a $(OBJ)
	rm -f $(OBJ)
	cp libmy.a ../..

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f a.out

re: fclean a.out
