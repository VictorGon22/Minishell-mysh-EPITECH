##
## EPITECH PROJECT, 2021
## d10
## File description:
## description
##

OBJ = $(SRCS_C:.c=.o)

LIB = -L./lib/my -lmy

SFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

CFLAGS = -W -Werror -Wextra -Wall

SRC		=	sources/

SRC_C	=	main.c 								\
			mysh_functions.c					\
			mysh_functions2.c					\
			function_ptr.c						\
			get_information.c 					\
			get_information2.c 					\
			env_functions.c						\
			exec_functions.c					\
			array_functions.c					\
			array_functions_2.c					\
			find_functions.c					\
			linked_functions.c					\
			fundamental_func/my_put_nbr.c 		\
			fundamental_func/extra_func.c 		\
			fundamental_func/my_callocs.c 		\
			fundamental_func/my_strcat.c		\
			fundamental_func/my_charcat.c		\
			fundamental_func/my_isalnum.c		\
			fundamental_func/my_return_char.c	\
			fundamental_func/my_strdup.c		\
			fundamental_func/my_strcpy.c 		\
			fundamental_func/my_revstr.c		\
			fundamental_func/my_strlen.c 		\
			fundamental_func/my_nbrlen.c		\
			fundamental_func/my_strcmp.c

SRCS_C	= 	$(addprefix $(SRC), $(SRC_C))

CFLAGS = -I./includes

NAME = 		mysh

all: $(NAME)

$(NAME): $(OBJ)
	gcc -g -W -Werror -Wextra -Wall -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
	make clean
