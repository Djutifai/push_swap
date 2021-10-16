SRC			= src/helpers/clear.c  src/sort/scoring.c src/sort/full_sort_helpers.c \
				src/sort/full_sort.c src/operations/actions.c src/sort/small_sorts.c \
				src/sort/small_sort.c src/operations/pushes.c src/helpers/ft_strfuncs.c \
				src/helpers/ft_help_funcs.c src/sort/sorts.c src/struct_functions/ft_struct_funcs.c \
				src/push_swap.c src/operations/operations_a.c src/operations/operations_b.c \
				src/operations/operations_ab.c

OBJ			= ${SRC:.c=.o}

INCLUDES	= includes/

NAME		= push_swap

CFLAGS		= -Wall -Werror -Wextra

%.o:		%.c Makefile $(INCLUDES)push_swap.h
			${CC} $(CFLAGS) -c $< -o $@ -I ${INCLUDES}

all:		$(NAME)

$(NAME):	$(OBJ) $(INCLUDES)push_swap.h Makefile
			${CC} ${CFLAGS} ${OBJ} -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
