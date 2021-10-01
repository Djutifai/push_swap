SRC			= src/push_swap.c src/ft_help_funcs.c

OBJ			= ${SRC:.c=.o}

INCLUDES	= includes/

NAME		= push_swap

CFLAGS		= -Wall -Werror -Wextra

%.o:		%.c Makefile ${INCLUDES}push_swap.h
			${CC} $(CFLAGS) -c $< -o $@ -I ${INCLUDES}

all:		$(NAME)
	
$(NAME):	${OBJ} $(INCLUDES)push_swap.h Makefile
			${CC} ${CFLAGS} ${OBJ} -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)
