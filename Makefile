NAME		:=	pipex

SRCS		:=

OBJS		:=	${SRCS:.c=.o}

CC			:=	gcc

CFLAGS		:=	-Wall -Wextra -Werror

INCLUDES	:= ./includes

all:		${NAME}

${NAME}:	${OBJS}
		${CC} ${OBJS} -0 ${NAME}

clean:
		rm -f ${OBJS}

fclean:		clean
		rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re