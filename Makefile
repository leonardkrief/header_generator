SRCS		=	srcs/get_next_line.c \
				srcs/utils.c \
				srcs/main.c

OBJS		= $(SRCS:.c=.o)

PROTOTYPES	=	prototypes

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g3
INCLUDE		=	-I include
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
