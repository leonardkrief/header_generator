SRCS		=	srcs/get_next_line.c \
				srcs/help.c \
				srcs/libft.c \
				srcs/put_file_to.c \
				srcs/main.c

OBJS		= $(SRCS:.c=.o)

PROTOTYPES	=	prototypes

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g3
INCLUDE		=	-Iinclude
RM			=	rm -rf

${PROTOTYPES}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${PROTOTYPES}

all:	${PROTOTYPES}

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

clean:
		${RM} ${OBJS}
		${RM} ${DEPS}

fclean:	clean
		${RM} "prototypes.txt"
		${RM} ${PROTOTYPES}

re:		fclean all

.PHONY: all clean fclean re
.SILENT:
