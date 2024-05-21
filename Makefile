##
## EPITECH PROJECT, 2023
## test
## File description:
## test
##

NAME =		asm

SRC = 		main.c			\
		write_header.c		\
		write_instruction.c	\
		write_params_type.c	\
		write_params.c		\
		op.c			\
		count_octet.c		\
		read_file.c		\
		have_headers.c		\
		check_args.c		\

OBJ = 		$(SRC:.c=.o)

CFLAGS =	-Wall -Wextra

CPPFLAGS = 	-I ./include

LD_LIBRARY_PATH = -L.

LDFLAGS  =	-lmy			\

LIB_PATH = 	./lib/my

all:    $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIB_PATH)
	$(CC) -o $(NAME) $(OBJ) $(LD_LIBRARY_PATH) $(LDFLAGS)

test: $(NAME)
	rm -f abel.s
	./asm abel.s
	hexdump -C abel.cor

tests_run: $(OBJ)
	$(MAKE) -C $(LIB_PATH)
	$(CC) -o tests/unit_tests $(SRC) tests/test_main.c \
	--coverage -lcriterion $(LD_LIBRARY_PATH) $(LDFLAGS) $(CPPFLAGS)

clean:
	rm -f libmy.a
	rm -f lib/my/libmy.a
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

tclean:
	rm -f tests/unit_tests*

re: fclean all
