NAME		:=	pipex

SRCS		:=	srcs/main.c \
				srcs/error.c \
				srcs/utils.c \
				srcs/ft_split.c \
				srcs/ft_strchr.c \
				srcs/ft_strlcpy.c \
				srcs/ft_strlen.c \
				srcs/ft_calloc.c \
				srcs/ft_bzero.c

OBJS		:=	${SRCS:.c=.o}

CC			:=	gcc

CFLAGS		:=	-Wall -Wextra -Werror

INCLUDES	:= ./includes

all:		${NAME}

${NAME}:	${OBJS}
		${CC} ${OBJS} -o ${NAME}

clean:
		rm -f ${OBJS}

fclean:		clean
		rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re