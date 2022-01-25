SRC_DIR		= src/

SRC			= $(shell find ${SRC_DIR} -type f -name "*.c")

OBJ			= ${SRC:.c=.o}

INCLUDES	= includes/

SRC_BON_DIR = bonus/

NAME		= push_swap

SRC_BON		= $(shell find ${SRC_BON_DIR} -type f -name "*bonus.c")

OBJ_BON		= ${SRC_BON:.c=.o}

INCLUDE_BON = ${SRC_BON_DIR}${INCLUDES}

NAME_BON	= checker

CFLAGS		= -Wall -Werror -Wextra

%bonus.o:	%bonus.c Makefile ${INCLUDE_BON}push_swap_bonus.h
			${CC} ${CFLAGS} -c $< -o $@ -I ${INCLUDE_BON}

%.o:		%.c Makefile $(INCLUDES)push_swap.h
			${CC} $(CFLAGS) -c $< -o $@ -I ${INCLUDES}

all:		$(NAME)

$(NAME):	${SRC} ${OBJ} $(INCLUDES)push_swap.h Makefile
			${CC} ${CFLAGS} ${OBJ} -o $(NAME)

bonus:		${NAME_BON}

${NAME_BON}:${SRC_BON} ${OBJ_BON} ${INCLUDE_BON}push_swap_bonus.h Makefile
			${CC} ${CFLAGS} ${OBJ_BON} -o ${NAME_BON}

clean:
			$(RM) $(OBJ) ${OBJ_BON}

fclean:		clean
			$(RM) $(NAME) ${NAME_BON}

re:			fclean all

.PHONY:		all clean fclean re
